#ifndef BRICK_HPP
#define BRICK_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "rectangle.hpp"

constexpr float BrickWidth{50.f}, BrickHeight{20.f};

namespace bs {

class Brick: public Rectangle {
public:  
    Brick(float a_x, float a_y);
    Brick(Brick const& a_other) = default;
    Brick& operator=(Brick const& a_other) = default;
    ~Brick() = default;
    
    void CreateBrick(float a_x, float a_y);

public:
   bool m_destroyed;
};




} //bs

/* #include "brick.hxx" */

#endif //BRICK_HPP