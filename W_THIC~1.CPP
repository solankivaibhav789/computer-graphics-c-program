#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void dda(int x1,int y1,int x2,int y2);
int sign(int x);
int interger(float x);
int mode(int x)
{
	if(x<0)
	{
		return -(x);
	}
	else
	{
		return x;
	}
}

int main()
{
	int gdriver=DETECT,gmode;
	int w,x1,x2,y1,y2,i;
	x1=50,y1=50;
	x2=50,y2=150;
	float Wy;
	int m=mode((x2-x1));
	int n=mode((y2-y2));
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	//printf("enter the thickness of line:");
	//scanf("%d",w);
	w=10;
	if((y2-y1)/(x2-x1) < 1)
	{
		Wy=(float)(w-1)/2 * (float)sqrt(pow((y2-y1),2)+pow((x2-x1),2))/m;
		for(i=0;i<Wy;i++)
		{
			line(x1,y1-i,x2,y2-i);
			line(x1,y1+i,x2,y2+i);	
		}	
	}
	else
	{
		Wx=(float)(w-1)/2 * (float)sqrt(pow((y2-y1),2)+pow((x2-x1),2))/n;
		for(i=0;i<Wx;i++)
		{
			line(x1-i,y1,x2-i,y2);
			line(x1+i,y1,x2+i,y2);
		}
	}
	
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
	//printf("%f %f %d %d\n", x, y, interger(x), interger(y));
	while (i < length)
	{
		x = x + delta_x;
		y = y + delta_y;

		//printf("%f %f %d %d\n", x,y,interger(x), interger(y));
		putpixel(interger(x), interger(y),5);
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
	if (x - b > 0.5)
	{
		return (x+1);
	}
	else
	{
		return(x);
	}
}
