// rational.h
class Rational {
  public:
    // methods that can be used in class and library to be drawin in .cpp and main
    Rational();
    Rational(int, int);
    ~Rational();
    int getNumer(); // grab valued numberator
    int getDenom(); // grab value denominator
    void setNumer(int); // set value in rational numberator
    void setDenom(int); // set value in rational denominator
    void print(); // cout raional
    Rational add(Rational);  // addition of two rationals
    Rational subtract(Rational); // subtraction of two rationals
    Rational multiply(Rational); // multiplation of two rationals
    Rational divide(Rational); // division of two rationals
  private:
    // data only accessed through classes 
    int numer;
    int denom;
};
