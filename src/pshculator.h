#ifndef PSHCULATOR_H
#define PSHCULATOR_H

#include <QMainWindow>
#include <mathoperations.h>
namespace Ui
{
class Pshculator;
}

class Pshculator : public QMainWindow
{
    Q_OBJECT
private:
    MathOperations math;
    char operation = ' ';
    bool symbolchange = 1;
    double value = 0;
    double savedvalue;

public:
    explicit Pshculator(QWidget *parent = nullptr);
    ~Pshculator();
private slots:
    void digits();
    void on_solveEquation_clicked();
    void changeSymbol();
    void on_Dot_clicked();
    void operations();
    void on_Clear_clicked();
    void on_MRC_clicked();
    void on_x_clicked();
    void on_numFactorial_clicked();
    void on_numSqrt_clicked();
    void on_pushButton_clicked();

    void on_mDevide_clicked();

private:
    Ui::Pshculator *ui;
};

#endif // PSHCULATOR_H
