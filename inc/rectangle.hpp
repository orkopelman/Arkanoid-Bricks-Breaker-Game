#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>

namespace bs {

class Rectangle : public sf::RectangleShape {
public:  
    float left() const noexcept;
    float right() const noexcept;
    float top() const noexcept;
    float bottom() const noexcept;  
};


} //bs

#include "../inl/rectangle.hxx"


#endif //RECTANGLE_HPP