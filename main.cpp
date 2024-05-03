/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "Camera.hpp"
#include "Sphere.hpp"
#include "SfmlUI.hpp"
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
        Math::Vector3D(0, 0, 0));
    RayTracer::Sphere sphere1(Math::Point3D(1, 1, -1), 0.5);
    RayTracer::Sphere sphere2(Math::Point3D(0, 0, -1), 0.5);
    RayTracer::SfmlUI ui(std::pair<unsigned int, unsigned int>(100, 100), "test");
    double u = 0.0;
    double v = 0.0;
    Math::Vector3D color;

    for (double y = 0; y <= 100; y++) {
        for (double x = 0; x <= 100; x++) {
            u = x / 100.0;
            v = y / 100.0;
            RayTracer::Ray r = cam.ray(u, v);

            if (sphere1.hits(r)) {
                color.x = 255;
                color.y = 0;
                std::cout << "Hit at : (" << y << ", " << x << ")" << std::endl;
            } else if (sphere2.hits(r)) {
                color.y = 255;
                color.x = 0;
                std::cout << "Hit at : (" << y << ", " << x << ")" << std::endl;
            } else {
                color.y = 0;
                color.x = 0;
                std::cout << "Didn't hit at : (" << y << ", " << x << ")" << std::endl;
            }
            ui.addPixel({ (float)x, (float)y }, color);
            if (ui.UILoop())
                return 0;
        }
    }
    while(!ui.event())
        ui.display();
}
