#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<ctype.h>
#include<math.h>

void create_border();
void draw_car(int n,int max_x,int mid_y,int s);
void draw_sun();
void draw_clouds();
void draw_mountains();
void draw_houses();
void draw_trees();


int main()
{
	int max_x,mid_y,i,j,s,n;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	max_x = getmaxx();
	mid_y = getmaxy()/2;
	n=10;

	for(j=0;j<n;j++)
	{

		s=0;

		for (i=0; i < max_x; i=i+5)
		{
			cleardevice();

			setbkcolor(7);

			create_border();

			draw_sun();

			draw_clouds();

			draw_mountains();

			draw_houses();

			draw_trees();

			draw_car(i,max_x,mid_y,s);
			s=s+30;
			delay(80);

		}
	}

	getch();
	return 0;
}

void draw_car(int n,int max_x,int mid_y,int s)
{
	int offset,a;
	setcolor(WHITE);

	offset=100;
	a=175-offset;

	line(0,mid_y+offset,max_x,mid_y+offset);

	line(100+n,50+mid_y-a,300+n,50+mid_y-a);
	line(100+n,50+mid_y-a,75+n,100+mid_y-a);
	line(300+n,50+mid_y-a,325+n,100+mid_y-a);

	line(80+n,100+mid_y-a,103+n,53+mid_y-a);
	line(103+n,53+mid_y-a,297+n,53+mid_y-a);
	line(297+n,53+mid_y-a,320+n,100+mid_y-a);
	line(320+n,100+mid_y-a,80+n,100+mid_y-a);

	line(200+n,53+mid_y-a,200+n,100+mid_y-a);

	line(75+n,100+mid_y-a,10+n,100+mid_y-a);
	line(325+n,100+mid_y-a,350+n,100+mid_y-a);

	line(10+n,150+mid_y-a,70+n,150+mid_y-a);
	line(10+n,150+mid_y-a,10+n,100+mid_y-a);
	line(130+n,150+mid_y-a,270+n,150+mid_y-a);

	line(350+n,100+mid_y-a,400+n,130+mid_y-a);
	line(330+n,150+mid_y-a,400+n,150+mid_y-a);
	line(400+n,150+mid_y-a,400+n,130+mid_y-a);

	arc(100+n,150+mid_y-a,0,180,30);
	arc(300+n,150+mid_y-a,0,180,30);

	setfillstyle(SOLID_FILL,RED);
	floodfill(20+n,120+mid_y-a,WHITE);

	setfillstyle(SOLID_FILL,CYAN);
	floodfill(90+n,82+mid_y-a,WHITE);

	setfillstyle(SOLID_FILL,CYAN);
	floodfill(205+n,73+mid_y-a,WHITE);

	circle(100+n,150+mid_y-a,25);
	circle(100+n,150+mid_y-a,20);

	setfillstyle(SOLID_FILL,0);

	pieslice(100+n,150+mid_y-a,-10+s,10+s,20);
	pieslice(100+n,150+mid_y-a,80+s,100+s,20);
	pieslice(100+n,150+mid_y-a,170+s,190+s,20);
	pieslice(100+n,150+mid_y-a,260+s,280+s,20);

	circle(300+n,150+mid_y-a,25);
	circle(300+n,150+mid_y-a,20);

	pieslice(300+n,150+mid_y-a,-10+s,10+s,20);
	pieslice(300+n,150+mid_y-a,80+s,100+s,20);
	pieslice(300+n,150+mid_y-a,170+s,190+s,20);
	pieslice(300+n,150+mid_y-a,260+s,280+s,20);

	setfillstyle(SOLID_FILL,GREEN);
	floodfill(77.5+n,150+mid_y-a,WHITE);

	setfillstyle(SOLID_FILL,GREEN);
	floodfill(277.5+n,150+mid_y-a,WHITE);

}

void create_border()
{
	setcolor(RED);
	rectangle(0,0,getmaxx(),getmaxy());
}

void draw_sun()
{
	int i,j,x,y;

	setfillstyle(SOLID_FILL,YELLOW);
	fillellipse(500,80,30,30);

	for(i=36;i<80;i++)
	{
		for(j=0;j<=360;j+=20)
		{
			x=500+i*cos(((float)j*3.14)/180);
			y=80+i*sin(((float)j*3.14)/180);
			putpixel(x,y,YELLOW);
		}
	}

}

void draw_clouds()
{

	setcolor(CYAN);
	setfillstyle(SOLID_FILL,CYAN);
	fillellipse(100,80,70,20);
	fillellipse(70,80,20,30);
	fillellipse(100,80,20,30);
	fillellipse(130,80,20,30);

	fillellipse(325,80,70,20);
	fillellipse(295,80,20,30);
	fillellipse(325,80,20,30);
	fillellipse(355,80,20,30);

}

void draw_mountains()
{

	int i,n,m,offset1,offset2;

	n=getmaxx();
	m=getmaxy()/2;
	offset1=50;
	offset2=50;

	n=(int)n/100;

	setcolor(GREEN);

	for(i=0;i<n;i++)
	{

		line(i*100,m-offset1,(i*100)+50,m-offset1-offset2);
		line((i*100)+50,m-offset1-offset2,(i*100)+100,m-offset1);

	}

	line(i*100,m-offset1,(i*100)+50,m-offset1-offset2);

	line(0,m-offset1,getmaxx(),m-offset1);

}

void draw_houses()
{

	int m,n,i,p;

	n=30;

	p=getmaxx();
	m=getmaxy()/2;

	p=(int)p/100;

	setcolor(MAGENTA);

	for(i=0;i<p-1;i++)
	{

		line(50+n,180+m,50+n,220+m);
		line(50+n,220+m,60+n,220+m);
		line(60+n,220+m,70+n,220+m);
		line(70+n,220+m,80+n,220+m);
		line(130+n,220+m,80+n,220+m);
		line(70+n,220+m,70+n,200+m);
		line(60+n,200+m,60+n,220+m);
		line(70+n,200+m,60+n,200+m);
		line(80+n,220+m,80+n,180+m);
		line(130+n,220+m,130+n,180+m);
		line(80+n,180+m,130+n,180+m);
		line(50+n,180+m,80+n,180+m);
		line(50+n,180+m,65+n,160+m);
		line(65+n,160+m,80+n,180+m);
		line(65+n,160+m,110+n,160+m);
		line(130+n,180+m,110+n,160+m);

		n=n+100;

	}

}

void draw_trees()
{

	int n,m;

	n=getmaxx();
	m=getmaxy()/2;

	setcolor(WHITE);
	rectangle(20,160+m,30,220+m);

	setfillstyle(SOLID_FILL,BROWN);
	floodfill(25,180+m,WHITE);

	setcolor(WHITE);
	rectangle(n-30,160+m,n-20,220+m);

	setfillstyle(SOLID_FILL,BROWN);
	floodfill(n-25,180+m,WHITE);

	setcolor(WHITE);

	line(5,160+m,45,160+m);
	line(5,160+m,25,120+m);
	line(45,160+m,25,120+m);

	line(n-45,160+m,n-5,160+m);
	line(n-45,160+m,n-25,120+m);
	line(n-5,160+m,n-25,120+m);

	setfillstyle(SOLID_FILL,GREEN);

	floodfill(25,150+m,WHITE);
	floodfill(n-25,150+m,WHITE);

}







