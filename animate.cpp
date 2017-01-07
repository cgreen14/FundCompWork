// animate.cpp
// Connor Green
// rotating wind mill, that will its speed determined by the user, this will then
// translate to a "light buld" that demonstates the power input relation to speed

// libs
#include <unistd.h>
#include <stdlib.h>
#include "gfx.h"
#include <cmath>
#include <math.h>
using namespace std;

void stableShapes();
void windmillArms(int, int, float, int);
void lightArms(int);
int main(){

  // initalize board dimensions and variables used
  int win_wd = 800, win_ht = 600;
  int xCenter = 125, yCenter = 325,dTheta = 0,dLight = 0;
  int x1,x2,x3,x4,y1,y2,y3,y4;
  float theta = 0;
  const int radius = 120;
  char c = ' ';
  // open up board called windmill
  gfx_open (win_wd, win_ht, "windmill");

  while(c != 'q'){
    gfx_clear();  // clear board

    // display key
    gfx_color(0,200,00);
    gfx_text(20,20, "use a and d or the right and left arrows");
    gfx_text(30,30, "to control the speed and generate light");

    stableShapes();  // creates the shapes that dont involve motion
    windmillArms(xCenter, yCenter, theta, radius);  // arms of windmill
    lightArms(dLight);  // create the associate light intensity

    gfx_flush();  // flush results to board

    usleep(30000);  // wait time

    // make changes to draw
    if(gfx_event_waiting()){  // waits for event to be true, then grabs it
      c = gfx_wait();  // grab the event
     switch(c) {
      case 'a':  // accounts for both arrow and for the letter
      case 'Q':
        dLight = dLight + 1;  // alters both counters if need to be scalled
        dTheta = dTheta + 1;
        break;
      case 'd':
      case 'S':
        dLight = dLight - 1;
        dTheta = dTheta - 1;
        break;
      case 'q':  // breaks out of loop if q to close window
        break;
     }
   }
   theta = theta + (0.1 * dTheta);  // iterate up theta to rotate lines
 }
  return 0;
}

void windmillArms(int xCenter, int yCenter, float theta, int radius){
  // create windmill arms
  // give arms a phase difference of pi/2 so at 90 degrees
  int x1 = xCenter - cos(theta)*radius;
  int x2 = xCenter + cos(theta)*radius;
  int y1 = yCenter - sin(theta)*radius;
  int y2 = yCenter + sin(theta)*radius;

  int x3 = xCenter - cos(theta+M_PI/2)*radius;
  int x4 = xCenter + cos(theta+M_PI/2)*radius;
  int y3 = yCenter - sin(theta+M_PI/2)*radius;
  int y4 = yCenter + sin(theta+M_PI/2)*radius;
  gfx_color(255, 255, 255); // white lines
  gfx_line(x1,y1,x2,y2);
  gfx_line(x3,y3,x4,y4);
}
void lightArms(int dLight){
  //create the light lines
    int y = 440,l = 0;
    y = (y - 25*dLight > 440) ? y + 25*dLight : y - 25*dLight;  // set a minimum
                                                                // value for the light line
    gfx_color(255, 255, 255); // color white
    gfx_line(535,440,535,y); // strait up light line
    l = y-440;
    // use geometry to set 2 other angled light lines to show power output
    gfx_line(515,440,l*acos(M_PI/4)+515,l*asin(M_PI/4)+440);
    gfx_line(555,440,555 - l*acos(M_PI/4),l*asin(M_PI/4)+440);
}
void stableShapes(){
  // base of windmill
  gfx_color(0,0,255);
  gfx_line(100,350,100,599);
  gfx_line(100,350,150,350);
  gfx_line(150,350,150,599);
  gfx_line(150,599,100,599);

  // top of windmill (top point at 125,325)
  gfx_color(0,0,255);
  gfx_line(100,350,125,325);
  gfx_line(150,350,125,325);

  // base of generator
  gfx_color(218,218,210);
  gfx_line(500,529,570,529);
  gfx_line(570,599,570,529);
  gfx_line(570,599,500,599);
  gfx_line(500,599,500,529);

  // filiment
  gfx_color(247,239,7);
  gfx_line(510,500,560,500);
  gfx_line(510,529,510,500);
  gfx_line(560,500,560,529);

  // wire
  gfx_line(151,550,500,550);

  // light bulb
  gfx_color(255,255,255);
  gfx_circle(535,485,30);
}
