#include "worker.h"

Worker::Worker(int id,QString name, QDate birthDate, QString contactData):generalOrderNumber(0), daySalary(0.0), dayNumberOfOrder(0), work(false)
{
    this->id = id;

    this->name = name;
    this->birthDate = birthDate;
    this->contactData = contactData;
}

void Worker::setName(QString name)
{
    this->name = name;
}

void Worker::setGeneralOrderNumber(int num)
{
    generalOrderNumber = num;
}

void Worker::setBirthDate(QDate birthDate)
{
    this->birthDate = birthDate;
}

void Worker::setContactData(QString contactData)
{
    this->contactData = contactData;
}

void Worker::setGeneralSalary(int num)
{
    generalSalary = num;
}

void Worker::setDaySalary(double num)
{
    daySalary = num;
}

void Worker::setDayNumberOfOrder(int num)
{
    dayNumberOfOrder = num;
}

void Worker::setWorkStatus(bool workStatus)
{
    work = workStatus;
}

int Worker::getID() const
{
    return id;
}

QString Worker::getName() const
{
    return name;
}

int Worker::getGeneralOrderNumber() const
{
    return generalOrderNumber;
}

QDate Worker::getBirthDate() const
{
    return birthDate;
}

QString Worker::getContactData() const
{
    return contactData;
}

double Worker::getGeneralSalary() const
{
    return generalSalary;
}

double Worker::getDaySalary() const
{
    return daySalary;
}

int Worker::getDayNumberOfOrder() const
{
    return dayNumberOfOrder;
}

bool Worker::isWorking()
{
    return work == true;
}
