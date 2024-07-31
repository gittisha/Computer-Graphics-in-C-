/* Midpoint Line Drawing 
 f(x,y)=ax+by+c=0
 y=mx+c
 or, y=(dy/dx)x+c
 or, (dx)y=(dy)x+(dx)c
 or, (dy)x-(dx)y+(dx)c-=0 ....... (i)
 ax+by+c=0 ....... (ii)
 a=dy , b=-dx 
 d>0 : dnew=dold+(a+b) NE pixel  dnew=dold+(dy-dx)
 d<0 : dnew=dold+a E pixel	     dnew=dold+dy   */
 
#include<graphics.h>
void midPoint(int X1, int Y1, int X2, int Y2) 
{ 
    
    int dx = X2 - X1; 
    int dy = Y2 - Y1; 
    int d,x,y;
    if(dy<=dx){ 
    // initial value of decision parameter d 
    d = dy - (dx/2); 
    x = X1, y = Y1; 
    while (x < X2) { 
        x++; 
        // E or East is chosen 
        if (d < 0) 
            d = d + dy; 
        // NE or North East is chosen 
        else
        { 
            d += (dy - dx); 
            y++; 
        } 
        putpixel(x,y,BLUE);
    } 
    }   
  else if(dx<dy) { 
    // initial value of decision parameter d 
    d = dx - (dy/2); 
    x = X1, y = Y1;  
    while (y < Y2) 
    { 
        y++; 
        if (d < 0) 
            d = d + dx; 
        else
        { 
            d += (dx - dy); 
            x++; 
        } 
        putpixel(x,y,BLUE);
    } 
  } 
} 
  int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	int x1,y1,x2,y2;
	int xmax=getmaxx();
	int ymax=getmaxy();
	setbkcolor(6);
	cleardevice();
	printf("Xmax of screen =%d\nYmax of screen =%d\n",xmax,ymax);
	printf("Enter line end coordinates according to Xmax and Ymax of Screen ! \n");
	printf("Enter endpoints A(x1,y1) : ");
	scanf("%d%d",&x1,&y1);
	printf("Enter endpoints B(x2,y2) : ");
	scanf("%d%d",&x2,&y2);
	midPoint(x1,y1,x2,y2);
	getch();
	return 0;
}
