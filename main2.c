#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void simplify(int* num, int* den) {
    int g = gcd(*num, *den);
    *num /= g;
    *den /= g;
}

void add(int a_num, int a_den, int b_num, int b_den, int* r_num, int* r_den) {
    *r_num = a_num * b_den + b_num * a_den;
    *r_den = a_den * b_den;
    simplify(r_num, r_den);
}

void mul(int a_num, int a_den, int b_num, int b_den, int* r_num, int* r_den) {
    *r_num = a_num * b_num;
    *r_den = a_den * b_den;
    simplify(r_num, r_den);
}

void parse(char* str, int* num, int* den) {
    sscanf(str, "%d/%d", num, den);
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("Usage: program width height\n");
        return 1;
    }

    int w_num, w_den;
    int h_num, h_den;

    parse(argv[1], &w_num, &w_den);
    parse(argv[2], &h_num, &h_den);

    int sum_num, sum_den;
    add(w_num, w_den, h_num, h_den, &sum_num, &sum_den);

    int peri_num = 2 * sum_num;
    int peri_den = sum_den;
    simplify(&peri_num, &peri_den);

    int area_num, area_den;
    mul(w_num, w_den, h_num, h_den, &area_num, &area_den);

    printf("Perimeter: %d/%d, Area: %d/%d\n",
        peri_num, peri_den, area_num, area_den);

    return 0;
}