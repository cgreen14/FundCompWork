#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
using namespace std;


float polarR(float a,float b)
{
        return sqrt((a*a)+(b*b));
}
float polarC(float x, float y, float r)
{
        float theta = asin(y/r);// inverse sin is asin
        theta = abs (theta); 
                if (x<0 && y > 0) // Second quadrant
                {
                        theta = M_PI - theta;
                }
                else if (x < 0 && y < 0) // third quadrant
                {
                        theta = M_PI + theta;
                }
                else if (x > 0 && y <0)// fourth quadrant
                {
                        theta = 2*M_PI - theta;
                }
        return theta;
}
char polarACheck (float x,float y)
{

        if ( x == 0 && y == 0)
                {
                        cout << "It is at the origin";
                }
        else if ( y== 0)
                {
                        cout << "It is on the x axis";
                }
        else if (x < 0 && y < 0)
                {
                        cout << "In third Quadrant";
                }
        else if ( x < 0  && y > 0)
                {
                        cout <<  "In second Quadrant";
                }
        else if ( x > 0 && y < 0)
                {
                        cout <<  "In fourth Quadrant";
                }
        else if ( x > 0 && y > 0)
                {
                        cout << "In first Quadrant";
                }
        else if ( x == 0)
                {
                        cout <<  "It is on the y axis";
                }
                return 0;
}

