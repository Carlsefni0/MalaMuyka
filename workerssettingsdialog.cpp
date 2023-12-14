#include "workerssettingsdialog.h"
#include "ui_workerssettingsdialog.h"

WorkersSettingsDialog::WorkersSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkersSettingsDialog)
{
    ui->setupUi(this);

    workerList = nullptr;

    ui->tableWidget->setColumnCount(6); // Кількість стовпців
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Ім'я", "Кількість вик. заовлень", "Дата народження", "Контактні дані", "К-сть зароблених грошей"});
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //connect(ui->tableWorkes, &QTableWidget::customContextMenuRequested, this, &PriceSettingsDialog::showTableContextMenu);




}

WorkersSettingsDialog::~WorkersSettingsDialog()
{
    delete ui;
}

void WorkersSettingsDialog::getWorkerListPtr(QVector<Worker> *workerListPtr)
{
    if(workerListPtr != nullptr)
    {
        workerList = workerListPtr;
        addWorkersFromVectorToTable(ui->tableWidget, workerList);
        qDebug() << "yes";
    }
    else
    {
        qDebug() << "no";
    }
}

void WorkersSettingsDialog::addWorkersFromVectorToTable(QTableWidget* table, QVector<Worker> *workerListPtr)
{
    table->clearContents();
    table->setRowCount(0);

    for (int i = 0; i < workerListPtr->size(); ++i) {
        int rowCount = table->rowCount();
        table->insertRow(rowCount);

        const Worker &currentWorker = (*workerListPtr)[i];

        QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(currentWorker.getID()));
        table->setItem(i, 0, idItem);

        QTableWidgetItem *nameItem = new QTableWidgetItem(currentWorker.getName());
        table->setItem(i, 1, nameItem);

        QTableWidgetItem *orderNumberItem = new QTableWidgetItem(QString::number(currentWorker.getGeneralOrderNumber()));
        table->setItem(i, 2, orderNumberItem);

        QTableWidgetItem *birthDateItem = new QTableWidgetItem(currentWorker.getBirthDate().toString("dd.MM.yyyy"));
        table->setItem(i, 3, birthDateItem);

        QTableWidgetItem *contactDataItem = new QTableWidgetItem(currentWorker.getContactData());
        table->setItem(i, 4, contactDataItem);

        QTableWidgetItem *salaryItem = new QTableWidgetItem(QString::number(currentWorker.getGeneralSalary()));
        table->setItem(i, 5, salaryItem);
    }

    table->update();
}

void WorkersSettingsDialog::addNewWorker(QTableWidget *table, QVector<Worker> *workerListPtr)
{
    AddWorkerDialog dialog(this);

    if(dialog.exec() == QDialog::Accepted)
    {
        // Отримати введені дані з діалогового вікна
        QString workerName = dialog.getWorkerName();
        int orderNumber = dialog.getOrderNumber();
        QDate birthDate = dialog.getBirthDate();
        QString contactData = dialog.getContactData();
        double generalSalary = dialog.getGeneralSalary();

        // Створити нового працівника
        Worker newWorker(0, workerName, birthDate, contactData);

        // Додати дані в QVector
        workerListPtr->append(newWorker);

        // Додати дані в QTableWidget
        int row = table->rowCount();
        table->insertRow(row);
        QTableWidgetItem *nameItem = new QTableWidgetItem(workerName);
        table->setItem(row, 0, nameItem);
        QTableWidgetItem *orderNumberItem = new QTableWidgetItem(QString::number(orderNumber));
        table->setItem(row, 1, orderNumberItem);
        QTableWidgetItem *birthDateItem = new QTableWidgetItem(birthDate.toString("dd.MM.yyyy"));
        table->setItem(row, 2, birthDateItem);
        QTableWidgetItem *contactDataItem = new QTableWidgetItem(contactData);
        table->setItem(row, 3, contactDataItem);
        QTableWidgetItem *salaryItem = new QTableWidgetItem(QString::number(generalSalary));
        table->setItem(row, 4, salaryItem);

        // Опціонально: оновити файли або базу даних
        // updateTxtFile(QString(workerName + ", " + QString::number(generalSalary)));



    }
}

void WorkersSettingsDialog::on_addNewWorkerButton_clicked()
{
    addNewWorker(ui->tableWidget, workerList);
}

