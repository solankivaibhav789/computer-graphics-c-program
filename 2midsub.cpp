#include<stdio.h>
#include<conio.h>
#include<graphics.h>

struct point 
{
	int x,y;
	int pcode[4];
}p;
int logical(point p1,point p2);
int Integer(float x);
int visible(point p1,point p2,int sum1,int sum2)
{
	//vflag=1 for partial,0 for totally visible,2 for invisible
	int vflag=1;
	int Inter;
	if(sum1==0 && sum2==0)
	{
		vflag=0;
	}
	else
	{
		Inter=logical(p1,p2);
		if(Inter!=0)
		{
			vflag=2;
		}
	}
}
int sum(point p)
{
	int sum=0;
	int i;
	for(i=0;i<4;i++)
	{
		sum=sum+p.pcode[i];
	}
	return sum;
}
int logical(point p1,point p2)
{
	int Inter=0;
	int i;
	for(i=0;i<4;i++)
	{
		int a=Integer((p1.pcode[i]+p2.pcode[i])/2);
		Inter=Inter+a;
	}
	return Inter;
}
int copy(point p1,point p2)
{
	int i;
	for(i=0;i<4;i++)
	{
		p2.pcode[i]=p1.pcode[i];
	}
}
int Integer(float x)
{
	if(x<0)
	{
		return (x-0.5);
	}
	else
	{
		return (x+0.4);
	}
}

int main()
{
		struct point p1,p2,savep2,savep1,temp,pm;
		int i,tempsum1,Inter;
		int error=1;
		int sum1=0,sum2=0;
		sum1=sum(p1);
		sum2=sum(p2);
		int vflag=0;
		vflag=visible(p1,p2,sum1,sum2);
		for(i=1;i<=2;i++)
		{
			if(i==1 && sum1==0)
			{
				savep2=p1;
				temp=p2;
				p2=p1;
				p1=temp;
				i=2;
			}
			if(i==1 && sum2==0)
			{
				temp=p2;
				p2=p1;
				p1=temp;
				savep2=p1;
				i=2;
			}
			savep1=p1;
			tempsum1=sum1;
			copy(p1,savep1);
			while(abs(p2.x-p1.x)>error || abs(p2.y-p1.y)>error)
			{
				pm.x=Integer((p1.x+p2.x)/2);
				pm.y=Integer((p1.y+p2.y)/2);
				temp=p1;
				p1=pm;
				sum(p1);
				vflag=visible(p1,p2,sum1,sum2);
				if(vflag==2)
				{
					p1=temp;
					p2=pm;
					copy(p1,p2);
					sum2=sum1;
					sum(p1);
				}
			}
			if(i==1)
			{
				savep2=pm;
				p1=pm;
				p2=savep1;
				sum2=tempsum1;
				copy(savep1,p2);
			}
			else
			{
				p1=pm;
				p2=savep2;
			}
			sum(p1);
			sum(p2);
			vflag=visible(p1,p2,sum1,sum2);
		}
		if(Inter==0)
		{
			//line(p1.x,p1.y,p2.x,p2.y);
		}
}
