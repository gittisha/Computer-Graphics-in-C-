// Program to fill rectangle using boundary fill algorithm
#include <graphics.h>
#include <stdio.h>


void boundaryFill(int x, int y, int fillColor, int boundaryColor) {
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
        putpixel(x, y, fillColor);
        boundaryFill(x + 1, y, fillColor, boundaryColor);
        boundaryFill(x - 1, y, fillColor, boundaryColor);
        boundaryFill(x, y + 1, fillColor, boundaryColor);
        boundaryFill(x, y - 1, fillColor, boundaryColor);
        boundaryFill(x + 1, y + 1, fillColor, boundaryColor);
        boundaryFill(x - 1, y - 1, fillColor, boundaryColor);
        boundaryFill(x + 1, y - 1, fillColor, boundaryColor);
        boundaryFill(x - 1, y + 1, fillColor, boundaryColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

   
    int left, top, right, bottom;
    printf("Enter top-left coordinates of rectangle (left top): ");
    scanf("%d %d", &left, &top);
    printf("Enter bottom-right coordinates of rectangle (right bottom): ");
    scanf("%d %d", &right, &bottom);

   
    rectangle(left, top, right, bottom);

   
    int x, y;
    printf("Enter starting coordinates for boundary fill (x y): ");
    scanf("%d %d", &x, &y);

    
    int fillColor, boundaryColor;
    printf("Enter fill color: ");
    scanf("%d", &fillColor);
    printf("Enter boundary color: ");
    scanf("%d", &boundaryColor);

    
    boundaryFill(x, y, fillColor, boundaryColor);

    getch();
    closegraph();
    return 0;
}
