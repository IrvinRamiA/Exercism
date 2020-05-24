#include "triangle.h"

static bool sides_equal_to_zero(triangle_t triangle)
{
    return !(triangle.a && triangle.b && triangle.c);
}

static bool meet_triangle_inequality(triangle_t triangle)
{
    bool condition = (triangle.a + triangle.b > triangle.c) && 
        (triangle.b + triangle.c > triangle.a) &&
        (triangle.c + triangle.a > triangle.b);

    return condition;
}

static bool valid_triangle(triangle_t triangle)
{
    return !sides_equal_to_zero(triangle) && 
        meet_triangle_inequality(triangle);
}

bool is_equilateral(triangle_t triangle)
{
    if(valid_triangle(triangle) && triangle.a == triangle.b &&
        triangle.a == triangle.c)
    {
        return true;
    }

    return false;
}

bool is_scalene(triangle_t triangle)
{
    if(valid_triangle(triangle) && triangle.a != triangle.b && 
        triangle.a != triangle.c && triangle.b != triangle.c)
    {
        return true;
    }
    return false;
}

bool is_isosceles(triangle_t triangle)
{
    if(valid_triangle(triangle) && !is_scalene(triangle))
    {
        return true;
    }

    return false;
}