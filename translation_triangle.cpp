/* Translation of a Triangle */
#include<stdio.h>
#include<graphics.h>
const int row=3; 
const int col=3; 

void display(int obj[row][col]){
	int i,j; 
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
			printf("%3d ",obj[i][j]);
		printf("\n");
	}
}

void matrix_multiplication(int tr[row][col],int obj[row][col]){
   int result[3][3]={0};
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
   line(result[0][0],result[1][0],result[0][1],result[1][1]); // line AB
   delay(1000);
   line(result[0][0],result[1][0],result[0][2],result[1][2]); // Line AC
   delay(1000);
   line(result[0][1],result[1][1],result[0][2],result[1][2]); //line BC*/
}
void Matrix_translation(int tr[row][col],int tx,int ty){
	for(int i=0;i<3;i++)
		tr[i][i]=1;
	tr[0][2]=tx;
	tr[1][2]=ty;
}
void Matrix_map(int obj[row][col],int x0,int y0,int x1,int y1,int x2,int y2){
	obj[0][0]=x0;
	obj[1][0]=y0;
	obj[0][1]=x1;
	obj[1][1]=y1;
	obj[0][2]=x2;
	obj[1][2]=y2;
	for(int i=0;i<3;i++)
		obj[2][i]=1;	
}
int main(){
	int gd=DETECT,gm;
	int x0,y0,x1,y1,x2,y2;
	//initgraph(&gd,&gm,(char*)"");
	printf("Enter Triangle ABC Coordinates.....");
	printf("\n Enter A:");
	scanf("%d%d",&x0,&y0);
	printf("\n Enter B:");
	scanf("%d%d",&x1,&y1);
	printf("\n Enter C:");
	scanf("%d%d",&x2,&y2);
	
	int obj[3][3]={0};
	Matrix_map(obj,x0,y0,x1,y1,x2,y2);
	
	printf("\n Matrix for Triangle ABC");
	printf("\n");
	display(obj);
	line(x0,y0,x1,y1);
	line(x0,y0,x2,y2);
	line(x1,y1,x2,y2);
	
	/*...........Translation ............*/
	int tx,ty;
	printf("Displacement towards x axis tx: ");
	scanf("%d",&tx);
	printf("Displacement towards Y axis ty: ");
	scanf("%d",&ty);
    int tr[3][3]={0};
    Matrix_translation(tr,tx,ty);
    
    printf("\n Translation Matrix:\n ");
    display(tr);
    
    matrix_multiplication(tr,obj);
	getch();
	closegraph();
	return 0;
}