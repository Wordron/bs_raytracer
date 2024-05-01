/*
** EPITECH PROJECT, 2024
** Point3D
** File description:
** Point3D
*/

#include "Point3D.hpp"

Math::Point3D::Point3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Math::Point3D::Point3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Math::Point3D &operator+=(Math::Point3D &dot, const Math::Vector3D &vector)
{
    dot.x += vector.x;
    dot.y += vector.y;
    dot.z += vector.z;
    return dot;
}

Math::Point3D &operator+(const Math::Point3D &dot, const Math::Vector3D &vector)
{
    static Math::Point3D new_dot(dot.x + vector.x, dot.y + vector.y, dot.z + vector.z);

    return new_dot;
}

Math::Point3D &operator-=(Math::Point3D &dot, const Math::Vector3D &vector)
{
    dot.x -= vector.x;
    dot.y -= vector.y;
    dot.z -= vector.z;
    return dot;
}

Math::Point3D &operator-(const Math::Point3D &dot, const Math::Vector3D &vector)
{
    static Math::Point3D new_dot(dot.x - vector.x, dot.y - vector.y, dot.z - vector.z);

    return new_dot;
}
