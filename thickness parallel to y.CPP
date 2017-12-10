#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void main(){
	int x1,y1,x2,y2,w,dx,dy,i,gd=DETECT,gm;

	printf("Enter x,y coordinates for a line.");
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

	printf("Enter thickness");
	scanf("%d",&w);

	initgraph(&gd,&gm,"..\\BGI");
	dy=w/2;

	for(i=-dy;i<dy;i++){
		line(x1,y1+i,x2,y2+i);
	}



	getch();`




}