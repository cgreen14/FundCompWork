#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include "gfxnew.h"
#include "ship.h"
#include <string>

//Prototypes
void startscreen();
void background();
void displaystats(int, int, int, int);
void crashscreen();
void landscreen();

int main(){
  //Initialize Variables
  int win_wd = 1000, win_ht = 800, fuel; // size of board and fuel
  char c = ' '; // intialize keyboard input;
  double radius = 7*M_PI/4, angle = 0, xspeed, yspeed, base;
  bool flame = false; // rocket starts off
  ship mland; // create ship

  gfx_open (win_wd, win_ht, "Moon Lander"); // open board
  while (c != 'q' && c != 's'){  // while user does't quit
    startscreen(); // open up start
    if(gfx_event_waiting()){
       c = gfx_wait();  // calls user input from screen
     }
  }
  gfx_clear();
  gfx_flush();
  while( c!= 'q'){
    gfx_clear();
    mland.newposition();  // Initialize postion of ship
    // static element
    background();
    // disp stats of ship
    displaystats(mland.getscore(), mland.getfuel(), 40*mland.getxspeed(), 40*mland.getyspeed() );
    // draw ship at the postion intialized
    mland.drawship(radius,flame);
    //Check to See if they are still on the Screen
    mland.shipbounds();
    //Find Orientation of Ship to See if Land is possible given position
    if (mland.checkLand()){
      base = mland.gyposition() - (mland.gyposition()-20*sin(radius));
      if(base > 13 && base < 15){ // acceptable radius rangle from point down
                                  // had to use sin to keep independent of roations around
        gfx_clear();
        while(c != 'c' && c != 'q'){
          landscreen(); // communicate score rise, and fact that land was made
          mland.landship();  // bring ship into ground
          radius = -(7*M_PI/4);
          background();
          displaystats(mland.getscore(), mland.getfuel(), 40*mland.getxspeed(), 40*mland.getyspeed() );
          mland.drawship(radius,flame);  // return ship to being
          if(gfx_event_waiting()){
            c = gfx_wait();
          }
        }
        mland.landStats(); // edit the scores and postion
        radius = 7*M_PI/4;  // reset rd
      }
    }
    //Check To see if there is a crash
    if(!mland.checkcrash(radius)){
      if(mland.getfuel() <= 0){break;}
      //If user presses 'c', resets stats and lower fuel
      while(c != 'c' && c != 'q'){
        mland.explosion(radius);  // go through angled explosion
        crashscreen(); // communicate a bound bridge was made
        radius = 7*M_PI/4;  // reset rd
        if(gfx_event_waiting()){
          c = gfx_wait();
        }
      }
      mland.crashstats();  // edit the data given consquences of crash
    }
    //Check to see if fuel is still remaining
    while(mland.getfuel() <= 0){
      gfx_clear();
      mland.endgame();  // if fuel is out end the game, communicate why and option
      if(gfx_event_waiting()){
        c = gfx_wait();
      }
      if(c != 'q'){break;}  // let them quit and close game
    }
    gfx_flush();
    usleep(20000);
    flame = false;  // reset flame to 0, allows for burst when up or w is hit
    angle = 0;  // make sure it rotates only once not keeps turning
    if(gfx_event_waiting()){
      c = gfx_wait();
      switch (c) {
        case 'a':
        case 'Q':
          angle = angle - 0.1; // alter angle clockwise
          break;
        case 'd':
        case 'S':
          angle = angle + 0.1;  // alter counter clockwise
          break;
        case 'w':
        case 'R':
          flame = true;  // animate boost
          mland.newspeed(radius); // update given acceleration
          break;
        case 'q':
          break;
       }
     }
     radius = radius + angle;  // update angle given a change up or down
  }
}
void startscreen(){
  //Create A Screen with the Title and a message that says press 's' t begin
  //Moon Lander Title
  char thefont[] = "-sony-fixed-medium-r-normal--24-170-100-100-c-120-iso8859-1";
  char thefont2[] = "-misc-fixed-medium-r-normal-ja-13-120-75-75-c-120-iso10646-1";
  char mytext[] = "Moon Lander";
  int x_winctr, y_winctr;            // window's center
  int pxl_w, pxl_h, x_txt, y_txt;    // text string's parameters
  int x_r;   // rectangle's parameters
  int pad = 10;                      // padding for the rectangle
  gfx_color(255,255,255);
  gfx_changefont(thefont);
  // find the window's center point coordinates
  x_winctr = 1000/2;
  y_winctr = 800/2;
  // determine the text string's width and height in pixels
  pxl_w = gfx_textpixelwidth(mytext, thefont);
  pxl_h = gfx_textpixelheight(mytext, thefont);
  // display the text, dead center, by first determining its lower left corner
  x_txt = x_winctr - pxl_w/2;
  y_txt = y_winctr + pxl_h/2 - 100;
  gfx_text(x_txt, y_txt, mytext);
  // draw a rectangle around the text, dead center, with a given padding
  // first determine its top left corner's x,y coordinates
  x_r = x_txt - pad;
  // now draw the rectangle with the above four values
  gfx_rectangle(x_r, y_txt - pxl_h - pad, pxl_w + 2*pad, pxl_h + 2*pad);
  //Display Instructions
  gfx_changefont(thefont2);
  gfx_text(x_r - 30, 440, "Press 's' to Start");
  gfx_text(x_r - 150, 460, "Press 'q' at any time to quit the game");
  gfx_text(x_r - 120, 480, "Rotate the ship using 'a' and 'd'");
  gfx_text(x_r - 130, 500, "Press 'w' to turn on the thrusters");
}
void background(){
  int i;
  char thefont[] = "-misc-fixed-bold-r-semicondensed--13-120-75-75-c-60-iso8859-1";
  int xvalues[] = {0, 50, 100, 125, 130, 135, 140, 145, 150, 275, 300, 350, 375, 375, 400, 450, 525, 550, 600, 610, 620, 650, 700, 750, 850, 875, 900, 920, 980, 1000};
  int yvalues[] = {400, 500, 500, 650, 660, 675, 680, 675, 650, 600, 600, 500, 450, 400, 400, 300, 475, 475, 550, 590, 600, 625, 625, 700, 700, 600, 450, 450, 440, 350};
  //Creae the Surface
  for(i = 1; i <= 29; i++){
    // iterates throught the lines, making the lines connect, creates surface
    gfx_line(xvalues[i-1], yvalues[i-1], xvalues[i], yvalues[i]);
  }
  //Display Incentives at proper place on map
  gfx_changefont(thefont);
  gfx_text(70, 515, "2X");
  gfx_text(383, 415, "4X");
  gfx_text(535, 490, "3X");
  gfx_text(670, 640, "2X");
  gfx_text(908, 465, "4X");
}
void displaystats(int score,int fuel,int xspeed,int yspeed){
  // change score from and int, to string, to const char so it can be printed be
  // gfx_text
  string sscore = to_string(score);
  char const *cscore = sscore.c_str();
  string sfuel = to_string(fuel);
  char const *cfuel = sfuel.c_str();
  string sxspeed = to_string(xspeed);
  char const *cxspeed = sxspeed.c_str();
  string syspeed = to_string(yspeed);
  char const *cyspeed = syspeed.c_str();
  //use smaller font for stats
  char thefont[] = "-misc-fixed-medium-r-semicondensed--12-110-75-75-c-60-iso8859-1";
  gfx_changefont(thefont);
  //Display Text
  gfx_text(50, 50, "Score: ");
  gfx_text(50, 75, "Fuel: ");
  gfx_text(900, 50, "X Speed: ");
  gfx_text(900, 75, "Y Speed: ");
  //Display Values after text
  gfx_text(95, 50, cscore );
  gfx_text(95, 75, cfuel );
  gfx_text(955, 50, cxspeed );
  gfx_text(955, 75, cyspeed );
}
void crashscreen(){
  char thefont[] = "-misc-fixed-bold-r-semicondensed--13-120-75-75-c-60-iso8859-1";
  gfx_changefont(thefont);
  gfx_text(400, 190, "You Crashed");
  gfx_text(360, 215, "Damage to the Ship Resulted in loss of 200 units of Fuel");
  gfx_text(400, 230, "Press c to continue");
}
void landscreen(){
  char thefont[] = "-misc-fixed-bold-r-semicondensed--13-120-75-75-c-60-iso8859-1";
  gfx_changefont(thefont);
  gfx_text(400, 190, "You Landed");
  gfx_text(360, 215, "Your Score has been updated");
  gfx_text(400, 230, "Press c to continue");
}
