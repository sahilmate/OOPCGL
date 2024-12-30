/*
#include&lt;iostream&gt;
#include&lt;conio.h&gt;
#include&lt;graphics.h&gt;
//#include&lt;dos.h&gt;

main()
{
//clrscr();
int gd=0,gm,x=20,flag=0,y=200,uplimit=250;
initgraph(&amp;gd,&amp;gm,&quot;C:\\Tc\\BGI&quot;);
while(!kbhit())
{
setcolor(4);
line(0,400,679,400);
if(flag==0)
{
y+=2;
x+=1;
if(y&gt;=385)
flag=1;
}
if(flag==1)
{
y-=2;
x+=1;
if(y&lt;=uplimit)
{

flag=0;
uplimit+=20;

}
}

setcolor(15);
fillellipse(x,y,15,15);
delay(15);
setcolor(0);
setfillstyle(1,20);
fillellipse(x,y,15,15);
cleardevice();
}

getch();
}
*/