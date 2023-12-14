#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>

#include "adminpage.h"
#include "customerpage.h"

#include "worker.h"
#include "order.h"

#include <QFile>
#include <QMap>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class HomePage; }
QT_END_NAMESPACE

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    HomePage(QWidget *parent = nullptr);
    ~HomePage();

    void acceptPassword(QLineEdit* lineEdit);
    void restoreData(QString filePath);

    QVector<Worker> restoreWorkerData(const QString &filePath);


private slots:
    void on_settingsButton_clicked();

    void on_doOrderButton_clicked();


private:
    Ui::HomePage *ui;

    QVector<Order> orderList;
    QVector<Worker> *workerList;

    QMap<QString, double> workType;
    QFile workTypeFile;

    AdminPage* settingsWindow;
    CustomerPage* orderWindow;

    QDialog *passwordWindow;
    QLineEdit *passwordLineEdit;


};
#endif // HOMEPAGE_H
