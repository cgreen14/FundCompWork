code pieces

x1 = r*cos(3*M_PI/2);
y1 = r*sin(3*M_PI/2);
x2 = r*cos(19*M_PI/10);
y2 = r*sin(19*M_PI/10);
x3 = r*cos(11*M_PI/10);
y3 = r*sin(11*M_PI/10);
x4 = r*cos(3*M_PI/10);
y4 = r*sin(3*M_PI/10);
x5 = r*cos(27*M_PI/10);
y5 = r*sin(27*M_PI/10);
gfx_line(x,y,x-x1,y-y1);
gfx_line(x,y,x-x2,y-y2);
gfx_line(x,y,x-x3,y-y3);
gfx_line(x,y,x-x4,y-y4);
gfx_line(x,y,x-x5,y-y5);
r = r/3;
drawSnowflake(x-x1,y-y1,r);
drawSnowflake(x-x2,y-y2,r);
drawSnowflake(x-x3,y-y3,r);
drawSnowflake(x-x4,y-y4,r);
drawSnowflake(x-x5,y-y5,r);
