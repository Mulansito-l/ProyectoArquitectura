#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int menuPrincipal = 0;
int seleccionoDificultad = 0;
int numeroLetras = 0;
char* palabraAdivinar = NULL;
char* palabrasFaciles[] = {
    "koala", "salud", "mujer", "terco", "cielo",
    "arbol", "libro", "nieto", "silla", "puerta"
};

int seleccionDificultad(int seleccion) {
    int numeroPalabras;
    __asm {
        cmp seleccion, 0
        jz seleccionadoFacil
        cmp seleccion, 1
        jz seleccionadoMedio
        cmp seleccion, 2
        jz seleccionadoDificil

        seleccionadoFacil:
        mov EAX, LENGTH palabrasFaciles
        mov numeroPalabras, EAX
        jmp fin

        seleccionadoMedio:

        seleccionadoDificil:
        
        fin:
    }
    srand(time(0));
    int desfaseAleatorio = rand() % (numeroPalabras);

    __asm {
        mov EDX, OFFSET palabrasFaciles
        mov ECX, desfaseAleatorio
        mov EAX, [EDX + ECX * 4]
        mov palabraAdivinar, EAX
    }
}

int main()
{
    InitWindow(1280, 720, "NotWordle");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        if (menuPrincipal == 0) {
            
            DrawText("NotWordle", 400, 50, 96, BLACK);
            GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, 0x52ff71FF);
            GuiSetStyle(0, TEXT_SIZE, 48);
            if (GuiButton((Rectangle) { 240, 310, 200, 100 }, "FACIL")) seleccionDificultad(0);
            GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, 0xffb452FF);
            if (GuiButton((Rectangle) { 540, 310, 200, 100 }, "MEDIA")) seleccionDificultad(1);
            GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, 0xff5252FF);
            if (GuiButton((Rectangle) { 840, 310, 200, 100 }, "DIFICiL")) seleccionDificultad(2);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}