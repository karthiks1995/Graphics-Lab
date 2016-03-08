#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

void setfillstyle( int pattern, int color);

void drawLine(int X0,int Y0,int X1,int Y1, int color, float scalex,float scaley, float angle){
	int dx,dy,Steps,v,a1,b1,a2,b2,p=0,q=0;
	float x,y,Xincrement,Yincrement;
	X0 = (int)X0*scalex;
	X1 = (int)X1*scalex;
	Y0 = (int)Y0*scaley;
	Y1 = (int)Y1*scaley;

    a1=p+(X0-p)*cos(angle)-(Y0-q)*sin(angle);
    b1=q+(X0-p)*sin(angle)+(Y0-q)*cos(angle);

    a2=p+(X1-p)*cos(angle)-(Y1-q)*sin(angle);
    b2=q+(X1-p)*sin(angle)+(Y1-q)*cos(angle);

    X0 = (int)a1;
    Y0 = (int)b1;

    X1 = (int)a2;
    Y1 = (int)b2;

	dx = X1-X0;
	dy = Y1-Y0;

	if(dx>dy){
		Steps = abs(dx);
	}
	else{
		Steps = abs(dy);
	}

	Xincrement = dx / (float)Steps;
	Yincrement = dy / (float)Steps;
		
	x = X0;
	y = Y0;

	for(v=0;v<Steps;v++){
		putpixel(x,y,color);
		x = (x + Xincrement);
		y = (y + Yincrement);
	}
}


house(float xs,float ys,int xt,int yt,int world[])
{
	int x[10],y[10],i;
	x[1]=100;	y[1]=100;
	x[2]=50;	y[2]=150;
	x[3]=150;	y[3]=150;
	x[4]=50;	y[4]=220;
	x[5]=150;	y[5]=220;
	x[6]=75;	y[6]=180;
	x[7]=125;	y[7]=180;
	x[8]=75;	y[8]=220;
	x[9]=125;	y[9]=220;
	for(i=0;i<=9;i++){
		x[i]=x[i]-xt;
		y[i]=y[i]-yt;
	}
	
	drawLine(x[1],y[1],x[2],y[2],RED,xs,ys,0);
	drawLine(x[1],y[1],x[3],y[3],RED,xs,ys,0);
	drawLine(x[2],y[2],x[3],y[3],RED,xs,ys,0);
	drawLine(x[2],y[2],x[4],y[4],RED,xs,ys,0);
	drawLine(x[4],y[4],x[5],y[5],RED,xs,ys,0);
	drawLine(x[3],y[3],x[5],y[5],RED,xs,ys,0);
	drawLine(x[6],y[6],x[7],y[7],RED,xs,ys,0);
	drawLine(x[6],y[6],x[8],y[8],RED,xs,ys,0);
	drawLine(x[8],y[8],x[9],y[9],RED,xs,ys,0);
	drawLine(x[7],y[7],x[9],y[9],RED,xs,ys,0);	
	
	drawpoly(5,world);
}
int main()
{
	int gd=DETECT,gm,x[10],y[10];
	int x1=300,y1=200,i;
	/*printf("Enter x1,y1,x2,y2\n ");
	scanf("%d%d%d%d",&x[1],&y[1],&x[2],&y[2]);
	printf("Enter x3,y3,x4,y4\n ");
	scanf("%d%d%d%d",&x[3],&y[3],&x[4],&y[4]);*/
	x[1]=50;  y[1]=50;
	x[2]=300; y[2]=300;

	x[3]=10;y[3]=30;
	x[4]=50;y[4]=150;
	int world[]={x[1],y[1],x[2],y[1],x[2],y[2],x[1],y[2],x[1],y[1]};
	initgraph(&gd, &gm, NULL);
	house(1,1,0,0,world);
	
	delay(2000);
	cleardevice();
	
	int world2[]={0,0,x[2]-x[1],0,x[2]-x[1],y[2]-y[1],0,y[2]-y[1],0,0};
	house(1,1,x[1],y[1],world2);

	delay(2000);
	float sx,sy;
	 sx=(float)(x[4]-x[3])/(x[2]-x[1]);
	 sy=(float)(y[4]-y[3])/(y[2]-y[1]);
	cleardevice();
	int world3[]={0,0,x[4]-x[3],0,x[4]-x[3],y[4]-y[3],0,y[4]-y[3],0,0};
	house(sx,sy,x[1],y[1],world3);
	delay(2000);
	cleardevice();
	int world4[]={x[3],y[3],x[4],y[3],x[4],y[4],x[3],y[4],x[3],y[3]};
	house(sx,sy,-x[3],-y[3],world4);
	delay(2000);
	closegraph();
	return 0;
}
