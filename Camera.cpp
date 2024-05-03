/*
** EPITECH PROJECT, 2024
** Camera
** File description:
** Camera
*/

#include "Camera.hpp"

RayTracer::Camera::Camera(
    std::pair<unsigned int, unsigned int> resolution,
    Math::Point3D pos = Math::Point3D(),
    Math::Vector3D rotation = Math::Vector3D()
) : _origin(pos), _screen(Rectangle3D(pos, resolution, rotation)), _resolution(resolution), _rotation(rotation)
{
    _AB = Math::Vector3D(_resolution.first + _rotation.x, _rotation.y, _rotation.z);
    _AC = Math::Vector3D(_rotation.x, _resolution.second + _rotation.y, _rotation.z);
    _normalVector = Math::Vector3D(
        (_AB.y * _AC.z - _AB.z * _AC.y) * 1000,
        (_AB.z * _AC.x - _AB.x * _AC.z) * 1000,
        (_AB.x * _AC.y - _AB.y * _AC.x) * 1000
    );
}

RayTracer::Ray RayTracer::Camera::ray(double u, double v)
{
    Math::Point3D pointStart = this->_screen.pointAt(u, v);
    Math::Point3D pointEnd = pointStart - _normalVector;
    Math::Vector3D vector(
        pointEnd.x - pointStart.x,
        pointEnd.y - pointStart.y,
        pointEnd.z - pointStart.z
    );
    RayTracer::Ray new_ray(vector, pointStart);

    return new_ray;
}
