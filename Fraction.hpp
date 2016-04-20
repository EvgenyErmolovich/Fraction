//
//  Fraction.hpp
//  25.03.2016
//
//  Created by Evgeny on 25.03.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#ifndef Fraction_hpp
#define Fraction_hpp

#include <stdio.h>

class Fraction
{
public:
    Fraction(int = 1, int = 1);
    int GetN() const;
    int GetD() const;
    void SetN(int n);
    void SetD(int d);
    Fraction operator + (const Fraction&);
    Fraction operator * (const Fraction& f2);
    bool operator < (const Fraction& f2);
    bool operator == (const Fraction& f2);
private:
    int n, d;
    void Reduce();
};
std:: ostream& operator << (std:: ostream& out, const Fraction& f);
std:: istream& operator >> (std:: istream& in, Fraction& f);
#endif /* Fraction_hpp */