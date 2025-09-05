#include <graphics.h>
#include <conio.h>
void main(){
    int gd = DETECT,gm;
    clrscr();
    initgraph (&gd, &gm,"C:\\TURBOC3\\BGI");
    char str[] = "Hello World";
    setbkcolor(GREEN);
    outtext("Hello World");
    outtextxy(100,100,"Hello World");
    outtextxy(100,100,str);
    getch();
    closegraph();
}