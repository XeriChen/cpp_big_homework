#include "FractionCalculator.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;

static vector<std::pair<Fraction, char>> splitFractions1(const string &input)
{
    vector<std::pair<Fraction, char>> fractions;
    std::istringstream ss(input);
    string fractionStr;
    char op = '+';

    while (getline(ss, fractionStr, '+')) {
        std::istringstream minusStream(fractionStr);
        string minusFractionStr;

        while (std::getline(minusStream, minusFractionStr, '-')) {
            std::istringstream multiplyStream(minusFractionStr);
            string multiplyFractionStr;

            while (getline(multiplyStream, multiplyFractionStr, '*')) {
                std::istringstream fs(multiplyFractionStr);
                Fraction fraction;
                fs >> fraction;
                fractions.push_back({fraction, op});
                op = '*';
            }

            op = '-';
        }

        op = '+';
    }

    return fractions;
}

static vector<Fraction> splitFractions(const string &input, const char &delim = ',')
{
    vector<Fraction> fractions;
    stringstream ss(input);
    string fractionStr;

    while (getline(ss, fractionStr, delim)) {
        stringstream fs(fractionStr);
        static Fraction fraction;
        fs >> fraction;
        fractions.push_back(fraction);
    }

    return fractions;
}

static Fraction superadd2(const string &input)
{
    int a, b, c, d;
    char x, y, z;
    cin >> a >> x >> b >> y >> c >> z >> d;
    // scanf("%d/%d%c%d/%d", &a, &b, &x, &c, &d);
    Fraction f1(a, b), f2(c, d);
    if (y == '+')
        return f1 + f2;
    else if (y == '-')
        return f1 - f2;
    else if (y == '*')
        return f1 * f2;
    else
        return f1 / f2;
}

static Fraction superadd(const string &input)
{
    auto fractions = splitFractions1(input);
    Fraction sum(0, 1);

    for (const auto &pair : fractions) {
        if (pair.second == '+') {
            sum = sum + pair.first;
        } else if (pair.second == '*') {
            sum = sum * pair.first;
        } else {
            sum = sum - pair.first;
        }
    }
    sum.RdcFrc();
    return sum;
}

void FractionCalculator::calculateFractions()
{
    string input;
    do {
        cout << "输入分数计算式如\"1/2+1/2*3/1-3/8\"不支持除法 （'#'返回主菜单）：";
        std::getline(cin, input);
        if (input == "#")
            break;

        try {
            Fraction result = superadd(input);
            cout << "结果：" << result << "\n";
        } catch (const std::invalid_argument &e) {
            cout << "输入错误：" << e.what() << "\n";
        }
    } while (true);
}

void FractionCalculator::sortFractions()
{
    string input;
    do {
        cout << "输入一组分数（以逗号分隔，用<结尾表示从小到大排序，用>结尾表示从大到小排序'#'返回主菜单）：";
        std::getline(cin, input);
        char check = input.end()[-1];
        if (input == "#")
            break;

        try {
            vector<Fraction> fractions = splitFractions(input, ',');
            sortFraction(fractions.data(), fractions.size(), check == '<');
            std::sort(fractions.begin(), fractions.end());
            cout << "排序结果：";
            for (const Fraction &fraction : fractions) {
                cout << fraction << " ";
            }
            cout << "\n";
        } catch (const std::invalid_argument &e) {
            cout << "输入错误：" << e.what() << "\n";
        }
    } while (true);
}

void FractionCalculator::convertFractionToDecimal()
{
    string input;
    do {
        cout << "输入一个分数（'#'返回主菜单）：";
        std::getline(cin, input);
        if (input == "#")
            break;

        try {
            Fraction fraction;
            std::istringstream iss(input);
            iss >> fraction;
            double decimal = static_cast<double>(fraction.getNumer()) / fraction.getDeno();
            cout << "转换结果：" << std::fixed << std::setprecision(2) << decimal << "\n";
        } catch (const std::invalid_argument &e) {
            cout << "输入错误：" << e.what() << "\n";
        }
    } while (true);
}
