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
	int x;
	int y;
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

	// se DeltaX < 0 inverte os pontos de inicio e fim da linha
	if (l.pB.x < l.pA.x) {
		Pixel a = l.pA;
		l.pA = l.pB;
		l.pB = a;
	}

	int dx = l.pB.x - l.pA.x;
	int dy = l.pB.y - l.pA.y;
	int d = 2 * dy - dx;
	int addE = 2 * dy;
	int addNE = 2 * (dy - dx);
	int x = l.pA.x;
	int y = l.pA.y;

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

void drawOctants() {
	Color branco = { 255, 255, 255, 255 };
	int i;

	for (i = 0; i < IMAGE_WIDTH; i++) {

		//desenha eixo x
		Pixel p = { i, IMAGE_HEIGHT / 2, branco };
		putPixel(p);

		//desenha eixo y
		p.x = IMAGE_WIDTH / 2;
		p.y = i;
		putPixel(p);

		//desenha diagonal principal
		p.x = i;
		p.y = i;
		putPixel(p);

		//desenha diagonal secundária
		p.x = 512 - i;
		p.y = i;
		putPixel(p);
	}

}

void drawOctantLines() {
	Pixel centro = { IMAGE_WIDTH / 2, IMAGE_HEIGHT / 2, { 255, 255, 255, 255 } };
	Color *corCentro = &(centro.color);

	//desenha linha no primeiro octante
	Color cor1 = { 255, 20, 147, 255 };
	*corCentro = cor1;
	Pixel final1 = { IMAGE_WIDTH - 1, IMAGE_HEIGHT * 3 / 4, cor1 };
	Line linha1 = { centro, final1 };
	drawLine(linha1);

	//desenha linha no segundo octante
	Color cor2 = { 255, 255, 0, 255 };
	*corCentro = cor2;
	Pixel final2 = { IMAGE_WIDTH * 3 / 4, IMAGE_HEIGHT - 1, cor2 };
	Line linha2 = { centro, final2 };
	drawLine(linha2);

	//desenha linha no terceiro octante
	Color cor3 = { 152, 251, 152, 255 };
	*corCentro = cor3;
	Pixel final3 = { IMAGE_WIDTH / 4, IMAGE_HEIGHT - 1, cor3 };
	Line linha3 = { centro, final3 };
	drawLine(linha3);

	//desenha linha no quarto octante
	Color cor4 = { 0, 255, 0, 255 };
	*corCentro = cor4;
	Pixel final4 = { 0, IMAGE_HEIGHT * 3 / 4, cor4 };
	Line linha4 = { centro, final4 };
	drawLine(linha4);

	//desenha linha no quinto octante
	Color cor5 = { 216, 191, 216, 255 };
	*corCentro = cor5;
	Pixel final5 = { 0, IMAGE_HEIGHT / 4, cor5 };
	Line linha5 = { centro, final5 };
	drawLine(linha5);

	//desenha linha no sexto octante
	Color cor6 = { 0, 0, 255, 255 };
	*corCentro = cor6;
	Pixel final6 = { IMAGE_WIDTH / 4, 0, cor6 };
	Line linha6 = { centro, final6 };
	drawLine(linha6);

	//desenha linha no sétimo octante
	Color cor7 = { 173, 255, 47, 255 };
	*corCentro = cor7;
	Pixel final7 = { IMAGE_WIDTH * 3 / 4, 0, cor7 };
	Line linha7 = { centro, final7 };
	drawLine(linha7);

	//desenha linha no oitavo octante
	Color cor8 = { 255, 69, 0, 255 };
	*corCentro = cor8;
	Pixel final8 = { IMAGE_WIDTH - 1, IMAGE_HEIGHT / 4, cor8 };
	Line linha8 = { centro, final8 };
	drawLine(linha8);
}

#endif // _MYGL_H_

