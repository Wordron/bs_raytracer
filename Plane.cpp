/*
** EPITECH PROJECT, 2024
** Plane
** File description:
** Plane
*/

#include "Plane.hpp"

extern "C" RayTracer::Plane *planeEntryPoint()
{
    return new RayTracer::Plane();
}

RayTracer::Plane::Plane()
{
    _PointA = Math::Point3D(0, 0, 0);
    _PointB = Math::Point3D(0, 2, 0);
    _PointC = Math::Point3D(0, 4, 0);
    _color = Math::Vector3D(0, 0, 255);
    _position = 0;
    _axis = "X";
}

RayTracer::Plane::Plane(Math::Vector3D color, double pos, std::string axis) : _color(color), _position(pos), _axis(axis)
{
    if (_axis == "X") {
        _PointA = Math::Point3D(_position, 0, 7);
        _PointB = Math::Point3D(_position, 2, 0);
        _PointC = Math::Point3D(_position, 17, 0);
    }
    if (_axis == "Y") {
        _PointA = Math::Point3D(0, _position, 7);
        _PointB = Math::Point3D(2, _position, 0);
        _PointC = Math::Point3D(4, _position, 17);
    }
    if (_axis == "Z") {
        _PointA = Math::Point3D(0, 7, _position);
        _PointB = Math::Point3D(2, 0, _position);
        _PointC = Math::Point3D(4, 17, _position);
    }
    _AB = Math::Vector3D ((_PointB.x - _PointA.x), (_PointB.y - _PointA.y), (_PointB.z - _PointA.z));
    _AC = Math::Vector3D ((_PointC.x - _PointA.x), (_PointC.y - _PointA.y), (_PointC.z - _PointA.z));
    _vectorNor = Math::Vector3D (
        (_AB.y * _AC.z - _AB.z * _AC.y),
        (_AB.z * _AC.x - _AB.x * _AC.z),
        (_AB.x * _AC.y - _AB.y * _AC.x)
    );
}

RayTracer::Plane::~Plane()
{
}

Math::Vector3D RayTracer::Plane::getColor() const
{
    return _color;
}

bool RayTracer::Plane::hits(RayTracer::Ray ray)
{
    return ((ray.direction.x * _vectorNor.x +
        ray.direction.y * _vectorNor.y +
        ray.direction.z * _vectorNor.z) != 0);
}

// void RayTracer::Plane::update(std::vector<std::string> argMap, std::va_list *argsList)
// {
//     for (const auto &argName : argMap) {
//         if (argName == "axis")
//             _axis = *va_arg(*argsList, std::string *);
//         else if (argName == "position")
//             _position = va_arg(*argsList, double);
//         else if (argName == "color")
//             _color = *va_arg(*argsList, Math::Vector3D *);
//         else
//             throw invalidArgumentPrimitive(argName);
//     }
//     if (_axis == "X") {
//         _PointA = Math::Point3D(_position, 0, 7);
//         _PointB = Math::Point3D(_position, 2, 0);
//         _PointC = Math::Point3D(_position, 17, 0);
//     }
//     if (_axis == "Y") {
//         _PointA = Math::Point3D(0, _position, 7);
//         _PointB = Math::Point3D(2, _position, 0);
//         _PointC = Math::Point3D(4, _position, 17);
//     }
//     if (_axis == "Z") {
//         _PointA = Math::Point3D(0, 7, _position);
//         _PointB = Math::Point3D(2, 0, _position);
//         _PointC = Math::Point3D(4, 17, _position);
//     }
//     _AB = Math::Vector3D ((_PointB.x - _PointA.x), (_PointB.y - _PointA.y), (_PointB.z - _PointA.z));
//     _AC = Math::Vector3D ((_PointC.x - _PointA.x), (_PointC.y - _PointA.y), (_PointC.z - _PointA.z));
//     _vectorNor = Math::Vector3D (
//         (_AB.y * _AC.z - _AB.z * _AC.y),
//         (_AB.z * _AC.x - _AB.x * _AC.z),
//         (_AB.x * _AC.y - _AB.y * _AC.x)
//     );
// }
