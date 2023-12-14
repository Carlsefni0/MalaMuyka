#ifndef WORKERSSETTINGSDIALOG_H
#define WORKERSSETTINGSDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>

#include "AddWorkerDialog.h"
#include "worker.h"
#include "order.h"

namespace Ui {
class WorkersSettingsDialog;
}

class WorkersSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WorkersSettingsDialog(QWidget *parent = nullptr);
    ~WorkersSettingsDialog();

    void getWorkerListPtr(QVector<Worker>* workerListPtr);

    void addWorkersFromVectorToTable(QTableWidget* table, QVector<Worker> *workerListPtr);
    void addNewWorker(QTableWidget* table, QVector<Worker> *workerListPtr);


private slots:
    void on_addNewWorkerButton_clicked();

private:
    Ui::WorkersSettingsDialog *ui;

    QVector<Worker> *workerList;
};

#endif // WORKERSSETTINGSDIALOG_H
