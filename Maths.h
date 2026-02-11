//
// Created by milo on 09/02/2026.
//

#ifndef PERLIN_MATHS_H
#define PERLIN_MATHS_H

#include "FVec.h"
#include "FInt.h"
#include "FFloat.h"

namespace Maths {
    class Maths {
        public:
        //gives vector at given place
        Vector2 Calculate(float x, float y);

        private:
        //get the integer corners from float coords
        static FInt GetC(float x, float y);

        //fast hash function
        [[nodiscard]] int Hash(int x, int y) const;

        //turns hash into angle
        float AngleIse(int hash) const;

        //turns angle to a vector
        static Vector2 ToVector(float angle);

        //gets the randomised corner vec
        Vector2 CalculateRandCornerVec(int x, int y) const;

        //returns FVec for the random corner vecs
        FVec RandCorners(FInt c) const;

        //returns FVec from corners to point for meshing
        static FVec FromCorners(float x, float y, FInt c);

        //does dotproduct between 2 FVecs
        static FFloat FVecDot(const FVec &a, const FVec &b);

        //dotproduct between 2 raylib Vector2s
        static float Dot(Vector2 a, Vector2 b);

        //interpolation fade function. used in getting the factor for lerp
        static float Fade(float t);

        //linear interpolation
        static float Lerp(float start, float end, float factor);

        //hashing consts
        const int A = 374761393;
        const int B = 668265263;
        const int Shift = 13;

        //rand resolution constant. prefers powers of 2
        const int N = 255;
    };
} // Maths

#endif //PERLIN_MATHS_H