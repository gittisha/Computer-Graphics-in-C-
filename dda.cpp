/* m>1 y(k+1)=y(k)+1   x(k+1)=x(k)+1/m
   m<1 y(k+1)=y(k)+m   x(k+1)=x(k)+1 */
#include<graphics.h>
#include<stdio.h>
#include<math.h>
#define R(x) (int(x+0.5))
void DDA(int x1,int y1,int x2,int y2){
	
	int dx,dy,steps,i;
	float xinr,yinr;
	float x,y;
	dx=(x2-x1);
	dy=(y2-y1);
	steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
	xinr=dx/(float)steps;
	yinr=dy/(float)steps;
	x=x1;
	y=y1;
	for(i=0;i<steps;i++){
		putpixel(R(x),R(y),YELLOW);
		delay(100);
		x=x+xinr;
		y=y+yinr;
	}
}
int main(){
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,(char*)"");
	int x1,y1,x2,y2;
	int xmax=getmaxx();
	int ymax=getmaxy();
	setbkcolor(RED);
	cleardevice();
	printf("Xmax of screen =%d\nYmax of screen =%d\n",xmax,ymax);
	printf("Enter line end coordinates according to Xmax and Ymax of Screen ! \n");
	printf("Enter endpoints A(x1,y1) : ");
	scanf("%d%d",&x1,&y1);
	printf("Enter endpoints B(x2,y2) : ");
	scanf("%d%d",&x2,&y2);
	DDA(x1,y1,x2,y2);
	getch();
	return 0;
}