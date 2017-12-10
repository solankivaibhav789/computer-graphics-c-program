#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void dda(int x1,int y1,int x2,int y2);
int sign(int x);
int interger(float x);
void kochCurve(float x1,float y1,float x2,float y2,int approx);

int main()
{
	int gdriver=DETECT,gmode;
	float x1=30,y1=30,x2=100,y2=30;
	//int legth=sqrt(pow((y2-y1),2)+pow((x2-x1),2);
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	kochCurve(x1,y1,x2,y2,1);
	getch();
	closegraph();
	return 0;
}

void kochCurve(float x1,float y1,float x2,float y2,int approx)
{
	float x3,y3,x4,y4,x5,y5;
	float d;

	x3=(1*x2+2*x1)/3.0;
	y3=(1*y2*2*y1)/3.0;

	x4=(2*x2+1*x1)/3.0;
	y4=(2*y2+1*y1)/3.0;


	//rotate line2 with repect to line1 around 60 degree
	x5=0.5*(x3-x4)-0.8660*(y3-y4)+x4;
	y5=0.8660*(x3-x4)+0.5*(y3-y4)+y4;

	if(approx==1)
	{
		line(x1,y1,x3,y3);
		line(x3,y3,x4,y4);
		line(x4,y4,x5,y5);
		line(x5,y5,x2,y2);
		return;
	}
	kochCurve(x1,y1,x3,y3,approx-1);
	kochCurve(x3,y3,x4,y4,approx-1);
	kochCurve(x4,y4,x5,y5,approx-1);
	kochCurve(x5,y5,x2,y2,approx-1);
}

void dda(int x1,int y1,int x2,int y2)
{
	int dx, dy;
      //	dx = x2 - x1;
       //	dy = y2 - y1;
	float x, y;
	float delta_x=0, delta_y=0;
	int length = 0;
	if (abs(x2 - x1) >= abs(y2 - y1))
	{
		length = abs(x2 - x1);
	}
	else
	{
		length = abs(y2 - y1);
	}
	delta_x = (float)(x2 - x1) / length;
	delta_y = (float)(y2 - y1) / length;

	x = x1 + (float)0.5*sign(delta_x);
	y = y1 + (float)0.5*sign(delta_y);


	int i = 1;
	putpixel(interger(x),interger(y),5);
       //	printf("%f %f %d %d\n", x, y, interger(x), interger(y));
	while (i < length)
	{
		x = x + delta_x;
		y = y + delta_y;

		//printf("%f %f %d %d\n", x,y,interger(x), interger(y));
		putpixel(interger(x), interger(y),5);
		i = i + 1;
	}

}
int sign(int x)
{
	if (x < 0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
int interger(float x)
{
	if (x <0)
	{
		return (x-0.5);
	}
	else
	{
		return(x+0.4);
	}
}
