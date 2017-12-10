#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
int mod(int a)
{
	if(a>0)
	{
		return a;
	}
	else
	{
		return -a;
	}
}
int main()
{
	int gdriver = DETECT , gmode;

	int x1,y1,x2,y2,wy,w,y,i;

	printf("enter the x1,y1,x2,y2,w");
	scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&w);

	wy=(float)(w-1)/2 * (float)sqrt(pow((y2-y1),2)+pow((x2-x1),2))/mod((x2-x1));
	printf("%d",wy);
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	for(i=0;i<=y1+wy;i++)
	{
		line(x1,y1+y,x2,y2+y);
		//printf("%d %d %d %d\n",x1,(y1+i),x2,(y2+i));
	}
	for(i=(y1+wy);i>=y1;i--)
	{
		line(x1,y1-y,x2,y2-y);
		//printf("%d %d %d %d\n",x1,(y1-i),x2,(y2-i));
	}
	getch();
	closegraph();
	return 0;
}
