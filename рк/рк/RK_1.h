#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

struct Fraction {
    int _numerator;   // числитель
    int _denominator; // знаменатель

    Fraction();
    Fraction(int numerator, int denominator);
};

 
int gcd(int a, int b);


int fracReduction(Fraction& frac);


Fraction sum(const Fraction& fr1, const Fraction& fr2);  
Fraction sub(const Fraction& fr1, const Fraction& fr2); 
Fraction mul(const Fraction& fr1, const Fraction& fr2); 
Fraction div(const Fraction& fr1, const Fraction& fr2);  


std::ostream& operator<<(std::ostream& os, const Fraction& frac);

#endif // FRACTION_H
