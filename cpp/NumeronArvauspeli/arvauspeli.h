#ifndef ARVAUSPELI_H
#define ARVAUSPELI_H

#include <QMainWindow>

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


private slots:
    void on_toolButton_clicked();

private:
    Ui::ArvausPeli *ui;
};
#endif // ARVAUSPELI_H
