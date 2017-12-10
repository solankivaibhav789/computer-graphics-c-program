#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int round(float a);

void main()
{
	int x1=3,y1=4,x2=6,y2=14,delta_x,delta_y,i;
	float x,y,slope,b;
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
	
	slope = (float)delta_y/delta_x;
	//printf("%.2f\n",slope);
	
	b = y1 - slope * x1;
	//printf("%.2f\n",b);
	
	if(delta_x==0)
	{
		for(i=0;i<=delta_y;i++)
		{
			//printf("%d  %d\n",x1,y1+i);
			putpixel(x1,y1+i,5);	
		}
	}
	else if(delta_y==0)
	{
		for(i=0;i<=delta_x;i++)
		{
			//printf("%d  %d\n",x1+i,y1);
			putpixel(x1+i,y1,10);
		}	
	}
	else
	{
		if(delta_x>delta_y)
		{
			for(i=0;i<=delta_x;i++)
			{
				y = slope*x1 + b;
			//	printf("%.2f",y);
				y1=round(y);
			//	printf("%d  %d\n",x1,y1);
				putpixel(x1,y1,12);
				x1++;
			}
		}
		else
		{
			for(i=0;i<=delta_y;i++)
			{
				x= (float)(y1-b)/slope;
			//	printf("%.2f",x);
				x1=round(x);
			//	printf("%d  %d\n",x1,y1);
				putpixel(x1,y1,16);
				y1++;
			}
		}
	}
	getch();
	closegraph();2
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
