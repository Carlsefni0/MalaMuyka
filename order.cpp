#include "order.h"


Order::Order(QString orderType, QString bodyType, QString boxNumber, double price,QDate creationData, QTime creationTime, QTime endTime, QVector<Worker> orderWorker): QObject(nullptr)
{
    id = QUuid::createUuid().toString();

    // Створення таймера
    timer = new QTimer();
    timer->start((creationTime.secsTo(endTime) * 1000));

    // Підключення сигналу timeout до слота handleTimeout
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));

    canChange = true;

    this->orderType = orderType;
    this->bodyType = bodyType;
    this->boxNumber = boxNumber;
    this->price = price;

    this->creationDate = creationData;
    this->creationTime = creationTime;
    this->endTime = endTime;

    this->orderWorker = orderWorker;
}

Order::~Order()
{
    delete timer;
}


void Order::calculateProfit()
{
    double moneyForWork = price / 2;
    profit = price / 2;

    int m = orderWorker.length();

    for(int i = 0; i < m; i++)
    {
        orderWorker[i].setDaySalary(orderWorker[i].getDaySalary() + (moneyForWork / m));
    }
}

void Order::handleTimeout()
{
    calculateProfit();
    canChange = false;
}
