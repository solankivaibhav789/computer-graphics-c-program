//draw pentagon and move it using for loop
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void fun()
{
lineral(0,-20);
lineral(10,-10);
lineral(10,10);
lineral(0,20);
lineral(-20,0);
}
void subfun()
{
move(10,10);
lineto(10,30);
lineto(20,40);
lineto(30,30);
lineto(30,10);
lineto(10,10);
}
void main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");

    for(i=0;i<100;i++)
	{
		moveto(10+i,40);
		fun();
		moveto(40+i,40);
		fun();
		moveto(20+i,40);
		fun();
		moveto(70+i,40);
		fun();
		getch();
		setcolor(BALCK):
		
	}
}
