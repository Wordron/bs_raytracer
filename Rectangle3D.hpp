/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Rectangle3D
*/

#ifndef RECTANGLE3D_HPP_
    #define RECTANGLE3D_HPP_

    #include "Vector3D.hpp"
    #include "Point3D.hpp"

namespace RayTracer {
    class Rectangle3D {
        public:
            Rectangle3D();
            Rectangle3D(
                Math::Point3D pos,
                std::pair<unsigned int, unsigned int> size,
                Math::Vector3D rotation
            );
            ~Rectangle3D() = default;

            Math::Point3D pointAt(double u, double v);

        protected:
            Math::Point3D _origin;
            Math::Vector3D _bottom_side;
            Math::Vector3D _left_side;
            Math::Vector3D _rotation;
        private:
    };
};

#endif /* !RECTANGLE3D_HPP_ */

