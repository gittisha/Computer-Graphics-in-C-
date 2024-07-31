#include <stdio.h>
#include<graphics.h>

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Window boundaries
int x_min, y_min, x_max, y_max;

// Function to compute the region code for a point (x, y)
int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < x_min) 
        code |= LEFT;
    else if (x > x_max) 
        code |= RIGHT;
    if (y < y_min) 
        code |= BOTTOM;
    else if (y > y_max) 
        code |= TOP;

    return code;
}

// Cohen-Sutherland clipping algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both endpoints lie within the rectangle
            accept = 1;
            break;
        } else if (code1 & code2) {
            // Both endpoints are outside the rectangle in the same region
            break;
        } else {
            // Some segment of the line must be inside the rectangle
            int code_out;
            int x, y;

            // At least one endpoint is outside the rectangle
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find the intersection point
            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Replace the outside point with the intersection point
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        printf("Line accepted from (%d, %d) to (%d, %d)\n", x1, y1, x2, y2);
        // Here you can add the code to draw the line from (x1, y1) to (x2, y2)
    } else {
        printf("Line rejected\n");
    }
}

int main() {
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,(char*)"");
	
    // Define the window
    x_min = 10; y_min = 10; x_max = 200; y_max = 200;
    cleardevice();
    rectangle(x_min, y_min, x_max, y_max);

    // Define the line segment
    //int x1 = 5, y1 = 5, x2 = 150, y2 = 150;
    //line(x1,y1,x2,y2);
    //line (40,20,180,180);
    line (50,50,250,50);

    // Apply the clipping algorithm
   // cohenSutherlandClip(x1, y1, x2, y2);
    //cohenSutherlandClip(40,20,180,180);
    cohenSutherlandClip(50,50,250,50);
	getch();
    return 0;
}