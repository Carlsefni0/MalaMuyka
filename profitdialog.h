#ifndef PROFITDIALOG_H
#define PROFITDIALOG_H

#include <QDialog>

#include "worker.h"
#include "order.h"

namespace Ui {
class ProfitDialog;
}

class ProfitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProfitDialog(QWidget *parent = nullptr);
    ~ProfitDialog();

private:
    Ui::ProfitDialog *ui;
};

#endif // PROFITDIALOG_H
