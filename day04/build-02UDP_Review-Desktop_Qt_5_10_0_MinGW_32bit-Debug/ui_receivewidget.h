/********************************************************************************
** Form generated from reading UI file 'receivewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVEWIDGET_H
#define UI_RECEIVEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_receiveWidget
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEditRead;

    void setupUi(QWidget *receiveWidget)
    {
        if (receiveWidget->objectName().isEmpty())
            receiveWidget->setObjectName(QStringLiteral("receiveWidget"));
        receiveWidget->resize(400, 300);
        gridLayout = new QGridLayout(receiveWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEditRead = new QTextEdit(receiveWidget);
        textEditRead->setObjectName(QStringLiteral("textEditRead"));
        textEditRead->setReadOnly(true);

        gridLayout->addWidget(textEditRead, 0, 0, 1, 1);


        retranslateUi(receiveWidget);

        QMetaObject::connectSlotsByName(receiveWidget);
    } // setupUi

    void retranslateUi(QWidget *receiveWidget)
    {
        receiveWidget->setWindowTitle(QApplication::translate("receiveWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class receiveWidget: public Ui_receiveWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVEWIDGET_H
