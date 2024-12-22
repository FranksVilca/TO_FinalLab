/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version X.X.X
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEditUser;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonLogin;
    QLabel *labelMessage;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);

        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));

        lineEditUser = new QLineEdit(centralWidget);
        lineEditUser->setObjectName(QString::fromUtf8("lineEditUser"));
        lineEditUser->setGeometry(QRect(100, 50, 200, 30));

        lineEditPassword = new QLineEdit(centralWidget);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(100, 100, 200, 30));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        pushButtonLogin = new QPushButton(centralWidget);
        pushButtonLogin->setObjectName(QString::fromUtf8("pushButtonLogin"));
        pushButtonLogin->setGeometry(QRect(150, 150, 100, 30));

        labelMessage = new QLabel(centralWidget);
        labelMessage->setObjectName(QString::fromUtf8("labelMessage"));
        labelMessage->setGeometry(QRect(100, 200, 200, 30));
        labelMessage->setAlignment(Qt::AlignCenter);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Login", nullptr));
        lineEditUser->setPlaceholderText(QCoreApplication::translate("MainWindow", "Usuario", nullptr));
        lineEditPassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "Contrase\303\261a", nullptr));
        pushButtonLogin->setText(QCoreApplication::translate("MainWindow", "Iniciar Sesión", nullptr));
        labelMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
