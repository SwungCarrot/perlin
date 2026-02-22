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
        static float Calculate(Vector2 in);

        private:
        //get the integer corners from float coords
        static FInt GetC(float x, float y);

        //fast hash function
        static int Hash(int x, int y);

        //turns angle to a vector
        static Vector2 ToVector(float angle);

        //gets the randomised corner vec
        static Vector2 CalculateRandCornerVec(int x, int y);

        //returns FVec for the random corner vecs
        static FVec RandCorners(FInt c);

        //returns FVec from corners to point for meshing
        static FVec FromCorners(float x, float y, FInt c);

        //does dotproduct between 2 FVecs
        static FFloat FVecDot(const FVec &a, const FVec &b);

        //dotproduct between 2 raylib Vector2s
        static float Dot(Vector2 a, Vector2 b);

        //interpolation fade function. used in getting the factor for lerp
        static float Fade(float t);

        //wrapper for Fade() in vec form
        static Vector2 VecFade(Vector2 vec);

        //linear interpolation
        static float Lerp(float start, float end, float factor);

        //random seed generator
        static int GenSeed();

        //hashing consts
        static constexpr int A = 374761393;
        static constexpr int B = 668265263;
        static constexpr int Shift = 13;

        //rand resolution constant. prefers powers of 2
        static constexpr int N = 255;

        //seed
        static constexpr int WorldSeed = 1224652887586574;
    };
} // Maths

#endif //PERLIN_MATHS_H