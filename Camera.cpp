/*
** EPITECH PROJECT, 2024
** Camera
** File description:
** Camera
*/

#include "Camera.hpp"

RayTracer::Camera::Camera(
    std::pair<unsigned int, unsigned int> resolution,
    Math::Point3D pos,
    Math::Vector3D rotation
) : _origin(pos), _screen(Rectangle3D(pos, resolution, rotation)), _resolution(resolution), _rotation(rotation)
{}

RayTracer::Ray RayTracer::Camera::ray(double u, double v)
{
    Math::Point3D pointStart = this->_screen.pointAt(u, v);
    Math::Point3D pointEnd = pointStart - Math::Vector3D(0, 0, 100);
    Math::Vector3D vector(
        pointEnd.x - pointStart.x,
        pointEnd.y - pointStart.y,
        pointEnd.z - pointStart.z
    );

    return RayTracer::Ray(vector, pointStart);
}
