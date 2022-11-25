#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //for all numbers instead of declaring for each buttons with numbers
    void btn_with_numbers_clicked();

    //for all arithmetic operations like addition, substraction, multiplication, increment...
    void on_arithmetic_operation_clicked();

    //for backspace
    void on_btn_del_clicked();

    //for deleting all inputs
    void on_btn_clear_clicked();

    //for decimal values
    void on_btn_dot_clicked();

    //for mathematical operations
    void on_btn_equals_clicked();


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
