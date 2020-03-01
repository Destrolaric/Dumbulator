#include "pshculator.h"
#include "ui_pshculator.h"

Pshculator::Pshculator(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::Pshculator)
{
    ui->setupUi(this);
    ui->label->setText("");
    //Connects digits to function//
    connect(ui->numZero, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numTwo, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numThree, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numFour, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numFive, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numSix, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numSeven, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numEight, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numNine, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numOne, SIGNAL(clicked()), this, SLOT(digits()));
    //connects button to changeSymbol function//
    connect(ui->PlusMinus, SIGNAL(clicked()), this, SLOT(changeSymbol()));
    //Connects buttons in ui to operations function
    connect(ui->numPlus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->Minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->numDivide, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->numMultiply, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->numToDegree, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->procentof, SIGNAL(clicked()), this, SLOT(operations()));
}
Pshculator::~Pshculator()
{
    delete ui;
}
/**
 * @brief  on = clicked
 * 
 */
void Pshculator::on_solveEquation_clicked() //kinda different from other operations because makes all future computations work with new data
{
    if (symbolchange)
    {
        QPushButton *button = (QPushButton *)sender();
        switch (operation)
        {
        case ' ':
            operation = (button->text()).toStdString()[0];
            value = (ui->label->text()).toDouble();
            ui->label->setText("");
            symbolchange = 0;
            return;
        case '*':
            if (symbolchange)
            {
                double labelnumber = (ui->label->text()).toDouble();
                labelnumber = math.multiplyValue(value, labelnumber);
                QString newLabel = QString::number(labelnumber, 'g', 100);
                ui->label->setText(newLabel);
                value = 0;
                symbolchange = 0;
                operation = ' ';
                return;
            }
            else
            {
                operation = (button->text()).toStdString()[0];

                return;
            }
        case '-':
            if (symbolchange)
            {
                double labelnumber = (ui->label->text()).toDouble();
                labelnumber = math.minusValue(value, labelnumber);
                QString newLabel = QString::number(labelnumber, 'g', 100);
                ui->label->setText(newLabel);
                value = 0;
                symbolchange = 0;
                operation = ' ';
                return;
            }
            else
            {
                operation = (button->text()).toStdString()[0];

                return;
            }
        case '/':
            if (symbolchange)
            {
                double labelnumber = (ui->label->text()).toDouble();
                labelnumber = math.divideValue(value, labelnumber);
                QString newLabel = QString::number(labelnumber, 'g', 100);
                ui->label->setText(newLabel);
                value = 0;

                symbolchange = 0;
                operation = ' ';
                return;
            }
            else
            {
                operation = (button->text()).toStdString()[0];
                return;
            }
        case '+':
            if (symbolchange)
            {
                double labelnumber = (ui->label->text()).toDouble();
                labelnumber = math.plusValue(value, labelnumber);
                QString newLabel = QString::number(labelnumber, 'g', 100);
                ui->label->setText(newLabel);
                value = 0;
                symbolchange = 0;
                operation = ' ';
                return;
            }
            else
            {
                operation = (button->text()).toStdString()[0];
            }
        case '^':
            if (symbolchange)
            {
                double labelnumber = (ui->label->text()).toDouble();
                labelnumber = math.performExponentiation(value, labelnumber);
                QString newLabel = QString::number(labelnumber, 'g', 100);
                ui->label->setText(newLabel);
                value = 0;

                symbolchange = 0;
                operation = ' ';
                return;
            }
            else
            {

                operation = (button->text()).toStdString()[0];
                return;
            }
        case '%':
            if (symbolchange)
            {
                double labelnumber = (ui->label->text()).toDouble();
                labelnumber = math.procentOfValue(value, labelnumber);
                QString newLabel = QString::number(labelnumber, 'g', 100);
                ui->label->setText(newLabel);
                value = 0;

                symbolchange = 0;
                operation = ' ';
                return;
            }
            else
            {
                operation = (button->text()).toStdString()[0];
                return;
            }
        }
    }
}
/**
 * @brief 
 * 
 */
void Pshculator::digits()
{
    QPushButton *button = (QPushButton *)sender();
    if (symbolchange)
    {
        if ((ui->label->text()).toStdString() == "0")
        {
            double labelnumber = (button->text()).toDouble();
            QString newLabel = QString::number(labelnumber, 'g', 100);
            ui->label->setText(newLabel);
            symbolchange = 1;
        }
        else
        {
            std::string labelnumber = (ui->label->text() + button->text()).toStdString();
            QString newLabel = QString::fromStdString(labelnumber);
            ui->label->setText(newLabel);
        }
    }
    else
    {
        double labelnumber = (button->text()).toDouble();
        QString newLabel = QString::number(labelnumber, 'g', 100);
        ui->label->setText(newLabel);
        symbolchange = 1;
    }
}
/**
 * @brief 
 * 
 */
void Pshculator::changeSymbol()
{
    if (operation != ' ')
    {
        operations();
    }
    double labelnumber = (ui->label->text()).toDouble();
    labelnumber = -labelnumber;
    QString newLabel = QString::number(labelnumber, 'g', 100);
    ui->label->setText(newLabel);
}
/**
 * @brief 
 * 
 */
void Pshculator::operations()
{
    QPushButton *button = (QPushButton *)sender();
    switch (operation)
    {
    case ' ':
        operation = (button->text()).toStdString()[0];
        value = (ui->label->text()).toDouble();
        ui->label->setText("");
        symbolchange = 0;
        return;
    case '*':
        if (symbolchange)
        {
            double labelnumber = (ui->label->text()).toDouble();
            labelnumber = math.multiplyValue(value, labelnumber);
            QString newLabel = QString::number(labelnumber, 'g', 100);
            ui->label->setText(newLabel);
            value = labelnumber;
            symbolchange = 0;
            operation = (button->text()).toStdString()[0];
            return;
        }
        else
        {
            operation = (button->text()).toStdString()[0];
            return;
        }
    case '-':
        if (symbolchange)
        {
            double labelnumber = (ui->label->text()).toDouble();
            labelnumber = math.minusValue(value, labelnumber);
            QString newLabel = QString::number(labelnumber, 'g', 100);
            ui->label->setText(newLabel);
            value = labelnumber;
            symbolchange = 0;
            operation = (button->text()).toStdString()[0];
            return;
        }
        else
        {
            operation = (button->text()).toStdString()[0];

            return;
        }
    case '/':
        if (symbolchange)
        {
            double labelnumber = (ui->label->text()).toDouble();
            labelnumber = math.divideValue(value, labelnumber);
            QString newLabel = QString::number(labelnumber, 'g', 100);
            ui->label->setText(newLabel);
            value = labelnumber;
            symbolchange = 0;
            operation = (button->text()).toStdString()[0];
            return;
        }
        else
        {
            operation = (button->text()).toStdString()[0];
            return;
        }
    case '+':
        if (symbolchange)
        {
            double labelnumber = (ui->label->text()).toDouble();
            labelnumber = math.plusValue(value, labelnumber);
            QString newLabel = QString::number(labelnumber, 'g', 100);
            ui->label->setText(newLabel);
            value = labelnumber;
            symbolchange = 0;
            operation = (button->text()).toStdString()[0];
            return;
        }
        else
        {
            operation = (button->text()).toStdString()[0];
            return;
        }
    case '^':
        if (symbolchange)
        {
            double labelnumber = (ui->label->text()).toDouble();
            labelnumber = math.performExponentiation(value, labelnumber);
            QString newLabel = QString::number(labelnumber, 'g', 100);
            ui->label->setText(newLabel);
            value = labelnumber;
            symbolchange = 0;
            operation = (button->text()).toStdString()[0];
            return;
        }
        else
        {
            operation = (button->text()).toStdString()[0];
            return;
        }
    case '%':
        if (symbolchange)
        {
            double labelnumber = (ui->label->text()).toDouble();
            labelnumber = math.procentOfValue(value, labelnumber);
            QString newLabel = QString::number(labelnumber, 'g', 100);
            ui->label->setText(newLabel);
            value = labelnumber;

            symbolchange = 0;
            operation = (button->text()).toStdString()[0];
            return;
        }
        else
        {
            operation = (button->text()).toStdString()[0];
            return;
        }
    }
}
/**
 * @brief 
 * 
 */
void Pshculator::on_Dot_clicked()
{
    QPushButton *button = (QPushButton *)sender();
    if (symbolchange)
    {
        if ((ui->label->text()).toStdString() != "" && !(ui->label->text().contains('.')))
        {
            std::string labelnumber = (ui->label->text() + button->text()).toStdString();
            QString newLabel = QString::fromStdString(labelnumber);
            ui->label->setText(newLabel);
        }
    }
}
/**
 * @brief 
 * 
 */

void Pshculator::on_Clear_clicked()
{
    ui->label->setText("");
}
/**
 * @brief 
 * 
 */
void Pshculator::on_MRC_clicked()
{
    value = 0;
    operation = ' ';
    ui->label->setText("");
}
/**
 * @brief 
 * 
 */
void Pshculator::on_x_clicked()
{
    if (operation != ' ')
    {
        operations();
    }
    double labelnumber = (ui->label->text()).toDouble();
    labelnumber = math.sqrtValue(labelnumber);
    QString newLabel = QString::number(labelnumber, 'g', 100);
    ui->label->setText(newLabel);
    symbolchange = 0;
    operation = ' ';
}
/**
 * @brief 
 * 
 */
void Pshculator::on_numFactorial_clicked()
{
    if (operation != ' ')
    {
        operations();
    }
    double labelnumber = (ui->label->text()).toDouble();
    labelnumber = math.factorialOfValue(labelnumber);
    QString newLabel = QString::number(labelnumber, 'g', 100);
    ui->label->setText(newLabel);
    symbolchange = 0;
    operation = ' ';
}
/**
 * @brief 
 * 
 */
void Pshculator::on_numSqrt_clicked()
{
    if (operation != ' ')
    {
        operations();
    }
    double labelnumber = (ui->label->text()).toDouble();
    labelnumber = math.squareValue(labelnumber);
    QString newLabel = QString::number(labelnumber, 'g', 100);
    ui->label->setText(newLabel);
    symbolchange = 0;
    operation = ' ';
}

void Pshculator::on_pushButton_clicked()
{
    if (operation != ' ')
    {
        operations();
    }
    savedvalue=(ui->label->text()).toDouble();
    operation = ' ';
}

void Pshculator::on_mDevide_clicked()
{
    if (operation != ' '){
        operations();
    }
    double labelnumber = (ui->label->text()).toDouble();
    labelnumber/=savedvalue;
    QString newLabel = QString::number(labelnumber, 'g',100);
    ui->label->setText(newLabel);
    operation=' ';
}
