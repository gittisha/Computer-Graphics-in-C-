// Shearing of a rectangle
#include <stdio.h>
#include <graphics.h>

void display(double obj[3][3], int rows, int cols){
    int i, j;
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++)
            printf("%f ", obj[i][j]);
        printf("\n");
    }
}

void display_rectangle(double obj[3][4]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++)
            printf("%f ", obj[i][j]);
        printf("\n");
    }
}

void matrix_multiplication(double shear[3][3], double obj[3][4]){
    double result[3][4] = {0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 3; ++k) {
                result[i][j] += shear[i][k] * obj[k][j];
            }
        }
    }
    printf("\n After shearing, rectangle coordinates:\n");
    display_rectangle(result);
    setcolor(YELLOW);
    line(result[0][0], result[1][0], result[0][1], result[1][1]);
    line(result[0][1], result[1][1], result[0][2], result[1][2]);
    line(result[0][2], result[1][2], result[0][3], result[1][3]);
    line(result[0][3], result[1][3], result[0][0], result[1][0]);
}

void Matrix_shear(double shear[3][3], double shx, double shy){
    shear[0][0] = 1;
    shear[0][1] = shx;    
    shear[1][0] = shy;
    shear[1][1] = 1;
    shear[2][2] = 1;
}

void Matrix_map(double obj[3][4], int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3){
    obj[0][0] = x0;
    obj[1][0] = y0;
    obj[0][1] = x1;
    obj[1][1] = y1;
    obj[0][2] = x2;
    obj[1][2] = y2;
    obj[0][3] = x3;
    obj[1][3] = y3;
    obj[2][0] = obj[2][1] = obj[2][2] = obj[2][3] = 1;    
}

int main(){
    int gd = DETECT, gm;
    int x0, y0, x1, y1, x2, y2, x3, y3;
    initgraph(&gd, &gm, (char*)"");
    printf("Enter Rectangle ABCD Coordinates.....");
    printf("\n Enter A:");
    scanf("%d%d", &x0, &y0);
    printf("\n Enter B:");
    scanf("%d%d", &x1, &y1);
    printf("\n Enter C:");
    scanf("%d%d", &x2, &y2);
    printf("\n Enter D:");
    scanf("%d%d", &x3, &y3);

    double obj[3][4] = {0};
    Matrix_map(obj, x0, y0, x1, y1, x2, y2, x3, y3);

    printf("\n Matrix for Rectangle ABCD");
    printf("\n");
    display_rectangle(obj);
    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x0, y0);

    /*...........Shearing ............*/
    double shx, shy;
    printf("Enter x shear factor: ");
    scanf("%lf", &shx);
    printf("Enter y shear factor: ");
    scanf("%lf", &shy);

    double shear[3][3] = {0};
    Matrix_shear(shear, shx, shy);

    printf("\n Shear Matrix:\n ");
    display(shear, 3, 3);

    matrix_multiplication(shear, obj);
    getch();
    closegraph();
    return 0;
}
