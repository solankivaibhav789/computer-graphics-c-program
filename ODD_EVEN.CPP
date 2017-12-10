#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
int intersection(float x11, float y11, float x12, float y12, float x21, float y21, float x22, float y22);

int main()
{
	int gdriver = DETECT, gmode;
	float x[4], y[4];
	float x1, y1;
	float max_x = 100, max_y = 100, min_x = 0, min_y = 0;
	float new_x1, new_y1, new_x2, new_y2;
	int i;
	int flag = 0;
	int no_intersection = 0;

	/*x[0]=50;y[0]=80;
	x[1]=50;y[1]=150;
	x[2]=100;y[2]=80;
	x[3]=140;y[3]=160;
	x[4]=170;y[4]=40;
	x[5]=80;y[5]=20;
	x[6]=50;y[6]=50;*/
	/*x[0] = 0; y[0] = 0;
	x[1] = 100; y[1] = 0;
	x[2] = 100; y[2] = 100;
	x[3] = 0; y[3] = 100;
	x[4] = 0; y[4] = 0;*/

	x[0] = 0; y[0] = 0;
	x[1] = 100; y[1] = 0;
	x[2] = 0; y[2] = 100;
	x[3] = 0; y[3] = 0;

	/*printf("enter the co-ordinate:");
	scanf("%f %f", &x1, &y1);
	new_x1 = min_x-1;
	new_y1 = y1;
	new_x2 = x1;
	new_y2 = y1;
	float new_x3, new_x4, new_y3, new_y4;
	*/

	initgraph(&gdriver,&gmode,"c:\\turboc3\\BGI");
	for(i=0;i<3;i++)
	{
		line(x[i],y[i],x[i+1],y[i+1]);
	}
	//line(new_x1,new_y1,new_x2,new_y2);
	/*if (x1<min_x || x1>max_x || y1<min_y || y1>max_y)
	{
		printf("outside");
	}
	else
	{*/
	for(new_x2=min_x;new_x2<=max_x;new_x2++)
	{
	for(new_y2=min_y;new_y2<=max_y;new_y2++)
	{
		new_x1=min_x-1;
		new_y1=new_y2;
		no_intersection=0;
		for (i = 0; i < 3; i++)
		{
			flag = intersection(new_x1, new_y1, new_x2, new_y2,x[i], y[i], x[i+1], y[i+1]);
			if (flag == 1)
			{
				flag = 0;
				no_intersection = no_intersection + 1;
			}
			else
			{

			}
		}
		//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\no of intersection: %d\n", no_intersection);
		if (no_intersection % 2 == 0)
		{

			//printf("\n\noutside\n\n");
		}
		else
		{
			putpixel(new_x2,new_y2,5);
			//printf("\n\ninside\n\n");
		}
	}
	}

	getch();
	closegraph();
	return 0;
}
int intersection(float x11, float y11, float x12, float y12, float x21, float y21, float x22, float y22)
{
	float r1=0, s1=0, t1=0, r2=0, s2=0, t2=0;
	int x=0, y=0;
	int flag = 0;

	r1 = y12 - y11;
	s1 = x11 - x12;
	t1 = x12*y11 - x11*y12;

	r2 = y22 - y21;
	s2 = x21 - x22;
	t2 = x22*y21 - x21*y22;

	x = fabs((float)(s1*t2 - s2*t1) / (r1*s2 - r2*s1));
	y = fabs((float)(r1*t2 - r2*t1) / (r2*s1 - r1*s2));

	if(x21>x22)
	{
		float temp;
		temp = x22;
		x22 = x21;
		x21 = temp;
	}
	if (y21 > y22)
	{
		float temp;
		temp = y22;
		y22 =y21;
		y21 = temp;
	}
	if (x11>x12)
	{
		float temp;
		temp = x12;
		x12 = x11;
		x11 = temp;
	}
	if (y11 > y12)
	{
		float temp;
		temp = y12;
		y12 = y11;
		y11 = temp;
	}

	if (r1*x + s1*y + t1 == 0)
	{

		if (r2*x + s2*y + t2 == 0)
		{

			if (x11 <= x && x <= x12)
			{

				if (x21 <= x && x <= x22)
				{

					if (y11 <= y && y <= y12)
					{

						if (y21 <= y && y <= y22)
						{

							flag = 1;

						}
					}

				}
			}
		}
	}
	return flag;
}

