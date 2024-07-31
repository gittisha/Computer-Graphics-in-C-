//Rotation of a triangle 
#include<stdio.h>
#include<math.h>
#include<graphics.h>

const int row=3;
const int col=3;

void display(double obj[row][col]){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
			printf("%f ",obj[i][j]);
		printf("\n");
	}
}

void matrix_multiplication(double tr[row][col],double obj[row][col]){
   double result[3][3]={0};
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
         for (int k = 0; k < col; ++k) {
            result[i][j] += tr[i][k] * obj[k][j];
         }
      }
   }
   printf("\n After translation line coordinates\n");
   display(result);
   setcolor(YELLOW);
   line(result[0][0],result[1][0],result[0][1],result[1][1]);
   delay(1000);
   line(result[0][0],result[1][0],result[0][2],result[1][2]);
   delay(1000) ;
   line(result[0][1],result[1][1],result[0][2],result[1][2]);
}

void Matrix_rotation(double rotation[row][col],double radian){
	rotation[0][0]=cos(radian);
	rotation[0][1]=-sin(radian);	
	rotation[1][0]=sin(radian);
	rotation[1][1]=cos(radian);
	rotation[2][2]=1;
	
}
void Matrix_map(double obj[row][col],int x0,int y0,int x1,int y1,int x2,int y2){
	obj[0][0]=x0;
	obj[1][0]=y0;
	obj[0][1]=x1;
	obj[1][1]=y1;
	obj[0][2]=x2;
	obj[1][2]=y2;
	obj[2][2]=obj[1][2]=obj[0][2]=1;	
}

int main(){
	int gd=DETECT,gm;
	int x0,y0,x1,y1,x2,y2;
	initgraph(&gd,&gm,(char*)"");
	printf("Enter Triangle ABC Coordinates.....");
	printf("\n Enter A:");
	scanf("%d%d",&x0,&y0);
	printf("\n Enter B:");
	scanf("%d%d",&x1,&y1);
	
	printf("\n Enter C:");
	scanf("%d%d",&x2,&y2);
	
	double obj[3][3]={0};
	Matrix_map(obj,x0,y0,x1,y1,x2,y2);
	
	printf("\n Matrix for Triangle ABC");
	printf("\n");
	display(obj);
	line(x0,y0,x1,y1);
	line(x0,y0,x2,y2);
	line(x1,y1,x2,y2);
	
	/*...........Rotation ............*/
	double degree,radian;
	printf("Enter degree of rotation: ");
	scanf("%lf",&degree);
	radian=degree*0.01745; 
    double rotation[3][3]={0};
    Matrix_rotation(rotation,radian);
    
    printf("\n Rotation Matrix:\n ");
    display(rotation);
    
    matrix_multiplication(rotation,obj);
	getch();
	closegraph();
	return 0;
}