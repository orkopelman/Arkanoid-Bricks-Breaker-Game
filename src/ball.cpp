#include "ball.hpp"

namespace bs {

Ball::Ball(float a_x, float a_y, float a_ballRadius, float a_ballVelocity) 
:   m_velocity({a_ballVelocity, a_ballVelocity})
,   m_initialVelocity(a_ballVelocity)
{
    CreateBallShape(a_x, a_y, a_ballRadius);
}

void Ball::CreateBallShape(float a_x, float a_y, float a_ballRadius)
{
    setRadius(a_ballRadius);
    setPosition(a_x, a_y);
    setFillColor(sf::Color::Blue);
    setOrigin(a_ballRadius, a_ballRadius);
    setOutlineThickness(4);
    setOutlineColor(sf::Color(250, 150, 50));

}


bool Ball::MoveInLimits(int a_windowWidth, int a_windowHeight)
{
    move(m_velocity);

    if (left() < 0) {
        m_velocity.x = m_initialVelocity;
    }
    if (right() > a_windowWidth ) {
        m_velocity.x -= m_initialVelocity; 
    }
    if (top() < 0) {
        m_velocity.y = m_initialVelocity;
    }
    if (bottom() > a_windowHeight ) {
        return false;
    }
    return true;
}





/* float Ball::GetPositionX() 
{
    return m_ball.getPosition().x;
} */









} // bs