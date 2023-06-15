/* #include "Circle.hpp" */

namespace bs {

inline float Circle::left() const noexcept 
{ 
    return getPosition().x - getRadius(); 
}

inline float Circle::right() const noexcept 
{ 
    return getPosition().x + getRadius(); 
}

inline float Circle::top() const noexcept 
{ 
    return getPosition().y + getRadius(); 
}

inline float Circle::bottom() const noexcept 
{ 
    return getPosition().y - getRadius(); 
}


} //bs