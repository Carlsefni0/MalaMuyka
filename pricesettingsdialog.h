#ifndef PRICESETTINGSDIALOG_H
#define PRICESETTINGSDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QResource>
#include <QMenu>
#include <QMessageBox>
#include <QTextStream>

#include "AddWorkTypeDialog.h"
#include "worker.h"
#include "order.h"

namespace Ui {
class PriceSettingsDialog;
}

class PriceSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PriceSettingsDialog(QWidget *parent = nullptr);
    ~PriceSettingsDialog();

    void getWorkTypeMapPtr(QMap<QString, double> *mapPtr);
    void addWorkTypeDataToTable(QTableWidget* table,  QMap<QString, double> *mapPtr);

    void addNewWorkTypeData(QTableWidget* table, QMap<QString, double> *mapPtr);
    void updateTxtFile(const QString &newService);
    void writeWorkTypeListInFile(const QMap<QString, double> &dataMap, const QString &filePath);

private slots:
    void on_addNewWorkTypeButton_clicked();
    void showTableContextMenu(const QPoint &pos);

private:
    Ui::PriceSettingsDialog *ui;

    QMap<QString, double> *workTypeList;


};

#endif // PRICESETTINGSDIALOG_H
