//kouch curve
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void koch_curve(int,int,int,int,int);

int main()
{
	int x1=100,y1=200,x2=400,y2=200;
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	koch_curve(x1,y1,x2,y2,2);
	getch();
	closegraph();
	return 0;
}

void koch_curve(int x1,int y1,int x2,int y2,int w)
{
	if(w == 1)
	{
		line(x1, y1, x2, y2);
		return;
	}

	//first point of division
	float ax = ((2*x1+x2)/3);
	float ay = ((2*y1+y2)/3);
	//second point of division
	float bx = (2*x2+x1)/3;
	float by = (2*y2+y1)/3;


	koch_curve(x1, y1, (int)(ax), (int)ay, w-1);
	koch_curve((int)ax, (int)(ay), (int)(0.5*(ax - bx) - 0.8666*(ay-by) + bx), (int)(0.8660*(ax- bx) + 0.5*(ay-by)+by), w-1);
	koch_curve( (int)(0.5*(ax - bx) - 0.8666*(ay-by) + bx),  (int)(0.8660*(ax- bx) + 0.5*(ay-by)+by), (int)(bx), (int)(by), w-1);
	koch_curve((int)(bx), (int)(by), x2, y2, w-1);
	//x being half so muliply by 0.5
	//y being rotate so 0.8666 value of rotate 30 degree so muliply by 0.8660
}
