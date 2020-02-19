#include"check.h"
#include "pshculator.h"
#include "mathoperations.h"
#include <QtTest>

check::check()
{

}

check::~check()
{

}
//void check::initTestCase()
//{

//}

//void check::cleanupTestCase()
//{
//    Pshculator data;
//}

//void check::test_case1()
//{

//}
void check::mathFunctionTestSum(){
    MathOperations data;
    QCOMPARE(data.plusValue(10,10),20);
    QCOMPARE(data.plusValue(10.5,10.5),21);
}
void check::mathFunctionTestFactorial(){
    MathOperations data;
    QCOMPARE(data.factorialOfValue(5),1*2*3*4*5);
}

QTEST_MAIN(check)
#include "tst_check.moc"
