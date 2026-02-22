//
// Created by milo on 09/02/2026.
//

#include "Maths.h"

#include <algorithm>

#include "raylib.h"
#include <cmath>
#include <cstdlib>

namespace Maths {

    float Maths::Calculate(const Vector2 in) {
        //get cell corners
        const FInt c = GetC(in.x, in.y);
        //get pseudo-rand vectors at corners
        const FVec g = RandCorners(c);
        //get displacement vectors from corners
        const FVec d = FromCorners(in.x, in.y, c);
        //calculate dotproducts
        const FFloat n = FVecDot(d, g);
        float fx = in.x - std::floor(in.x);
        float fy = in.y - std::floor(in.y);
        //stabiity clamp
        fx = std::clamp(fx, 0.0f, 1.0f);
        fy = std::clamp(fy, 0.0f, 1.0f);

        const Vector2 uv = VecFade({fx, fy});
        //linear interpolation for the xs
        // First interpolate along Y (because 01 is vertical from 00)
        const float y0 = Lerp(n.f00, n.f01, uv.y); // left column
        const float y1 = Lerp(n.f10, n.f11, uv.y); // right column
        //return final y value at this point
        return Lerp(y0, y1, uv.x);
    }

    FInt Maths::GetC(const float x, const float y) {
        const int x0 = static_cast<int>(std::floor(x));
        const int y0 = static_cast<int>(std::floor(y));
        return {
            x0,
            y0,
            x0 + 1,
            y0 + 1,
        };
    }

    int Maths::Hash(const int x, const int y) {
        int hash = WorldSeed;
        hash ^= x * A + B * y; // suppress NOLINT(*-narrowing-conversions)
        hash ^= hash >> Shift;
        return hash;
    }

    Vector2 Maths::ToVector(const float angle) {
        return { cosf(angle), sinf(angle) };
    }

    Vector2 Maths::CalculateRandCornerVec(const int x, const int y) {
        const int hash = Hash(x, y);
        const float angle = (hash & 0xFFFF) / 65535.0f * 2.0f * M_PI;

        return ToVector(angle);
    }

    FVec Maths::RandCorners(const FInt c) {
        return FVec {
            CalculateRandCornerVec(c.x0, c.y0),
            CalculateRandCornerVec(c.x0, c.y1),
            CalculateRandCornerVec(c.x1, c.y0),
            CalculateRandCornerVec(c.x1, c.y1)
        };
    }

    FVec Maths::FromCorners(const float x, const float y, const FInt c) {
    return {
        { x - c.x0, y - c.y0 }, // 00
        { x - c.x0, y - c.y1 }, // 01
        { x - c.x1, y - c.y0 }, // 10
        { x - c.x1, y - c.y1 }  // 11
    };
}

    FFloat Maths::FVecDot(const FVec &a, const FVec &b) {
        return {
            Maths::Dot(a.v00, b.v00),
            Dot(a.v01, b.v01),
            Dot(a.v10, b.v10),
            Dot(a.v11, b.v11)
        };
    }

    float Maths::Dot(const Vector2 a, const Vector2 b) {
        return a.x * b.x + a.y * b.y;
    }

    float Maths::Fade(const float t) {
        return 6* std::pow(t, 5.f) - 15 * std::pow(t, 4.f) + 10 * std::pow(t, 3.f);
    }

    Vector2 Maths::VecFade(const Vector2 vec) {
        return { Fade(vec.x), Fade(vec.y) };
    }

    float Maths::Lerp(const float start, const float end, const float factor) {
        return start + (end - start) * factor;
    }

    int Maths::GenSeed() {
        return std::rand() ;
    }
} // Maths