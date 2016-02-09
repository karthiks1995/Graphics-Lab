#include<stdio.h>
#include<graphics.h>
#include<math.h>
void Draw_Circle(int X, int Y, int P, int Q)
{
	int color=7;
	putpixel (X + P, Y + Q,color);
	putpixel (X - P, Y + Q,color);
	putpixel (X + P, Y - Q,color);
	putpixel (X - P, Y - Q,color);
	putpixel (X + Q, Y + P,color);
	putpixel (X - Q, Y + P,color);
	putpixel (X + Q, Y - P,color);
	putpixel (X - Q, Y - P,color);

}

void circle(int x, int y, int r)
{
	int d, p, q;
	p=0;
	q=r;
	d=3-r;
	d=d-r;

	while(p<=q)
    {
     
    	Draw_Circle(x,y,p,q);
    	if(d<=0)
    		d=d+(4*p)+6;
    	else
    	{
    		d=d+4*(p-q)+10;
    		q=q-1;
    	}
    	p++;
    	
    }
}

void draw_line(int x1, int y1, int x2, int y2)
{

	int x, y;
	int dx, dy, p, end;
	dx = abs(x1 - x2);
	dy = abs(y1 - y2);
	if(dx>dy)
	{
		p = 2 * dy - dx;
		if(x1 > x2)
		{
		    x = x2;
		    y = y2;
		    end = x1;
		}
		else
		{
		    x = x1;
		    y = y1;
		    end = x2;
		}
		putpixel(x, y, 7);
		while(x < end)
		{
		    x = x + 1;
		    if(p < 0)
		    {
		          p = p + 2 * dy;
		    }
		    else
		    {
		    	if(y2>y1)
		          	y = y + 1;
		        else
		        	y=y-1;
		        p = p + 2 * (dy - dx);
		    }
		    putpixel(x, y, 7);
		}
	}
	else
	{
		p = 2 * dx - dy;
		if(y1 > y2)
		{
		    x = x2;
		    y = y2;
		    end = y1;
		}
		else
		{
		    x = x1;
		    y = y1;
		    end = y2;
		}
		putpixel(x, y, 7);
		while(y < end)
		{
		    y = y + 1;
		    if(p < 0)
		    {
		          p = p + 2 * dx;
		    }
		    else
		    {
		    	if(x2>x1)
		            x = x + 1;
		        else 
		        	x = x - 1;
		        
		        p = p - 2 * (dy - dx);
		    }
		    putpixel(x, y, 7);
		}	
	}
}

int main()
{
	float i,n=100;
	int x[10],y[10];
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\tc\bgi");

	
	x[1]=150;	y[1]=20;
	x[2]=100;	y[2]=80;
	x[3]=125;	y[3]=130;
	x[4]=175;	y[4]=130;
	x[5]=200;	y[5]=80;
	cleardevice();
	//draw_line(x[1],y[1],x[2],y[2]);
	//draw_line(x[2],y[2],x[3],y[3]);
	//draw_line(x[3],y[3],x[4],y[4]);
	draw_line(0,0,125,125);
	//draw_line(x[5],y[5],x[1],y[1]);
	
	delay(10000);

}






















