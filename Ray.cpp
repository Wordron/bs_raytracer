/*
** EPITECH PROJECT, 2024
** Ray
** File description:
** Ray
*/

#include "Ray.hpp"

RayTracer::Ray::Ray()
{
    direction = Math::Vector3D();
    origin = Math::Point3D();
}

RayTracer::Ray::Ray(Math::Vector3D dir, Math::Point3D origin) : direction(dir), origin(origin)
{}
