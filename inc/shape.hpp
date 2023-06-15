/* #ifndef SHAPE_HPP
#define SHAPE_HPP

#include <SFML/Graphics.hpp>

namespace bs {

class Shape {
public:
    virtual float left() const noexcept = 0; 
    virtual float right() const noexcept = 0;
    virtual float top() const noexcept = 0;
    virtual float bottom() const noexcept = 0;
};

} //bs

#include "shape.hxx"

#endif //SHAPE_HPP  */