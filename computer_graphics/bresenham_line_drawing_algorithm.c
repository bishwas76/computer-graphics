#include<stdio.h>
#include<graphics.h>
#include<math.h>

//for the line having negative slope

void BRESENHAM_LINE_negative_m(int x1, int y1, int x2, int y2){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    float dx, dy, P0, Pk, k, x0, y0, X, Y;
    dx = x2 - x1;
	dy = y2 - y1;

    // initial decision parameter

    P0 = 2*dy - dx;
    Pk = P0;

    X = x1;
    Y = y1;

    for(k = 0; k < dx; k++){
        putpixel((int)X, (int)Y, WHITE);
        if (Pk <= 0){
            X = X + 1;
            Y = Y;
            Pk = Pk + 2*dy;
        }
        else if(Pk > 0){
            X = X + 1;
            Y = Y + 1;
            Pk = Pk + 2*(dy - dx);
        }
        delay(2);
    }
}

//for line having positive slope

void BRESENHAM_LINE_positive_m(int x1, int y1, int x2, int y2){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    float dx, dy, P0, Pk, k, x0, y0, X, Y;
    dx = x2 - x1;
	dy = y2 - y1;

    // initial decision parameter

    P0 = 2*dx - dy;
    Pk = P0;

    X = x1;
    Y = y1;

    for(k = 0; k < dy; k++){
        putpixel((int)X, (int)Y, WHITE);
        if (Pk <= 0){
            Y = Y + 1;
            X = X;
            Pk = Pk + 2*dx;
        }
        else if(Pk > 0){
            X = X + 1;
            Y = Y + 1;
            Pk = Pk + 2*(dx - dy);
        }
        delay(2);
    }
}

int main(){
    int x1, y1, x2, y2, slope_m;
    printf("Enter two end points: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    slope_m = (y2 - y1)/(x2 - x1);
    if(slope_m > 1){
        BRESENHAM_LINE_positive_m(x1, y1, x2, y2);
    }
    if(slope_m <= 1){
        BRESENHAM_LINE_negative_m(x1, y1, x2, y2);
    }
    printf("Press any key to exit");
    getch();
    return 0;
    closegraph(); 
}