// rational.cpp
// Connor Green
// class implementation for the rational class

// include library rational
#include "rational.h"
#include <iostream>
using namespace std;

// declare the member functions

Rational::Rational(){  // intialize private values
  numer = 1;
  denom = 1;
}
Rational::Rational(int a, int b){
  numer = a;
  denom = b;
}
Rational::~Rational(){}

int Rational::getNumer(){
  return numer;
}
int Rational::getDenom(){
  return denom;
}
void Rational::setNumer(int n){
  numer = n;
};
void Rational::setDenom(int d){
  denom = d;
};
void Rational::print(){
  cout << numer << "/" << denom << endl; // print numer/demon
}
Rational Rational::add(Rational x){ // a/b + c/d
  Rational z; // declare a new Rational
  z.numer = numer * x.getDenom() + denom*x.getNumer(); // sum ad + cb
  z.denom = denom * x.getDenom(); // multiply b*d
  return z;
}
Rational Rational::subtract(Rational x){ //a/b - c/d
  Rational z;
  z.numer = numer * x.getDenom() - denom*x.getNumer(); // sub ad - cb
  z.denom = denom * x.getDenom(); // multiply b*d
  return z;
}
Rational Rational::multiply(Rational x){ // a/b * c/d = ac/db
  Rational z;
  z.numer = numer * x.getNumer(); // a*c
  z.denom = denom * x.getDenom(); // d*b
  return z;
}
Rational Rational::divide(Rational x){  //a/b / c/d = a/b * d/c
  Rational z;
  z.numer = numer * x.getDenom();
  z.denom = denom * x.getNumer();
  return z;
}
