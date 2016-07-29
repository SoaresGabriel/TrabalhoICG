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


#endif // _MYGL_H_

