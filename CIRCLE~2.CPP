//circle using dda
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int main()
{
	float x1,y1,x2,y2,startx,starty,epsilon;
	int gdriver=DETECT,gmode;
	int r,i,val;
	clrscr();
	printf("enter the radius of circle:\n");
	scanf("%d",&r);
	initgraph(&gdriver,&gmode,"c:\\turboc3\\BGI");
	x1=r*cos(0);
	y1=r*sin(0);
	startx=x1;
	starty=y1;
	i=0;
	do
	{
		val=pow(2,i);
		i++;
	}while(val<r);
	
	epsilon=1/pow(2,i-1);
	do
	{
		x2=x1+y1*epsilon;
		y2=y1-epsilon*x2;
		putpixel(200+x2,200+y2,5);
		x1=x2;
		y1=y2;
	}while((y1-starty)<epsilon || (startx-x1)>epsilon);
	getch();
	closegraph();
}
