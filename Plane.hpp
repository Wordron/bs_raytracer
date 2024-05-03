/*
** EPITECH PROJECT, 2024
** Plane
** File description:
** Plane
*/

#ifndef PLANE_HPP_
    #define PLANE_HPP_

    #include "Ray.hpp"
    #include "Point3D.hpp"

namespace RayTracer {
    class Plane {
        public:
            Plane();
            Plane(Math::Vector3D color, double pos, std::string axis);
            ~Plane();
            bool hits(RayTracer::Ray);
            Math::Vector3D getColor() const;
            // void update(std::vector<std::string> argMap, std::va_list *argsList);

        protected:
        private:
            Math::Point3D _PointA;
            Math::Point3D _PointB;
            Math::Point3D _PointC;
            Math::Vector3D _AB;
            Math::Vector3D _AC;
            Math::Vector3D _color;
            Math::Vector3D _vectorNor;
            double _position;
            std::string _axis;
    };
};

#endif /* !PLANE_HPP_ */
