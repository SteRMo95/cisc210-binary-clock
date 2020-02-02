#ifndef __PI_SENSE_FRAMEBUFFER
#define __PI_SENSE_FRAMEBUFFER

#include <stdint.h>
#include <linux/fb.h>

typedef struct {
	uint16_t pixel[8][8];
} sense_fb_bitmap_t;

typedef struct{
	int fd;
	struct fb_fix_screeninfo info;
	sense_fb_bitmap_t* bitmap;
} pi_framebuffer_t;


/*getFBDevice
  returns a pi_framebuffer_t object describing the sense hat frame buffer, or null on failure
  Note: function allocates a pi_framebuffer_t object on success which must be freed with a call to freeFrameBuffer()
*/
pi_framebuffer_t* getFBDevice();

/*freeFrameBuffer
  frees and unmaps a previously allocated frame buffer
*/
void freeFrameBuffer(pi_framebuffer_t* device);

/*clearBitmap
  bitmap: a bitmap object to modify
  color: the fill color for the bitmap
  Fills the bitmap with the color
*/
void clearBitmap(sense_fb_bitmap_t* bitmap,uint16_t color);

/*getColor
  red: the 8 bit red component
  green: the 8 bit green component
  blue: the 8 bit blue component
  returns a 16 bit representation of the 32 bit color specified by the arguments
*/
uint16_t getColor(int red,int green,int blue);
#endif
