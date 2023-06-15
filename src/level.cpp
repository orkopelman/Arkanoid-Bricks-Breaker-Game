#include "level.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm> 

constexpr float ballRadius{10.f}, ballVelocity{0.2f};
constexpr float paddleWidth{150.f}, paddleHeight{20.f}, paddleVelocity{1.f};
constexpr int countBlocksX{7}, countBlocksY{3};
constexpr int windowWidth{800}, windowHeight{600};

namespace bs {

Level::Level()
:   m_ball(Ball(0 , 0, ballRadius, ballVelocity))
,   m_paddle(Paddle(windowWidth/2, windowHeight - paddleHeight, paddleWidth, paddleHeight, paddleVelocity ))
,   m_bricks(CreateBricksWall(countBlocksX, countBlocksY)) 
{}


std::list<Brick> Level::CreateBricksWall (int a_blockX, int a_blockY) 
{
    std::list<Brick> vectBrickOut;
    for (int i=0; i < a_blockX; ++i) {
        for (int j=0; j < a_blockY; ++j) {
            vectBrickOut.emplace_back((i + 4) * (55) , (j + 4) * (45));
        }    
    }
    return vectBrickOut;
}


static void WindowRemainOpen(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
    window.clear();
}

template <class T1, class T2>
bool IsIntersecting(T1& a_obj1, T2& a_obj2) noexcept
{
    return a_obj1.right() >= a_obj2.left() && a_obj1.left() <= a_obj2.right() &&
           a_obj1.bottom() <= a_obj2.top() && a_obj1.top() >= a_obj2.bottom();
}

void CheckCollision(Paddle& a_paddle, Ball& a_ball) 
{
    if(!IsIntersecting(a_paddle, a_ball)) {
        return;
    }

    a_ball.m_velocity.y = -ballVelocity;
    if(a_ball.getPosition().x < a_paddle.getPosition().x) {
            a_ball.m_velocity.x = -ballVelocity;
    }else {
        a_ball.m_velocity.x = ballVelocity;
    }
}

void CheckCollision(Brick& a_brick, Ball& a_ball)
{
    if(!IsIntersecting(a_brick, a_ball)) {
        return;
    }
    a_brick.m_destroyed = true;

    float overlapLeft = (a_ball.right() - a_brick.left());
    float overlapRight = (a_brick.right() - a_ball.left());
    float overlapTop = (a_ball.bottom() - a_brick.top());
    float overlapBottom = (a_brick.bottom() - a_ball.top());
    bool ballFromLeft = (abs(overlapLeft) < abs(overlapRight));
    bool ballFromTop = (abs(overlapTop) < abs(overlapBottom));
    float minOverLapX = (ballFromLeft? overlapLeft : overlapRight);
    float minOverLapY = (ballFromTop? overlapTop : overlapBottom);

    if (abs(minOverLapX) < abs(minOverLapY)) {
        a_ball.m_velocity.x = ballFromLeft? -a_ball.m_initialVelocity : a_ball.m_initialVelocity;
    } else {
        a_ball.m_velocity.y = ballFromTop? a_ball.m_initialVelocity : -a_ball.m_initialVelocity;
    }
}

void Level::DrawEntities(sf::RenderWindow& a_window) const 
{
    a_window.draw(m_ball);
    a_window.draw(m_paddle);
    for (auto& brick : m_bricks) a_window.draw(brick);
}


void Level::RemoveDestroyedBricks() 
{
    m_bricks.erase(remove_if(begin(m_bricks), end(m_bricks),
    [](const Brick& brick){return brick.m_destroyed;} ),
    end(m_bricks));
  
}


void Level::RunLevel() 
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "My Arkanoid");

    while (window.isOpen() && m_ball.MoveInLimits(windowWidth, windowHeight))
    {
        WindowRemainOpen(window); 
        DrawEntities(window);
        m_paddle.RespondToKeyboard(windowWidth);
        CheckCollision(m_paddle, m_ball);
        
        for (auto& brick : m_bricks) CheckCollision(brick, m_ball);

        RemoveDestroyedBricks(); 

        window.display();
    }
}


} // bs