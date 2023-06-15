#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "ball.hpp"
#include "paddle.hpp"
#include "brick.hpp"
#include <list>


namespace bs {

class Level {
public:  
    Level();
    Level(Level const& a_other) = default;
    Level& operator=(Level const& a_other) = default;
    ~Level() = default;


    std::list<Brick> CreateBricksWall (int a_blockX, int a_blockY);

    void RemoveDestroyedBricks();
    void DrawEntities(sf::RenderWindow& a_window) const;
    void RunLevel();
    
private:
    Ball m_ball;
    Paddle m_paddle;
    std::list<Brick> m_bricks;

};




} //bs


#endif //LEVEL_HPP