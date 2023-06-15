#ifndef BALL_HPP
#define BALL_HPP

#include "circle.hpp"

namespace bs {

class Ball : public Circle{
public:  
    Ball(float a_x, float a_y, float a_ballRadius, float a_ballVelocity);
    Ball(Ball const& a_other) = default;
    Ball& operator=(Ball const& a_other) = default;
    ~Ball() = default;

    void CreateBallShape(float a_x, float a_y, float a_ballRadius);
    bool MoveInLimits(int a_windowWidth, int a_windowHeight);

public:

    sf::Vector2f m_velocity;
    float m_initialVelocity;
    
};

} //bs



#endif //BALL_HPP