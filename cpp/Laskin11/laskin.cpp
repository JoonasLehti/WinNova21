#include "laskin.h"
#include "calculator.h"
#include "ui_laskin.h"

Laskin::Laskin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Laskin)
    , calculator(new Calculator)
{
    ui->setupUi(this);
}

Laskin::~Laskin()
{
    delete ui;
    delete calculator;
}

void Laskin::on_equal_clicked()
{
    calculator->equalClicked();
    ui->textBrowser->setText(calculator->display());
}

void Laskin::on_number_0_clicked()
{
    calculator->digitClicked("0");
    ui->textBrowser->setText(calculator->display());
}

void Laskin::on_number_1_clicked()
{
    calculator->digitClicked("1");
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_number_2_clicked()
{
    calculator->digitClicked("2");
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_number_3_clicked()
{
    calculator->digitClicked("3");
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_number_4_clicked()
{
    calculator->digitClicked("4");
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_number_5_clicked()
{
    calculator->digitClicked("5");
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_number_6_clicked()
{
    calculator->digitClicked("6");
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_number_7_clicked()
{
    calculator->digitClicked("7");
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_number_8_clicked()
{
    calculator->digitClicked("8");
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_number_9_clicked()
{
    calculator->digitClicked("9");
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_addition_clicked()
{
    calculator->additiveOperatorClicked(Calculator::Addition);
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_substraction_clicked()
{
    calculator->additiveOperatorClicked(Calculator::Subtraction);
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_multiply_clicked()
{
    calculator->multiplicativeOperatorClicked(Calculator::Multiplication);
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_divide_clicked()
{
    calculator->multiplicativeOperatorClicked(Calculator::Division);
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_inverse_clicked()
{
    calculator->unaryOperatorClicked(Calculator::Inverse);
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_chisquared_clicked()
{
    calculator->unaryOperatorClicked(Calculator::Square);
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_squareroot_clicked()
{
    calculator->unaryOperatorClicked(Calculator::SquareRoot);
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_memoryAdd_clicked()
{
    calculator->addToMemory();
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_memorySave_clicked()
{
    calculator->setMemory();
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_memoryRecall_clicked()
{
    calculator->readMemory();
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_memoryClear_clicked()
{
    calculator->clearMemory();
    ui->textBrowser->setText(calculator->display());
}



void Laskin::on_backspace_clicked()
{
    calculator->backspaceClicked();
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_clear_clicked()
{
    calculator->clear();
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_clearall_clicked()
{
    calculator->clearAll();
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_dot_clicked()
{
    calculator->pointClicked();
    ui->textBrowser->setText(calculator->display());
}


void Laskin::on_negative_clicked()
{
    calculator->changeSignClicked();
    ui->textBrowser->setText(calculator->display());
}

