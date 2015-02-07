// ass2.cpp : ass2
// By: Tyson C. Welt
// Date: 6th Feb 2015
// Description:
//  Main file in the fraction reduction/ operator overloading assignment.
// Input:
//  Takes user input for fraction and 2 operand calculations.
// Output:
//  Output the results of fraction reduction and 2 operand calculations.

// start
#include "ass2.hpp"
#include <math.h>
#include <cstdlib>

using namespace std;

// Constructors for 0 to 3 variables
frac::frac() : a(0), b(1) {}
frac::frac(int a) : a(a), b(1) {}
frac::frac(int a, int b) : a(a), b(b) {
  reduce();
}

// Input: Numerator and Denominator
// Output: Greatest Common Divisor
int frac::gcd(int a, int b) {
  if((a > 0) && b > 0) {
    while (a != b) {
      if (a < b) {
        b = b - a;
      } else {
        a = a - b;
      }
    }
  }
  return a;
}

// Input: Numerator and Denominator
// Output: Ruduce fraction by comparing negatives and then calling GCD 
void frac::reduce() {
  bool neg=0;
  if ((a < 0 || b < 0) && !(a < 0 && b < 0))  {
    a=sqrt(a*a);
    b=sqrt(b*b);
    neg=1;
  }
 
  if (b == 0) { std::cout << "DIVIDE BY ZERO!!!!" << endl; exit(1); }
  int gcdummy = 1;
  gcdummy = gcd(a, b);
  cout << gcdummy << "gcd" << endl;
  a = a/gcdummy;
  b = b/gcdummy;
  if (neg == 1) { a = -a;}
}

// Input: Left and right fraction Class and overload the + operator 
// Output: The two fractions added up
frac operator+(frac& l, frac& r) {
  frac add(
      l.top()*r.bottom()+r.top()*l.bottom(),
      l.bottom()*r.bottom()
      );
  return add;
}

// Input: Left and right fraction Class and overload the - operator 
// Output: The two fractions difference
frac operator-(frac &l, frac &r) {
  frac subt(
      l.top()*r.bottom()-r.top()*l.bottom(),
      l.bottom()*r.bottom()
      );
  return subt;
}

// Input: Just a negative frac class
// Output: Make sure the top is negative and not the bottom.
frac operator-(frac &a) {
  frac neg(-a.top(), a.bottom());
  return neg;
}

// Input: Two frac classes
// Output: The product of the two classes
frac operator*(frac& l, frac& r) {
  frac mult(
      l.top()*r.top(),
      l.bottom()*r.bottom()
      );
  return mult;
}

// Input: Two frac classes, right being the divisor
// Output: Division
frac operator/(frac &l,frac &r){
  frac div(
      l.top()*r.bottom(),
      r.top()*l.bottom()
      );
  return div;
}

// Input: A fraction class
// Output: Something readable for the user
std::ostream& operator<<(std::ostream& outs, frac& outy) {
  outs << outy.top() << "/" << outy.bottom();
  return outs;
}

