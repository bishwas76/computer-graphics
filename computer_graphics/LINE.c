#include<stdio.h>
#include<graphics.h>
#include<math.h>

void DDA_line(int x1, int y1, int x2, int y2){
	int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
	float x, y, k, dx, dy, steps, xi, yi;
	dx = x2 - x1;
	dy = y2 - y1;
    x=x1;
	y=y1;
	if (abs(dx) > abs(dy)){
		steps = abs(dx);
	}else{
		steps = abs(dy);
	}
	xi = dx / steps;
	yi = dy / steps;
	for(k = 0; k < steps; k++){
        putpixel((int)x, (int)y, WHITE);
		x = x + xi;
		y = y + yi;
		delay(2);
	}
}
int main(){
	int a, b, c, d;
	printf("Enter two end points: ");
	scanf("%d %d %d %d",&a, &b, &c ,&d);
	DDA_line(a, b, c, d);	
	printf("Press any key to exit");
    getch();
	closegraph();
	return 0;
}