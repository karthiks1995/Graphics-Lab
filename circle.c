#include<graphics.h>
#include<stdio.h>
void main()
{
	int gd=DETECT,gm;
	int d,r,x,y,xc,yc;
	
	printf("Enter Radius\n");
	scanf("%d",&r);
	printf("Enter Center of circle\n");
	scanf("%d",&xc);
	scanf("%d",&yc);
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
	getch();
}
