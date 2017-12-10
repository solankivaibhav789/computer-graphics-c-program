//min distance between line and point
#include<stdio.h>
#include<conio.h>
#include<math.h>
int pos	(float x);
void main()
{
	int x1,y1,x2,y2,x3,y3;
	float d;
	int r,s,t,temp,line;
	clrscr();
	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	r=y2-y1;
	s=x1-x2;
	t=x2*y1-x1*y2;
	temp=r*x3+s*y3+t;
	line=pos(temp);
	d=line/(float)pow(r*r+s*s,0.5);
	printf("distance is %.2f",d);
	getch();

}
int pos(float x)
{
	if(x<0)
	{
		x=(-1)*x;
		return x;
	}
	else
	{
		return x;
	}

}
