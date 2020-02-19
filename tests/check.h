#ifndef CHECK_H
#define CHECK_H
#include <QtTest>
#include <QtGui>
#include <QCoreApplication>

class check : public QObject
{
    Q_OBJECT

public:
    check();
    ~check();

private slots:
//    void initTestCase();
//    void cleanupTestCase();
//    void test_case1();
    void mathFunctionTestSum();
    void mathFunctionTestFactorial();
    //void mathFunctionTestProcent();
    //void mathFunctionTestMinus();
    //void guiTest();
};
#endif // CHECK_H
