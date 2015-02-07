// main.cpp : ass2
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
using namespace std;

int main() {
  int t1,b1,t2,b2;
  char c,ch1,ch2,operate;

  cout << "welcome to the fraction thing v0.0.0.0.0.00001" << endl;
  while (1) {
    cout << "What would you like to do? Reduce fractions test, press (a). Calculate fractions press (b)." << endl;
    cin >> c;
    if (c == 'a') {
      cout << "Enter a fraction: _ / _" << endl;
      cin >> t1 >> ch1 >> b1;
      cout << "Reducing... "<< t1 << ch1 << b1 << endl;
      frac reduceit(t1,b1);
      cout << reduceit << endl;
    } else if (c == 'b') {
      cout << "Enter an expression: _ / _ [*|/|-|+] _ / _" << endl;
      cin >> t1 >> ch1 >> b1 >> operate >> t2 >> ch2 >> b2;
      cout << "Doing this: " << t1 << ch1 << b1 << operate << t2 << ch2 << b2 << endl;
      frac calc1(t1,b1);
      frac calc2(t2,b2);
      frac result;
      if (operate == '*') {
        result = calc1 * calc2;
        cout << result << endl;
      } else if (operate == '/') {
        result = calc1 / calc2;
        cout << result << endl;
      } else if (operate == '-') {
        result = calc1 - calc2;
        cout << result << endl;
      } else if (operate == '+') {
        result = calc1 + calc2;
        cout << result << endl;
      } else if (!(ch1 == '/' && ch2 == '/')) {
        cout << "try again!" << endl;
        continue;
      }
    }
  }

  return 0;
}
