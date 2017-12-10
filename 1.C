#include<graphics.h>
#include<conio.h>

int main()
{
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	line(0,0,20,20);
	getch();

}
