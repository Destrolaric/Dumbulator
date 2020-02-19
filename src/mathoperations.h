#include <functional>
#ifndef MATHOPERATIONS_H
#define MATHOPERATIONS_H
/**
 * @brief  Basic Mathematic operations
 * 
 * 
 */
class MathOperations
{
public:
/**
 * @brief 
 * 
 * @param first 
 * @param second 
 * @return double 
 */
    static double minusValue(double first, double second);
    static double plusValue(double first, double second);
    static double reverseValue(double val);
    static double squareValue(double val);
    static double sqrtValue(double val);
    static double divideValue(double first, double second);
    static double multiplyValue(double first, double second);
    static double procentOfValue(double first, double second);
    static double performExponentiation(double first, double second);
    static double factorialOfValue(double val);
};

#endif // MATHOPERATIONS_H
