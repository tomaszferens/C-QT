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


void MainWindow::on_checkBox_toggled()
{
    if (ui->checkBox->isChecked() == false) {
        ui->lineEdit->setText("");
        ui->lineEdit->setPlaceholderText("Podaj kurs");
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
        ui->lineEdit_2->setEnabled(true);
}

void MainWindow::on_lineEdit_textChanged()
{
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
    res = dollar*cash;
    r = QString::number(res, 'f', 2);
    ui->label_7->setText(r + " PLN");
    if (ui->label_7->text() == "0.00 PLN")
        ui->label_7->setText("Kwota");
}

void MainWindow::on_lineEdit_2_textChanged()
{
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
    res = euro*cash;
    r = QString::number(res, 'f', 2);
    ui->label_7->setText(r + " PLN");
    if (ui->label_7->text() == "0.00 PLN")
        ui->label_7->setText("Kwota");
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

    if(ui->lineEdit->isEnabled()) {
        dollar = b.toDouble();
        cash = a.toDouble();
        res = dollar*cash;
        r = QString::number(res, 'f', 2);

        ui->label_7->setText(r + " PLN");
    }

    if(ui->lineEdit_2->isEnabled()) {
        euro = c.toDouble();
        cash = a.toDouble();
        res = euro*cash;
        r = QString::number(res, 'f', 2);

        ui->label_7->setText(r + " PLN");
    }
    if (ui->label_7->text() == "0.00 PLN")
        ui->label_7->setText("Kwota");
}
