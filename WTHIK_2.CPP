#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int mode(int x)
{
	if(x<0)
	{
		return -x;
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
	float Wy,Wx;
	int m=mode((x2-x1));
	int n=mode((y2-y2));

	printf("enter the thickness of line:");
	scanf("%d",w);
	//w=9;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
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
