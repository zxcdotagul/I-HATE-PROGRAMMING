#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_ButtonAbout_clicked()
{
    QMessageBox::about(this, "О программе",
                       "Переводит числа между системами счисления:\n"
                       "- Двоичная (2)\n"
                       "- Восьмеричная (8)\n"
                       "- Десятичная (10)\n"
                       "- Шестнадцатеричная (16)");
}


void MainWindow::on_Edit_10cc_textEdited(const QString &arg1)
{
    if (arg1.isEmpty()) return;

    if (arg1.length() > 9) {
        QMessageBox::warning(this, "Ошибка", "Слишком большая длина числа (максимум 9 цифр)");
        ui->Edit_10cc->setText(arg1.left(arg1.length() - 1));
        return;
    }

    QChar lastChar = arg1.at(arg1.length() - 1);
    if (!lastChar.isDigit()) {
        QMessageBox::warning(this, "Ошибка", "Разрешено вводить только цифры");
        ui->Edit_10cc->setText(arg1.left(arg1.length() - 1));
    }
}


void MainWindow::on_Edit_2cc_textEdited(const QString &arg1)
{
    if (arg1.isEmpty()) return;

    if (arg1.length() > 31) {
        QMessageBox::warning(this, "Ошибка", "Слишком большая длина числа (максимум 31 бит)");
        ui->Edit_2cc->setText(arg1.left(arg1.length() - 1));
        return;
    }

    QChar lastChar = arg1.at(arg1.length() - 1);
    if (lastChar != '0' && lastChar != '1') {
        QMessageBox::warning(this, "Ошибка", "Разрешено вводить только 0 или 1");
        ui->Edit_2cc->setText(arg1.left(arg1.length() - 1));
    }
}


void MainWindow::on_ButtonTo2_clicked()
{
    QString decimalText = ui->Edit_10cc->text();

    if (decimalText.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите число в десятичной системе");
        return;
    }

    bool ok;
    int decimal = decimalText.toInt(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Некорректное десятичное число");
        return;
    }

    if (decimal == 0) {
        ui->Edit_2cc->setText("0");
        return;
    }

    QString binary = "";
    int temp = decimal;

    while (temp > 0) {
        binary = QString::number(temp % 2) + binary;
        temp /= 2;
    }

    ui->Edit_2cc->setText(binary);
}


void MainWindow::on_ButtonTo10_clicked()
{
    QString binaryText = ui->Edit_2cc->text();

    if (binaryText.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите число в двоичной системе");
        return;
    }

    for (int i = 0; i < binaryText.length(); i++) {
        if (binaryText[i] != '0' && binaryText[i] != '1') {
            QMessageBox::warning(this, "Ошибка", "Двоичное число может содержать только 0 и 1");
            return;
        }
    }

    int decimal = 0;
    int length = binaryText.length();

    for (int i = 0; i < length; i++) {
        if (binaryText[i] == '1') {
            decimal += pow(2, length - i - 1);
        }
    }

    ui->Edit_10cc->setText(QString::number(decimal));
}


void MainWindow::on_Edit_8cc_textEdited(const QString &arg1)
{
    if (arg1.isEmpty()) return;

    if (arg1.length() > 11) {
        QMessageBox::warning(this, "Ошибка", "Слишком большая длина числа (максимум 11 цифр)");
        ui->Edit_8cc->setText(arg1.left(arg1.length() - 1));
        return;
    }

    QChar lastChar = arg1.at(arg1.length() - 1);
    if (lastChar < '0' || lastChar > '7') {
        QMessageBox::warning(this, "Ошибка", "Разрешено вводить только цифры от 0 до 7");
        ui->Edit_8cc->setText(arg1.left(arg1.length() - 1));
    }
}


void MainWindow::on_ButtonTo8_clicked()
{
    QString decimalText = ui->Edit_10cc->text();

    if (decimalText.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите число в десятичной системе");
        return;
    }

    bool ok;
    int decimal = decimalText.toInt(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Некорректное десятичное число");
        return;
    }

    if (decimal == 0) {
        ui->Edit_8cc->setText("0");
        return;
    }

    QString octal = "";
    int temp = decimal;

    while (temp > 0) {
        octal = QString::number(temp % 8) + octal;
        temp /= 8;
    }

    ui->Edit_8cc->setText(octal);
}


void MainWindow::on_ButtonFrom8_clicked()
{
    QString octalText = ui->Edit_8cc->text();

    if (octalText.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите число в восьмеричной системе");
        return;
    }


    for (int i = 0; i < octalText.length(); i++) {
        if (octalText[i] < '0' || octalText[i] > '7') {
            QMessageBox::warning(this, "Ошибка", "Восьмеричное число может содержать только цифры от 0 до 7");
            return;
        }
    }

    bool ok;
    int decimal = octalText.toInt(&ok, 8);

    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Некорректное восьмеричное число");
        return;
    }

    ui->Edit_10cc->setText(QString::number(decimal));
}


void MainWindow::on_Edit_16cc_textEdited(const QString &arg1)
{
    if (arg1.isEmpty()) return;

    if (arg1.length() > 8) {
        QMessageBox::warning(this, "Ошибка", "Слишком большая длина числа (максимум 8 символов)");
        ui->Edit_16cc->setText(arg1.left(arg1.length() - 1));
        return;
    }

    QChar lastChar = arg1.at(arg1.length() - 1).toUpper();
    bool valid = (lastChar >= '0' && lastChar <= '9') ||
                 (lastChar >= 'A' && lastChar <= 'F');

    if (!valid) {
        QMessageBox::warning(this, "Ошибка",
                             "Разрешено вводить только:\n"
                             "- цифры от 0 до 9\n"
                             "- буквы от A до F");
        ui->Edit_16cc->setText(arg1.left(arg1.length() - 1));
    }
}


void MainWindow::on_ButtonTo16_clicked()
{
    QString decimalText = ui->Edit_10cc->text();

    if (decimalText.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите число в десятичной системе");
        return;
    }

    bool ok;
    int decimal = decimalText.toInt(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Некорректное десятичное число");
        return;
    }

    if (decimal == 0) {
        ui->Edit_16cc->setText("0");
        return;
    }

    QString hex = "";
    int temp = decimal;

    while (temp > 0) {
        int remainder = temp % 16;
        if (remainder < 10) {
            hex = QString::number(remainder) + hex;
        } else {

            hex = QChar('A' + remainder - 10) + hex;
        }
        temp /= 16;
    }

    ui->Edit_16cc->setText(hex);
}


void MainWindow::on_ButtonFrom16_clicked()
{
    QString hexText = ui->Edit_16cc->text().toUpper();

    if (hexText.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите число в шестнадцатеричной системе");
        return;
    }


    for (int i = 0; i < hexText.length(); i++) {
        QChar c = hexText[i];
        bool valid = (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F');
        if (!valid) {
            QMessageBox::warning(this, "Ошибка",
                                 "Шестнадцатеричное число может содержать только:\n"
                                 "- цифры 0-9\n"
                                 "- буквы A-F");
            return;
        }
    }

    bool ok;
    int decimal = hexText.toInt(&ok, 16);

    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Некорректное шестнадцатеричное число");
        return;
    }

    ui->Edit_10cc->setText(QString::number(decimal));
}
