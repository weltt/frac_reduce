// ass2.hpp : ass2
// By: Tyson C. Welt
// Date: 6th Feb 2015
// Description:
//  Main file in the fraction reduction/ operator overloading assignment.
// Input:
//  Takes user input for fraction and 2 operand calculations.
// Output:
//  Output the results of fraction reduction and 2 operand calculations.

//start
#ifndef ASS2_HPP
#define ASS2_HPP
#include <iostream>

// Class: The class to hold the values of the numberator(a) and denominator(b)
class frac {
  public:
    // Constructors
    frac();
    frac(int a);
    frac(int a, int b);

    // Accessors 
    int top () { return a; }
    int bottom () { return b; }
    // Reduce: gcd() acccesor and negitive handler
    void reduce();
  
  private:
    int a;
    int b;
    int gcd(int n, int m);
};

// Declare the overload functions right here.
frac operator+(frac &l, frac &r);
frac operator/(frac &l, frac &r);
frac operator*(frac &l, frac &r);
frac operator-(frac &l, frac &r);
frac operator-(frac &negfrac);
std::ostream& operator<<(std::ostream &outs, frac &outy);

#endif
