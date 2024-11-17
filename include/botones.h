#include <raylib.h>

typedef struct s_boton {
	int x, y, width, height;
	Texture normal;
} Boton;

void dibujarBoton(Boton boton) {
	DrawTexture(boton.normal,boton.x, boton.y, WHITE);
}

bool botonPresionado(Boton boton, int x, int y){
	return (x > boton.x && x < (boton.x + boton.width) && y > boton.y && y < boton.y + boton.height);
}