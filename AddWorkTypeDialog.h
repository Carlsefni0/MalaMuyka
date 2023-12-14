#ifndef ADDWORKTYPEDIALOG_H
#define ADDWORKTYPEDIALOG_H

#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QDoubleValidator>
#include <QMap>

class AddWorkTypeDialog : public QDialog {
    Q_OBJECT
public:
    AddWorkTypeDialog(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Додати нову послугу");

        QDoubleValidator *priceValidator = new QDoubleValidator(0, 999999, 2, this);

        nameLineEdit = new QLineEdit(this);
        priceLineEdit = new QLineEdit(this);

        priceLineEdit->setValidator(priceValidator);

        QFormLayout *formLayout = new QFormLayout(this);
        formLayout->addRow("Назва послуги:", nameLineEdit);
        formLayout->addRow("Ціна послуги:", priceLineEdit);

        QPushButton *okButton = new QPushButton("OK", this);
        connect(okButton, &QPushButton::clicked, this, &AddWorkTypeDialog::accept);
        formLayout->addWidget(okButton);

        QPushButton *cancelButton = new QPushButton("Відміна", this);
        connect(cancelButton, &QPushButton::clicked, this, &AddWorkTypeDialog::reject);
        formLayout->addWidget(cancelButton);
    }

    QString getServiceName() const {
        return nameLineEdit->text();
    }

    double getServicePrice() const {
        QString str = priceLineEdit->text().replace(',', '.');
        return str.toDouble();
    }

private:
    QLineEdit *nameLineEdit;
    QLineEdit *priceLineEdit;
};

#endif // ADDWORKTYPEDIALOG_H
