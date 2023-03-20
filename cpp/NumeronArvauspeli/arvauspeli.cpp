#include "arvauspeli.h"
#include "ui_arvauspeli.h"
#include <random>
#include <iostream>
#include <QString>

using namespace std;

    int attempt = 10;
    int random_number;

ArvausPeli::ArvausPeli(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ArvausPeli)
{
    ui->setupUi(this);
}

ArvausPeli::~ArvausPeli()
{
    delete ui;
}

int ArvausPeli::RandomNum()
{
    mt19937 gen(time(nullptr));
    uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    return random_number;
}

void ArvausPeli::StartGame() //gives a random num when called
{
    random_number = RandomNum();
}

void ArvausPeli::on_toolButton_clicked()
{
    QString text = ui->plainTextEdit->toPlainText(); //get user inputted number from textbox (plainTextEdit)
    int guess = text.toInt(); //convert Qstring to int value
   // cout << random_number << endl;
    if (guess < random_number && attempt > 1) // guess too low
    {
        ui->label->setText("Arvauksesi on liian pieni");
        --attempt;
        ui->label_2->setText(QString::number(attempt));
    }
    else if (guess > random_number  && attempt > 1) // guess too high
    {
        ui->label->setText("Arvauksesi on liian suuri");
        --attempt;
        ui->label_2->setText(QString::number(attempt));
    }
    else if (guess == random_number) //user wins
    {
        ui->label->setText("Oikein arvattu!");
        StartGame(); //call StartGame to randomize a new number
        attempt = 10;
    }
    else if (attempt == 1) //user looses
    {
        ui->label->setText("Havisit Pelin");
        ui->label_2->setText("0");
        StartGame();
        attempt = 10;
    }
}
