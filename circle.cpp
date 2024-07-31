#include <graphics.h>
#include <stdio.h>

// Function to draw a circle using the Midpoint Circle Drawing Algorithm
void midPointCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 1 - r;
    putpixel(xc + x, yc + y, BLUE);
    putpixel(xc - x, yc + y, BLUE);
    putpixel(xc + x, yc - y, BLUE);
    putpixel(xc - x, yc - y, BLUE);
    putpixel(xc + y, yc + x, BLUE);
    putpixel(xc - y, yc + x, BLUE);
    putpixel(xc + y, yc - x, BLUE);
    putpixel(xc - y, yc - x, BLUE);

    while (x < y) {
        if (d < 0) {
            d = d + 2 * x + 3;
        } else {
            d = d + 2 * (x - y) + 5;
            y--;
        }
        x++;
        putpixel(xc + x, yc + y, BLUE);
        putpixel(xc - x, yc + y, BLUE);
        putpixel(xc + x, yc - y, BLUE);
        putpixel(xc - x, yc - y, BLUE);
        putpixel(xc + y, yc + x, BLUE);
        putpixel(xc - y, yc + x, BLUE);
        putpixel(xc + y, yc - x, BLUE);
        putpixel(xc - y, yc - x, BLUE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int xc, yc, r;
    int xmax = getmaxx();
    int ymax = getmaxy();
    setbkcolor(WHITE);
    cleardevice();

    printf("Xmax of screen = %d\nYmax of screen = %d\n", xmax, ymax);
    printf("Enter center of circle (xc, yc) : ");
    scanf("%d%d", &xc, &yc);
    printf("Enter radius of circle r : ");
    scanf("%d", &r);

    midPointCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}
