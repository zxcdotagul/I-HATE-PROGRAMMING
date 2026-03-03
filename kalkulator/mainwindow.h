#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Слоты для цифровых кнопок
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

    // Слот для точки
    void on_pushButton_tochka_clicked();

    // Слот для удаления последнего символа (стрелочка)
    void on_pushButton_sp_clicked();

    // Слот для очистки всего (стрелочка с крестиком)
    void on_pushButton_remove_clicked();

    // Слоты для операций
    void on_pushButton_plus_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_multiply_clicked();
    void on_pushButton_delit_clicked();

    // Слот для равно
    void on_pushButton_ravno_clicked();

    // Слот для редактирования строки ввода
    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;

    // Вспомогательная функция для выполнения операции
    int run_oper(double *c);
};

#endif // MAINWINDOW_H
