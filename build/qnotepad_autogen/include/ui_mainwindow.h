/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "editor.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *fileOpen;
    QAction *fileNew;
    QAction *fileSave;
    QAction *fileSaveAs;
    QAction *fileExit;
    QAction *helpAbout;
    QAction *helpBugReport;
    QAction *editUndo;
    QAction *editCut;
    QAction *editCopy;
    QAction *editPaste;
    QAction *editRedo;
    QAction *formatWordWrap;
    QAction *viewStatusBar;
    QAction *formatFont;
    QAction *editFind;
    QAction *filePrint;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    Editor *text;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QMenu *menuFormat;
    QMenu *menuView;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        fileOpen = new QAction(MainWindow);
        fileOpen->setObjectName(QString::fromUtf8("fileOpen"));
        fileNew = new QAction(MainWindow);
        fileNew->setObjectName(QString::fromUtf8("fileNew"));
        fileSave = new QAction(MainWindow);
        fileSave->setObjectName(QString::fromUtf8("fileSave"));
        fileSaveAs = new QAction(MainWindow);
        fileSaveAs->setObjectName(QString::fromUtf8("fileSaveAs"));
        fileExit = new QAction(MainWindow);
        fileExit->setObjectName(QString::fromUtf8("fileExit"));
        helpAbout = new QAction(MainWindow);
        helpAbout->setObjectName(QString::fromUtf8("helpAbout"));
        helpBugReport = new QAction(MainWindow);
        helpBugReport->setObjectName(QString::fromUtf8("helpBugReport"));
        editUndo = new QAction(MainWindow);
        editUndo->setObjectName(QString::fromUtf8("editUndo"));
        editCut = new QAction(MainWindow);
        editCut->setObjectName(QString::fromUtf8("editCut"));
        editCopy = new QAction(MainWindow);
        editCopy->setObjectName(QString::fromUtf8("editCopy"));
        editPaste = new QAction(MainWindow);
        editPaste->setObjectName(QString::fromUtf8("editPaste"));
        editRedo = new QAction(MainWindow);
        editRedo->setObjectName(QString::fromUtf8("editRedo"));
        formatWordWrap = new QAction(MainWindow);
        formatWordWrap->setObjectName(QString::fromUtf8("formatWordWrap"));
        formatWordWrap->setCheckable(true);
        viewStatusBar = new QAction(MainWindow);
        viewStatusBar->setObjectName(QString::fromUtf8("viewStatusBar"));
        viewStatusBar->setCheckable(true);
        viewStatusBar->setChecked(true);
        formatFont = new QAction(MainWindow);
        formatFont->setObjectName(QString::fromUtf8("formatFont"));
        editFind = new QAction(MainWindow);
        editFind->setObjectName(QString::fromUtf8("editFind"));
        filePrint = new QAction(MainWindow);
        filePrint->setObjectName(QString::fromUtf8("filePrint"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        text = new Editor(centralwidget);
        text->setObjectName(QString::fromUtf8("text"));
        text->setMouseTracking(true);
        text->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"border: none;\n"
"outline: none;\n"
"}"));
        text->setLineWrapMode(QTextEdit::NoWrap);
        text->setAcceptRichText(false);

        gridLayout->addWidget(text, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 18));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuFormat = new QMenu(menubar);
        menuFormat->setObjectName(QString::fromUtf8("menuFormat"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setEnabled(true);
        statusBar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuFormat->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(fileNew);
        menuFile->addAction(fileOpen);
        menuFile->addAction(fileSave);
        menuFile->addAction(fileSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(filePrint);
        menuFile->addSeparator();
        menuFile->addAction(fileExit);
        menuHelp->addAction(helpBugReport);
        menuHelp->addAction(helpAbout);
        menuEdit->addAction(editUndo);
        menuEdit->addAction(editRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(editCut);
        menuEdit->addAction(editCopy);
        menuEdit->addAction(editPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(editFind);
        menuFormat->addAction(formatWordWrap);
        menuFormat->addAction(formatFont);
        menuView->addAction(viewStatusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\343\203\241\343\203\242\345\270\263", nullptr));
        fileOpen->setText(QApplication::translate("MainWindow", "\351\226\213\343\201\217...", nullptr));
#ifndef QT_NO_SHORTCUT
        fileOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        fileNew->setText(QApplication::translate("MainWindow", "\346\226\260\350\246\217", nullptr));
#ifndef QT_NO_SHORTCUT
        fileNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        fileSave->setText(QApplication::translate("MainWindow", "\344\270\212\346\233\270\343\201\215\344\277\235\345\255\230", nullptr));
#ifndef QT_NO_SHORTCUT
        fileSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        fileSaveAs->setText(QApplication::translate("MainWindow", "\345\220\215\345\211\215\343\202\222\344\273\230\343\201\221\343\201\246\344\277\235\345\255\230...", nullptr));
        fileExit->setText(QApplication::translate("MainWindow", "\347\265\202\344\272\206", nullptr));
#ifndef QT_NO_SHORTCUT
        fileExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        helpAbout->setText(QApplication::translate("MainWindow", "\343\203\220\343\203\274\343\202\270\343\203\247\343\203\263\346\203\205\345\240\261", nullptr));
        helpBugReport->setText(QApplication::translate("MainWindow", "\343\203\225\343\202\243\343\203\274\343\203\211\343\203\220\343\203\203\343\202\257\343\201\256\351\200\201\344\277\241", nullptr));
        editUndo->setText(QApplication::translate("MainWindow", "\345\205\203\343\201\253\346\210\273\343\201\231", nullptr));
#ifndef QT_NO_SHORTCUT
        editUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        editCut->setText(QApplication::translate("MainWindow", "\345\210\207\343\202\212\345\217\226\343\202\212", nullptr));
#ifndef QT_NO_SHORTCUT
        editCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        editCopy->setText(QApplication::translate("MainWindow", "\343\202\263\343\203\224\343\203\274", nullptr));
#ifndef QT_NO_SHORTCUT
        editCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        editPaste->setText(QApplication::translate("MainWindow", "\350\262\274\343\202\212\344\273\230\343\201\221", nullptr));
#ifndef QT_NO_SHORTCUT
        editPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        editRedo->setText(QApplication::translate("MainWindow", "\343\202\204\343\202\212\347\233\264\343\201\227", nullptr));
#ifndef QT_NO_SHORTCUT
        editRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_NO_SHORTCUT
        formatWordWrap->setText(QApplication::translate("MainWindow", "\345\217\263\347\253\257\343\201\247\346\212\230\343\202\212\350\277\224\343\201\231", nullptr));
        viewStatusBar->setText(QApplication::translate("MainWindow", "\343\202\271\343\203\206\343\203\274\343\202\277\343\202\271 \343\203\220\343\203\274", nullptr));
        formatFont->setText(QApplication::translate("MainWindow", "\343\203\225\343\202\251\343\203\263\343\203\210...", nullptr));
        editFind->setText(QApplication::translate("MainWindow", "\346\244\234\347\264\242...", nullptr));
#ifndef QT_NO_SHORTCUT
        editFind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        filePrint->setText(QApplication::translate("MainWindow", "\345\215\260\345\210\267...", nullptr));
#ifndef QT_NO_SHORTCUT
        filePrint->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        menuFile->setTitle(QApplication::translate("MainWindow", "\343\203\225\343\202\241\343\202\244\343\203\253", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\343\203\230\343\203\253\343\203\227", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "\347\267\250\351\233\206", nullptr));
        menuFormat->setTitle(QApplication::translate("MainWindow", "\346\233\270\345\274\217", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "\350\241\250\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
