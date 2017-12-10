//shearing two type
//1. x shear  -> y remain as it is and x change
//2. y shear  -> x remain as it is and y change
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
struct point
{
	float x;
	float y;
};
int main()
{
	int gdriver = DETECT , gmode;


		//point
	//	struct point p1,p2;
		int i,j,k;

		//input point
	//	p1.x=15;
	//	p1.y=6;

		float m1[4][2];
		float m2[2][2];
		float m[4][2]={{0,0},{0,0},{0,0},{0,0}};

		m1[0][0]=50;
		m1[0][1]=50;
		m1[1][0]=100;
		m1[1][1]=50;
		m1[2][0]=50;
		m1[2][0]=100;
		m1[3][0]=50;
		m1[3][1]=50;

		m[0][0]=50;
		m[0][1]=50;
		m[1][0]=100;
		m[1][1]=50;
		m[2][0]=50;
		m[2][0]=100;
		m[3][0]=50;
		m[3][1]=50;

		float a,b;
		int shear=0;
		initgraph(&gdriver,&gmode,"c:\\turboc3\\BGI");
		//printf("enter 1. x shear\n2.y shear");
		//scanf("%d",&shear);
		shear=1;
		a=5;
		b=5;
		//how much change(shear)
		if(shear==1)
		{
			m2[0][0]=1;
			m2[0][1]=0;
			m2[1][0]=b;
			m2[1][1]=1;
		}
		else
		{
			m2[0][0]=1;
			m2[0][1]=a;
			m2[1][0]=0;
			m2[1][1]=1;
		}

       for(i = 0; i < 4; i++)
	{
	    for(j = 0; j < 2; j++)
	    {
		for(k = 0; k < 2; k++)
		{
		    m[i][j] = m[i][j] + (m1[i][k] * m2[k][j]);
		}
	    }
	}
	//m[0][0] = m1[0][0]+m1[0][1]*b;
	//m[3][0]=m[0][0];
	line(m1[0][0],m1[0][1],m1[1][0],m1[1][1]);
	line(m1[1][0],m1[1][1],m1[2][0],m1[2][1]);
	line(m1[2][0],m1[2][1],m1[3][0],m1[3][1]);

	line(m[0][0],m[0][1],m[1][0],m[1][1]);
	line(m[1][0],m[1][1],m[2][0],m[2][1]);
	line(m[2][0],m[2][1],m[3][0],m[3][1]);
		//printf("output :\n\n p2.x=%f p2.y=%f",p2.x,p2.y);
		getch();
		closegraph();
		return 0;
}
