//hilbert curve
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void hilbert(int,int,int ,int ,int ,int);
int main()
{
	int gdriver=DETECT,gmode,i=5;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\BGI");
	//for(i=0;i<10;i++)
	//{
		cleardevice();
		moveto(100,100);
		hilbert(100,100,400,400,i,0);
		getch();
	//}
	closegraph();
}

void hilbert(int x1,int y1,int x2,int y2,int n,int d)
{
	int mx,my;
	mx=(x1+x2)/2;
	my=(y1+y2)/2;
	if(n==1)
	{
		lineto((x1+mx)/2,(y1+my)/2);
		if(d==0)
		{
			lineto((x1+mx)/2,(y2+my)/2);
			lineto((x2+mx)/2,(y2+my)/2);
			lineto((x2+mx)/2,(y1+my)/2);
		}
		else
		{
			lineto((x2+mx)/2,(y1+my)/2);
			lineto((x2+mx)/2,(y2+my)/2);
			lineto((x1+mx)/2,(y2+my)/2);
		}
	}
	else
	{
		hilbert(x1,y1,mx,my,n-1,1-d);
		if(d==1)
		{
			hilbert(mx,y1,x2,my,n-1,1);
			hilbert(mx,my,x2,y2,n-1,1);
			hilbert(mx,y2,x1,my,n-1,0);
		}
		else
		{
			hilbert(x1,my,mx,y2,n-1,0);
			hilbert(mx,my,x2,y2,n-1,0);
			hilbert(x2,my,mx,y1,n-1,1);
		}
	}
}
