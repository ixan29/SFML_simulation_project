#include "Complex.h"
#include <cmath>

float Complex::lengthSq() const {
    return r*r+i*i;
}

float Complex::length() const {
    return sqrt(lengthSq());   
}

Complex Complex::conjugate() const {
    return Complex(r, -i);
}

Complex operator+(const Complex& first, const Complex& second)
{
    return Complex(first.r + second.r, first.i + second.i);
}

Complex operator-(const Complex& first, const Complex& second)
{
    return Complex(first.r - second.r, first.i - second.i);
}

Complex operator*(const Complex& first, const Complex& second)
{
    return Complex (
        first.r * second.r - first.i * second.i,
        first.i * second.r + first.r * second.i
    );
}

Complex operator/(const Complex& first, const Complex& second)
{
    return first * second.conjugate() * (1/second.lengthSq());
}

Complex eulerComplexRotation(float angle)
{
    return Complex(cos(angle), sin(angle));
}

Complex power(float n, const Complex& c)
{
    return eulerComplexRotation(c.i * log(n)) * powf(n,c.r);
}