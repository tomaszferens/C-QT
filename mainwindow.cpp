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
    dollar = ui->lineEdit->text().toDouble();
    cash = ui->lineEdit_3->text().toDouble();
    res = dollar*cash;
    r = QString::number(res, 'f', 2);
    ui->label_7->setText(r + " PLN");
}

void MainWindow::on_lineEdit_2_textChanged()
{
    euro = ui->lineEdit_2->text().toDouble();
    cash = ui->lineEdit_3->text().toDouble();
    res = euro*cash;
    r = QString::number(res, 'f', 2);
    ui->label_7->setText(r + " PLN");
}

void MainWindow::on_lineEdit_3_textChanged()
{
    if(ui->lineEdit->isEnabled()) {
        dollar = ui->lineEdit->text().toDouble();
        cash = ui->lineEdit_3->text().toDouble();
        res = dollar*cash;
        r = QString::number(res, 'f', 2);

        ui->label_7->setText(r + " PLN");
    }

    if(ui->lineEdit_2->isEnabled()) {
        euro = ui->lineEdit_2->text().toDouble();
        cash = ui->lineEdit_3->text().toDouble();
        res = euro*cash;
        r = QString::number(res, 'f', 2);

        ui->label_7->setText(r + " PLN");
    }
}
