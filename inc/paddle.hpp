#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "rectangle.hpp"

namespace bs {

class Paddle : public Rectangle{
public:  
    Paddle(float a_x, float a_y, float a_width, float a_height, float a_velocity);
    Paddle(Paddle const& a_other) = default;
    Paddle& operator=(Paddle const& a_other) = default;
    ~Paddle() = default;

    void CreatePaddle(float a_x, float a_y, float a_width, float a_height);
    void RespondToKeyboard(float a_windowWidth);

public:
   sf::Vector2f m_velocity;
   float m_initialVelocity;
};


} //bs


#endif //PADDLE_HPP