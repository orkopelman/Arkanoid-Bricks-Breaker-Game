
namespace bs {


inline float Rectangle::left() const noexcept 
{
     return getPosition().x - getSize().x / 2.f; 
}

inline float Rectangle::right() const noexcept
{ 
    return getPosition().x + getSize().x / 2.f; 
}

inline float Rectangle::top() const noexcept 
{
     return getPosition().y + getSize().y / 2.f; 
}

inline float Rectangle::bottom() const noexcept 
{ 
    return getPosition().y - getSize().y / 2.f; 
}


} // bs