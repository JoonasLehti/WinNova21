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
    //mt19937 gen(time(nullptr));
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
    if (guess < random_number && attempt > 1)
    {
        ui->label->setText("Arvauksesi on liian pieni");
        --attempt;
        ui->label_2->setText(QString::number(attempt));
    }
    else if (guess > random_number  && attempt > 1)
    {
        ui->label->setText("Arvauksesi on liian suuri");
        --attempt;
        ui->label_2->setText(QString::number(attempt));
    }
    else if (guess == random_number)
    {
        ui->label->setText("Oikein arvattu!");
        StartGame();
        attempt = 10;
    }
    else if (attempt == 1)
    {
        ui->label->setText("Havisit Pelin");
        ui->label_2->setText("0");
        StartGame();
        attempt = 10;
    }
}

double ArvausPeli::monteCarloSimulation(int simulations)
{
    int wins = 0;
    for (int i = 0; i < simulations; ++i)
    {
        int random_number = RandomNum();
        int attempt = 10;
        while (attempt > 0)
        {
            int guess = 50;
            if (guess == random_number)
            {
                ++wins;
                break;
            }
            --attempt;
        }
    }
    return static_cast<double>(wins) / simulations;
}

double ArvausPeli::monteCarloSimulation2(int simulations)
{
    int wins = 0;
    for (int i = 0; i < simulations; ++i)
    {
        int random_number = RandomNum();
        int attempt = 10;
        int min_value = 1;
        int max_value = 100;
        while (attempt > 0)
        {
            int guess = (min_value + max_value) / 2;
            if (guess == random_number)
            {
                ++wins;
                break;
            }
            else if (guess < random_number)
            {
                min_value = guess + 1;
            }
            else if (guess > random_number)
            {
                max_value = guess - 1;
            }
            --attempt;
        }
    }
    return static_cast<double>(wins) / simulations;
}

double ArvausPeli::monteCarloSimulation3(int simulations)
{
    int wins = 0;
    for (int i = 0; i < simulations; ++i)
    {
        int random_number = RandomNum();
        int attempt = 10;
        bool win = false;
        while (attempt > 0 && !win)
        {
            for (int guess = 1; guess <= 100; guess += 10)
            {
                if (guess == random_number)
                {
                    ++wins;
                    win = true;
                    break;
                }
            }
            --attempt;
        }
    }
    return static_cast<double>(wins) / simulations;
}

void ArvausPeli::displayProbability()
{
    int simulations = 100000;
    double probability = monteCarloSimulation(simulations);
    QString text = QString("Voiton todennakoisyys kun vastataan 50: %1%").arg(probability * 100);
    ui->label_3->setText(text);
    double probability2 = monteCarloSimulation2(simulations);
    QString text2 = QString("Voiton todennakoisyys kun vastataan aina puolesta valista: %1%").arg(probability2 * 100);
    ui->label_4->setText(text2);
    double probability3 = monteCarloSimulation3(simulations);
    QString text3 = QString("Voiton todennakoisyys kun vastataan aina 10,20,30...: %1%").arg(probability3 * 100);
    ui->label_5->setText(text3);
}
