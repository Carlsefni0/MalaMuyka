#include "pricesettingsdialog.h"
#include "ui_pricesettingsdialog.h"

PriceSettingsDialog::PriceSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PriceSettingsDialog)
{
    ui->setupUi(this);


    ui->tablePrice->setColumnCount(2);
    ui->tablePrice->setHorizontalHeaderLabels({"Послуга", "Ціна"});
    ui->tablePrice->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tablePrice->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tablePrice->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tablePrice->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->tablePrice, &QTableWidget::customContextMenuRequested, this, &PriceSettingsDialog::showTableContextMenu);
}

PriceSettingsDialog::~PriceSettingsDialog()
{
    delete ui;
}

void PriceSettingsDialog::getWorkTypeMapPtr(QMap<QString, double> *mapPtr)
{
    if(mapPtr != nullptr)
    {
        workTypeList = mapPtr;
        addWorkTypeDataToTable(ui->tablePrice, mapPtr);
    }
}

void PriceSettingsDialog::addWorkTypeDataToTable(QTableWidget *table, QMap<QString, double> *mapPtr)
{
    // Очищення таблиці перед додаванням нових даних
    table->clearContents();
    table->setRowCount(0);
    // Заповнення таблиці даними з QMap
    int row = 0;
    for (auto it = mapPtr->constBegin(); it != mapPtr->constEnd(); ++it) {
        table->insertRow(row);

        QTableWidgetItem *serviceNameItem = new QTableWidgetItem(it.key());
        table->setItem(row, 0, serviceNameItem);

        QTableWidgetItem *servicePriceItem = new QTableWidgetItem(QString::number(it.value()));
        table->setItem(row, 1, servicePriceItem);

        ++row;
    }
}

void PriceSettingsDialog::addNewWorkTypeData(QTableWidget *table, QMap<QString, double> *mapPtr)
{
    AddWorkTypeDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        // Отримати введені дані з діалогового вікна
        QString serviceName = dialog.getServiceName();
        double servicePrice = dialog.getServicePrice();
        qDebug() << dialog.getServicePrice();

        // Додати дані в QMap
        mapPtr->insert(serviceName, servicePrice);

        // Додати дані в QTableWidget
        int row = table->rowCount();
        table->insertRow(row);
        QTableWidgetItem *serviceNameItem = new QTableWidgetItem(serviceName);
        table->setItem(row, 0, serviceNameItem);
        QTableWidgetItem *servicePriceItem = new QTableWidgetItem(QString::number(servicePrice));
        table->setItem(row, 1, servicePriceItem);

        // Оновити файл .txt
        updateTxtFile(QString(serviceName + ", " + QString::number(servicePrice)));
    }
}

void PriceSettingsDialog::updateTxtFile(const QString &newService)
{

    QFile file("C:\\Users\\Admin\\Desktop\\MalaMuyka\\MalaMuyka\\worktype.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        QTextStream out(&file);
        out << newService << "\n";  // Додайте нову послугу у новому рядку
        file.close();
    }
    else
    {
        qDebug() << "GG";
    }

}

void PriceSettingsDialog::writeWorkTypeListInFile(const QMap<QString, double> &dataMap, const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Не вдалося відкрити файл для запису:" << file.errorString();
        return;
    }

    QTextStream out(&file);
    for (auto it = dataMap.constBegin(); it != dataMap.constEnd(); ++it) {
        out << it.key() << ", " << it.value() << "\n";
    }

    file.close();
    qDebug() << "Дані успішно записані у файл:" << filePath;
}

void PriceSettingsDialog::on_addNewWorkTypeButton_clicked()
{
    addNewWorkTypeData(ui->tablePrice, workTypeList);
}

void PriceSettingsDialog::showTableContextMenu(const QPoint &pos)
{
    // Отримайте глобальну позицію курсора
    QPoint globalPos = ui->tablePrice->mapToGlobal(pos);

    // Створіть контекстне меню
    QMenu contextMenu(this);
    contextMenu.addAction("Remove");

    // Показати контекстне меню на глобальній позиції курсора
    QAction* selectedItem = contextMenu.exec(globalPos);

    // Обробка вибору користувача
    if (selectedItem) {
        if (selectedItem->text() == "Remove") {
            int selectedRow = ui->tablePrice->currentRow();
            if (selectedRow >= 0) {
                // Вивести діалогове вікно підтвердження
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Confirmation", "Are you sure you want to remove this item?",
                                              QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                    QTableWidgetItem *item = ui->tablePrice->item(selectedRow, 0);
                    QString serviceName = item->text();

                    // Видалити запис з workTypeList за ключем (назвою послуги)
                    workTypeList->remove(serviceName);

                    // Видалити рядок з таблиці
                    ui->tablePrice->removeRow(selectedRow);

                    writeWorkTypeListInFile(*workTypeList, "C:\\Users\\Admin\\Desktop\\MalaMuyka\\MalaMuyka\\worktype.txt" );
                }
            }
        }
    }
}


