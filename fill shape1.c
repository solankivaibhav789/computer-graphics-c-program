#include<stdio.h>
#include<conio.h>
void sort(int *,int *,int);
int x_max(int *,int);
int y_max(int *,int);
int x_min(int *,int);
int y_min(int *,int);
//#include<graphics.h>
struct point
{
	int x;
	int y;
};
int instersect(struct point p1,struct point p2,struct point p3,struct point p4)
{
//p1p2 line one
//p3p4 line two
	
	float x,y;
	float slope1,slope2;			//slope1 for line 1 and slope2 for line 2
	float x,y;
	float r1,s1,t1;		//slope1 for line 1 and slope2 for line 2
	float r2,s2,t2;					//b1 for line 1 and b2 for line 2
	
	r1=p2.y-p1.y;
	s1=p1.x-p2.x;
	t1=p2.x*p1.y-p1.x*p2.y;
	
	r2=p4.y-p3.y;
	s2=p3.x-p4.x;
	t2=p4.x*p3.y-p3.x*p4.y;
	
	x=(s1*t2-s2*t1)/(r1*s2-r2*s1);
	y=(r1*t2-r2*t1)/(r2*s1-r1*s2);
	
	printf("%d  %d\n",delta_x1,delta_y1);
	printf("%d  %d\n\n",delta_x2,delta_y2);
	slope1 = (float)delta_y1/delta_x1;
	slope2 = (float)delta_y2/delta_x2;
	
	printf("%.2f  %.2f\n",slope1,slope2);
	
	b1=y11-slope1*x11;
	b2=y21-slope2*x21;
	
	printf("%.2f  %.2f\n\n",b1,b2);
	
	x=(float)(b2-b1)/(slope1-slope2);
	y=(float)(slope1*b2-b1*slope2)/(slope1-slope2);
	
	if(r1*x + s1*y + t1 == 0)
	{
		if(r2*x + s2*y + t2 == 0)
		{
			if(p1.x<=x && x<= p2.x)
			{
				if(p3.x<=x && X<= p4.x)
				{
					if(p1.y<=y && x<= p2.y)
					{
						if(p3.x<=y && X<= p4.y)
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
		printf("x:%d y:%d\n",x,y);
	}
	else
	{
		printf("liine is not intersect");
	}
	
}
int main()
{
	FILE *fp;
	int opcode,x,y,x2=0,y2=0,i;
	int ax[10],ay[10];
	int n;
	/*
	int ax = (int *)malloc(sizeof(int)*n);
	int ay = (int *)malloc(sizeof(int)*n);
	*/
	int xmax,xmin,ymax,ymin;
	//int gdriver = DETECT, gmode;
	//	clrscr();
	//initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	fp=fopen("input.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%d %d %d",&opcode,&x,&y);
		//printf("%d %d %d\n",opcode,x,y);
		if(opcode==1)
		{
			ax[i]=x;
			ay[i]=y;
			//putpixel(x,y,3);
		}
		else
		{
			ax[i]=x;
			ay[i]=y;
			fscanf(fp,"%d %d %d",&opcode,&x2,&y2);
			//line(x,y,x2,y2);
		}
		i++;
	}
	n=i-1;
	fclose(fp);
	for(i=0;i<=n;i++)
	{
		printf("%d %d\n",ax[i],ay[i]); 
	}
	sort(ax,ay,n);
	printf("\n");
	for(i=0;i<=n;i++)
	{
		printf("%d %d ",ax[i],ay[i]); 
	}
	//getch();
	//closegraph();
	xmax=x_max(ax,n);
	ymax=y_max(ay,n);
	xmin=x_min(ax,n);
	ymin=y_min(ay,n);
	
	printf("\n\nxmax=%d\n",xmax);
	printf("ymax=%d\n",ymax);
	printf("xmin=%d\n",ymin);
	printf("ymin=%d\n",ymin);
	return 0;
}
void sort(int *a,int *b,int n)
{
	int i,j,temp=0;
	for(i=0;i<n;i++)
	{
		for(j=n;j>i-1;j--)
		{
			if(a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;	
			}
			if(b[j]<b[j-1])
			{
				temp=b[j];
				b[j]=b[j-1];
				b[j-1]=temp;
			}
		}
	}
	
}

int x_max(int ax[],int n)
{
	return (ax[n]);
}
int y_max(int ay[],int n)
{
	return (ay[n]);
}
int x_min(int ax[],int n)
{
	n=0;
	return (ax[n]);
}
int y_min(int ay[],int n)
{
	n=0;
	return (ay[n]);
}
