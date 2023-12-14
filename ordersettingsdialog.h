#ifndef ORDERSETTINGSDIALOG_H
#define ORDERSETTINGSDIALOG_H

#include <QDialog>

#include "worker.h"
#include "order.h"

namespace Ui {
class OrderSettingsDialog;
}

class OrderSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OrderSettingsDialog(QWidget *parent = nullptr);
    ~OrderSettingsDialog();

private:
    Ui::OrderSettingsDialog *ui;
};

#endif // ORDERSETTINGSDIALOG_H
