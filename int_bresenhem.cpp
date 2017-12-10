//interger bresenhem's algorithm
#include<stdio.h>
#include<conio.h>
//#include<graphics.h>
int main()
{
	int x=0,y=0,delta_x=0,delta_y=0,e_bar=0;
	int x1=0,y1=0,x2=0,y2=0,i;
	printf("enter the x1,y1,x2,y2: ");
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	x=x1;
	y=y1;
	delta_x=x2-x1;
	delta_y=y2-y1;
	e_bar = 2 * delta_y - delta_x;
	for(i=1;i<=delta_x;i++)
	{
		printf("e_bar:%d  x:%d  y:%d\n",e_bar,x,y);
		//putpixel(x,y);
		while(e_bar>=0)
		{
			y=y+1;
			e_bar = e_bar - 2* delta_x;
			printf("e_bar:%d  x:%d  y:%d\n",e_bar,x,y);
		}
	}
	x = x+1;
	e_bar = e_bar + 2 * delta_y;
	printf("e_bar:%d  x:%d  y:%d\n",e_bar,x,y);
}
