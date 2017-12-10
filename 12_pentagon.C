//draw the pentagon by line command
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
       
       
		i=20;
		line(i+10,i+10,i+10,i+30);
		line(i+10,i+30,i+20,i+40);
		line(i+20,i+40,i+30,i+30);
		line(i+30,i+30,i+30,i+10);
		line(i+30,i+10,i+10,i+10);
       
	getch();
	closegraph();

}
