
//	PROTOTYPES FOR THE FUNCTIONS IN DISPLAY.C

#include "framebuffer.h"

void display_time(int hours, int minutes, int seconds, pi_framebuffer_t *dev);

void display_colons(pi_framebuffer_t *dev);

void display_hours(int hours, pi_framebuffer_t *dev);

void display_minutes(int minutes, pi_framebuffer_t *dev);

void display_seconds(int seconds, pi_framebuffer_t *dev);
