//bresenham's algorithm 1
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	int gdriver = DETECT,gmode;

	int x,y,x1,y1,x2,y2,i;
	float e,delta_x,delta_y;
	clrscr();
	printf("enter x1 y1:");
	scanf("%d %d",&x1,&y1);
	printf("enter x2 y2:");
	scanf("%d %d",&x2,&y2);
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
	x=x1;
	y=y1;
	delta_x=x2-x1;
	delta_y=y2-y1;
	//printf("%.3f %.3f\n",delta_x,delta_y);
	e = ((float)(delta_y/delta_x)-0.5);
	for(i=0;i<delta_x;i++)
	{

		putpixel(x,y,3);
		while(e>=0)
		{
			y=y+1;
			e=e-1;
		       //	printf("%.3f %d %d\n",e,x,y);
		}
		x=x+1;
		e=e+(float)(delta_y/delta_x);
		//printf("%.3f %d %d\n\n",e,x,y);
	}
	getch();
	closegraph();
}
