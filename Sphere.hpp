/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    #include "Ray.hpp"
    #include "Point3D.hpp"

namespace RayTracer {
    class Sphere {
        public:
            Sphere();
            Sphere(Math::Point3D point, double rad);
            ~Sphere() = default;
            bool hits(RayTracer::Ray);

            double radius;
            Math::Point3D center;

        protected:
        private:
    };
}

#endif /* !SPHERE_HPP_ */
