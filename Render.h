//
// Created by milo on 11/02/2026.
//

#ifndef PERLIN_RENDER_H
#define PERLIN_RENDER_H

namespace Render {
    class Render {
    public:
        static void DrawFrame();
        private:
        //stretch amount for the noise
        static constexpr float Scale = 0.01f;
    };
} // Render

#endif //PERLIN_RENDER_H