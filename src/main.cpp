#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void line(int x0,  int y0, int x1, int y1, TGAImage& image, TGAColor color)
{
	for (float t = 0.; t < 1.; t += .01) {
		int x = x0 + (x1 - x0) * t;
		int y = y0 + (y1 - y0) * t;
		image.set(x, y, color);
	}
}
int main(int argc, char** argv) {
	TGAImage image(100, 100, TGAImage::RGB);
	//image.set(52, 41, red);
	line(10, 10, 50, 50, image, red);
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
	return 0;
}

