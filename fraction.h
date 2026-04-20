#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

struct Fraction {
    int _numerator;   // числитель
    int _denominator; // знаменатель 

    Fraction();
    Fraction(int numerator, int denominator);
};

int fracReduction(Fraction& frac);

#endif // FRACTION_H
