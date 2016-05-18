#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setDisabled(true);
    ui->lineEdit_2->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    ui->lineEdit->setEnabled(true);
    if (ui->checkBox->isEnabled())
        ui->lineEdit->setText("0");
    connect(ui->checkBox,SIGNAL(toggled(bool)),
            ui->lineEdit,SLOT(setEnabled(bool)));

}

void MainWindow::on_checkBox_2_toggled(bool checked)
{
    ui->lineEdit_2->setEnabled(true);
    if (ui->checkBox_2->isEnabled())
        ui->lineEdit_2->setText("0");
    connect(ui->checkBox_2,SIGNAL(toggled(bool)),
            ui->lineEdit_2,SLOT(setEnabled(bool)));
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    dollar = ui->lineEdit->text().toDouble();
    cash = ui->lineEdit_3->text().toDouble();
    res = dollar*cash;
    r = QString::number(res);
    ui->label_7->setText(r);
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    dollar = ui->lineEdit_2->text().toDouble();
    cash = ui->lineEdit_3->text().toDouble();
    res = dollar*cash;
    r = QString::number(res);
    ui->label_7->setText(r);
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    if(ui->lineEdit->isEnabled()) {
        euro = ui->lineEdit->text().toDouble();
        cash = ui->lineEdit_3->text().toDouble();
        res = dollar*cash;
        r = QString::number(res);
        ui->label_7->setText(r);
    }

    if(ui->lineEdit_2->isEnabled()) {
        euro = ui->lineEdit_2->text().toDouble();
        cash = ui->lineEdit_3->text().toDouble();
        res = dollar*cash;
        r = QString::number(res);
        ui->label_7->setText(r);
    }
}
