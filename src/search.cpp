#include <QWidget>
#include <QMessageBox>
#include <spdlog/spdlog.h>
#include <fmt/core.h>

#include "mainwindow.h"
#include "search.h"
#include "./ui_searchdialog.h"
#include "version.h"

SearchDialog::SearchDialog(QWidget *parent)
    :QDialog(parent)
    , ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    setModal(false);
    show();

    // Signal handling
    connect(ui->cancelButton, &QPushButton::pressed, this, &SearchDialog::close);
    connect(ui->findNextButton, &QPushButton::pressed, this, &SearchDialog::findNext);
    connect(ui->query, &QLineEdit::textChanged, this, &SearchDialog::queryUpdated);
}

void SearchDialog::findNext()
{
    // TODO: find a better way to access the main editor
    // (this just seems silly to create this pointer again each time the button is pressed)
    Editor* editor = ((MainWindow*)parent())->editor();

    // Set the search flags
    QTextDocument::FindFlags flags;
    if(ui->downRadio->isChecked())
        flags.setFlag(QTextDocument::FindBackward, true);
    if(ui->matchCase->isChecked())
        flags.setFlag(QTextDocument::FindCaseSensitively, true);

    // Execute the search
    bool found = false;
    found = editor->find(ui->query->text(), flags);
    if(!found)
        QMessageBox::information(this, PROGRAM, fmt::format("'{}' が見つかりません。", ui->query->text().toStdString()).c_str(), QMessageBox::Ok);
}

// Set the enabled status of the "find next" button according to the presence of text
void SearchDialog::queryUpdated() { ui->findNextButton->setEnabled(!ui->query->text().isEmpty()); }
