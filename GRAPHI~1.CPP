#include<iostream.h>
#include<graphics.h>
#include<conio.h>

#define WIDTH 639
#define HEIGHT 399
int main()
{
    int gdriver = DETECT , gmode;
    initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
    setfillstyle(SOLID_FILL,GREEN);
    bar(0,0,WIDTH,30);
    char a1[5]="FILE";
    outtextxy(10,10,a1);
    char a2[5]="EDIT";
    outtextxy(60,10,a2);
    char a3[5]="TOOLS";
    outtextxy(110,10,a3);
    char a4[5]="IMAGE";
    outtextxy(200,10,a4);
    char a5[5]="COLOR";
   outtextxy(210,10,a5);
    char a6[6]="ROTATE";
    outtextxy(260,10,a6);
    getch();
    closegraph();
    return 0;
}
