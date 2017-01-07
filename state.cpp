// state.cpp
// Connor Green
// class implementation for the state class

// include library rational
#include "state.h"

State::State(){}
State::State(string a,string b,string c,int d,int e,int f){
  stateAbv = a;
  stateName = b;
  stateCapital = c;
  statePop = d;
  yearOrigin = e;
  repCongress = f;
}
State::~State(){}
string State::getstateABV(){
  return stateAbv;
}
string State::getstateName(){
  return stateName;
}
string State::getstateCapital(){
  return stateCapital;
}
int State::getstatePop(){
  return statePop;
}
int State::getyearOrigin(){
  return yearOrigin;
}
int State::getrepCongress(){
  return repCongress;
}
