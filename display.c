
#include "display.h"
#include "framebuffer.h"
#include <math.h>

void display_colons(pi_framebuffer_t *dev){

	for (int i = 1; i < 6; i++){
		if (i != 3){
			for (int j = 1; j < 6; j++){
				if (j != 3){
					dev->bitmap->pixel[i][j] = getColor(100, 100, 100);
				}
			}
		}
	}
	 

	return;
}

void display_time(int hours, int minutes, int seconds, pi_framebuffer_t *dev){

	display_seconds(seconds, dev);
	display_minutes(minutes, dev);
	display_hours(hours, dev);
}

void display_hours(int hours, pi_framebuffer_t *dev){

	uint16_t blue = getColor(0,0,150);
	uint16_t clear = getColor(0,0,0);
	double bin_val;

	for (int i = 6; i >= 0; i--){
		bin_val = pow((double)2.0, (double)i);

		if (bin_val <= hours){
			dev->bitmap->pixel[i][6] = blue;
			hours -= bin_val;
		}
		else{
			dev->bitmap->pixel[i][6] = clear;
		}
	}

}

void display_minutes(int minutes, pi_framebuffer_t *dev){

	uint16_t green = getColor(0,150,0);
	uint16_t clear = getColor(0,0,0);
	double bin_val;

	for (int i = 6; i >= 0; i--){
		bin_val = pow(2.0, (double)i);

		if (bin_val <= minutes){
			dev->bitmap->pixel[i][3] = green;
			minutes -= bin_val;
		}
		else{
			dev->bitmap->pixel[i][3] = clear;
		}
	}
}

void display_seconds(int seconds, pi_framebuffer_t *dev){

	uint16_t red = getColor(150,0,0);
	uint16_t clear = getColor(0,0,0);
	double bin_val;

	for (int i = 6; i >= 0; i--){
		bin_val = pow(2.0, (double)i);
		
		if (bin_val <= seconds){
			dev->bitmap->pixel[i][0] = red;
			seconds -= bin_val;
		}
		else{
			dev->bitmap->pixel[i][0] = clear;
		}

	}
}
