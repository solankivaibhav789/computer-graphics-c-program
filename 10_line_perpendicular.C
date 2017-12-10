//two line is perpandicular or not
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main()
{

	//int gdriver = DETECT ,gmode;
	int x11,y11,x12,y12;
	int x21,y21,x22,y22;
	float slope1,slope2;
	int delta_x1,delta_y1,delta_x2,delta_y2;
       //	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
       //	int x11,y11,x12,y12;
       //	int x21,y21,x22,y22;
       //	float slope1,slope2;
	scanf("point of line 1 :%d %d %d %d",&x11,&y11,&x12,&y12);
	scanf("point of line 2 :%d %d %d %d",&x21,&y21,&x22,&y22);
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
	    delta_y2=x21-x22;
	}
	else
	{
	    delta_x2=x22-x21;
	}
	slope1=(delta_y1)/(float)(delta_x1);
	slope2=(delta_y2)/(float)(delta_x2);
	printf("%f %f",slope1,slope2);
	if(slope1*slope2==-1)
	{
		printf("line is perpandicular");
	}
	else
	{
		printf("line is not perpandiclar");
	}
	getch();
	closegraph();
	return 0;
}
