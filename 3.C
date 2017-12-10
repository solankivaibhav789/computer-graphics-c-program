#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
int round(float a);

void main()
{       int i,b,x1,y1,x2,y2,delta_x,delta_y;
	float slope,x,y;
	int gdriver = DETECT , gmode;
	clrscr();


	printf("X1 : ");
	scanf("%d" , &x1);

	printf("Y1 : ");
	scanf("%d" , &y1);


	printf("X2 : ");
	scanf("%d" , &x2);

	printf("Y2 : ");
	scanf("%d" , &y2);

	delta_x = x2 - x1;
	delta_y = y2 - y1;

	printf("%d %d\n",delta_x,delta_y);
	slope = (float)delta_y / delta_x;
	printf("%.2f" ,slope);
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	if(delta_x==0)
	{
		for(i=0;i<delta_y;i++)
		{
				printf("%d %d\n",x1,y1);
		       //	putpixel(x1,y1+i,3);			//putpixel(p,q,r) is fill pixel of (p,q) co-ordinate by r color
		}

	}
	else if(delta_y==0)
	{
		for(i=0;i<delta_x;i++)
		{
			printf("%d %d\n",x1,y1);
		       //	putpixel(x1+i,y1,5);
		}
	}
	else
	{
		if(delta_x>delta_y)			//delta_x > delta_y than x increment by 1
		{
			for(i=0;i<delta_x;i++)
			{
				y= slope*x1 + b;
				y1=round(y);
				printf("%d %d\n",x1,y1);
				//putpixel(x1,y1,9);
				x1++;
				//or use
				/*
				y= slope*x1 + b;
				putpixel(x1,round(x1));
				*/

			}
		}
		else						//delta_x < delta_y than y increment by 1
		{
			for(i=0;i<delta_y;i++)
			{
				x=(y-b)/slope;
				x1=round(x);
				printf("%d %d\n",x1,y1);
			 //	putpixel(x1,y1,9);
				y1++;
			}
		}
	}
	getch();
	closegraph();
}
int round(float a)
{
	return(a+0.4);
}
