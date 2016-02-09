#include <graphics.h>
#include <math.h>
#define PI 3.14159265

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


void pentagon(int x, int y, float scalex,float scaley, float angle){
	drawLine(x,y,x+100,y,RED,scalex,scaley,angle);
	
	drawLine(x,y,x-30,y-80,RED,scalex,scaley,angle);
	drawLine(x+100,y,x+130,y-80,RED,scalex,scaley,angle);

	drawLine(x+50,y-150,x-30,y-80,RED,scalex,scaley,angle);
	drawLine(x+50,y-150,x+130,y-80,RED,scalex,scaley,angle);
}

int main(){
	int gd = DETECT, gm;

	int x = 200, y= 150,i,angle,choice,n1,n,m1;

	//pentagon(x,y,1,0);
	
	printf("\n1.Translation\n2.Rotation \n3.Scaling\nYour choice: ");
	scanf("%d",&choice);
	
	initgraph(&gd,&gm,NULL);
	switch(choice){
		case 1://for(i=0;i<100;i++)
			{
			scanf("%d%d",&n1,&m1);
			n=60;
			cleardevice();
			pentagon(x,y,1,1,0);
			delay(1500);
			cleardevice();
			pentagon(x+n1,y+m1,1,1,0);
			delay(1500);
		}
		break;

		case 2://for(i=0;i<100;i++)
			{
			n=40;
			cleardevice();
			pentagon(x,y,1,1,0);
			delay(1500);
			cleardevice();
			pentagon(x,y,1,1,n/80.0);
			delay(1500);
		}
		break;

		case 3://for(i=0;i<100;i++)
			{
			n=30;
			cleardevice();
			pentagon(x,y,1,1,0);
			delay(1500);
			cleardevice();
			pentagon(x,y,(100+n)/100.0,(100-n)/100.0,0);
			
			delay(1500);
		}
		break;
	}

	delay(100000000);
	closegraph();

	return 0;
}
