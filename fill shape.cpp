#include<stdio.h>
#include<conio.h>
//#include<graphics.h>
void sort(int *,int *);
int x_max(int *);
int y_max(int *);
int x_min(int *);
int y_min(int *);

int main()
{
	FILE *fp;
	int opcode,x,y,x2=0,y2=0,i;
	static int ax[10],ay[10];
	static int n;
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
	sort(ax,ay);
	printf("\n");
	for(i=0;i<=n;i++)
	{
		printf("%d %d",ax[i],ay[i]); 
	}
	//getch();
	//closegraph();
	return 0;
}
void sort(int *a,int *b)
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
int x_max(int ax)
{
	return ax[n];
}
int y_max(int ay)
{
	return ay[n];
}
int x_min(int ax)
{
	return ax[0];
}
int y_min(int ay)
{
	return ay[0];
}
