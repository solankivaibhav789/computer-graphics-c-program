#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main()
{
	FILE *fp;
	int opcode,x,y,x2=0,y2=0;
	int gdriver = DETECT, gmode;
	clrscr();
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	fp=fopen("input.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%d %d %d",&opcode,&x,&y);
		//printf("%d %d %d\n",opcode,x,y);
		if(opcode==1)
		{
			putpixel(x,y,3);
		}
		else
		{
			fscanf(fp,"%d %d %d",&opcode,&x2,&y2);
			line(x,y,x2,y2);
		}
	}
	fclose(fp);
	getch();
	closegraph();
	return 0;
}
