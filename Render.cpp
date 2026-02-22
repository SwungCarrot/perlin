//
// Created by milo on 11/02/2026.
//

#include "Render.h"

#include <iostream>
#include <ostream>

#include "Maths.h"
#include <raylib.h>

namespace Render {
    void Render::DrawFrame() {
        for (int x = 0; x < GetScreenWidth(); x++ ) {
            for (int y = 0; y < GetScreenHeight(); y++) {
                Vector2 f = {x * Scale, y * Scale};
                //apply perlin
                float n = Maths::Maths::Calculate(f);
                //clamp
                if (n < -1.f) n = -1.f;
                if (n > 1.f) n = 1.f;
                const auto color = static_cast<unsigned char>((n + 1.0f) * 0.5f * 255.0f);
                //map to 0-255 for brightness
                DrawPixel(x, y, Color{
                    color,
                    color,
                    color,
                    255
                });
            }
        }
    }
} // Render