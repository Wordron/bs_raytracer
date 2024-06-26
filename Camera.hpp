/*
** EPITECH PROJECT, 2024
** Camera
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "Rectangle3D.hpp"
    #include "Ray.hpp"

namespace RayTracer {
    class Camera {
        public:
            Camera(
                std::pair<unsigned int, unsigned int> resolution,
                Math::Point3D pos,
                Math::Vector3D rotation
            );
            ~Camera() = default;
            RayTracer::Ray ray(double, double);

        protected:
            Math::Point3D _origin;
            Rectangle3D _screen;
            std::pair<unsigned int, unsigned int> _resolution;
            Math::Vector3D _rotation;
            Math::Vector3D _AB;
            Math::Vector3D _AC;
            Math::Vector3D _normalVector;
        private:
    };
};

#endif /* !CAMERA_HPP_ */
