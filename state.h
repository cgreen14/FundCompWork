// state.h
// Connor Green
#include <string>
using namespace std;

class State{
  public:
    // methods that can be used in class and library to be drawin in .cpp and main
    State();
    State(string,string,string,int,int,int);
    ~State();
    string getstateABV();
    string getstateName();
    string getstateCapital();
    int getstatePop();
    int getyearOrigin();
    int getrepCongress();

  private:
    // data only accessed through classes
    string stateAbv;
    string stateName;
    string stateCapital;
    int statePop;
    int yearOrigin;
    int repCongress;
};
