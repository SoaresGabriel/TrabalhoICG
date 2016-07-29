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
};



#endif // _MYGL_H_

