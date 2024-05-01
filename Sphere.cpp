/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Sphere
*/
#include "Sphere.hpp"

RayTracer::Sphere::Sphere() : radius(0.0)
{
    this->center = Math::Point3D();
}

RayTracer::Sphere::Sphere(Math::Point3D point, double rad) : radius(rad), center(point)
{}

bool RayTracer::Sphere::hits(RayTracer::Ray ray)
{
    Math::Vector3D lineOrigin(ray.origin.x - this->center.x, ray.origin.y - this->center.y, ray.origin.z - this->center.z);
    double a = std::pow(ray.direction.length(), 2);
    double b = 2 * (ray.direction.x * lineOrigin.x + ray.direction.y * lineOrigin.y + ray.direction.z * lineOrigin.z);
    double c = std::pow(lineOrigin.length(), 2) - std::pow(this->radius, 2);

    return ((std::pow(b, 2) - (4 * a * c)) >= 0);
}
