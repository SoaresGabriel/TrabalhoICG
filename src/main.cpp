#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void) {
	//drawOctants();
	//drawOctantLines();

	//drawTriangles();

	showPolygons();

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv) {
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

