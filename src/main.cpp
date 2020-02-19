#include "pshculator.h"
#include <QApplication>
/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pshculator w;
    w.show();
    return a.exec();
}
