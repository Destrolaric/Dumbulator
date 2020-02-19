#include "mathoperations.h"
#include <cmath>

/**
 * @brief 
 * 
 * @param first 
 * @param second 
 * @return double 
 */
double MathOperations::minusValue(double first, double second)
{
    return first - second;
}
/**
 * @brief 
 * 
 * @param val 
 * @return double 
 */
double MathOperations::squareValue(double val)
{
    return sqrt(val);
}
/**
 * @brief 
 * 
 * @param val 
 * @return double 
 */
double MathOperations::reverseValue(double val)
{
    return -val;
}
/**
 * @brief 
 * 
 * @param val 
 * @return double 
 */
double MathOperations::factorialOfValue(double val)
{
    double result = 1;
    for (int i = 1; i <= val; i++)
    {
        result *= i;
    }
    return result;
}
/**
 * @brief 
 * 
 * @param val 
 * @return double 
 */
double MathOperations::sqrtValue(double val)
{
    return pow(val, 2);
}
/**
 * @brief 
 * 
 * @param first 
 * @param second 
 * @return double 
 */
double MathOperations::multiplyValue(double first, double second)
{
    return first * second;
}
/**
 * @brief 
 * 
 * @param first 
 * @param second 
 * @return double 
 */
double MathOperations::performExponentiation(double first, double second)
{
    return pow(first, second);
}
/**
 * @brief 
 * 
 * @param first 
 * @param second 
 * @return double 
 */
double MathOperations::divideValue(double first, double second)
{
    return first / second;
}
/**
 * @brief 
 * 
 * @param first 
 * @param second 
 * @return double 
 */
double MathOperations::plusValue(double first, double second)
{
    return first + second;
}
/**
 * @brief 
 * 
 * @param first 
 * @param second 
 * @return double 
 */
double MathOperations::procentOfValue(double first, double second)
{
    return second / 100 * first;
}
