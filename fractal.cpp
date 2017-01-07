8//Ryan Green, Lab 11, 12/4/16
// Used Part of example code provided
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include "gfxnew.h"

//Prototypes
void sierpinski(int, int, int, int, int, int);
void drawtriangle(int, int, int, int, int, int);
void drawCircle(int,int,int);
void drawSnowflake(int,int,int);
void drawTree(int x, int y,float rad ,float angle);
void drawFern(int x, int y,float rad ,float angle);

int main(){
  int x1 , y1, x2 , y2 , x3 , y3;
  int win_wd = 500, win_ht = 500;
  char c;
  gfx_open (win_wd, win_ht, "Fractal");
  while(c!='q'){
    if(gfx_event_waiting()){
       c = gfx_wait();
     }
    switch (c) {
      case '1':
        x1 = 250, y1 = 400, x2 = 130, y2 = 160, x3 = 370, y3 = 160;
        sierpinski( x1, y1, x2, y2, x3, y3 );
        break;
      case '2':
        break;
      case '3':
        break;
      case '4':
        drawCircle(250,250,150);
        break;
      case '5':
        drawSnowflake(250,250,150);
        break;
      case '6':
        drawTree(250,475,100,M_PI/2);
        break;
      case '7':
        drawFern(250,475,300,M_PI/2);
        break;
      case '8':
        break;
    }

  }
  return 0;
}

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 ){
   // Base case.
   if( abs(x2-x1) < 5 ) return;

   // Draw the triangle
   drawtriangle( x1, y1, x2, y2, x3, y3 );

   // Recursive calls
   sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
   sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
   sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}
void drawtriangle( int x1, int y1, int x2, int y2, int x3, int y3 ){
  gfx_line(x1, y1, x2, y2);
  gfx_line(x1, y1, x3, y3);
  gfx_line(x3, y3, x2, y2);

}
void drawCircle(int x,int y,int r){
  if (r<5) return;
  float x3,y3;

  // draw first circle
  gfx_circle(x,y,r);
  r = r/3;
  x3 = 3*r*cos(M_PI/3);
  y3 = 3*r*sin(M_PI/3);
  drawCircle(x+(3*r),y,r);
  drawCircle(x-(3*r),y,r);
  drawCircle(x+x3,y+y3,r);
  drawCircle(x-x3,y+y3,r);
  drawCircle(x+x3,y-y3,r);
  drawCircle(x-x3,y-y3,r);
}
void drawSnowflake(int x,int y,int r){
  if (r<5) return;
  float dx,dy,x1,y1;
  x1 = r*cos(3*M_PI/2);
  y1 = r*sin(3*M_PI/2);
  gfx_line(x,y,x-x1,y-y1);
  int a;
  for (a = 1; a < 4; a++){
    dx = r*cos((a/4)*3*M_PI/10);
    dy = r*sin((a/4)*3*M_PI/10);
    drawSnowflake(dx,dy,r/3);
  }

}
void drawTree(int x, int y,float rad ,float angle){
  if (rad<5) return;
  float dx,dy;
  dx = x - rad*cos(angle);
  dy = y - rad*sin(angle);
  rad = rad*0.75;
  gfx_line(x,y,dx,dy);
  drawTree(dx,dy,rad,angle+M_PI/4);
  drawTree(dx,dy,rad,angle-M_PI/4);

}
void drawFern(int x,int y,float rad,float angle){
  if (rad<8) return;
  float dx1,dy1,dx2,dy2;
  dx1 = x - rad*cos(angle);
  dy1 = y - rad*sin(angle);
  gfx_line(x,y,dx1,dy1);
  int a;
  for(a =1 ; a < 5 ; a++){
    dx2 = x - rad* a/4 * cos(angle);
    dy2 = y - rad* a/4 * sin(angle);
    drawFern(dx2,dy2,rad*0.4,angle+M_PI/6);
    drawFern(dx2,dy2,rad*0.4,angle-M_PI/6);
  }
}
