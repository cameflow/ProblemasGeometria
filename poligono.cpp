/* Algoritmo DDA para el trazado de líneas */

#include <stdio.h>
//#include <iostream>
#include <graphics.h>

class punto{
public:
  punto(int r, int d){x=r;y=d;}
  int x;
  int y;
  int getX(){return x;}
  int getY(){return y;}
  void setX(int X){x=X;}
  void setY(int Y){y=Y;}
};


int DDALine(int x0, int y0, int x1, int y1);
void dibujarPoligono(punto vertices[], int n);


int main(int argc, char **argv)
{

	int gd = DETECT, gm = VGAMAX;

  punto a(50,50);
  punto b(100,50);
  punto c(50,100);
  punto d(100,100);

  punto vertices[4] ={a,b,c,d};


	initgraph(&gd, &gm, NULL);
  dibujarPoligono(vertices,4);
// DDALine(0, 0, 50, 50);

	getch();

	closegraph();
//  std::cout << vertices[2].x << std::endl;
	return 0;
}

/* Algoritmo DDA */
int DDALine(int x0, int y0, int x1, int y1)
{
	int maxY, i;

	float dx, dy, m, x, y;

	i=0;

	dx=x1-x0;
	dy=y1-y0;

	maxY=getmaxy();

	if (dx == 0) /* Es una línea vertical */
	{
		for(y = y0; y <= y1; ++y)
		{
			putpixel(x0, maxY-y, WHITE);
		}
	}
	else if (dy == 0) /* Es una línea horizontal */
	{
		for(x = x0; x <= x1; ++x)
		{
			putpixel(x, y0, WHITE);
		}
	}
	else if (dy <= dx) /* Es una línea con pendiente < 1 */
	{
		m = dy/dx;
		y = y0;

		for(x = x0; x <= x1; ++x)
		{
			putpixel(x, (int)(maxY-y), WHITE);
			y = y + m;
		}
	}
	else /* Es una línea con pendiente > 1 */
	{
		m = dx/dy;
		x = x0;
		for(y = y0; y <= y1; ++y)
		{
			putpixel((int)x, maxY-y, WHITE);
			x = x + m;
		}
	}

	return i;
 }

 void dibujarPoligono(punto vertices[], int n)
 {
   int i;
   for(i = 1;i<n-1;i++)
   {
     DDALine(vertices[i-1].x,vertices[i-1].y,vertices[i].x,vertices[i].y);
   }
   DDALine(vertices[n-1].x,vertices[n-1].y,vertices[0].x,vertices[0].y);
 }
