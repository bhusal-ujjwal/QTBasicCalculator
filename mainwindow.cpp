#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

double firstNum;
bool userIsTypingSecondNumber;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //for numbers
    connect(ui->btn_0,SIGNAL(released()),this,SLOT(btn_with_numbers_clicked()));
    connect(ui->btn_1,SIGNAL(released()), this, SLOT(btn_with_numbers_clicked()));
    connect(ui->btn_2,SIGNAL(released()), this, SLOT(btn_with_numbers_clicked()));
    connect(ui->btn_3,SIGNAL(released()), this, SLOT(btn_with_numbers_clicked()));
    connect(ui->btn_4,SIGNAL(released()), this, SLOT(btn_with_numbers_clicked()));
    connect(ui->btn_5,SIGNAL(released()), this, SLOT(btn_with_numbers_clicked()));
    connect(ui->btn_6,SIGNAL(released()), this, SLOT(btn_with_numbers_clicked()));
    connect(ui->btn_7,SIGNAL(released()), this, SLOT(btn_with_numbers_clicked()));
    connect(ui->btn_8,SIGNAL(released()), this, SLOT(btn_with_numbers_clicked()));
    connect(ui->btn_9,SIGNAL(released()), this, SLOT(btn_with_numbers_clicked()));

    //for arithmetic operations
    connect(ui->btn_add,SIGNAL(released()), this, SLOT(on_arithmetic_operation_clicked()));
    connect(ui->btn_substract,SIGNAL(released()), this, SLOT(on_arithmetic_operation_clicked()));
    connect(ui->btn_divide,SIGNAL(released()), this, SLOT(on_arithmetic_operation_clicked()));
    connect(ui->btn_multiply,SIGNAL(released()), this, SLOT(on_arithmetic_operation_clicked()));
    connect(ui->btn_percent,SIGNAL(released()), this, SLOT(on_arithmetic_operation_clicked()));
    connect(ui->btn_plusminus,SIGNAL(released()), this, SLOT(on_arithmetic_operation_clicked()));

    //for backspace as clear all and quit is implemented from the UI signal and slot editor
    connect(ui->btn_del,SIGNAL(released()), this, SLOT(on_btn_del_clicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

//for numbers button
void MainWindow::btn_with_numbers_clicked()
{
    QPushButton * button = (QPushButton*)sender();
    QString newLabel;
    double labelNumber;

    if ((ui->btn_add->isChecked() || ui->btn_substract->isChecked() || ui->btn_multiply->isChecked() || ui->btn_divide->isChecked() || ui->btn_percent->isChecked()) && (!userIsTypingSecondNumber))
    {
        labelNumber = button->text().right(1).toDouble();
        userIsTypingSecondNumber = true;
        newLabel = QString::number(labelNumber,'g',15);
    }
    else
    {
        if (ui->lineEdit->text().contains('.') && button->text().right(1) == "0")
        {
            newLabel = (ui->lineEdit->text() + button->text().right(1)); // the first character in the returned field is &
        }
        else
        {
            labelNumber = (ui->lineEdit->text() + button->text().right(1)).toDouble(); // the first character in the returned field is &
            newLabel = QString::number(labelNumber,'g',15);
        }

        ui->lineEdit->setText(newLabel);

    }

    ui->lineEdit-> setText(newLabel);

}

//for various arithmetic operations
void MainWindow::on_arithmetic_operation_clicked()
{
    QPushButton * button = (QPushButton*) sender();
    QString newLabel;
    double labelNumber;

    if(button->text() == "+-")
    {
        labelNumber = ui->lineEdit->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->lineEdit->setText(newLabel);
    }

    if(button->text() == "%")
    {
        labelNumber = ui->lineEdit->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->lineEdit->setText(newLabel);

        //for removing check of other buttons
        ui->btn_percent->setChecked(true);
        if(ui->btn_add->isChecked())
            ui->btn_add->setChecked(false);
        else if (ui->btn_substract->isChecked())
            ui->btn_substract->setChecked(false);
        else if (ui->btn_multiply->isChecked())
            ui->btn_multiply->setChecked(false);
        else if (ui->btn_divide->isChecked())
            ui->btn_divide->setChecked(false);

    }

    if(button->text() == "+")
    {
        //for removing check of other buttons
        ui->btn_add->setChecked(true);
        if(ui->btn_percent->isChecked())
            ui->btn_percent->setChecked(false);
        else if (ui->btn_substract->isChecked())
            ui->btn_substract->setChecked(false);
        else if (ui->btn_multiply->isChecked())
            ui->btn_multiply->setChecked(false);
        else if (ui->btn_divide->isChecked())
            ui->btn_divide->setChecked(false);

    }

    if(button->text() == "-")
    {
        //for removing check of other buttons
        ui->btn_substract->setChecked(true);
        if(ui->btn_add->isChecked())
            ui->btn_add->setChecked(false);
        else if (ui->btn_percent->isChecked())
            ui->btn_percent->setChecked(false);
        else if (ui->btn_multiply->isChecked())
            ui->btn_multiply->setChecked(false);
        else if (ui->btn_divide->isChecked())
            ui->btn_divide->setChecked(false);

    }

    if(button->text() == "X")
    {
        //for removing check of other buttons
        ui->btn_multiply->setChecked(true);
        if(ui->btn_add->isChecked())
            ui->btn_add->setChecked(false);
        else if (ui->btn_substract->isChecked())
            ui->btn_substract->setChecked(false);
        else if (ui->btn_percent->isChecked())
            ui->btn_percent->setChecked(false);
        else if (ui->btn_divide->isChecked())
            ui->btn_divide->setChecked(false);

    }

    if(button->text() == "÷")
    {
        //for removing check of other buttons
        ui->btn_divide->setChecked(true);
        if(ui->btn_add->isChecked())
            ui->btn_add->setChecked(false);
        else if (ui->btn_substract->isChecked())
            ui->btn_substract->setChecked(false);
        else if (ui->btn_multiply->isChecked())
            ui->btn_multiply->setChecked(false);
        else if (ui->btn_percent->isChecked())
            ui->btn_percent->setChecked(false);

    }

    firstNum = ui->lineEdit->text().toDouble();
    button->setChecked(true);

}


//for backspace functionality
void MainWindow::on_btn_del_clicked()
{
    QString newLabel;
    double labelNumber;
    int num2chop = 1;

    labelNumber = ui->lineEdit->text().size();
    if(labelNumber > 0)
    {
        //backspace
        if(labelNumber > 1)
        {
           if(ui->lineEdit->text().back() != ' ')
           {
               num2chop = 1;
           }
        }
        ui->lineEdit->setText(ui->lineEdit->text().chopped(num2chop));
    }

    ui->btn_add->setChecked(false);
    ui->btn_substract->setChecked(false);
    ui->btn_multiply->setChecked(false);
    ui->btn_divide->setChecked(false);
    ui->btn_percent->setChecked(false);

}


//for clearing all inputs
void MainWindow::on_btn_clear_clicked()
{
    ui->btn_add->setChecked(false);
    ui->btn_substract->setChecked(false);
    ui->btn_multiply->setChecked(false);
    ui->btn_divide->setChecked(false);
    ui->btn_percent->setChecked(false);

    userIsTypingSecondNumber = false;
    ui->lineEdit->setText("0");
}

//for decimal values
void MainWindow::on_btn_dot_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("."));
}

//for calculation of various arithmetic operations
void MainWindow::on_btn_equals_clicked()
{
    double labelNumber, secondNum;
    QString newLabel;

    secondNum = ui->lineEdit->text().toDouble();

    if(ui->btn_add->isChecked())
    {
        labelNumber = firstNum + secondNum;
        ui->btn_add->setChecked(false);

    }
    if(ui->btn_substract->isChecked())
    {
        labelNumber = firstNum - secondNum;
        ui->btn_substract->setChecked(false);
    }
    if(ui->btn_multiply->isChecked())
    {
        labelNumber = firstNum * secondNum;
        ui->btn_multiply->setChecked(false);
    }
    if(ui->btn_divide->isChecked())
    {
        labelNumber = firstNum / secondNum;
        ui->btn_divide->setChecked(false);
    }

    newLabel = QString::number(labelNumber,'g',15);
    ui->lineEdit->setText(newLabel);

    userIsTypingSecondNumber = false;

}
