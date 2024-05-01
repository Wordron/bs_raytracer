/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Rectangle3D
*/

#include "Rectangle3D.hpp"

RayTracer::Rectangle3D::Rectangle3D() : _origin(Math::Point3D())
{
    this->_bottom_side = Math::Vector3D(1, 0, 0);
    this->_left_side = Math::Vector3D(0, 1, 0);
}

RayTracer::Rectangle3D::Rectangle3D(
    Math::Point3D pos,
    std::pair<unsigned int, unsigned int> size,
    Math::Vector3D rotation) : _origin(pos), _rotation(rotation)
{
    this->_bottom_side = Math::Vector3D(size.first, 0, 0);
    this->_left_side = Math::Vector3D(0, size.second, 0);
}

Math::Point3D RayTracer::Rectangle3D::pointAt(double u, double v)
{
    if (u < 0 || v < 0)
        throw std::invalid_argument("Can't be under 0\n");
    if (u > 1 || v > 1)
        throw std::invalid_argument("Can't be bigger than 1\n");
    return Math::Point3D(
        (this->_bottom_side.x * u) + this->_origin.x + this->_rotation.x,
        (this->_left_side.y * v) + this->_origin.y + this->_rotation.y,
        this->_origin.z + this->_rotation.z);
}
