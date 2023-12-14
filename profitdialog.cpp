#include "profitdialog.h"
#include "ui_profitdialog.h"

ProfitDialog::ProfitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfitDialog)
{
    ui->setupUi(this);
}

ProfitDialog::~ProfitDialog()
{
    delete ui;
}
