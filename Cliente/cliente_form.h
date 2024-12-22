// cliente_form.h
#ifndef CLIENTE_FORM_H
#define CLIENTE_FORM_H

#include <QDialog>
#include "Cliente.h"

namespace Ui {
class ClienteForm;
}

class ClienteForm : public QDialog {
    Q_OBJECT

public:
    explicit ClienteForm(QWidget* parent = nullptr);
    ~ClienteForm();

private slots:
    void on_btnGuardar_clicked();

private:
    Ui::ClienteForm *ui;
};

#endif // CLIENTE_FORM_H
