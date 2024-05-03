/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

Math::Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Math::Vector3D::Vector3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

double Math::Vector3D::length()
{
    return std::sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
}

double Math::Vector3D::dot(std::vector<double> array1, std::vector<double> array2)
{
    double result = 0;

    for (std::size_t i = 0; i < array1.size(); i++)
        result = result + (array1[i] * array2[i]);
    return result;
}

Math::Vector3D &operator+(const Math::Vector3D &first, const Math::Vector3D &second)
{
    static Math::Vector3D new_vector(first.x + second.x, first.y + second.y, first.z + second.z);

    return new_vector;
}

Math::Vector3D &operator+=(Math::Vector3D &first, const Math::Vector3D &second)
{
    first.x += second.x;
    first.y += second.y;
    first.z += second.z;
    return first;
}

Math::Vector3D &operator-(const Math::Vector3D &first, const Math::Vector3D &second)
{
    static Math::Vector3D new_vector(first.x - second.x, first.y - second.y, first.z - second.z);

    return new_vector;
}

Math::Vector3D &operator-=(Math::Vector3D &first, const Math::Vector3D &second)
{
    first.x -= second.x;
    first.y -= second.y;
    first.z -= second.z;
    return first;
}

Math::Vector3D &operator*(const Math::Vector3D &first, double nb)
{
    static Math::Vector3D new_vector(first.x * nb, first.y * nb, first.z * nb);

    return new_vector;
}

Math::Vector3D &operator*=(Math::Vector3D &first, double nb)
{
    first.x *= nb;
    first.y *= nb;
    first.z *= nb;
    return first;
}

Math::Vector3D &operator/(const Math::Vector3D &first, double nb)
{
    if (nb >= 0.0001 && nb <= -0.0001)
        throw std::invalid_argument("Can't multiply by 0\n") ;
    static Math::Vector3D new_vector(first.x / nb, first.y / nb, first.z / nb);

    return new_vector;
}

Math::Vector3D &operator/=(Math::Vector3D &first, double nb)
{
    if (nb >= 0.0001 && nb <= -0.0001)
        throw std::invalid_argument("Can't divide by 0\n") ;
    first.x /= nb;
    first.y /= nb;
    first.z /= nb;
    return first;
}
