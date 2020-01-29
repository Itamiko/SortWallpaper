#include <stdio.h>
#include "determineImageSize.h"
#include <libpng16/png.h>

void readImage(char *filename)
{
	FILE *fp = fopen(filename, "rb");

	png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if(!png) {
		return;
	}

	png_infop info = png_create_info_struct(png);
	if(!info) {
		return;
	}

	png_init_io(png, fp);
	png_read_info(png, info);

	imageSize(png_get_image_height(png, info), png_get_image_width(png, info));
	fclose(fp);
	png_destroy_read_struct(&png, &info, NULL);
}

int imageSize(int height, int width)
{
	printf("%i x %i", height, width);
	return 0;
}