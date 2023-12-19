// Fraction.hpp
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using std::istream;
using std::ostream;

class Fraction
{
    friend Fraction operator+(const Fraction &frac1, const Fraction &frac2);
    friend Fraction operator-(const Fraction &frac1, const Fraction &frac2);
    friend Fraction operator*(const Fraction &frac1, const Fraction &frac2);
    friend Fraction operator/(const Fraction &frac1, const Fraction &frac2);
    friend bool operator==(Fraction frac1, Fraction frac2);
    friend bool operator>(const Fraction &frac1, const Fraction &frac2);
    friend bool operator<(const Fraction &frac1, const Fraction &frac2);
    friend ostream &operator<<(ostream &out, const Fraction &frac);
    friend istream &operator>>(istream &in, Fraction &frac);
    friend void sortFraction(Fraction arr[], int size, bool ascending = true);

public:
    Fraction();
    Fraction(int n, int d);
    Fraction(const Fraction &f);
    void setFraction(int n, int d);
    int getNumer();
    int getDeno();
    void RdcFrc();

private:
    int numer;
    int deno;
};

#endif