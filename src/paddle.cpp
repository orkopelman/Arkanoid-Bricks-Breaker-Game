#include "paddle.hpp"

namespace bs {

Paddle::Paddle(float a_x, float a_y, float a_width, float a_height, float a_velocity)
:   m_velocity({a_velocity, 0})
,   m_initialVelocity(a_velocity)
{
    CreatePaddle(a_x, a_y, a_width, a_height);
}


void Paddle::CreatePaddle(float a_x, float a_y, float a_width, float a_height)
{
    setSize(sf::Vector2f(a_width, a_height));
    setPosition(a_x, a_y);
    setFillColor(sf::Color::Red);
    setOrigin(a_width / 2.f, a_height / 2.f);
}

void Paddle::RespondToKeyboard(float a_windowWidth)
{
    /* m_shape. */move(m_velocity);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0)
        m_velocity.x = -m_initialVelocity;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) &&
            right() < a_windowWidth)
        m_velocity.x = m_initialVelocity;
    else
        m_velocity.x = 0;
}


} // bs