#ifndef CUSTOMERPAGE_H
#define CUSTOMERPAGE_H

#include <QMap>
#include <QDialog>
#include "order.h"
#include "worker.h"

namespace Ui {
class CustomerPage;
}

class CustomerPage : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerPage(QVector<Order>* orderList, QVector<Worker>* workerList);
    ~CustomerPage();

    void getWorkTypeMapPtr(QMap<QString, double> *mapPtr);

private slots:
    void on_cancelButton_clicked();

    void on_confirmButton_clicked();

private:
    Ui::CustomerPage *ui;

    QMap<QString, double> *workTypeList;
    QVector<Order>* orderList;
    QVector<Worker>* workerList;
};

#endif // CUSTOMERPAGE_H
