#include "brick.hpp"

namespace bs {

Brick::Brick(float a_x, float a_y)
:  m_destroyed(false)
{
    CreateBrick(a_x, a_y);
}


void Brick::CreateBrick(float a_x, float a_y)
{
    setSize(sf::Vector2f(BrickWidth, BrickHeight));
    setPosition(a_x, a_y);
    setFillColor(sf::Color::Yellow);
    setOrigin(BrickWidth / 2.f, BrickWidth / 2.f);
}


} // bs