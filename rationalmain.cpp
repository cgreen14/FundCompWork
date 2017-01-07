// rational.cpp
// Connor Green
// class implementation for the rational class

// driver to test the Rational class, added from sample
#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a(5,6), b(3,7), c, s;

  cout << "*** display a and b ***\n";
  a.print();
  b.print();
  cout << "*** display c ***\n";
  c.print();  // recall that c was instantiated with the default constructor

  // 'mathematically' add a and b
  cout << "*** compute s as the math sum of a and b, and display s ***\n";
  s = a.add(b);
  s.print();

  return 0;
}
