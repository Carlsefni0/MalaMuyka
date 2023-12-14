#include "homepage.h"
#include "ui_homepage.h"

HomePage::HomePage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);

    workerList = new QVector<Worker>;

    orderWindow = new CustomerPage(&orderList, workerList);
    settingsWindow = new AdminPage(&orderList, workerList);
    restoreData(":/data/worktype.txt");
    *workerList = restoreWorkerData(":/data/workerlist.txt");

    orderWindow->getWorkTypeMapPtr(&workType);
    settingsWindow->getWorkTypeMapPtr(&workType);

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


    //---------------------------------------------------------------

/*   /-----------------\
     | WIDGET SETTINGS |
     \---------------- /
*/

    //passwordWindow
    // Створення поля введення паролю
    passwordWindow = new QDialog();

    passwordWindow->setWindowModality(Qt::WindowModality::ApplicationModal);

    // Створення кнопки підтвердження
    QPushButton *confirmButton = new QPushButton("OK", this);
    connect(confirmButton, &QPushButton::clicked, this, &HomePage::on_settingsButton_clicked);

    // Розміщення віджетів у вертикальному лейауті
    QVBoxLayout *layout = new QVBoxLayout(this);
    passwordLineEdit = new QLineEdit(this);
    layout->addWidget(passwordLineEdit);
    layout->addWidget(confirmButton);

    passwordWindow->setLayout(layout);
    passwordWindow->setWindowTitle("Введіть пароль");
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::acceptPassword(QLineEdit* lineEdit)
{
    if(lineEdit->text() == "1234")
    {
        lineEdit->clear();
        passwordWindow->close();
        settingsWindow->show();
    }
}

void HomePage::restoreData(QString filePath)
{
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не вдалося відкрити файл.";
        return;
    }

    // Зчитування та обробка рядків файлу
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");

        if (parts.size() == 2) {
            QString serviceNameB = parts[0];
            double servicePriceB = parts[1].toDouble();

            // Додавання пари ключ-значення до QMap
            workType.insert(serviceNameB, servicePriceB);
        }
    }

    qDebug() << "Service Prices:";
    for (auto it = workType.constBegin(); it != workType.constEnd(); ++it) {
        qDebug() << it.key() << ": $" << it.value();
    }

    file.close();
}

QVector<Worker> HomePage::restoreWorkerData(const QString &filePath)
{
    QVector<Worker> workers;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Обробка помилки відкриття файлу
        qDebug() << "Помилка відкриття файлу";
        return workers;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(", ");

        if (parts.size() == 6) {
            Worker worker(parts[0].toInt(), parts[1], QDate::fromString(parts[3], "dd.MM.yyyy"), parts[4]);

            worker.setGeneralOrderNumber(parts[2].toInt());
            worker.setGeneralSalary(parts[5].toDouble());

            workers.append(worker);
        }
    }

    file.close();

    return workers;
}


void HomePage::on_settingsButton_clicked()
{
    passwordWindow->show();

    acceptPassword(passwordLineEdit);

}


void HomePage::on_doOrderButton_clicked()
{
    orderWindow->show();
}

