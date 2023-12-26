#include "Fraction.hpp"
#include "FractionCalculator.hpp"
#include <limits>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    FractionCalculator calculator;
    int choice;
    do {
        cout << "1. 分数计算\n2. 分数排序\n3. 分数转小数\n4. 退出\n选择功能：";
        cin >> choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            calculator.calculateFractions();
            break;
        case 2:
            calculator.sortFractions();
            break;
        case 3:
            calculator.convertFractionToDecimal();
            break;
        case 4:
            cout << "退出程序\n";
            break;
        default:
            cout << "无效的选择\n";
            break;
        }
    } while (choice != 4);
    return 0;
}