// Fraction.cpp
#include "Fraction.hpp"

Fraction::Fraction()
{
    numer = 0;
    deno = 1;
}

Fraction::Fraction(int n, int d)
{
    numer = n;
    deno = d;
}

Fraction::Fraction(const Fraction &f)
{
    numer = f.numer;
    deno = f.deno;
}

void Fraction::setFraction(int n, int d)
{
    numer = n;
    deno = d;
}

int Fraction::getNumer()
{
    return numer;
}

int Fraction::getDeno()
{
    return deno;
}

static int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

#include <algorithm>
void Fraction::RdcFrc()
{
    int gcd = 1;
    gcd = ::gcd(std::min(numer, deno), std::max(numer, deno));
    numer /= gcd;
    deno /= gcd;
}

Fraction operator+(const Fraction &frac1, const Fraction &frac2)
{
    int n = frac1.numer * frac2.deno + frac2.numer * frac1.deno;
    int d = frac1.deno * frac2.deno;
    Fraction result(n, d);
    result.RdcFrc();
    return result;
}

Fraction operator-(const Fraction &frac1, const Fraction &frac2)
{
    int n = frac1.numer * frac2.deno - frac2.numer * frac1.deno;
    int d = frac1.deno * frac2.deno;
    Fraction result(n, d);
    result.RdcFrc();
    return result;
}

Fraction operator*(const Fraction &frac1, const Fraction &frac2)
{
    int n = frac1.numer * frac2.numer;
    int d = frac1.deno * frac2.deno;
    Fraction result(n, d);
    result.RdcFrc();
    return result;
}

Fraction operator/(const Fraction &frac1, const Fraction &frac2)
{
    int n = frac1.numer * frac2.deno;
    int d = frac1.deno * frac2.numer;
    Fraction result(n, d);
    result.RdcFrc();
    return result;
}

bool operator==(Fraction frac1, Fraction frac2)
{
    frac1.RdcFrc();
    frac2.RdcFrc();
    return (frac1.numer == frac2.numer && frac1.deno == frac2.deno);
}

bool operator>(const Fraction &frac1, const Fraction &frac2)
{
    double val1 = static_cast<double>(frac1.numer) / frac1.deno;
    double val2 = static_cast<double>(frac2.numer) / frac2.deno;
    return (val1 > val2);
}

bool operator<(const Fraction &frac1, const Fraction &frac2)
{
    double val1 = static_cast<double>(frac1.numer) / frac1.deno;
    double val2 = static_cast<double>(frac2.numer) / frac2.deno;
    return (val1 < val2);
}

ostream &operator<<(ostream &out, const Fraction &frac)
{
    out << frac.numer << "/" << frac.deno;
    return out;
}

istream &operator>>(istream &in, Fraction &frac)
{
    char slash;
    in >> frac.numer >> slash >> frac.deno;
    if (slash != '/')
        throw std::invalid_argument("分数格式错误");
    if (frac.deno == 0)
        throw std::invalid_argument("分数格式错误");

    if (in.fail())
        throw std::invalid_argument("输入错误");

    return in;
}

#include <algorithm>

void sortFraction(Fraction arr[], int size, bool ascending)
{
    if (ascending) {
        std::sort(arr, arr + size);
    } else {
        std::sort(arr, arr + size, [](const Fraction &frac1, const Fraction &frac2) {
            return frac1 > frac2;
        });
    }
}
