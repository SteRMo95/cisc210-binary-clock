
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "display.h"
#include "framebuffer.h"

int main(){

	uint16_t blank = getColor(0,0,0);
	pi_framebuffer_t *fb = getFBDevice();
	clearBitmap(fb->bitmap, blank);

	display_colons(fb);

	char input[10];
	int hours, minutes, seconds;

	//fb->bitmap->pixel[1][1] = getColor(255,0,0);

	while (1){

		scanf("%s", input);
		//printf("%s\n", input);
		hours = atoi(input);
		minutes = atoi(&input[3]);
		seconds = atoi(&input[6]);

		if ((strlen(input) != 8) || !isdigit(input[0]) || !isdigit(input[3]) || !isdigit(input[6])){
			clearBitmap(fb->bitmap, blank);
			freeFrameBuffer(fb);
			return 0;
		}

		display_time(hours, minutes, seconds, fb);

		/*
		display_hours(atoi(input), fb);
		display_minutes(atoi(&input[3]), fb);
		display_seconds(atoi(&input[6]), fb);
		*/


	}
	printf("%s", input);

	return 0;
}
