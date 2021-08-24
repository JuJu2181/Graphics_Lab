// Bresenham's Line Drawing algorithm
// !!! To run in linux : g++ bla.c -o bla -std=c++0x -pthread -lX11 -lgraph && ./bla!!!
/* for dx > 0 and dy > 0; Xk+1 = xk +1
    if dx < 0 Xk+1 = Xk-1
    if dy <0 YK_+1 = Yk -1 or YK
* for positive slope and |m| < 1 i-e dy < dx
    p0 = 2dy - dx
    if(p <0)
        Pk+1 = Pk + 2dy
    else
        Pk+1 = Pk + 2dy - 2dx
* for positive slope and |m| > 1 i-e dy > dx
        p0 = 2dx - dy
    if(p <0)
        Pk+1 = Pk + 2dx
    else
        Pk+1 = Pk + 2dx - 2dy
*
*/
#include<graphics.h>
#include<stdio.h>
// Linux only 🐧
#include<thread>
#include<X11/Xlib.h>
int main()
{
//Linux only 🐧
XInitThreads();
// main code from here 🙃
int gd = DETECT,gm;
int x1, y1, x2, y2, dx, dy, p, temp;
// * by default the steps wil be 1 considering x1,y1 < x2,y2
int stepx = 1, stepy = 1;
float m;
// Input initial and final points
printf("Enter Initial Point (x1,y1): ");
scanf("%d%d",&x1,&y1);
printf("Enter Final Point (x2,y2): ");
scanf("%d%d",&x2,&y2);
// initgraph after input for linux 🐧
// TODO: Also for windows use the path C:\\TC\\BGI 😇
initgraph(&gd, &gm, NULL);
// * if x1 or y1 is greater than x2 or y2 then we will simply decrease in each step rather increasing them 
if(x1 > x2){
    stepx = -1;
}
if(y1 > y2){
    stepy = -1;
}
// calculate dx and dy
// calculate absolute value of dx and dy so this program can be used for any cases
dx = abs(x2-x1);
dy = abs(y2-y1);
// // if dy > dx swap dx and dy as formula changes
// if(dy > dx){
//     temp = dx;
//     dx = dy;
//     dy = temp;
// }
// !using swap is good but it can get confusing so I decided to use slope and if else as below
// as dy and dx are absolute so slope is also absolute 😃
m = dy / dx;
//? for slope less than 1 i-e dy < dx
if(m < 1){
    //compute initial decision parameter
    p = 2*dy-dx;
    for(int i=0; i<dx;i++){
        putpixel(x1,y1,GREEN);
        x1 = x1+stepx;
        if(p<0){
            p += 2*dy;
        }else{
            p = p+2*dy-2*dx;
            y1 = y1+stepy;
        }
        delay(50);
    }
// ? for slope greater than 1 i-e dy > dx
}else if(m >= 1){
    p = 2*dx-dy;
    for(int i=0; i<dy;i++){
        putpixel(x1,y1,GREEN);
        y1 = y1+stepy;
        if(p<0){
            p += 2*dx;
        }else{
            p = p+2*dx-2*dy;
            x1 = x1+stepx;
        }
        delay(50);
    } 
}
// hope you have a good day 😇
getch();
closegraph();
}
