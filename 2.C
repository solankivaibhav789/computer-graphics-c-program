#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#define width 639
#define height 399
void main()
{       int x2,y2,i,x1,y1;
	int gdriver = DETECT , gmode;
	clrscr();

	printf("enter option:\n");
	scanf("%d",&i);
	printf("enter x1");
	scanf("%d",&x1);
	printf("enter y1");
	scanf("%d",&y1);
	printf("enter x2");
	scanf("%d",&x2);
	printf("enter y2");
	scanf("%d",&y2);
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
		switch(i)
		{
			case 1:
				line(0,0,width,0);		//x axis
				line(0,0,0,height);		//y axis
				line(x1,y1,x2,y2);
				break;
			case 2:
				line(width,0,0,0);
				line(width,0,width,height);
				line(width-x1,y1,width-x2,y2);
				break;
			case 3:
				line(0,height,0,0);
				line(0,height,width,height);
				line(x1,height-y1,x2,height-y2);
				break;
			case 4:
				line(width,height,0,height);
				line(width,height,width,0);
				line(width-x1,height-y1,width-x2,height-y2);
				break;
			case 5:
				exit();
		}


	getch();
	closegraph();
}
