#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int round(float a);

int main()
{
	int x1=30,y1=20,x2=120,y2=100,i,delta_x,delta_y;
	float u,x,y,p;		//u is parameter
	int gdriver= DETECT , gmode;

	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	if(x1>x2)
	{
		delta_x=x1-x2;
	}
	else
	{
		delta_x=x2-x1;
	}
	if(y1>y2)
	{
		delta_y=y1-y2;
	}
	else
	{
		delta_y=y2-y1;
	}
	if(delta_x>delta_y)
	{
		u=1/(float)delta_x;
	}
	else
	{
		u=1/(float)delta_y;
	}
//	printf("%.5f\n",u);
//	p=0.0;
	for(i=0;i<=((delta_x>delta_y)?delta_x:delta_y);i++)
	{
		x1=30;		//all time x1 and y1 change so every time initalize
		y1=20;
//		printf("%d\n",i);
		x = x1 + p * (x2-x1);
		y = y1 + p * (y2-y1);
		x1 = round(x);
		y1 = round(y);
//		printf("%.2f\n",p);
//		printf("%.5f  %.5f\n",x,y);
//		printf("%d %d\n\n",x1,y1);
		putpixel(x1,y1,5);
		p=p+u;
	}
	getch();
	closegraph();
}
int round(float a)
{
	if(a>0)
	{
		return(a+0.4);
	}
	else
	{
		return(a-0.4);
	}
}


