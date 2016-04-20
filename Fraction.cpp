//
//  Fraction.cpp
//  25.03.2016
//
//  Created by Evgeny on 25.03.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#include <iostream>
#include "Fraction.hpp"

const int N = 100;

Fraction:: Fraction(int a, int b)
{
    this -> n = a;
    this -> d = b;
    Reduce();
}
int Fraction:: GetN() const
{
    return n;
}
int Fraction:: GetD() const
{
    return d;
}
void Fraction:: SetN(int n)
{
    this -> n = n;
}
void Fraction:: SetD(int d)
{
    this -> d = d;
}
Fraction Fraction:: operator + (const Fraction& other)
{
    return Fraction(n*other.d + d*other.n, d*other.d);
}
Fraction Fraction:: operator * (const Fraction& other)
{
    return Fraction(n*other.n, d*other.d);
}
bool Fraction:: operator < (const Fraction& other)
{
    return n*d < d*other.n;
}
bool Fraction:: operator == (const Fraction& other)
{
    return n*d == d*other.n;
}
void Fraction:: Reduce()
{
    for (int i = 2; i < n; )
    {
        if ((n % i == 0) && (d%i == 0))
        {
            n /= i;
            d /= i;
        }
        else i++;
    }
}
std:: ostream& operator << (std:: ostream& out, const Fraction& f)
{
    int n = f.GetN();
    int d = f.GetD();
    if (d == 1)
        out << n;
    else
    {
        if (n > d)
        {
            out << n / d << ' ';
            n = n % d;
        }
        out << n << '/' << d;
    }
    return out;
}
std:: istream& operator >> (std:: istream& in, Fraction& f)
{
    int a, b;
    char buffer[N];
    in >> buffer;
    sscanf(buffer, "%d/%d", &a, &b);
    f = Fraction(a, b);
    return in;
}
