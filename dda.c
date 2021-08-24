// graphics.h for graphics, thread and X11/Xlib.h for multithread in linux
// for windows user remove thread and X11/Xlib.h and include windows.h
// also in init graph use "C:\\turboc3\\bgi" in place of null and you can also place initgraph before taking inputs
// in linux I took input from console instead of GUI as it was often crashing when tried taking input from GUI
//!!! for running in linux g++ dda.c -o dda -std=c++0x -pthread -lgraph -lX11
#include <graphics.h>
#include<stdio.h>
#include<math.h>
#include<thread>  //remove for windows
#include<X11/Xlib.h> //remove for windows
// #include<windows.h> //add for windows

int main(){
    // init threads needed for multithreading in linux remove for windows
    XInitThreads(); //remove for windows
    int graphics_driver = DETECT, graphics_mode, i;
    float x,y,x1,y1,x2,y2,dx,dy,step,x_increment,y_increment;
    // for windows er can take input from GUI
    // here use your bgi path here
    // initgraph(&graphics_driver, &graphics_mode, "C:\\TC\\BGI");
    printf("Enter the value of x1 and y1: ");
    scanf("%f%f",&x1,&y1);

    printf("Enter the value of x2 and y2: ");
    scanf("%f%f",&x2,&y2);
    // for linux use initgraph after console input
    initgraph(&graphics_driver, &graphics_mode, NULL);

    dx = abs(x2-x1);
    dy = abs(y2-y1);
    // m = dy/dx if dx > dy it means m < 1 and if dx < dy it means m > 1
    if(dx > dy){
        step = dx;
    }else{
        step = dy;
    }
    // for m < 1 x_inc = 1 and y_inc = m and for m > 1 yinc = 1 and x_inc = 1/m
    x_increment = dx/step;
    y_increment = dy/step;

    // for negative slopes i-e when dx is negative, or dy is negative or both is negative we need to decrease x and y instead of increasing them
    if(x1 > x2){
        x_increment = -x_increment;
    }

    if(y1 > y2){
        y_increment = -y_increment;
    }

    // start from x1 and y1 and draw line from there
    x = x1;
    y = y1;
    // using loop for putpixel to draw line
    for(i = 1 ; i <= step; i++){
        putpixel(x,y,GREEN);
        x = x + x_increment;
        y = y + y_increment;
        delay(50);
    }
    getch();
    closegraph();
    return 0;
}
