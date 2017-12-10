#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void dda(int x1,int y1,int x2,int y2);
int sign(int x);
int interger(float x);
int main()
{
	int gdriver=DETECT,gmode;
	int dx, dy,x1,y1,x2,y2;
	printf("enter the x1,y1,x2,y2:");
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	initgraph(&gdriver,&gmode,"c:\\turboc3\\BGI");
	dda(x1, y1, x2, y2);
	getch();
	closegraph();
	return 0;
}
void dda(int x1,int y1,int x2,int y2)
{
	int dx, dy;
	dx = x2 - x1;
	dy = y2 - y1;
	float x, y;
	
	int ox,oy;		//origin_x and origin_y
	ox=getmaxx()/2;
	oy=getmaxy()/2;
	

	line(0,oy,getmaxx(),oy);
	line(ox,0,ox,getmaxy());

	float delta_x=0, delta_y=0;
	int length = 0;
	if (abs(x2 - x1) >= abs(y2 - y1))
	{
		length = abs(x2 - x1);
	}
	else
	{
		length = abs(y2 - y1);
	}
	delta_x = (float)(x2 - x1) / length;
	delta_y = (float)(y2 - y1) / length;

	x = x1 + (float)0.5*sign(delta_x);
	y = y1 + (float)0.5*sign(delta_y);


	int i = 1;
	putpixel((interger(x)+ox),(interger(y)+oy),5);
      // printf("%f %f %d %d\n", x, y, interger(x), interger(y));
	while (i < length)
	{
		x = x + delta_x;
		y = y + delta_y;

	   //	printf("%f %f %d %d\n", x,y,interger(x), interger(y));
		putpixel((interger(x)+ox), (interger(y)+oy),5);
		i = i + 1;
	}

}
int sign(int x)
{
	if (x < 0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
int interger(float x)
{
	int b=fabs(x);
	if(x<0)
	{
		x=x-0.5;
		return x;
	}
	else
	{
		x=x+0.4;
		return x;
	}
}
