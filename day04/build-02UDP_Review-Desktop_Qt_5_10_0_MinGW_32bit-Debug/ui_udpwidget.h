/********************************************************************************
** Form generated from reading UI file 'udpwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPWIDGET_H
#define UI_UDPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_udpwidget
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEditRead;
    QPushButton *pushButtonSend;
    QLabel *labelIP;
    QLineEdit *lineEditIP;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClose;

    void setupUi(QWidget *udpwidget)
    {
        if (udpwidget->objectName().isEmpty())
            udpwidget->setObjectName(QStringLiteral("udpwidget"));
        udpwidget->resize(400, 300);
        gridLayout = new QGridLayout(udpwidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEditRead = new QTextEdit(udpwidget);
        textEditRead->setObjectName(QStringLiteral("textEditRead"));
        textEditRead->setReadOnly(false);

        gridLayout->addWidget(textEditRead, 2, 0, 1, 3);

        pushButtonSend = new QPushButton(udpwidget);
        pushButtonSend->setObjectName(QStringLiteral("pushButtonSend"));

        gridLayout->addWidget(pushButtonSend, 3, 0, 1, 1);

        labelIP = new QLabel(udpwidget);
        labelIP->setObjectName(QStringLiteral("labelIP"));

        gridLayout->addWidget(labelIP, 0, 0, 1, 1);

        lineEditIP = new QLineEdit(udpwidget);
        lineEditIP->setObjectName(QStringLiteral("lineEditIP"));

        gridLayout->addWidget(lineEditIP, 0, 1, 1, 2);

        labelPort = new QLabel(udpwidget);
        labelPort->setObjectName(QStringLiteral("labelPort"));

        gridLayout->addWidget(labelPort, 1, 0, 1, 1);

        lineEditPort = new QLineEdit(udpwidget);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 1, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

        pushButtonClose = new QPushButton(udpwidget);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));

        gridLayout->addWidget(pushButtonClose, 3, 2, 1, 1);


        retranslateUi(udpwidget);

        QMetaObject::connectSlotsByName(udpwidget);
    } // setupUi

    void retranslateUi(QWidget *udpwidget)
    {
        udpwidget->setWindowTitle(QApplication::translate("udpwidget", "udpwidget", nullptr));
        pushButtonSend->setText(QApplication::translate("udpwidget", "send", nullptr));
        labelIP->setText(QApplication::translate("udpwidget", "\345\257\271\346\226\271IP", nullptr));
        labelPort->setText(QApplication::translate("udpwidget", "\345\257\271\346\226\271\347\253\257\345\217\243\345\217\267", nullptr));
        pushButtonClose->setText(QApplication::translate("udpwidget", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class udpwidget: public Ui_udpwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPWIDGET_H
