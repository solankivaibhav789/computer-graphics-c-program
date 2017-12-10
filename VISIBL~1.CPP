#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

struct point
{
	int x,y;
	int flag;
}p;
point intersection(float x11, float y11, float x12, float y12, float x21, float y21, float x22, float y22);
int main()
{
	int x1=50,y1=300,x2=300,y2=300;
	int Xl=200,Xr=400,Yt=400,Yb=200;
	int gdriver=DETECT,gmode,i;
	int visible=2;//invisible=0 partially visible=1 & totally visible=2
	int x,y;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");

	line(Xl,Yb,Xl,Yt);
	line(Xl,Yt,Xr,Yt);
	line(Xr,Yt,Xr,Yb);
	line(Xl,Yb,Xr,Yb);

	if(x1<Xl && x2<Xl)
	{
		printf("1");
		visible=0;

	}
	if(x1>Xr && x2>Xr)
	{
		printf("2");
		visible=0;

	}
	if(y1>Yt && y2>Yt)
	{
		printf("3");
		visible=0;

	}
	if(y1<Yb && y2<Yb)
	{
		printf("4");
		visible=0;

	}
	printf("%d\n",visible);
	if(visible==0)//if not visible
	{
		printf("invisible");
	}

	if(x1<Xl || x1>Xr)
	{
		printf("1");
		visible=1;
		i=2;
	}
	if(x2<Xl || x2>Xr)
	{
		printf("2");
		visible=1;
		i=1;
	}
	if(y1<Yb || y1>Yt)
	{
		printf("3");
		visible=1;
		i=2;
	}
	if(y2<Yb || y2>Yt)
	{
		printf("4");
		visible=1;
		i=1;
	}
	printf("visible%d %d",visible,i);
	if(visible==2)//if partially visible than
	{
		line(x1,y1,x2,y2);
	}

	if(visible==1)
	{      // x=300,y=300;
		if(i==1)
		{
			x=x1;
			y=y1;
		}
		else
		{
			x=x2;
			y=y2;
		}
		struct point p2,p3,p4,p5;
		p2=intersection(x1,y1,x2,y2,Xl,Yb,Xl,Yt);
		if(p2.flag==1)
		{
			printf("\nabc1\n");
			line(x,y,p2.x,p2.y);
		}
		p3=intersection(x1,y1,x2,y2,Xl,Yt,Xr,Yt);
		if(p3.flag==1)
		{
			printf("\nabc2\n");
			line(x,y,p3.x,p3.y);
		}
		p4=intersection(x1,y1,x2,y2,Xr,Yt,Xr,Yb);
		if(p4.flag==1)
		{
			printf("\nabc3\n");
			line(x,y,p4.x,p4.y);
		}
		p5=intersection(x1,y1,x2,y2,Xl,Yb,Xr,Yb);
		if(p5.flag==1)
		{
			printf("\nabc4\n");
			line(x,y,p5.x,p5.y);
		}
	}
	getch();
	closegraph();
	return 0;
}

point intersection(float x11, float y11, float x12, float y12, float x21, float y21, float x22, float y22)
{
	float r1=0, s1=0, t1=0, r2=0, s2=0, t2=0;
	int x=0, y=0;
	int flag = 0;

	r1 = y12 - y11;
	s1 = x11 - x12;
	t1 = x12*y11 - x11*y12;

	r2 = y22 - y21;
	s2 = x21 - x22;
	t2 = x22*y21 - x21*y22;

	x = fabs((float)(s1*t2 - s2*t1) / (r1*s2 - r2*s1));
	y = fabs((float)(r1*t2 - r2*t1) / (r2*s1 - r1*s2));

	if(x21>x22)
	{
		float temp;
		temp = x22;
		x22 = x21;
		x21 = temp;
	}
	if (y21 > y22)
	{
		float temp;
		temp = y22;
		y22 =y21;
		y21 = temp;
	}
	if (x11>x12)
	{
		float temp;
		temp = x12;
		x12 = x11;
		x11 = temp;
	}
	if (y11 > y12)
	{
		float temp;
		temp = y12;
		y12 = y11;
		y11 = temp;
	}

	if (r1*x + s1*y + t1 == 0)
	{

		if (r2*x + s2*y + t2 == 0)
		{

			if (x11 <= x && x <= x12)
			{

				if (x21 <= x && x <= x22)
				{

					if (y11 <= y && y <= y12)
					{

						if (y21 <= y && y <= y22)
						{

							flag = 1;

						}
					}

				}
			}
		}
	}
	struct point p1;
	if(flag==1)
	{

		p1.x=x;
		p1.y=y;
		p1.flag=1;
		return p1;
	}
	else
	{
		p1.flag=0;
		p1.x=0;
		p1.y=0;
		return p1;
	}
}
