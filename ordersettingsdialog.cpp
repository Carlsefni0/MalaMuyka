#include "ordersettingsdialog.h"
#include "ui_ordersettingsdialog.h"

OrderSettingsDialog::OrderSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderSettingsDialog)
{
    ui->setupUi(this);
}

OrderSettingsDialog::~OrderSettingsDialog()
{
    delete ui;
}
