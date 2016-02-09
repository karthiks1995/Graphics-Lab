#include <graphics.h>
#include <stdio.h>
#include <math.h>
 
void draw(int r,int xc,int yc)
{
	int gd=DETECT,gm;
	int d,x,y;
	

	initgraph(&gd,&gm,"c:\\tc\\");
	d=3-2*r;
	x=0;
	y=r;
	while(x<=y)
	{
		putpixel(xc+x,yc+y,BLUE);
		putpixel(xc-y,yc-x,BLUE);
		putpixel(xc+y,yc-x,BLUE);
		putpixel(xc-y,yc+x,BLUE);
		putpixel(xc+y,yc+x,BLUE);
		putpixel(xc-x,yc-y,BLUE);
		putpixel(xc+x,yc-y,BLUE);
		putpixel(xc-x,yc+y,BLUE);
		if(d<=0)
		{
			d=d+4*x+6;
		}
		else
		{
			d=d+4*x-4*y+10;
			y=y-1;
		}
	x=x+1;
	}

}
void draw_line(int x1,int y1,int x2,int y2,int clr)
{
	int gd = DETECT, gm = DETECT, s, dx, dy, m;
    float xi, yi, x, y;
 
    
 
    
 
    initgraph(&gd, &gm, "");
    //cleardevice();
 
    dx = x2 - x1;
    dy = y2 - y1;
 
    if (abs(dx) > abs(dy))
	s = abs(dx);
    else
	s = abs(dy);
 
    xi = dx / (float) s;
    yi = dy / (float) s;
 
    x = x1;
    y = y1;
 
    putpixel(x1, y1, clr);
 
    for (m = 0; m < s; m++) {
	x += xi;
	y += yi;
	putpixel(x, y, clr);
    }
    
}
void main()
{
 
 
	int a[8],b[8],i,x1,y1,x2,y2;
    float xi, yi, x, y;
 	a[0]=0;b[0]=0;            		a[1]=300;b[1]=0;
	a[2]=0;b[2]=67;           		a[3]=300;b[3]=67;
	a[4]=0;b[4]=67+67;           	a[5]=300;b[5]=67+67;
	a[6]=0;b[6]=67+67+67;			a[7]=300;b[7]=67+67+67;
    
 

 	for(i=0;i<8;i+=2)
	{
		//draw_line(a[i],b[i],a[i+1],b[i+1],4);
	}

	draw_line(a[0],b[0],a[6],b[6],4);
	draw_line(a[1],b[1],a[7],b[7],4);
	draw((b[2]-b[0])/2,(a[1]-a[0])/2,(b[7]-b[1])/2);
	
	for(i=b[0];i<b[2];i++)
	{
		draw_line(a[0],i,a[1],i,12);
	}
	for(i=b[2];i<b[4];i++)
	{
		draw_line(a[0],i,a[1],i,WHITE);
	}
	for(i=b[4];i<b[6];i++)
	{
		draw_line(a[0],i,a[1],i,GREEN);
	}
	draw((b[2]-b[0])/2,(a[1]-a[0])/2,(b[7]-b[1])/2);
	draw_line(150,67,150,67+67,BLUE);
	draw_line(150-33.5,67+67/2,150+33.5,67+67/2,BLUE);
	delay(1000);
    getch();
}























