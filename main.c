#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_fraction.h"

int main() {
    int n1, d1, n2, d2;
    char op;

    scanf("%d/%d %c %d/%d", &n1, &d1, &op, &n2, &d2);

    Fraction a = make_fraction(n1, d1);
    Fraction b = make_fraction(n2, d2);
    Fraction result;

    switch (op) {
    case '+': result = add(a, b); break;
    case '-': result = sub(a, b); break;
    case '*': result = mul(a, b); break;
    case '/': result = divi(a, b); break;
    default:
        printf("Invalid operator\n");
        return 1;
    }

    print_fraction(result);

    return 0;
}