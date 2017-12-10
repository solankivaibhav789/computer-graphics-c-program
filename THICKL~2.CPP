//w thickness thick line
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void dda(int x1,int y1,int x2,int y2);
int sign(int x);
int interger(float x);
void myThickLine(struct point,struct point,int width,int color);
struct point
{
	float x,y;
};
int main()
{
	int gdriver=DETECT,gmode;
	int w,i;
	struct point p1,p2;
	p1.x=50,p1.y=50;
	p2.x=50,p2.y=150;
	float Wy;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	printf("enter the thickness of line:");
	scanf("%d",w);
	myThickLine(p1,p2,w,5);


	getch();
	closegraph();
	return 0;
}

void myThickLine(struct point p1,struct point p2,int width,int color){
    int del_x,del_y;
    float wx,wy,xy,xx;
    struct point p,q,r,s;

    del_x = abs(p2.x-p1.x);
    del_y = abs(p2.y-p1.y);

    if(del_x>del_y){
	//gentle slope line
	wy = ((width-1)/2) * (pow(pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2),0.5)/del_x);
	xy = (del_x/pow(pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2),0.5));


	for(int i=0;i<wy;i++)
		{
	    p.x = p1.x+xy*i;
	    q.x = p2.x+xy*i;
	    r.x = p1.x-xy*i;
	    s.x = p2.x-xy*i;

	    p.y = p1.y-i;
	    q.y = p2.y-i;
	    r.y = p1.y+i;
	    s.y = p2.y+i;

	    dda(p.x,p.y,q.x,q.y);
	    dda(r.x,r.y,s.x,s.y);
	}
    }
	else
	{
	//sharp slope
	wx = ((width-1)/2) * (pow(pow((p2.x-p1.x),2)+ pow((p2.y-p1.y),2),0.5)/del_y);
	xy = (del_y/pow(pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2),0.5));


	for(int i=0;i<wy;i++)
		{
	    p.y = p1.y+xy*i;
	    q.y = p2.y+xy*i;
	    r.y = p1.y-xy*i;
	    s.y = p2.y-xy*i;
	    p.x = p1.x-i;
	    q.x = p2.x-i;
	    r.x = p1.x+i;
	    s.x = p2.x+i;

	    dda(p.x,p.y,q.x,q.y);
	    dda(r.x,r.y,s.x,s.y);
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
	if (x<0)
	{
		return (x-0.5);
	}
	else
	{
		return(x+0.4);
	}
}
