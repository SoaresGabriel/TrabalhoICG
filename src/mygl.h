#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"

typedef struct Color {
	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char A;
} Color;

typedef struct Pixel {
	unsigned int x;
	unsigned int y;
	Color color;
} Pixel;

typedef struct Line {
	Pixel pA;
	Pixel pB;
} Line;

typedef struct Triangle {
	Pixel vA;
	Pixel vB;
	Pixel vC;
} Triangle;

unsigned int getMemoryAdress(Pixel p) {
	return (p.x) * 4 + (p.y) * IMAGE_WIDTH * 4;
}

void putPixel(Pixel p) {
	unsigned int adress = getMemoryAdress(p);

	FBptr[adress] = p.color.R;
	FBptr[adress + 1] = p.color.G;
	FBptr[adress + 2] = p.color.B;
	FBptr[adress + 3] = p.color.A;
}

void drawLine(Line l) {
	int dx = l.pB.x - l.pA.x;
	int dy = l.pB.y - l.pA.y;
	int d = 2 * dy - dx;
	int addE = 2 * dy;
	int addNE = 2 * (dy - dx);
	unsigned int x = l.pA.x;
	unsigned int y = l.pB.x;

	Pixel pixel = { x, y, l.pB.color };
	Pixel *p = &pixel;

	putPixel(pixel);

	while (pixel.x < l.pB.x) {
		if (d <= 0) {
			d += addE;
			p->x++;
		} else {
			d += addNE;
			p->x++;
			p->y++;
		}

		putPixel(pixel);
	}
}

#endif // _MYGL_H_

