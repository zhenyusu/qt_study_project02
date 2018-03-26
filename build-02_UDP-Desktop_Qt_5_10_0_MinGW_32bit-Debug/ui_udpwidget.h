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

class Ui_UdpWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditIp;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QTextEdit *textEdit;
    QPushButton *pushButtonSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClose;

    void setupUi(QWidget *UdpWidget)
    {
        if (UdpWidget->objectName().isEmpty())
            UdpWidget->setObjectName(QStringLiteral("UdpWidget"));
        UdpWidget->resize(400, 300);
        gridLayout = new QGridLayout(UdpWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(UdpWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditIp = new QLineEdit(UdpWidget);
        lineEditIp->setObjectName(QStringLiteral("lineEditIp"));

        gridLayout->addWidget(lineEditIp, 0, 1, 1, 2);

        label_2 = new QLabel(UdpWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditPort = new QLineEdit(UdpWidget);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 1, 1, 1, 2);

        textEdit = new QTextEdit(UdpWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 2, 0, 1, 4);

        pushButtonSend = new QPushButton(UdpWidget);
        pushButtonSend->setObjectName(QStringLiteral("pushButtonSend"));

        gridLayout->addWidget(pushButtonSend, 3, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(217, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 2, 1, 1);

        pushButtonClose = new QPushButton(UdpWidget);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));

        gridLayout->addWidget(pushButtonClose, 3, 3, 1, 1);


        retranslateUi(UdpWidget);

        QMetaObject::connectSlotsByName(UdpWidget);
    } // setupUi

    void retranslateUi(QWidget *UdpWidget)
    {
        UdpWidget->setWindowTitle(QApplication::translate("UdpWidget", "UdpWidget", nullptr));
        label->setText(QApplication::translate("UdpWidget", "\345\257\271\346\226\271\347\232\204ip", nullptr));
        lineEditIp->setText(QString());
        label_2->setText(QApplication::translate("UdpWidget", "\345\257\271\346\226\271\347\232\204\347\253\257\345\217\243", nullptr));
        pushButtonSend->setText(QApplication::translate("UdpWidget", "send", nullptr));
        pushButtonClose->setText(QApplication::translate("UdpWidget", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UdpWidget: public Ui_UdpWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPWIDGET_H
