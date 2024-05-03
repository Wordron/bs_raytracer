/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** SfmlUI
*/

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.h>
#include <memory>
#include "Vector3D.hpp"

namespace RayTracer {
    class SfmlUI {
        public:
            SfmlUI(std::pair<unsigned int, unsigned int> resolution, const std::string name);
            ~SfmlUI();

            bool UILoop();
            void display();
            bool event();
            sf::RectangleShape createPixel(sf::Vector2f position, Math::Vector3D color);
            void addPixel(std::pair<double, double> position, Math::Vector3D color);

        private:
            std::pair<unsigned int, unsigned int> _resolution;
            std::unique_ptr<sf::RenderWindow> _window;
            sf::Event _event;
            std::vector<sf::RectangleShape> _pixels;
    };
}
