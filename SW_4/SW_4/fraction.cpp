#include "Fraction.h"
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
	// 0 знаменатель  и 0\0
    if (frac._denominator == 0) {
        return -1;
    }

    // 0 числитель 
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