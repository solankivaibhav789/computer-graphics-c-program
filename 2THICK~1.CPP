#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void dda(int x1,int y1,int x2,int y2);
int sign(int x);
int interger(float x);
void myThickLine(int x1,int y1,int x2,int y2,int width,int color);

int main()
{
	int gdriver=DETECT,gmode;
	int w,x1,x2,y1,y2,i;
	x1=50,y1=50;
	x2=50,y2=150;
	float Wy;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	printf("enter the thickness of line:");
	scanf("%d",w);
	myThickLine(x1,y1,x2,y2,w,5);


	getch();
	closegraph();
	return 0;
}

void myThickLine(int x1,int y1,int x2,int y2,int width,int color)
{
    int del_x,del_y;
    float wx,wy;

    del_x = abs(x2-x1);
    del_y = abs(y2-y1);

    if(del_x>del_y)
	{
        //gentle slope line
        wy = ((width-1)/2) * (pow((x2-x1)(x2-x1) + (y2-y1)(y2-y1),0.5)/del_x);

        for(int i=0;i<wy;i++){
            DDA(x1,y1-i,x2,y2-i,WHITE);
            DDA(x1,y1+i,x2,y2+i,WHITE);
        }

    }else
	{
        //sharp slope
        wx = ((width-1)/2) * (pow((x2-x1)(x2-x1) + (y2-y1)(y2-y1),0.5)/del_y);

        for(int i=0;i<wx;i++){
            DDA(x1-i,y1,x2-i,y2,WHITE);
            DDA(x1+i,y1,x2+i,y2,WHITE);
        }
	}
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
		putpixel(interger(x), interger(y));
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
	if (x<0)
	{
		return (x-0.5);
	}
	else
	{
		return(x+0.4);
	}
}
