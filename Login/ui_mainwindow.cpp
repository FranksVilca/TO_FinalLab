/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI code!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *usuarioLineEdit;
    QLineEdit *contrasenaLineEdit;
    QPushButton *loginButton;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 200);

        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));

        usuarioLineEdit = new QLineEdit(centralwidget);
        usuarioLineEdit->setObjectName(QString::fromUtf8("usuarioLineEdit"));
        usuarioLineEdit->setGeometry(QRect(120, 30, 200, 30));

        contrasenaLineEdit = new QLineEdit(centralwidget);
        contrasenaLineEdit->setObjectName(QString::fromUtf8("contrasenaLineEdit"));
        contrasenaLineEdit->setGeometry(QRect(120, 70, 200, 30));
        contrasenaLineEdit->setEchoMode(QLineEdit::Password);

        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(150, 120, 100, 30));

        MainWindow->setCentralWidget(centralwidget);
        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    }

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Login", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
    }
};

#endif // UI_MAINWINDOW_H
