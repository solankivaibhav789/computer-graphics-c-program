#include<stdio.h>
#include<conio.h>
#include<graphics.h>
//`#define 1 DRAW_POINT()
//#define 2 DRAW_LINE()

void main()
{
	int c;
	FILE *fp;
	fp = fopen("c:\\Users\\rabunsana\\Desktop\\computer graphics\\test.in","r");
	if(fp)
	{
		while((c=getc(fp))!=EOF)
		{
			putchar(c);

		}
		fclose(fp);
	}
	getch();
}