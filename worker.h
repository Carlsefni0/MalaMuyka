#ifndef WORKER_H
#define WORKER_H

#include <QString>
#include <QDate>

class Worker
{
public:
    Worker(int id, QString name, QDate birthDate, QString contactData);

    void setName(QString name);
    void setGeneralOrderNumber(int num);
    void setBirthDate(QDate birthDate);
    void setContactData(QString contactData);
    void setGeneralSalary(int num);

    void setDaySalary(double num);
    void setDayNumberOfOrder(int num);
    void setWorkStatus(bool workStatus);


    int getID() const;
    QString getName() const;
    int getGeneralOrderNumber() const;
    QDate getBirthDate() const;
    QString getContactData() const;
    double getGeneralSalary() const;

    double getDaySalary() const;
    int getDayNumberOfOrder() const;

    bool isWorking();
private:
    //permanent filds
    int id;
    QString name;
    int generalOrderNumber;
    QDate birthDate;
    QString contactData;

    double generalSalary;     // general information

    //temporary filds
    double daySalary;         // for current day
    int dayNumberOfOrder;
    bool work;
};

#endif // WORKER_H
