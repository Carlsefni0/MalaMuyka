#include "adminpage.h"
#include "ui_adminpage.h"

#include <QLCDNumber>
#include <QDateTime>
#include <QTimer>

AdminPage::AdminPage(QVector<Order>* orderList, QVector<Worker>* workerList) :
    QDialog(nullptr),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);

    this->orderList = orderList;
    this->workerList = workerList;

    //---------------------------------------------------------------
/*   /-----------------\
     | WINDOW SETTINGS |
     \---------------- /   */

    // Window style
    setFixedSize(1060,596);
    QString imagePath = ":/image/img/photo_2023-11-23_18-03-17.jpg";
    QString styleSheet = "background-image: url(" + imagePath + ");";
    //setStyleSheet(styleSheet);

    // Window behavior
    setWindowModality(Qt::WindowModality::ApplicationModal);


    //---------------------------------------------------------------

/*   /-----------------\
     | WIDGET SETTINGS |
     \---------------- /   */


    //lcdTimer
    ui->lcdTime->setDigitCount(8); // Вказуємо кількість цифр для відображення годин, хвилин і секунд
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AdminPage::updateTime);
    timer->start(1000); // Оновлення кожну секунду

    //WorkersSettingsDialog* workerSettings;
    workerSettings = new WorkersSettingsDialog();
    workerSettings->setWindowModality(Qt::WindowModality::ApplicationModal);

    //OrderSettingsDialog* orderSettings;
    orderSettings = new OrderSettingsDialog();
    orderSettings->setWindowModality(Qt::WindowModality::ApplicationModal);

    //ProfitDialog* profitSettings;
    profitSettings = new ProfitDialog();
    profitSettings->setWindowModality(Qt::WindowModality::ApplicationModal);

    //PriceSettingsDialog* priceSettings;
    priceSettings = new PriceSettingsDialog();
    priceSettings->setWindowModality(Qt::WindowModality::ApplicationModal);


    //---------------------------------------------------------------



}

AdminPage::~AdminPage()
{
    delete ui;
}

void AdminPage::getWorkTypeMapPtr(QMap<QString, double> *mapPtr)
{
    workTypeList = mapPtr;
}

void AdminPage::updateTime() {
    // Отримуємо поточний час з системного годинника
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QTime currentTime = currentDateTime.time();

    // Встановлюємо поточний час у QLCDNumber
    ui->lcdTime->display(currentTime.toString("hh:mm:ss"));
}

void AdminPage::on_priceButton_clicked()
{
    priceSettings->getWorkTypeMapPtr(workTypeList);
    priceSettings->show();
    qDebug()<< workerList->size() << " size";
}


void AdminPage::on_workersListButton_clicked()
{
    qDebug() << (*workerList)[0].getID() << " size";
    workerSettings->getWorkerListPtr(workerList);
    workerSettings->show();
}


void AdminPage::on_orderInfoButton_clicked()
{
    orderSettings->show();
}


void AdminPage::on_salaryButton_clicked()
{
    profitSettings->show();
}

