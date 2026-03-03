#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Инициализация начальных значений
    ui->label_operand->setText("0");
    ui->label_sign->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ========== ЦИФРОВЫЕ КНОПКИ ==========
void MainWindow::on_pushButton_0_clicked()
{
    QString st = ui->lineEdit->text();
    ui->lineEdit->setText(st + "0");
}

void MainWindow::on_pushButton_1_clicked()
{
    QString st = ui->lineEdit->text();
    ui->lineEdit->setText(st + "1");
}

void MainWindow::on_pushButton_2_clicked()
{
    QString st = ui->lineEdit->text();
    ui->lineEdit->setText(st + "2");
}

void MainWindow::on_pushButton_3_clicked()
{
    QString st = ui->lineEdit->text();
    ui->lineEdit->setText(st + "3");
}

void MainWindow::on_pushButton_4_clicked()
{
    QString st = ui->lineEdit->text();
    ui->lineEdit->setText(st + "4");
}

void MainWindow::on_pushButton_5_clicked()
{
    QString st = ui->lineEdit->text();
    ui->lineEdit->setText(st + "5");
}

void MainWindow::on_pushButton_6_clicked()
{
    QString st = ui->lineEdit->text();
    ui->lineEdit->setText(st + "6");
}

void MainWindow::on_pushButton_7_clicked()
{
    QString st = ui->lineEdit->text();
    ui->lineEdit->setText(st + "7");
}

void MainWindow::on_pushButton_8_clicked()
{
    QString st = ui->lineEdit->text();
    ui->lineEdit->setText(st + "8");
}

void MainWindow::on_pushButton_9_clicked()
{
    QString st = ui->lineEdit->text();
    ui->lineEdit->setText(st + "9");
}

// ========== КНОПКА ТОЧКИ ==========
void MainWindow::on_pushButton_tochka_clicked()
{
    QString st = ui->lineEdit->text();

    // Проверяем, есть ли уже точка в строке
    if (st.indexOf('.') == -1)
    {
        // Если строка пустая, добавляем "0."
        if (st.isEmpty()) {
            ui->lineEdit->setText("0.");
        } else {
            ui->lineEdit->setText(st + ".");
        }
    }
    else
    {
        QMessageBox::information(this, "Информация", "Точка уже есть");
    }
}

// ========== КНОПКА УДАЛЕНИЯ ПОСЛЕДНЕГО СИМВОЛА (СТРЕЛОЧКА) ==========
void MainWindow::on_pushButton_sp_clicked()
{
    QString st = ui->lineEdit->text();
    if (!st.isEmpty()) {
        int sz = st.length();
        st = st.left(sz - 1);
        ui->lineEdit->setText(st);
    }
}

// ========== КНОПКА ОЧИСТКИ ВСЕГО (СТРЕЛОЧКА С КРЕСТИКОМ) ==========
void MainWindow::on_pushButton_remove_clicked()
{
    ui->lineEdit->clear();
    ui->label_operand->setText("0");
    ui->label_sign->clear();
}

// ========== ОБРАБОТКА РЕДАКТИРОВАНИЯ ПОЛЯ ВВОДА ==========
void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    // Здесь можно добавить валидацию при необходимости
    // Например, проверка на несколько точек
    if (arg1.count('.') > 1) {
        QString corrected = arg1;
        int firstDot = arg1.indexOf('.');
        for (int i = arg1.length() - 1; i > firstDot; i--) {
            if (arg1[i] == '.') {
                corrected.remove(i, 1);
                break;
            }
        }
        ui->lineEdit->setText(corrected);
        QMessageBox::information(this, "Ошибка", "Число может содержать только одну точку");
    }
}

// ========== ФУНКЦИЯ ВЫПОЛНЕНИЯ ОПЕРАЦИИ ==========
int MainWindow::run_oper(double *c)
{
    bool ok_a, ok_b;

    // Получаем значения из меток
    QString st_a = ui->label_operand->text();
    QString st_b = ui->lineEdit->text();
    QString st_sign = ui->label_sign->text();

    // Проверяем, что поле ввода не пустое
    if (st_b.isEmpty()) {
        return -1;
    }

    // Преобразуем строки в числа
    double a = st_a.toDouble(&ok_a);
    double b = st_b.toDouble(&ok_b);

    if (!ok_a || !ok_b) {
        return -1;
    }

    // Определяем знак операции
    char sg;
    if (!st_sign.isEmpty()) {
        sg = st_sign.at(0).toLatin1();
    } else {
        return -1;
    }

    // Выполняем операцию
    switch (sg)
    {
    case '+':
        *c = a + b;
        break;
    case '-':
        *c = a - b;
        break;
    case '*':
        *c = a * b;
        break;
    case '/':
        if (b == 0) {
            QMessageBox::critical(this, "Ошибка", "Деление на ноль невозможно!");
            return -1;
        }
        *c = a / b;
        break;
    default:
        return -1;
    }

    return 0;
}

// ========== КНОПКА ПЛЮС ==========
void MainWindow::on_pushButton_plus_clicked()
{
    double c;
    int er = run_oper(&c);

    if (er == 0) {
        // Если операция успешна, обновляем верхнюю метку результатом
        ui->label_operand->setNum(c);
    } else {
        // Если ошибка, просто перемещаем текущее число в верхнюю метку
        QString st_b = ui->lineEdit->text();
        if (!st_b.isEmpty()) {
            ui->label_operand->setText(st_b);
        }
    }

    // Устанавливаем знак операции
    ui->label_sign->setText("+");

    // Очищаем поле ввода
    ui->lineEdit->clear();
}

// ========== КНОПКА МИНУС ==========
void MainWindow::on_pushButton_minus_clicked()
{
    double c;
    int er = run_oper(&c);

    if (er == 0) {
        ui->label_operand->setNum(c);
    } else {
        QString st_b = ui->lineEdit->text();
        if (!st_b.isEmpty()) {
            ui->label_operand->setText(st_b);
        }
    }

    ui->label_sign->setText("-");
    ui->lineEdit->clear();
}

// ========== КНОПКА УМНОЖЕНИЯ ==========
void MainWindow::on_pushButton_multiply_clicked()
{
    double c;
    int er = run_oper(&c);

    if (er == 0) {
        ui->label_operand->setNum(c);
    } else {
        QString st_b = ui->lineEdit->text();
        if (!st_b.isEmpty()) {
            ui->label_operand->setText(st_b);
        }
    }

    ui->label_sign->setText("*");
    ui->lineEdit->clear();
}

// ========== КНОПКА ДЕЛЕНИЯ ==========
void MainWindow::on_pushButton_delit_clicked()
{
    double c;
    int er = run_oper(&c);

    if (er == 0) {
        ui->label_operand->setNum(c);
    } else {
        QString st_b = ui->lineEdit->text();
        if (!st_b.isEmpty()) {
            ui->label_operand->setText(st_b);
        }
    }

    ui->label_sign->setText("/");
    ui->lineEdit->clear();
}

// ========== КНОПКА РАВНО ==========
void MainWindow::on_pushButton_ravno_clicked()
{
    double c;
    int er = run_oper(&c);

    if (er == 0) {
        // Выводим результат в поле ввода
        ui->lineEdit->setText(QString::number(c));
        // Сбрасываем верхнюю метку
        ui->label_operand->setText("0");
        // Сбрасываем знак
        ui->label_sign->clear();
    } else {
        QMessageBox::warning(this, "Ошибка", "Некорректная операция");
    }
}
