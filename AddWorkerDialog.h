#ifndef ADDWORKERDIALOG_H
#define ADDWORKERDIALOG_H

#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QDateEdit>
#include <QMap>

class AddWorkerDialog : public QDialog {
    Q_OBJECT
public:
    AddWorkerDialog(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Додати нового працівника");

        birthDateEdit = new QDateEdit(this);
        birthDateEdit->setDisplayFormat("dd.MM.yyyy");
        birthDateEdit->setCalendarPopup(true);

        QFormLayout *formLayout = new QFormLayout(this);
        formLayout->addRow("Ім'я:", nameLineEdit);
        formLayout->addRow("Номер замовлення:", orderNumberLineEdit);
        formLayout->addRow("Дата народження:", birthDateEdit);
        formLayout->addRow("Контактні дані:", contactDataLineEdit);
        formLayout->addRow("Заробітна плата:", generalSalaryLineEdit);

        QPushButton *okButton = new QPushButton("OK", this);
        connect(okButton, &QPushButton::clicked, this, &AddWorkerDialog::accept);
        formLayout->addWidget(okButton);

        QPushButton *cancelButton = new QPushButton("Відміна", this);
        connect(cancelButton, &QPushButton::clicked, this, &AddWorkerDialog::reject);
        formLayout->addWidget(cancelButton);
    }

    QString getWorkerName() const {
        return nameLineEdit->text();
    }

    int getOrderNumber() const {
        QString str = orderNumberLineEdit->text();
        return str.toInt();
    }

    QDate getBirthDate() const {
        return birthDateEdit->date();
    }

    QString getContactData() const {
        return contactDataLineEdit->text();
    }

    double getGeneralSalary() const {
        QString str = generalSalaryLineEdit->text().replace(',', '.');
        return str.toDouble();
    }

private:
    QLineEdit *nameLineEdit = new QLineEdit(this);
    QLineEdit *orderNumberLineEdit = new QLineEdit(this);
    QDateEdit *birthDateEdit;
    QLineEdit *contactDataLineEdit = new QLineEdit(this);
    QLineEdit *generalSalaryLineEdit = new QLineEdit(this);
};

#endif // ADDWORKERDIALOG_H
