#include <stdio.h>
#include "my_fraction.h"

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

Fraction simplify(Fraction f) {
    int g = gcd(f.num, f.den);
    f.num /= g;
    f.den /= g;
    return f;
}

Fraction make_fraction(int num, int den) {
    Fraction f;
    f.num = num;
    f.den = den;
    return simplify(f);
}

Fraction add(Fraction a, Fraction b) {
    return simplify((Fraction) {
        a.num* b.den + b.num * a.den,
            a.den* b.den
    });
}

Fraction sub(Fraction a, Fraction b) {
    return simplify((Fraction) {
        a.num* b.den - b.num * a.den,
            a.den* b.den
    });
}

Fraction mul(Fraction a, Fraction b) {
    return simplify((Fraction) {
        a.num* b.num,
            a.den* b.den
    });
}

Fraction divi(Fraction a, Fraction b) {
    return simplify((Fraction) {
        a.num* b.den,
            a.den* b.num
    });
}

void print_fraction(Fraction f) {
    if (f.den == 1)
        printf("%d\n", f.num);
    else
        printf("%d/%d\n", f.num, f.den);
}