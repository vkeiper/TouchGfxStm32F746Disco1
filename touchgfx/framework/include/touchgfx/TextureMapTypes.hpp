/******************************************************************************
 * This file is part of the TouchGFX 4.9.3 distribution.
 * Copyright (C) 2017 Draupner Graphics A/S <http://www.touchgfx.com>.
 ******************************************************************************
 * This is licensed software. Any use hereof is restricted by and subject to 
 * the applicable license terms. For further information see "About/Legal
 * Notice" in TouchGFX Designer or in your TouchGFX installation directory.
 *****************************************************************************/

#ifndef TEXTUREMAPTYPES_HPP
#define TEXTUREMAPTYPES_HPP

#include <touchgfx/hal/Types.hpp>
namespace touchgfx
{
/**
 * @struct Gradients TextureMapTypes.hpp touchgfx/TextureMapTypes.hpp
 *
 * @brief Gradients contains all the data to interpolate u,v texture coordinates and z coordinates
 *        across a planar surface.
 */
struct Gradients
{
    /**
     * @fn Gradients(const Point3D* vertices);
     *
     * @brief Constructor. Construct the gradients using 3 3D vertices.
     *
     * @param vertices The vertices.
     *
     * @see Point3D
     */
    Gradients(const Point3D* vertices);

    float oneOverZ[3];       ///< 1/z for each vertex
    float UOverZ[3];         ///< u/z for each vertex
    float VOverZ[3];         ///< v/z for each vertex
    float dOneOverZdX;       ///< d(1/z)/dX
    float dOneOverZdY;       ///< d(1/z)/dY
    float dUOverZdX;         ///< d(u/z)/dX
    float dUOverZdY;         ///< d(u/z)/dY
    float dVOverZdX;         ///< d(v/z)/dX
    float dVOverZdY;         ///< d(v/z)/dY
    fixed16_16 dUdXModifier; ///< The dUdX x coordinate modifier
    fixed16_16 dVdXModifier; ///< The dVdX x coordinate modifier
};

/**
 * @struct Edge TextureMapTypes.hpp touchgfx/TextureMapTypes.hpp
 *
 * @brief An edge contains information about one edge, between two points, of a triangle, as well
 *        as information about how to interpolate values when moving in the vertical direction.
 */
struct Edge
{
    /**
     * @fn Edge(const Gradients& gradients, const Point3D* vertices, int top, int bottom);
     *
     * @brief Constructor.
     *
     *        Construct the edge between two vertices and using the gradients for calculating
     *        the interpolation values.
     *
     * @param gradients The gradients for the triangle.
     * @param vertices  The vertices for the triangle.
     * @param top       The index in the vertices array of the top vertex of this edge.
     * @param bottom    The index in the vertices array of the bottom vertex of this edge.
     */
    Edge(const Gradients& gradients, const Point3D* vertices, int top, int bottom);

    /**
     * @fn inline int step()
     *
     * @brief Perform a step along the edge.
     *
     *        Perform a step along the edge.
     *
     * @return the Height.
     */
    inline int step()
    {
        X += XStep;
        Y++;
        height--;
        UOverZ += UOverZStep;
        VOverZ += VOverZStep;
        oneOverZ += oneOverZStep;

        errorTerm += numerator;
        if (errorTerm >= denominator)
        {
            X++;
            errorTerm -= denominator;
            oneOverZ += oneOverZStepExtra;
            UOverZ += UOverZStepExtra;
            VOverZ += VOverZStepExtra;
        }

        return height;
    }

    /**
     * @fn inline int step(int steps)
     *
     * @brief Performs a number of steps along the edge.
     *
     *        Performs a number of steps along the edge.
     *
     * @param steps The number of steps the perform.
     *
     * @return height.
     */
    inline int step(int steps)
    {
        for (int i = 0; i < steps; i++)
        {
            step();
        }
        return height;
    }

    int32_t X;               ///< The X coordinate
    int32_t XStep;           ///< Amount to increment x
    int32_t numerator;       ///< The numerator
    int32_t denominator;     ///< The denominator
    int32_t errorTerm;       ///< The error term
    int Y;                   ///< The Y coordinate
    int height;              ///< The height
    float oneOverZ;          ///< The one over z coordinate
    float oneOverZStep;      ///< The one over z coordinate step
    float oneOverZStepExtra; ///< The one over z coordinate step extra
    float UOverZ;            ///< The over z coordinate
    float UOverZStep;        ///< The over z coordinate step
    float UOverZStepExtra;   ///< The over z coordinate step extra
    float VOverZ;            ///< The over z coordinate
    float VOverZStep;        ///< The over z coordinate step
    float VOverZStepExtra;   ///< The over z coordinate step extra
};

/**
 * @fn inline float fixed28_4ToFloat(fixed28_4 value)
 *
 * @brief Fixed 28 4 to float.
 *
 * @param value The value.
 *
 * @return The value as float.
 */
inline float fixed28_4ToFloat(fixed28_4 value)
{
    return value / 16.0f;
}

/**
 * @fn inline fixed28_4 floatToFixed28_4(float value)
 *
 * @brief Float to fixed 28 4.
 *
 * @param value The value.
 *
 * @return The value as fixed28_4.
 */
inline fixed28_4 floatToFixed28_4(float value)
{
    return (fixed28_4)(value * 16);
}

/**
 * @fn inline fixed16_16 floatToFixed16_16(float value)
 *
 * @brief Float to fixed 16.
 *
 * @param value The value.
 *
 * @return The value as fixed16_16.
 */
inline fixed16_16 floatToFixed16_16(float value)
{
    return (fixed16_16)(value * 65536);
}

/**
 * @fn inline fixed28_4 fixed28_4Mul(fixed28_4 a, fixed28_4 b)
 *
 * @brief Fixed 28 4 mul.
 *
 * @param a The fixed28_4 to process.
 * @param b The fixed28_4 to process.
 *
 * @return the result.
 */
inline fixed28_4 fixed28_4Mul(fixed28_4 a, fixed28_4 b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    if ((a * b) / b == a)
    {
        return (a * b) / 16;
    }

    // Rewrite "b = max_b * num_max_b + rem_b" so that a * max_b does not overflow.
    int sign = 1;
    if (b < 0)
    {
        sign = -sign;
        b = -b;
    }
    if (a < 0)
    {
        sign = -sign;
        a = -a;
    }
    if (a < b)
    {
        fixed28_4 tmp = a;
        a = b;
        b = tmp;
    }
    int32_t max_b = 0x7FFFFFFF / a; // Max b value that can be multiplied with a without overflow
    int32_t num_max_b = b / max_b; // How many times do we have to multiply with "max_b" to get to "b"
    int32_t rem_b = b - max_b * num_max_b; // plus some remainder.
    int32_t max_prod = a * max_b;
    int32_t result = sign * (num_max_b * (max_prod / 16) + (num_max_b * (max_prod % 16) + rem_b * a) / 16);
    return result;
}

/**
 * @fn inline int32_t ceil28_4(fixed28_4 value)
 *
 * @brief Ceiling 28 4.
 *
 * @param value The value.
 *
 * @return The ceil result.
 */
inline int32_t ceil28_4(fixed28_4 value)
{
    int32_t returnValue;
    int32_t numerator = value - 1 + 16;
    if (numerator >= 0)
    {
        returnValue = numerator / 16;
    }
    else
    {
        // deal with negative numerators correctly
        returnValue = -((-numerator) / 16);
        returnValue -= ((-numerator) % 16) ? 1 : 0;
    }
    return returnValue;
}

/**
 * @fn inline void floorDivMod(int32_t numerator, int32_t denominator, int32_t& floor, int32_t& mod)
 *
 * @brief Floor div modifier.
 *
 * @param numerator      The numerator.
 * @param denominator    The denominator.
 * @param [in,out] floor The floor.
 * @param [in,out] mod   The modifier.
 */
inline void floorDivMod(int32_t numerator, int32_t denominator, int32_t& floor, int32_t& mod)
{
    assert(denominator > 0);        // we assume it's positive
    if (numerator >= 0)
    {
        // positive case, C is okay
        floor = numerator / denominator;
        mod = numerator % denominator;
    }
    else
    {
        // Numerator is negative, do the right thing
        floor = -((-numerator) / denominator);
        mod = (-numerator) % denominator;
        if (mod)
        {
            // there is a remainder
            floor--;
            mod = denominator - mod;
        }
    }
}

} //namespace touchgfx

#endif // TEXTUREMAPTYPES_HPP
