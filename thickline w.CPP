#include<stdio.h>
#include<Math.h>
#include<graphics.h>
#include<conio.h>

void main(){
	int w,dx,dy,j,i,gd=DETECT,gm;
	float x1,x2,y1,y2,len,temp;

	printf("Enter x,y coordinates for a line.");
	scanf("%f %f %f %f",&x1,&y1,&x2,&y2);

	printf("Enter thickness");
	scanf("%d",&w);

	initgraph(&gd,&gm,"..\\BGI");
	temp=(y2-y1)*(y2-y1)+(x2-x1)*(x2-x1);
	len=sqrt(temp);
	dy=(w/2)*(x2-x1)/len;
	temp=1-((x2-x1)/len)*((x2-x1)/len);
	dx=(w/2)*sqrt(temp);

	for(i=-dy,j=dx;i<dy;i++,j--){
		line(x1+j,y1+i,x2+j,y2+i);
	}



	getch();




}