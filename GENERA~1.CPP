//general bresenhem's algorithm
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
int sign(int x);
int main()
{
	int x=0,y=0,delta_x=0,delta_y=0,e_bar=0;
	int x1=50,y1=-50,x2=-50,y2=50,i,interchange;
	int s1,s2;
	int gdriver=DETECT,gmode;
	int ox,oy;		//origin x and origin y
	int temp;




       //	printf("enter the x1,y1,x2,y2:%d %d ",ox,oy);
       // scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

	initgraph(&gdriver,&gmode,"c:\\turboc3\\BGI");

	ox=getmaxx()/2;
	oy=getmaxy()/2;
      line(0,oy,getmaxx(),oy);
      line(ox,0,ox,getmaxy());


	x=x1;
	y=y1;
	delta_x=abs(x2-x1);
	delta_y=abs(y2-y1);
	s1=sign(x2-x1);
	s2=sign(y2-y1);
	e_bar = 2 * delta_y - delta_x;
	//printf("e:%d delta_x:%d delta_y:%d\n",e_bar,delta_x,delta_y);
	if(delta_y>delta_x)
	{

		temp=delta_y;
		delta_y=delta_x;
		delta_x=temp;
		interchange=1;
	}
	else
	{
		interchange=0;
	}
	//printf("e:%d delta_x:%d delta_y:%d interchange=%d\n",e_bar,delta_x,delta_y,interchange);
	for(i=1;i<=delta_x;i++)
	{
		//printf("i:%d  e_bar:%d  x:%d  y:%d\n",i,e_bar,x,y);
		putpixel((x+ox),(y+oy),5);
		while(e_bar>=0)
		{
			if(interchange==1)
			{
				x=x+s1;
			}
			else
			{
				y=y+s2;
			}
			e_bar = e_bar - 2* delta_x;
			//printf("e_bar:%d  x:%d  y:%d\n",e_bar,x,y);
		}

		if(interchange==1)
		{
			y=y+s2;
		}
		else
		{
			x = x+s1;
		}
		e_bar = e_bar + 2 * delta_y;
	}
		//printf("e_bar:%d  x:%d  y:%d\n",e_bar,x,y);
	getch();
	closegraph();
	return 0;
}
int sign(int x)
{
	if(x<0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
