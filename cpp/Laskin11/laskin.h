#ifndef LASKIN_H
#define LASKIN_H

#include "calculator.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Laskin; }
QT_END_NAMESPACE

class Laskin : public QMainWindow
{
    Q_OBJECT

public:
    Laskin(QWidget *parent = nullptr);
    ~Laskin();

private slots:
    void on_number_1_clicked();

    void on_number_2_clicked();

    void on_number_3_clicked();

    void on_number_0_clicked();

    void on_number_4_clicked();

    void on_number_5_clicked();

    void on_number_6_clicked();

    void on_number_7_clicked();

    void on_number_8_clicked();

    void on_number_9_clicked();

    void on_addition_clicked();

    void on_equal_clicked();

    void on_substraction_clicked();

    void on_multiply_clicked();

    void on_divide_clicked();

    void on_inverse_clicked();

    void on_chisquared_clicked();

    void on_squareroot_clicked();

    void on_memoryAdd_clicked();

    void on_memorySave_clicked();

    void on_memoryRecall_clicked();

    void on_memoryClear_clicked();

    void on_backspace_clicked();

    void on_clear_clicked();

    void on_clearall_clicked();

    void on_dot_clicked();

    void on_negative_clicked();

private:
    Ui::Laskin *ui;
    Calculator *calculator;
};
#endif // LASKIN_H
