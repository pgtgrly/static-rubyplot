#include "cairo_backend.h"

int main()
{
	Renderer graph(1000,1000,2,125,125,125);
	graph.createBackground(255,255,255);
	graph.changeColor(125,15,125);
	graph.drawLine(250,250,800,600);
	graph.changeColor(0,0,0);
	graph.drawLine(400,200,600,800);
	graph.drawLine(100,100,100,890);
	graph.drawLine(100,890,890,890);
	graph.saveFigure("Sample.png");
	graph.Destroy();

}