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
        putpixel((int)x, (int)y, GREEN);
		x = x + xi;
		y = y + yi;
        delay(2);
	}
}

int main(){
    // int gd = DETECT, gm;
    // initgraph(&gd, &gm, NULL);
    int a, b, l;
	printf("Enter a point and length: ");
	scanf("%d %d %d",&a, &b, &l);// a = 300 b = 100, length = 100

    //cube design

    //back square

	DDA_line(a, b, a + l, b);
    DDA_line(a, b + l, a + l, b + l);
    DDA_line(a, b, a, b + l);
    DDA_line(a + l, b, a + l, b + l);

    //other lines

    DDA_line(a, b, a + 50, b + 50);
    DDA_line(a + l, b, a + l + 50, b + 50);
    DDA_line(a, b + l, a + 50, b + l + 50);
    DDA_line(a + l, b + l, a + l + 50, b + l + 50);

    //front square

    DDA_line(a + 50, b + 50, a + l + 50, b + 50);
    DDA_line(a + 50, b + l + 50, a + l + 50, b + l + 50);
    DDA_line(a + 50, b + 50, a + 50, b + l + 50);
    DDA_line(a + l + 50, b + 50, a + l + 50, b + l + 50);

    // DDA_line(300, 100, 400,100);
    // DDA_line(300, 200, 400, 200);
    // DDA_line(300, 100, 300, 200);
    // DDA_line(400, 100, 400, 200);

    // DDA_line(300, 100, 350, 150);
    // DDA_line(400, 100, 450, 150);
    // DDA_line(300, 200, 350, 250);
    // DDA_line(400, 200, 450, 250);

    // DDA_line(350, 150, 450, 150);
    // DDA_line(350, 250, 450, 250);
    // DDA_line(350, 150, 350, 250);
    // DDA_line(450, 150, 450, 250);
    printf("Press any key to exit");
    getch();
    closegraph();
    return 0;
}