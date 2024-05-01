/*
** EPITECH PROJECT, 2024
** Ray
** File description:
** Ray
*/

#ifndef RAY_HPP_
    #define RAY_HPP_

    #include "Vector3D.hpp"
    #include "Point3D.hpp"

namespace RayTracer {
    class Ray {
        public:
            Ray();
            Ray(Math::Vector3D, Math::Point3D);
            ~Ray() = default;

            Math::Vector3D direction;
            Math::Point3D origin;

        protected:
        private:
    };
};

#endif /* !RAY_HPP_ */
