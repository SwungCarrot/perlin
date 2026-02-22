#include <iostream>
#include <list>
#include <ctime>
#include "raylib.h"
#include "Render.h"

int main() {
    InitWindow(1280, 720, "perlin");
    SetTargetFPS(60);
    BeginDrawing();
    Render::Render::DrawFrame();
    EndDrawing();
    while (!WindowShouldClose()) {
    }
    return 0;
}
