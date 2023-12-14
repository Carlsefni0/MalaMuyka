#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include "workerssettingsdialog.h"
#include "ordersettingsdialog.h"
#include "profitdialog.h"
#include "pricesettingsdialog.h"


#include <QMap>
#include <QDialog>

namespace Ui {
class AdminPage;
}

class AdminPage : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPage(QVector<Order>* orderList, QVector<Worker>* workerList);
    ~AdminPage();

    void getWorkTypeMapPtr(QMap<QString, double> *mapPtr);


private slots:
    void on_priceButton_clicked();

    void on_workersListButton_clicked();

    void on_orderInfoButton_clicked();

    void on_salaryButton_clicked();

    void updateTime();

private:
    Ui::AdminPage *ui;

    QMap<QString, double> *workTypeList;
    QVector<Order>* orderList;
    QVector<Worker>* workerList;

    WorkersSettingsDialog* workerSettings;
    OrderSettingsDialog* orderSettings;
    ProfitDialog* profitSettings;
    PriceSettingsDialog* priceSettings;
};

#endif // ADMINPAGE_H
