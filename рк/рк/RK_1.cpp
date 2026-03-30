#include "RK_1.h"
#include <cmath>
#include <cstdlib>


Fraction::Fraction() {
    _numerator = 0;
    _denominator = 1;
}


Fraction::Fraction(int numerator, int denominator) {
    _numerator = numerator;
    _denominator = denominator;
}

int gcd(int a, int b) {
    a = std::abs(a); 
    b = std::abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int fracReduction(Fraction& frac) {
    if (frac._denominator == 0) {
        return -1;
    }

    if (frac._numerator == 0) {
        frac._denominator = 1;
        return 3;
    }

    int divisor = gcd(frac._numerator, frac._denominator);

    frac._numerator /= divisor;
    frac._denominator /= divisor;

    if (frac._denominator < 0) {
        frac._numerator = -frac._numerator;
        frac._denominator = -frac._denominator;
    }

    return 0;
}

Fraction sum(const Fraction& fr1, const Fraction& fr2) {
    Fraction result;

    // a/b + c/d = (a*d + c*b) / (b*d)
    result._numerator = fr1._numerator * fr2._denominator + fr2._numerator * fr1._denominator;
    result._denominator = fr1._denominator * fr2._denominator;

    fracReduction(result);
    return result;
}

Fraction sub(const Fraction& fr1, const Fraction& fr2) {
    Fraction result;

    // a/b - c/d = (a*d - c*b) / (b*d)
    result._numerator = fr1._numerator * fr2._denominator - fr2._numerator * fr1._denominator;
    result._denominator = fr1._denominator * fr2._denominator;

    fracReduction(result);
    return result;
}

Fraction mul(const Fraction& fr1, const Fraction& fr2) {
    Fraction result;

    // a/b * c/d = (a*c) / (b*d)
    result._numerator = fr1._numerator * fr2._numerator;
    result._denominator = fr1._denominator * fr2._denominator;

    fracReduction(result);
    return result;
}

Fraction div(const Fraction& fr1, const Fraction& fr2) {
    Fraction result;

    // a/b : c/d = a/b * d/c = (a*d) / (b*c)
    result._numerator = fr1._numerator * fr2._denominator;
    result._denominator = fr1._denominator * fr2._numerator;

    fracReduction(result);
    return result;
}

std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac._numerator << " / " << frac._denominator;
    return os;
}