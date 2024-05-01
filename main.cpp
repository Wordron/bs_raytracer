/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "Camera.hpp"
#include "Sphere.hpp"
#include <iostream>

void write_color(Math::Vector3D vector)
{
    std::cout << vector.x << "  " << vector.y << "  " << vector.z << std::endl;
    return;
}

int main(void)
{
    RayTracer::Camera cam(
        std::pair<unsigned int, unsigned int>(1, 1),
        Math::Point3D(),
        Math::Vector3D(-1, -1, 0));
    RayTracer::Sphere sphere(Math::Point3D(0, 0, -1), 0.5);
    double u = 0.0;
    double v = 0.0;

    for (double y = 0; y <= 10; y++) {
        for (double x = 0; x <= 10; x++) {
            u = x / 10.0;
            v = y / 10.0;
            RayTracer::Ray r = cam.ray(u, v);

            if (sphere.hits(r)) {
                std::cout << "Hit at : (" << y << ", " << x << ")" << std::endl;
            } else {
                std::cout << "Didn't hit at : (" << y << ", " << x << ")" << std::endl;
            }
        }
    }
}
