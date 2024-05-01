/*
** EPITECH PROJECT, 2024
** Point3D
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
    #define POINT3D_HPP_

#include "Vector3D.hpp"

namespace Math {
    class Point3D {
        public:
            Point3D();
            Point3D(double, double, double);
            ~Point3D() = default;
            double x;
            double y;
            double z;

        protected:
        private:
    };
};

Math::Point3D &operator+=(Math::Point3D &dot, const Math::Vector3D &vector);
Math::Point3D &operator+(const Math::Point3D &dot, const Math::Vector3D &vector);
Math::Point3D &operator-=(Math::Point3D &dot, const Math::Vector3D &vector);
Math::Point3D &operator-(const Math::Point3D &dot, const Math::Vector3D &vector);

#endif /* !POINT3D_HPP_ */
