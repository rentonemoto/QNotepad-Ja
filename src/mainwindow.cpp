#include <QCloseEvent>
#include <QMessageBox>
#include <QScreen>
#include <QStandardPaths>
#include <QFileDialog>
#include <QFontDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QDesktopServices>
#include <QGuiApplication>
#include <QPainter>
#include <QUrl>
#include <spdlog/spdlog.h>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <fmt/core.h>



#include "mainwindow.h"
#include "version.h"
#include "editor.h"
#include "search.h"
#include "./ui_mainwindow.h"
#include "./ui_searchdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , searchDialog(new SearchDialog(this))
{
    spdlog::info(PROGRAM " " VERSION);
#if !ADVANCED
    spdlog::info("Running in classic mode. Build with -DCLASSIC=OFF to enable advanced features");
#endif
    searchDialog->close();
    ui->setupUi(this);
    ui->helpAbout->setText(fmt::format("About {}", PROGRAM).c_str());
    move(pos() + (QGuiApplication::primaryScreen()->geometry().center() - geometry().center()));
    updateTitle();

    // StatusBar
    statusBarLabel.setAlignment(Qt::AlignRight);
    cursorMoved();
    ui->statusBar->addWidget(&statusBarLabel, 1);

    // Signal handling
    connect(ui->fileExit, &QAction::triggered, this, &MainWindow::fileExit);
    connect(ui->fileNew, &QAction::triggered, this, &MainWindow::newFile);
    connect(ui->fileOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui->fileSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(ui->fileSaveAs, &QAction::triggered, this, &MainWindow::saveAs);
    connect(ui->filePrint, &QAction::triggered, this, &MainWindow::print);
    connect(ui->text, &QTextEdit::textChanged, this, &MainWindow::textUpdated);
    connect(ui->helpBugReport, &QAction::triggered, this, &MainWindow::reportBug);
    connect(ui->helpAbout, &QAction::triggered, this, &MainWindow::aboutDialog);
    connect(ui->editUndo, &QAction::triggered, this, &MainWindow::undo);
    connect(ui->editRedo, &QAction::triggered, this, &MainWindow::redo);
    connect(ui->editCut, &QAction::triggered, this, &MainWindow::cut);
    connect(ui->editCopy, &QAction::triggered, this, &MainWindow::copy);
    connect(ui->editPaste, &QAction::triggered, this, &MainWindow::paste);
    connect(ui->formatWordWrap, &QAction::triggered, this, &MainWindow::wordWrap);
    connect(ui->viewStatusBar, &QAction::triggered, this, &MainWindow::statusBar);
    connect(ui->text, &QTextEdit::cursorPositionChanged, this, &MainWindow::cursorMoved);
    connect(ui->formatFont, &QAction::triggered, this, &MainWindow::selectFont);
    connect(ui->editFind, &QAction::triggered, this, &MainWindow::search);

    spdlog::info("Initialized main window");
}

void MainWindow::withFile(std::string fileName)
{
    // Load the file if it exists
    if(std::filesystem::exists(fileName))
        loadFile(fileName);
    // Otherwise make a new file
    else {
        this->fileName = std::filesystem::path(fileName).filename().u8string();
        filePath = fileName;
        saved = false;
        updateTitle();
    }
}

// General functions

bool MainWindow::exit(bool fullExit = true) 
{ 
    if(!saved) {
        // Create a messagebox
        auto answer = QMessageBox::question(this, PROGRAM, fmt::format("'{}' への変更内容を保存しますか?", fileName).c_str(), 
                                            QMessageBox::Save | QMessageBox::StandardButton::Discard | QMessageBox::Cancel);

        // Handle the output of the messagebox
        if(answer == QMessageBox::Save) {
            saveFile();
            if(!fullExit)
                return true;
        }
        else if(answer == QMessageBox::Discard && !fullExit)
            return true;
        else if(answer == QMessageBox::Cancel)
            return false;
        else if(!fullExit)
            return false;
    }

    // If we are exiting the whole program
    if(fullExit) {
        spdlog::info("Shutting down...");
        std::exit(0);
    }

    return true; // Just to make the compiler happy
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // Call exit() to get save dialogs if needed
    if(exit(false)) {
        spdlog::info("Shutting down...");
        event->accept();
    }
    else
        event->ignore();
}

void MainWindow::textUpdated() 
{
    // Update the title if the save state changes
    if(saved) {
        saved = false;
        updateTitle(); // Only update the title when changing state
    }
}

void MainWindow::cursorMoved()
{
    // Update the statusbar
    int row = ui->text->textCursor().blockNumber()+1;
    int col = ui->text->textCursor().positionInBlock()+1;
    statusBarLabel.setText(fmt::format("{}行、{} 列", row, col).c_str());
}

void MainWindow::updateTitle() 
{
    setWindowTitle(fmt::format("{}{} - {}", saved ? "" : "*", fileName.c_str(), PROGRAM).c_str());
}

// File functions

void MainWindow::openFile()
{
    // Use exit for the save prompt
    if(!exit(false))
        return;

    // Get the file from the user
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Open"), QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), tr("テキスト文書 (*.txt *.text);;すべてのファイル (*)"));
    
    // This should only trigger if the user exits the dialog
    if(!std::filesystem::exists(fileName.toStdString())) {
        spdlog::error("ファイルを開くことができません。");
        return;
    }

    // Load the file
    loadFile(fileName.toStdString());
}

void MainWindow::newFile()
{
    // We use exit here simply for the save dialog
    if(exit(false)) {
        ui->text->clear();
        saved = true;
        fileName = "無題";
        filePath.clear();
        updateTitle();
        spdlog::info("ファイルを作成しました");
    }
}

void MainWindow::saveFile()
{
    // If there is no file path, use a "save as" dialog to get one
    if(filePath.empty()) {
        filePath = saveAsDialog();
        if(filePath.empty())
            return;
    }

    // Write the file
    std::ofstream file(filePath);
    file << ui->text->toPlainText().toStdString();
    file.close();

    // Change GUI and internal file vars
    saved = true;
    fileName = std::filesystem::path(filePath).filename().u8string();
    updateTitle();
}

void MainWindow::saveAs()
{
    // Get a file path from the user
    filePath = saveAsDialog();
    if(filePath.empty())
        return;

    // Save the file; using the other function 'cause it's already there
    saveFile();
}

void MainWindow::print()
{
    // Printer setup (if needed)
    if(printer == nullptr)
        printer = new QPrinter();
    if(printDialog == nullptr)
        printDialog = new QPrintDialog(printer, this);

    if(printDialog->exec() != QDialog::Accepted)
        return;
    
    // Confirmation
    auto answer = QMessageBox::question(this, "Print", fmt::format("次のドキュメントを印刷しますか? : '{}'", fileName).c_str(), QMessageBox::Yes, QMessageBox::No);

    // Print
    if(answer == QMessageBox::Yes)
        ui->text->print(printer);
}

void MainWindow::loadFile(std::string fileName)
{
    // Read the file into a string
    std::ifstream file(fileName);
    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    
    // Load the file to GUI
    this->fileName = std::filesystem::path(fileName).filename().u8string();
    filePath = std::filesystem::path(fileName);
    ui->text->setText(text.c_str());
    ui->text->moveCursor(QTextCursor::MoveOperation::End);
    saved = true;
    updateTitle();
    file.close();
}

std::string MainWindow::saveAsDialog()
{
    // Get the location from the user
    QString fileName = QFileDialog::getSaveFileName(this,
    tr("Save As..."), QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), tr("テキスト文書 (*.txt *.text);;すべてのファイル (*)"));

    return fileName.toStdString();
}

// Edit functions

void MainWindow::undo() { ui->text->undo(); }
void MainWindow::redo() { ui->text->redo(); }
void MainWindow::cut() { ui->text->cut(); }
void MainWindow::copy() { ui->text->copy(); }
void MainWindow::paste() { ui->text->paste(); }
void MainWindow::search() { searchDialog->exec(); }

// Format functions

void MainWindow::wordWrap()
{
    // Set word wrapping in the textbox
    if(ui->formatWordWrap->isChecked())
        ui->text->setLineWrapMode(QTextEdit::LineWrapMode::WidgetWidth);
    else
        ui->text->setLineWrapMode(QTextEdit::LineWrapMode::NoWrap);
}

void MainWindow::selectFont()
{
    // Get the font input from the user
    bool setFont;
    QFont font = QFontDialog::getFont(&setFont, ui->text->font(), this);

    // Set the font if the user pressed OK
    if(setFont) {
        ui->text->setFont(font);
        spdlog::info("Changed font");
    }
}

// View functions

void MainWindow::statusBar()
{
    // Toggle the status bar
    if(ui->viewStatusBar->isChecked())
        ui->statusBar->show();
    else
        ui->statusBar->hide();
}

// Help functions

void MainWindow::reportBug() { QDesktopServices::openUrl(QUrl("https://github.com/Starman0620/QNotepad/issues/new")); }
void MainWindow::aboutDialog() { QMessageBox::about(this, fmt::format("メモ帳 について", PROGRAM).c_str(), fmt::format("{} {}\n\nWritten by Cam K.\nTranslated by Rento Nemoto\nQNotepad とそのユーザー インターフェイスは、日本国およびその他の国/地域の著作権およびその他の知的財産権によって保護されています。\nこのソフトウェアは、2条項BSDライセンスの条件に基づいて利用可能です。\nこのソフトウェアは自由ソフトウェアです。", PROGRAM, VERSION).c_str()); }

// Getters

Editor *MainWindow::editor() { return ui->text; }
