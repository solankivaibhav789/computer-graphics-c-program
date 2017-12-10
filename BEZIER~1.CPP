//bezier caurve
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void myBezierCurve(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4);
int main()
{
	int gdriver=DETECT,gmode;
	float x1=100,y1=100,x2=200,y2=200,x3=300,y3=200,x4=400,y4=100;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	myBezierCurve(x1,y1,x2,y2,x3,y3,x4,y4);
	getch();
	closegraph();
	return 0;
}

void myBezierCurve(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{

    float u=0;
    float x=0,y=0;


    while(u<=1){
	x = (x4*pow(u,3)) + (3*x3*pow(u,2)*(1-u)) + (3*x2*u*pow((1-u),2)) + (x1*pow((1-u),3));
	y = (y4*pow(u,3)) + (3*y3*pow(u,2)*(1-u)) + (3*y2*u*pow((1-u),2)) + (y1*pow((1-u),3));
	putpixel(x,y,WHITE);
	u += 0.001;
    }

}
