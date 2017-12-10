//intersection of two line general
#include<stdio.h>
#include<conio.h>
//#include<graphics.h>


int main()
{
	//float x11=0,x12=0,y11=0,y12=3;		//for line 1
	//float x21=5,x22=5,y21=1,y22=-1;		//for line 2
	
	
	float x11=0,x12=5,y11=0,y12=0;		//for line 1
	float x21=5,x22=5,y21=-1,y22=1;		//for line 2
	
	float x=0,y=0;
	
	
	float r1=0,s1=0,t1=0;		//slope1 for line 1 and slope2 for line 2
	float r2=0,s2=0,t2=0;					//b1 for line 1 and b2 for line 2
	
	int flag=0;
	
	r1=y12-y11;
	s1=x11-x12;
	t1=x12*y11-x11*y12;
	
	r2=y22-y21;
	s2=x21-x22;
	t2=x22*y21-x21*y22;
	
	printf("r1:%f s1:%f t1:%f\n",r1,s1,t1);
	printf("r2:%f s2:%f t2:%f\n",r2,s2,t2);
	x=(s1*t2-s2*t1)/(r1*s2-r2*s1);
	y=(r1*t2-r2*t1)/(r2*s1-r1*s2);
	
	printf("line 1:x11:%f  y11:%f  x12:%f  y12:%f\n",x11,y11,x12,y12);
	printf("line 2:x21:%f  y21:%f  x22:%f  y22:%f\n",x21,y21,x22,y22);
	printf("x:%f  y:%f\n",x,y);	
	
//	printf("%.f  %.f",x,y);
	
	if(r1*x+s1*y+t1==0)
	{
		if(r2*x+s2*y+t2==0)
		{
			if(x11<=x && x<=x12)
			{	
				if(x21<=x && x<=x22)
				{
					if(y11<=y && y<=y12 )
					{
						if(y21<=y && y<=y22)
						{
							flag=1;	
						}										
					}
					
				}
			}
		}
	}
	
	
	
	
	if(flag==1)
	{
		printf("line is intersect\n");
		printf("x:%f    y:%f",x,y);
	}
	else
	{
		printf("line is not intersect");
	}
						
	
	return 0;
	
}
