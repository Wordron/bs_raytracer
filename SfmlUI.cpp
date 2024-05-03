/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** SfmlUI
*/

#include "SfmlUI.hpp"

RayTracer::SfmlUI::SfmlUI(std::pair<unsigned int, unsigned int> resolution, const std::string name) :
    _resolution(resolution),
    _window(std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(
        sf::VideoMode(resolution.first, resolution.second),
        name)
    ))
{}

RayTracer::SfmlUI::~SfmlUI()
{
    this->_window->close();
}

void RayTracer::SfmlUI::display()
{
    this->_window->clear();
    for (const auto& pixel : this->_pixels) {
        this->_window->draw(pixel);
    }
    this->_window->display();
}

bool RayTracer::SfmlUI::event()
{
    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            return true;
    }
    return false;
}

bool RayTracer::SfmlUI::UILoop()
{
    this->display();
    return this->event();
}

sf::RectangleShape RayTracer::SfmlUI::createPixel(sf::Vector2f position, Math::Vector3D color)
{
    sf::RectangleShape pixel;

    pixel.setSize({ 1.0, 1.0 });
    pixel.setFillColor({ (sf::Uint8)color.x, (sf::Uint8)color.y, (sf::Uint8)color.z });
    pixel.setPosition({ position.x, this->_resolution.second - position.y });
    return pixel;
}

void RayTracer::SfmlUI::addPixel(std::pair<double, double> position, Math::Vector3D color)
{
    this->_pixels.push_back(this->createPixel({ (float)position.first, (float)position.second }, color));
}
