#include<stdio.h>
#include<graphics.h>

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
	int x, y, r, x1, y1, x2, y2;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\tc\bgi");
	

	draw_line(100,80,100,150);
	circle(100,55,25);
	draw_line(70,110,100,100);
	draw_line(100,100,130,110);
	draw_line(70,170,100,150);
	draw_line(100,150,130,170);
	


	draw_line(300,80,300,150);
	circle(300,55,25);
	draw_line(270,100,330,100);
	draw_line(270,170,300,150);
	draw_line(300,150,330,170);



	draw_line(500,80,500,150);
	circle(500,55,25);	
	draw_line(470,100,500,110);
	draw_line(500,110,530,100);
	draw_line(470,170,500,150);
	draw_line(500,150,530,170);


	delay(10000);
    closegraph();
    return 0;
}
