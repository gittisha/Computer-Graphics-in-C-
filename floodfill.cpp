// Program to fill rectangle using flood fill algorithm
#include <graphics.h>
#include <stdio.h>


void flood(int x, int y, int new_col, int old_col){
    if (getpixel(x, y) == old_col) {
        putpixel(x, y, new_col);
        flood(x + 1, y, new_col, old_col);
        flood(x - 1, y, new_col, old_col);
        flood(x, y + 1, new_col, old_col);
        flood(x, y - 1, new_col, old_col);
    }
}
int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

 
    int left, top, right, bottom;
    printf("Enter top-left coordinates of rectangle (left top): ");
    scanf("%d %d", &left, &top);
    printf("Enter bottom-right coordinates of rectangle (right bottom): ");
    scanf("%d %d", &right, &bottom);

    // Drawing the rectangle
    rectangle(left, top, right, bottom);

    
    int x, y;
    printf("Enter starting coordinates for flood fill (x y): ");
    scanf("%d %d", &x, &y);

    
    int newcolor, oldcolor;
    printf("Enter new color: ");
    scanf("%d", &newcolor);
    oldcolor = getpixel(x, y);

   
    flood(x, y, newcolor, oldcolor);

    getch();
    closegraph();
    return 0;
}