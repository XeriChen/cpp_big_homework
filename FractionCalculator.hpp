#ifndef FRACTION_CALCULATOR_H
#define FRACTION_CALCULATOR_H

#include "Fraction.hpp" //  Fraction 类定义在这个头文件中
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

class FractionCalculator
{
public:
    void calculateFractions();
    void sortFractions();
    void convertFractionToDecimal();
};

#endif // FRACTION_CALCULATOR_H