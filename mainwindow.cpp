#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setDisabled(true);
    ui->lineEdit_2->setDisabled(true);
    connect(ui->checkBox,SIGNAL(toggled(bool)),
            ui->lineEdit,SLOT(setEnabled(bool)));
    connect(ui->checkBox_2,SIGNAL(toggled(bool)),
            ui->lineEdit_2,SLOT(setEnabled(bool)));

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change()
{
    if (resd!=0)
    {
        ui->label_4->setStyleSheet("color: red;");
        ui->label_5->setStyleSheet("color: black;");
    }

    if (rese!=0)
    {
        ui->label_5->setStyleSheet("color: red;");
        ui->label_4->setStyleSheet("color: black;");
    }

    if (resd==0 && rese==0)
    {
        ui->label_4->setStyleSheet("color: black;");
        ui->label_5->setStyleSheet("color: black;");
    }

}

void MainWindow::onResult(QNetworkReply *reply)
{
 if (!reply->error()) {
     QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
     QJsonObject root = document.object();
     QJsonValue jv = root.value("quotes");
     QJsonObject jo = jv.toObject();
     if (ui->lineEdit->isEnabled()) {
         double USDPLN_2 = jo.value(jo.keys().at(117)).toDouble();
         QString Susdpln_2 = QString::number(USDPLN_2);
         Susdpln_2[1] = ',';
         ui->lineEdit->setText(Susdpln_2);

     }
     if (ui->lineEdit_2->isEnabled()) {
        double USDEUR = jo.value(jo.keys().at(46)).toDouble();
        double USDPLN = jo.value(jo.keys().at(117)).toDouble();
        double PLNEUR = (1/USDEUR) * USDPLN;
        QString Splneur = QString::number(PLNEUR);
        Splneur[1] = ',';

        ui->lineEdit_2->setText(Splneur);
     }

 }
 reply->deleteLater();

 }


void MainWindow::on_checkBox_toggled()
{
    if (ui->checkBox->isChecked() == false) {
        ui->lineEdit->setText("");
        ui->lineEdit->setPlaceholderText("Podaj kurs");
        on_lineEdit_2_textChanged();
    }
    if (ui->lineEdit->text() == "") {
        ui->label_7->setText("Kwota");
        on_lineEdit_2_textChanged();
    }
       ui->lineEdit->setEnabled(true);
}

void MainWindow::on_checkBox_2_toggled()
{
    if (ui->checkBox_2->isChecked() == false) {
        ui->lineEdit_2->setText("");
        ui->lineEdit_2->setPlaceholderText("Podaj kurs");
        on_lineEdit_textChanged();
    }
    if (ui->lineEdit_2->text() == "") {
        ui->label_7->setText("Kwota");
        on_lineEdit_textChanged();
    }
        ui->lineEdit_2->setEnabled(true);
}

void MainWindow::on_lineEdit_textChanged()
{
    check_for_color = true;
    QString a;
    a = ui->lineEdit->text();
    for (int i=0; i<ui->lineEdit->maxLength(); i++) {
        if (a[i] == ',') {
            a[i] = '.';
        }
    }

    QString b;
    b = ui->lineEdit_3->text();
    for (int i=0; i<ui->lineEdit_3->maxLength(); i++) {
        if (b[i] == ',') {
            b[i] = '.';
        }
    }

    dollar = a.toDouble();
    cash = b.toDouble();
    resd = dollar*cash;

    if (ui->label_7->text() == "0.00 PLN" || resd <= 0)
        ui->label_7->setText("Kwota");

    if (resd > 0) {
        rd = QString::number(resd, 'f', 2);
        ui->label_7->setText(rd + " PLN");
    }

    if (ui->lineEdit->text() == "" && ui->lineEdit_2->text() != "") {
        on_lineEdit_2_textChanged();
        ui->label_5->setStyleSheet("color: red");
        ui->label_4->setStyleSheet("color: black");
        check_for_color = false;
    }
    line_edited = 1;
    rese = 0;
    if (check_for_color)
    change();
}

void MainWindow::on_lineEdit_2_textChanged()
{
    check_for_color = true;
    QString a;

    a = ui->lineEdit_2->text();
    for (int i=0; i<ui->lineEdit_2->maxLength(); i++) {
        if (a[i] == ',') {
            a[i] = '.';
        }
    }

    QString b;

    b = ui->lineEdit_3->text();
    for (int i=0; i<ui->lineEdit_3->maxLength(); i++) {
        if (b[i] == ',') {
            b[i] = '.';
        }
    }
    euro = a.toDouble();
    cash = b.toDouble();
    rese = euro*cash;

    if (ui->label_7->text() == "0.00 PLN" || rese <= 0)
        ui->label_7->setText("Kwota");

    if (rese > 0) {
        re = QString::number(rese, 'f', 2);
        ui->label_7->setText(re + " PLN");
    }

    if (ui->lineEdit_2->text() == "" && ui->lineEdit->text() != "") {
        on_lineEdit_textChanged();
        ui->label_4->setStyleSheet("color: red");
        ui->label_5->setStyleSheet("color: black");
        check_for_color = false;
    }

    line_edited = 2;
    resd = 0;
    if (check_for_color)
    change();
}

void MainWindow::on_lineEdit_3_textChanged()
{
    QString a;
    a = ui->lineEdit_3->text();
    for (int i=0; i<ui->lineEdit_3->maxLength(); i++) {
        if (a[i] == ',') {
            a[i] = '.';
        }
    }

    QString b;
    b = ui->lineEdit->text();
    for (int i=0; i<ui->lineEdit_3->maxLength(); i++) {
        if (b[i] == ',') {
            b[i] = '.';
        }
    }

    QString c;
    c = ui->lineEdit_2->text();
    for (int i=0; i<ui->lineEdit_2->maxLength(); i++) {
        if (c[i] == ',') {
            c[i] = '.';
        }
    }

    if(line_edited == 1) {
        dollar = b.toDouble();
        cash = a.toDouble();
        resd = dollar*cash;
        if (resd >= 0) {
            rd = QString::number(resd, 'f', 2);
            ui->label_7->setText(rd + " PLN");
        }
    }

    if(line_edited == 2) {
        euro = c.toDouble();
        cash = a.toDouble();
        rese = euro*cash;
        if(rese >= 0) {
            re = QString::number(rese, 'f', 2);
            ui->label_7->setText(re + " PLN");
        }
    }
    if (ui->label_7->text() == "0.00 PLN")
        ui->label_7->setText("Kwota");
    change();
}

void MainWindow::on_pushButton_2_clicked()
{
        networkManager = new QNetworkAccessManager();
        connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::onResult);
        networkManager->get(QNetworkRequest(QUrl("http://apilayer.net/api/live?access_key=a2712922ea49e46b78e54cb9ba3f0c8b")));
        change();
}
