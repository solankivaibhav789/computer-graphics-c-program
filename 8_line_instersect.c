//line instesect point
#include<stdio.h>
#include<conio.h>
//#include<graphics.h>


void main()
{
	int x11=15,x12=49,y11=10,y12=25;		//for line 1
	int x21=29,x22=32,y21=5,y22=32;		//for line 2
	float x,y;
	float slope1,slope2;			//slope1 for line 1 and slope2 for line 2
	float b1,b2;					//b1 for line 1 and b2 for line 2
	int delta_x1,delta_y1;		//for line 1
	int delta_x2,delta_y2;		//for line 2
	
	if(x11>x12)
	{
		delta_x1=x11-x12;
	}
	else
	{
		delta_x1=x12-x11;	
	}
	if(y11>y12)
	{
		delta_y1=y11-y12;	
	}
	else
	{
		delta_y1=y12-y11;
	}
	
	if(x21>x22)
	{
		delta_x2=x21-x22;
	}
	else
	{
		delta_x2=x22-x21;	
	}
	if(y21>y22)
	{
		delta_y2=y21-y22;	
	}
	else
	{
		delta_y2=y22-y21;
	}
	
	printf("%d  %d\n",delta_x1,delta_y1);
	printf("%d  %d\n\n",delta_x2,delta_y2);
	slope1 = (float)delta_y1/delta_x1;
	slope2 = (float)delta_y2/delta_x2;
	
	printf("%.2f  %.2f\n",slope1,slope2);
	
	b1=y11-slope1*x11;
	b2=y21-slope2*x21;
	
	printf("%.2f  %.2f\n\n",b1,b2);
	
	x=(float)(b2-b1)/(slope1-slope2);
	y=(float)(slope1*b2-b1*slope2)/(slope1-slope2);
	
	printf("%.2f  %.2f",x,y);
}
