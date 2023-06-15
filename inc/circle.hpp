#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <SFML/Graphics.hpp>

namespace bs {

class Circle : public sf::CircleShape {
public:
    float left() const noexcept;
    float right() const noexcept;
    float top() const noexcept;
    float bottom() const noexcept;  
};


} // bs

#include "circle.hxx"

#endif //CIRCLUE_HPP