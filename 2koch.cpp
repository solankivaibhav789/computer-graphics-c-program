#include<stdio.h>
#include<conio.h>
#include<graphics.h>

struct point 
{
	float x,y;
};

void dda(int x1,int y1,int x2,int y2);
int sign(int x);
int interger(float x);
void kochCurve(point p1,point p2,int approx);

int main()
{
	struct point p1,p2;
	p1.x=100,p1.y=100,p2.x=300,p2.y=100;
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	KochCurve(p1,p2,1);
	getch();
	closegraph();
	return 0;
}
void myKochCurve(struct point p, struct point q, int approx){
        /*
            using equation - divide line into m:n equation from p
            p(x1,y1) .----. q(x2,y2)

            x = (m * x2 + n*x1)/m+n;
            y = (m*y2 + n*y1)/m+n;

        */
        struct point a,b,c;
        float d;

        a.x = (1*q.x + 2*p.x)/3.0;
        a.y = (1*q.y + 2*p.y)/3.0;

        b.x = (2*q.x + 1*p.x)/3.0;
        b.y = (2*q.y + 1*p.y)/3.0;

        /* imp : rotating 'b' w.r.t 'a' around 60**/
        c.x = 0.5*(a.x-b.x) - 0.8660*(a.y-b.y) + b.x;
        c.y = 0.8660*(a.x-b.x) + 0.5*(a.y-b.y) + b.y;

        if(approx == 1){
            dda(p,a,WHITE);
            dda(a,c,WHITE);
            dda(c,b,WHITE);
            dda(b,q,WHITE);
            return;
        }

        KochCurve(p,a,approx-1);
        KochCurve(a,c,approx-1);
        KochCurve(c,b,approx-1);
        KochCurve(b,q,approx-1);
}

void dda(int x1,int y1,int x2,int y2)
{
	int dx, dy;
      //	dx = x2 - x1;
       //	dy = y2 - y1;
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
	putpixel(interger(x),interger(y),5);
       //	printf("%f %f %d %d\n", x, y, interger(x), interger(y));
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
	if (x <0)
	{
		return (x-0.5);
	}
	else
	{
		return(x+0.4);
	}
}
