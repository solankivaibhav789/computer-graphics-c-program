//rotation of polygon
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.14159265
struct point
{
	float x;
	float y;
};
int main()
{
	int gdriver = DETECT , gmode;
		//sa and sb is scaling factor
		float sa,sb;
		float val=PI/180;
		//x is theta value in degree
		int x;
		//direction for clockwise and anticlockwise
		int direction;
		//matrix
		float m1[4][2];
		float m2[2][2];
		float m[4][2]={{0,0},{0,0},{0,0},{0,0}};
		//row and column of matrix 1
		//int rm1=1,cm1=2;
		//row and column of matrix 2
		//int rm2=2,cm2=2;
		//point
		//struct point p1;
		int i,j,k;

		/*printf("enter the i:");
		scanf("%d",&i);
		printf("enter the p1.x: and p1.y");
		scanf("%f %f",&p1.x,&p1.y);
		printf("enter 1.clockwise\n2.anticlockwise\n\n");
		scanf("%d",direction);
		//assign value to scaling factor
		switch(i)
		{
			case 1:
				x=30;
				break;
			case 2:
				x=45;
				break;
			case 3:
				x=60;
				break;
			case 4:
				x=90;
				break;
			case 5:
				x=120;
				break;
			case 6:
				x=150;
				break;
			case 7:
				x=180;
				break;
			default:
				x=0;
				break;
		}*/
		float a,b;
		initgraph(&gdriver,&gmode,"");
		//input
		i=1;
		m1[0][0]=50;
		m1[0][1]=50;
		m1[1][0]=100;
		m1[1][1]=50;
		m1[2][0]=50;
		m1[2][0]=100;
		m1[3][0]=50;
		m1[3][1]=50;

		direction=2;
		x=30;


		a=sin(x*val);
		b=cos(x*val);
		if(direction==1)
		{
			//if clockwise
			m2[0][0]=b;
			m2[0][1]=-a;
			m2[1][0]=a;
			m2[1][1]=b;
		}
		else
		{
			//if anticlockwise
			m2[0][0]=b;
			m2[0][1]=a;
			m2[1][0]=-a;
			m2[1][1]=b;
		}

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
        line(m1[0][0],m1[0][1],m1[1][0],m1[1][1]);
        line(m1[1][0],m1[1][1],m1[2][0],m1[2][1]);
        line(m1[2][0],m1[2][1],m1[3][0],m1[3][1]);

        line(m[0][0],m[0][1],m[1][0],m[1][1]);
        line(m[1][0],m[1][1],m[2][0],m[2][1]);
        line(m[2][0],m[2][1],m[3][0],m[3][1]);
        /*
        for(i=0;i<1;i++)
        {
        	for(j=0;j<2;j++)
        	{
        		printf("m[%d][%d]=%f\n",i,j,m[i][j]);
			}
		}*/
		getch();
		closegraph();
		return 0;
}
