#include<stdio.h>
#include<graphics.h>

const int row = 3;
const int col = 3;

void display(int obj[row][col]){
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++)
            printf("%3d ", obj[i][j]);
        printf("\n");
    }
}

void matrix_multiplication(int tr[row][col], int obj[row][col]){
    int result[3][3] = {0};
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            for (int k = 0; k < col; ++k) {
                result[i][j] += tr[i][k] * obj[k][j];
            }
        }
    }
    printf("\n After scaling, line coordinates\n");
    display(result);
    setcolor(YELLOW);
    line(result[0][0], result[1][0], result[0][1], result[1][1]); // line AB
    delay(1000);
    line(result[0][0], result[1][0], result[0][2], result[1][2]); // Line AC
    delay(1000);
    line(result[0][1], result[1][1], result[0][2], result[1][2]); //line BC
}

void Matrix_scaling(int tr[row][col], float Sx, float Sy){
    tr[0][0] = Sx;
    tr[1][1] = Sy;
    tr[2][2] = 1;
}

void Matrix_map(int obj[row][col], int x0, int y0, int x1, int y1, int x2, int y2){
    obj[0][0] = x0;
    obj[1][0] = y0;
    obj[0][1] = x1;
    obj[1][1] = y1;
    obj[0][2] = x2;
    obj[1][2] = y2;
    for(int i = 0; i < 3; i++)
        obj[2][i] = 1;
}

int main(){
    int gd = DETECT, gm;
    int x0, y0, x1, y1, x2, y2;
    initgraph(&gd,&gm,(char*)"");
    printf("Enter Triangle ABC Coordinates.....");
    printf("\n Enter A:");
    scanf("%d%d", &x0, &y0);
    printf("\n Enter B:");
    scanf("%d%d", &x1, &y1);
    printf("\n Enter C:");
    scanf("%d%d", &x2, &y2);

    int obj[3][3] = {0};
    Matrix_map(obj, x0, y0, x1, y1, x2, y2);

    printf("\n Matrix for Triangle ABC");
    printf("\n");
    display(obj);
    line(x0, y0, x1, y1);
    line(x0, y0, x2, y2);
    line(x1, y1, x2, y2);

    /*...........Scaling ............*/
    float Sx, Sy;
    printf("Scaling factor along x axis (Sx): ");
    scanf("%f", &Sx);
    printf("Scaling factor along y axis (Sy): ");
    scanf("%f", &Sy);

    int tr[3][3] = {0};
    Matrix_scaling(tr, Sx, Sy);

    printf("\n Scaling Matrix:\n ");
    display(tr);

    matrix_multiplication(tr, obj);
    getch();
    closegraph();
    return 0;
}
