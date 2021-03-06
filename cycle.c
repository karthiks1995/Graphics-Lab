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
	float i,x[10],y[10],n=100;
	
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\tc\bgi");
	int mark=0;
	//while(mark!=4)
{
	cleardevice();
	printf("1.Translate\n2.Scale\n3.Rotate\n4.Exit\nChouce: ");
	//scanf("%d",&mark);
	//if(mark==1)
	{
	//for(i=0;i<=n;i++)
		printf("Value of n: ");
		//scanf("%f",&n);
		i=0;
		{
			cleardevice();
			circle(150+i,95,25);
			draw_line(150+i,120,150+i,180);  //body
			draw_line(100+i,180,200+i,180);	//horizontal
			circle(100+i,180,30);		//back wheel
			circle(200+i,180,30);	//front wheel
			draw_line(200+i,150,200+i,120);	//handle vertical
			draw_line(180+i,120,220+i,120);	//handle horizontal
			delay(2000);
		}
		i=n;
		{
			cleardevice();
			circle(150+i,95,25);
			draw_line(150+i,120,150+i,180);  //body
			draw_line(100+i,180,200+i,180);	//horizontal
			circle(100+i,180,30);		//back wheel
			circle(200+i,180,30);	//front wheel
			draw_line(200+i,150,200+i,120);	//handle vertical
			draw_line(180+i,120,220+i,120);	//handle horizontal
			delay(2000);
		}
		
		
	}
	x[1]=250; y[1]=120;
	x[2]=250; y[2]=180;
	x[3]=200; y[3]=180;
	x[4]=300; y[4]=180;
	x[7]=250; y[7]=95;
	x[5]=300; y[5]=150;
	x[6]=300; y[6]=120;
	x[8]=280; y[8]=120;
	x[9]=320; y[9]=120;
	i=0;
	/*for(i=0;i<15;i++)	
	{
		cleardevice();
		circle(x[7],y[7]-2*i,25+i);
		draw_line(x[1],y[1]-i,x[2],y[2]);  //body
		draw_line(x[3]-i,y[3],x[4]+i,y[4]);	//horizontal
		circle(x[3]-i,y[3],30+i/2);		//back wheel
		circle(x[4]+i,y[4],30+i/2);	//front wheel
		draw_line(x[6]+i,y[6]-i/2,x[5]+i,y[5]-i/2);	//handle vertical
		draw_line(x[8]+i,y[8]-i/2,x[9]+i,y[9]-i/2);	//handle horizontal
		delay(10);
		
	}*/
	//if(mark==2)
	{
		printf("Scale value: ");
		//scanf("%f",&i);
		i=1.7;
	//for(i=0.1;i<2;)	
		{
			cleardevice();
			circle(x[7]*i,y[7]*i,25*i);
			draw_line(x[1]*i,y[1]*i,x[2]*i,y[2]*i);  //body
			draw_line(x[3]*i,y[3]*i,x[4]*i,y[4]*i);	//horizontal
			circle(x[3]*i,y[3]*i,30*i);		//back wheel
			circle(x[4]*i,y[4]*i,30*i);	//front wheel
			draw_line(x[6]*i,y[6]*i,x[5]*i,y[5]*i);	//handle vertical
			draw_line(x[8]*i,y[8]*i,x[9]*i,y[9]*i);	//handle horizontal
			delay(10);
			i=i+0.1;
			delay(2000);
		}
	}
	//if(mark==3)
	{
		float th=20;
		float r11,r12,r21,r22;
		r11=cos((th*3.1428)/180);
		r12=sin((th*3.1428)/180);
		r21=(-sin((th*3.1428)/180));
		r22=cos((th*3.1428)/180);
	
		cleardevice();
		circle(x[7],y[7],25);
		draw_line(x[1],y[1],x[2],y[2]);  //body
		draw_line(x[3],y[3],x[4],y[4]);	//horizontal
		circle(x[3],y[3],30);		//back wheel
		circle(x[4],y[4],30);	//front wheel
		draw_line(x[6],y[6],x[5],y[5]);	//handle vertical
		draw_line(x[8],y[8],x[9],y[9]);
		int j;
		delay(2000);
		for(j=0;j<10;j++)
		{
			
			x[j]=((x[j]*r11)-(y[j]*r12));
			y[j]=((x[j]*r12)+(y[j]*r11));
		}
		cleardevice();
		circle(x[7],y[7],25);
		draw_line(x[1],y[1],x[2],y[2]);  //body
		draw_line(x[3],y[3],x[4],y[4]);	//horizontal
		circle(x[3],y[3],30);		//back wheel
		circle(x[4],y[4],30);	//front wheel
		draw_line(x[6],y[6],x[5],y[5]);	//handle vertical
		draw_line(x[8],y[8],x[9],y[9]);
		delay(2000);
	}
}
    delay(10000);

    closegraph();
    return 0;
}
