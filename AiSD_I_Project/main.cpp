#include <iostream>
#include <cassert>
#include "poly.h"

void test_int() {
    int coef1[] = {3, 8, 3};
    int coef2[] = {7, 0, 2, 6};

    Polynomial<int> p1(coef1, 2);
    Polynomial<int> p2(coef2, 3);

    std::cout << std::endl;

    std::cout << "W1(x) = ";
    p1.display();

    std::cout << "W2(x) = ";
    p2.display();

    std::cout << std::endl;

    Polynomial<int> p_sum = p1 + p2;

    int result1[] = {10, 8, 5, 6};
    Polynomial<int> add_result(result1, 3);
    assert(add_result == p_sum);

    std::cout << "W1(x) + W2(x) = ";
    p_sum.display();

    Polynomial<int> p_sub = p1 - p2;

    int result2[] = {-4, 8, 1, -6};
    Polynomial<int> diff_result(result2, 3);
    assert(diff_result == p_sub);

    std::cout << "W1(x) - W2(x) = ";
    p_sub.display();

    Polynomial<int> p_mul = p1 * p2;

    int result3[] = {21, 56, 27, 34, 54, 18};
    Polynomial<int> mul_result(result3, 5);
    assert(mul_result == p_mul);

    std::cout << "W1(x) * W2(x) = ";
    p_mul.display();

    std::cout << std::endl;

    int h1 = p1.horner(7);
    int result4 = 206;
    assert(result4 == h1);
    std::cout << "Wartosc wielomianu W1(x) dla x = 7: " << h1 << "\n";

    int h2 = p2.horner(4);
    int result5 = 423;
    assert(result5 == h2);
    std::cout << "Wartosc wielomianu W2(x) dla x = 5: " << h2 << "\n";

    std::cout << std::endl;
}

int main() {
    test_int();
}