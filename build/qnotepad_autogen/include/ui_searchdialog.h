/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *query;
    QVBoxLayout *verticalLayout;
    QPushButton *findNextButton;
    QPushButton *cancelButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *matchCase;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *upRadio;
    QRadioButton *downRadio;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName(QString::fromUtf8("SearchDialog"));
        SearchDialog->resize(381, 123);
        horizontalLayoutWidget = new QWidget(SearchDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 381, 86));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        query = new QLineEdit(horizontalLayoutWidget);
        query->setObjectName(QString::fromUtf8("query"));
        query->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(query);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        findNextButton = new QPushButton(horizontalLayoutWidget);
        findNextButton->setObjectName(QString::fromUtf8("findNextButton"));
        findNextButton->setEnabled(false);

        verticalLayout->addWidget(findNextButton);

        cancelButton = new QPushButton(horizontalLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        verticalLayout->addWidget(cancelButton);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayoutWidget_2 = new QWidget(SearchDialog);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 63, 291, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 0, 5, 0);
        matchCase = new QCheckBox(horizontalLayoutWidget_2);
        matchCase->setObjectName(QString::fromUtf8("matchCase"));
        matchCase->setEnabled(true);

        horizontalLayout_2->addWidget(matchCase);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        upRadio = new QRadioButton(horizontalLayoutWidget_2);
        upRadio->setObjectName(QString::fromUtf8("upRadio"));
        upRadio->setChecked(true);

        verticalLayout_2->addWidget(upRadio);

        downRadio = new QRadioButton(horizontalLayoutWidget_2);
        downRadio->setObjectName(QString::fromUtf8("downRadio"));

        verticalLayout_2->addWidget(downRadio);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(SearchDialog);

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QApplication::translate("SearchDialog", "\346\244\234\347\264\242", nullptr));
        label->setText(QApplication::translate("SearchDialog", "\346\244\234\347\264\242\343\201\231\343\202\213\346\226\207\345\255\227\345\210\227:", nullptr));
        findNextButton->setText(QApplication::translate("SearchDialog", "\346\254\241\343\202\222\346\244\234\347\264\242", nullptr));
        cancelButton->setText(QApplication::translate("SearchDialog", "\343\202\255\343\203\243\343\203\263\343\202\273\343\203\253", nullptr));
        matchCase->setText(QApplication::translate("SearchDialog", "\345\244\247\346\226\207\345\255\227\343\201\250\345\260\217\346\226\207\345\255\227\343\202\222\345\214\272\345\210\245\343\201\231\343\202\213", nullptr));
        upRadio->setText(QApplication::translate("SearchDialog", "\344\270\212\343\201\270", nullptr));
        downRadio->setText(QApplication::translate("SearchDialog", "\344\270\213\343\201\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
