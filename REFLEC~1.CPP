//reflection of polygon
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

		//matrix
		float m1[4][2]={{0,0},{0,0},{0,0},{0,0},};
		float m2[2][2]={{0,0},{0,0}};
		float m[4][2]={{0,0},{0,0},{0,0},{0,0}};
		m2[0][0]=0;
		m2[0][1]=0;
		m2[1][0]=0;
		m2[1][1]=0;
		//row and column of matrix 1
		int rm1=1,cm1=2;
		//row and column of matrix 2
		int rm2=2,cm2=2;
		//point
		struct point p1;
		int i,j,k;

		p1.x=2;
		p1.y=3;
		i=4;
		printf("enter i for reflection with respect to \n1. x\n2.y\n \n3.origin \n4.y=x line \n5.y=-x line\n\n");
		//scanf("%d",i);
		//assign value to scaling factor
		switch(i)
		{
			case 1:
				m2[0][0]=-1;
				m2[1][1]=1;
				break;
			case 2:
				m2[0][0]=1;
				m2[1][1]=-1;
				break;
			case 3:
				m2[0][0]=-1;
				m2[1][1]=-1;
				break;
			case 4:
				m2[0][1]=1;
				m2[1][0]=1;
				break;
			case 5:
				m2[0][1]=-1;
				m2[1][0]=-1;
				break;
		}
		initgraph(&gdriver,&gmode,"c:\\turboc3\\BGI");
		m1[0][0]=50;
		m1[0][1]=50;
		m1[1][0]=100;
		m1[1][1]=50;
		m1[2][0]=50;
		m1[2][0]=100;
		m1[3][0]=50;
		m1[3][1]=50;


		/*for(i=0;i<1;i++)
		{
			for(j=0;j<2;j++)
			{
				printf("%f ",m1[i][j]);
			}
			printf("\n");
		}
		printf("\n\n\n");

		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				printf("%f ",m2[i][j]);
			}
			printf("\n");
		}*/

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
	/*for(i=0;i<1;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("m[%d][%d]=%f\n",i,j,m[i][j]);
			}
		}*/
		//initgraph(gdriver,gmode,"c:\\truboc3\\BGI");
		//putpixel(m[0][0],m[0][1]);
	line(m1[0][0],m1[0][1],m1[1][0],m1[1][1]);
	line(m1[1][0],m1[1][1],m1[2][0],m1[2][1]);
	line(m1[2][0],m1[2][1],m1[3][0],m1[3][1]);

	line(m[0][0],m[0][1],m[1][0],m[1][1]);
	line(m[1][0],m[1][1],m[2][0],m[2][1]);
	line(m[2][0],m[2][1],m[3][0],m[3][1]);

	getch();
	closegraph();
		return 0;
}
