#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QTime>
#include <QTimer>
#include <QUuid>

#include "worker.h"

class Order: public QObject
{
    Q_OBJECT
public:
    explicit  Order(QString orderType, QString bodyType, QString boxNumber, double price,QDate creationData, QTime creationTime, QTime endTime, QVector<Worker> orderWorker);
    ~Order();

    void calculateProfit();

private slots:
    void handleTimeout();

private:
    QString id;

    QString orderType;
    QString bodyType;
    QString boxNumber;

    double price;
    double profit;

    QTimer* timer;
    QDate creationDate;

    QTime creationTime;
    QTime endTime;

    QVector<Worker> orderWorker;

    bool canChange;
};

#endif // ORDER_H
