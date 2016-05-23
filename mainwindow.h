#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QJsonObject>
#include <QUrlQuery>
#include <QNetworkReply>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    double dollar;
    double cash;
    double res;
    double euro;
    QString r;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void onResult (QNetworkReply *reply);

private slots:
    void on_checkBox_toggled();

    void on_checkBox_2_toggled();

    void on_lineEdit_textChanged();

    void on_lineEdit_2_textChanged();

    void on_lineEdit_3_textChanged();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *networkManager;
};

#endif // MAINWINDOW_H
