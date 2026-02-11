//
// Created by milo on 09/02/2026.
//

#include "Maths.h"
#include "raylib.h"
#include <cmath>

namespace Maths {

    Vector2 Maths::Calculate(const float x, const float y) {
        const FInt c = GetC(x, y);
        const FVec g = RandCorners(c);
        const FVec d = FromCorners(x, y, c);
        FFloat n = FVecDot(d, g);
        Vector2 uv = VecFade({x - c.x0, y - c.y0});

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

    int Maths::Hash(const int x, const int y) const {
        int hash = x * A + B * y; // suppress NOLINT(*-narrowing-conversions)
        hash = hash ^ hash >> Shift;
        return hash;
    }
    float Maths::AngleIse(const int hash) const {
        return (hash % N) * (M_PI / N);
    }

    Vector2 Maths::ToVector(const float angle) {
        return { cosf(angle), sinf(angle) };
    }

    Vector2 Maths::CalculateRandCornerVec(const int x, const int y) const {
        const int hash = Hash(x, y);
        const float angle = AngleIse(hash);
        return ToVector(angle);
    }

    FVec Maths::RandCorners(const FInt c) const {
        return FVec {
            CalculateRandCornerVec(c.x0, c.y0),
            CalculateRandCornerVec(c.x0, c.y1),
            CalculateRandCornerVec(c.x1, c.y0),
            CalculateRandCornerVec(c.x1, c.y1)
        };
    }

    FVec Maths::FromCorners(const float x, const float y, const FInt c) {
        return {
            { x - c.x0, y - c.y0 },
            { x - c.x1, y - c.y0 },
            { x - c.x0, y - c.y1 },
            { x - c.x1, y -c. y1 }
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

} // Maths