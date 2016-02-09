#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

void setfillstyle( int pattern, int color);

drawCube(int x, int y, int x1, int y1, float angle){

	int a1,b1,a2,b2,p=x,q=y;
    	a1=p+(x-p)*cos(angle)-(y-q)*sin(angle);
    	b1=q+(x-p)*sin(angle)+(y-q)*cos(angle);

    	a2=p+(x1-p)*cos(angle)-(y1-q)*sin(angle);
   	 b2=q+(x1-p)*sin(angle)+(y1-q)*cos(angle);

    	x = (int)a1;
   	 y = (int)b1;

   	 x1 = (int)a2;
   	 y1 = (int)b2;

	int points1[]={x,y,x+150,y,x+150,y+150,x,y+150,x,y};
	int points2[]={x1,y1,x1+150,y1,x1+150,y1+150,x1,y1+150,x1,y1};
	int points3[]={x,y,x,y+150,x1,y1+150,x1,y1,x,y};
	int points4[]={x+150,y,x+150,y+150,x1+150,y1+150,x1+150,y1,x+150,y};
	int points5[]={x,y,x1,y1,x1+150,y1,x+150,y,x,y};
	int points6[]={x,y+150,x1,y1+150,x1+150,y1+150,x+150,y+150,x,y+150};

	setlinestyle(3,2,1);
	setcolor(12);
	fillpoly(5, points1);
	drawpoly(5,points1);

	setlinestyle(3,2,1);
	setcolor(RED);
	fillpoly(5, points2);
	drawpoly(5, points2);	
	
	setlinestyle(3,2,1);
	setcolor(BLUE);
	fillpoly(5, points3);
	drawpoly(5, points3);

	setlinestyle(3,2,1);
	setcolor(GREEN);
	fillpoly(5, points4);
	drawpoly(5, points4);

	setlinestyle(3,2,1);
	setcolor(WHITE);
	fillpoly(5, points5);
	drawpoly(5, points5);

	setlinestyle(3,2,1);
	setcolor(YELLOW);
	fillpoly(5, points6);
	drawpoly(5, points6);
	
	setcolor(BLACK);
	drawpoly(5,points1);
	drawpoly(5,points2);
	drawpoly(5,points3);
	drawpoly(5,points4);
	drawpoly(5,points5);
	drawpoly(5,points6);

	
}
int main()
{
	int gd=DETECT,gm,x=200,y=200,x1,y1,i;
	x1=x+75;
	y1=y+75;

	initgraph(&gd, &gm, NULL);
	for(i=0;i<500;i++){
		cleardevice();
		drawCube(x,y,x1,y1,i/80.0);
		delay(35);
	}
	delay(20000);
	closegraph();
	return 0;
}
