#include "customerpage.h"
#include "ui_customerpage.h"

CustomerPage::CustomerPage(QVector<Order>* orderList, QVector<Worker>* workerList) :
    QDialog(nullptr),
    ui(new Ui::CustomerPage)
{
    ui->setupUi(this);

    this->orderList = orderList;
    this->workerList = workerList;


    //---------------------------------------------------------------

/*   /-----------------\
     | WINDOW SETTINGS |
     \---------------- /
*/
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





    //---------------------------------------------------------------
}

CustomerPage::~CustomerPage()
{
    delete ui;
}

void CustomerPage::getWorkTypeMapPtr(QMap<QString, double> *mapPtr)
{
    workTypeList = mapPtr;
}

void CustomerPage::on_cancelButton_clicked()
{
    this->close();
}


void CustomerPage::on_confirmButton_clicked()
{

}

