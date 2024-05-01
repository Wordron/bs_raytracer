/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Vector3D.hpp
*/

#include <vector>
#include <cmath>
#include <exception>
#include <stdexcept>

#ifndef VECTOR3D_HPP_
    #define VECTOR3D_HPP_

namespace Math {
    class Vector3D {
        public:
            Vector3D(double, double, double);
            Vector3D();
            ~Vector3D() = default;
            double x;
            double y;
            double z;

            double length();
            double dot(std::vector<double>, std::vector<double>);
        private:

    };
};

Math::Vector3D &operator+=(Math::Vector3D &first, const Math::Vector3D &second);
Math::Vector3D &operator+(const Math::Vector3D &first, const Math::Vector3D &second);
Math::Vector3D &operator-(const Math::Vector3D &first, const Math::Vector3D &second);
Math::Vector3D &operator-=( Math::Vector3D &first, const Math::Vector3D &second);
Math::Vector3D &operator*(const Math::Vector3D &first, double nb);
Math::Vector3D &operator*=( Math::Vector3D &first, double nb);
Math::Vector3D &operator/(const Math::Vector3D &first, double nb);
Math::Vector3D &operator/=( Math::Vector3D &first, double nb);

#endif /* !VECTOR3D_HPP_ */
