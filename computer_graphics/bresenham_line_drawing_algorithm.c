#include<stdio.h>
#include<graphics.h>
#include<math.h>

void BRESENHAM_LINE_neg_m(int x1, int y1, int x2, int y2){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int dx, dy, P0, Pk, k, x0, y0, X, Y;
    dx = (x2 - x1);
	dy = (y2 - y1);

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
        else{
            X = X + 1;
            Y = Y - 1;
            Pk = Pk + 2*(dy - dx);
        }
        delay(20);
    }
}

void BRESENHAM_LINE_pos_m(int x1, int y1, int x2, int y2){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int dx, dy, P0, Pk, k, x0, y0, X, Y;
    dx = (x2 - x1);
	dy = (y2 - y1);

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
        else{
            X = X + 1;
            Y = Y + 1;
            Pk = Pk + 2*(dy - dx);
        }
        delay(20);
    }
}

int main(){
    int x1, y1, x2, y2, slope_m;
    printf("Enter two end points: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    slope_m = (y2 - y1)/(x2 - x1);
    BRESENHAM_LINE_neg_m(x1, y1, x2, y2);
    BRESENHAM_LINE_pos_m(x1, y1, x2, y2);
    printf("Press any key to exit");
    getch();
    closegraph();
    return 0;
}