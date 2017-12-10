#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int round(float a);
void main()
{
	int r,s,t,i,x1=3,y1=2,x2=100,y2=200,delta_x,delta_y;
	float x,y;
	int gdriver = DETECT,gmode;
	clrscr();
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	r=y2-y1;
	s=x1-x2;
	t=x2*y1 -x1*y2;
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

	//printf("%d %d %d %d %d\n",r,s,t,delta_x,delta_y);
	if(delta_x > delta_y)
	{
		for(i=0;i<=delta_x;i++)
		{
			y = (float)(t+r*x1)/s;
		//	printf("%.2f\n",y);
			y1=round(y);
		//	printf("%d  %d\n",x1,(-1)*y1);
			putpixel(x1,(-1)*y1,5);
			x1++;
		}
	}
	else
	{
		for(i=0;i<=delta_y;i++)
		{
			x = (float)(t+s*y1)/r;
		//	printf("%.2f\n",x);
			x1=round(x);
		//	printf("%d  %d\n",x1,(-1)*y1);
			putpixel((-1)*x1,y1,5);
			y1++;
		}
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
