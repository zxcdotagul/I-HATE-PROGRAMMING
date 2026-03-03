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
    // Существующие слоты
    void on_Edit_10cc_textEdited(const QString &arg1);
    void on_ButtonTo2_clicked();
    void on_Edit_2cc_textEdited(const QString &arg1);
    void on_ButtonTo10_clicked();
    void on_ButtonAbout_clicked();

    // Новые слоты для 8-ричной системы
    void on_Edit_8cc_textEdited(const QString &arg1);
    void on_ButtonTo8_clicked();
    void on_ButtonFrom8_clicked();

    // Новые слоты для 16-ричной системы
    void on_Edit_16cc_textEdited(const QString &arg1);
    void on_ButtonTo16_clicked();
    void on_ButtonFrom16_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
