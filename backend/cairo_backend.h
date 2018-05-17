#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cairo.h>
#include <math.h>

class FigureCanvas{

	protected:
	cairo_surface_t *surface;
    cairo_t *cr;
    int Xsize;
    int Ysize;
    

	public:
		//TO DO define constructor combinations
    	FigureCanvas(int X, int Y){
    		Xsize=X;
    		Ysize=Y;
    	}

    	//TO DO save in different formats
    	void saveFigure(std::string figname){

    		cairo_stroke (cr);
    		cairo_surface_write_to_png (surface, &figname[0]);
    	}
    	void Destroy(){
    		    cairo_destroy (cr);
    			cairo_surface_destroy (surface);
    	}

};

class Renderer : public FigureCanvas{

	public:

		int lineWidth;
		int colorR,colorG,colorB;

		//TO DO: define various constructor combinations
		// Make a function to determine origin in the Artist layer and transform data accordingly
		Renderer(int X, int Y,int lWidth, int cR, int cG, int cB):FigureCanvas(X,Y){
        	
          	lineWidth = lWidth;
          	colorR = cR;
          	colorG = cG;
          	colorB = cB;
          	cairo_set_source_rgb (cr, colorR, colorB, colorG);
          	surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, Xsize, Ysize);
    		cr = cairo_create (surface);
    		cairo_set_line_width (cr, lineWidth);

		}

    	void createBackground(int cR, int cG, int cB){

    	//Creates a Paper of given colour
    		cairo_set_line_width (cr, 2);
			cairo_set_source_rgb (cr, cR, cG, cB);
			cairo_rectangle (cr, 0, 0,Xsize,Ysize);
			cairo_fill (cr);
			cairo_set_source_rgb (cr, colorR, colorB, colorG);
			cairo_set_line_width (cr, lineWidth);

    	}

		void changeColor(int cR, int cG, int cB){ // BUG: currently only the last changed color is used.
			colorR = cR;
        	colorG = cG;
        	colorB = cB;
        	cairo_set_source_rgb (cr, colorR, colorG, colorB);
		}
		void drawLine(int x1,int y1,int x2,int y2){
		//expecting transformed data as coordinates
		//draws line between two coordinates
			cairo_move_to(cr,x1,y1);
			cairo_line_to(cr,x2,y2);
			
		}
		void drawMarker(int x1,int y1,std::string mtype){
			//draws markers
			//ToDo: Add various Marker types
			cairo_move_to(cr,x1,y1);
			if(!strcmp(&mtype[0],"dot"))
				cairo_arc (cr,x1,y1, 2, 0., 2 * M_PI);
		}
};

