#include<stdio.h>
#include<conio.h>
void sort(int *,int *,int);
int x_max(int *,int);
int y_max(int *,int);
int x_min(int *,int);
int y_min(int *,int);
//#include<graphics.h>
/*int instersect()
{
	
	float x,y;
	float slope1,slope2;			//slope1 for line 1 and slope2 for line 2
	float b1,b2;					//b1 for line 1 and b2 for line 2
	int delta_x1,delta_y1;		//for line 1
	int delta_x2,delta_y2;		//for line 2
	
	if(x11>x12)
	{
		delta_x1=x11-x12;
	}
	else
	{
		delta_x1=x12-x11;	
	}
	if(y11>y12)
	{
		delta_y1=y11-y12;	
	}
	else
	{
		delta_y1=y12-y11;
	}
	
	if(x21>x22)
	{
		delta_x2=x21-x22;
	}
	else
	{
		delta_x2=x22-x21;	
	}
	if(y21>y22)
	{
		delta_y2=y21-y22;	
	}
	else
	{
		delta_y2=y22-y21;
	}
	
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
	
	printf("%.2f  %.2f",x,y);
}*/
int main()
{
	FILE *fp;
	int opcode,x,y,x2=0,y2=0,i;
	int ax[10],ay[10];
	int n;
	int xmax,ymax,xmin,ymin;
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
		printf("%d %d",ax[i],ay[i]); 
	}
	//getch();
	//closegraph();
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
	xmax=x_max(*ax,n);
	ymax=y_max(*ay,n);
	xmin=x_min(*ax,n);
	ymin=y_min(*ay,n);
}

int x_max(int ax,int n)
{
	return (ax[n]);
}
int y_max(int ay,int n)
{
	return (ay[n]);
}
int x_min(int ax,int n)
{
	n=0;
	return (ax[n]);
}
int y_min(int ay,int n)
{
	n=0;
	return (ay[n]);
}
