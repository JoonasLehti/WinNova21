#ifndef ARVAUSPELI_H
#define ARVAUSPELI_H

#include <QMainWindow>
#include <random>

QT_BEGIN_NAMESPACE
namespace Ui { class ArvausPeli; }
QT_END_NAMESPACE

class ArvausPeli : public QMainWindow
{
    Q_OBJECT

public:
    ArvausPeli(QWidget *parent = nullptr);
    ~ArvausPeli();

    int RandomNum();
    void StartGame();
    double monteCarloSimulation(int);
    double monteCarloSimulation2(int);
    double monteCarloSimulation3(int);
    void displayProbability();

private slots:
    void on_toolButton_clicked();

private:
    Ui::ArvausPeli *ui;
    std::mt19937 gen{std::random_device{}()};
};
#endif // ARVAUSPELI_H
