#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1920, 1080), "Pong!", Style::Fullscreen);
    
    Bat bat(1920.f * 0.5f, 1080.f - 100.f);
    Ball ball(1920.f*0.5f, 0.f);
    
    bool prevColSide = false;
    bool prevColTop = false;
    bool prevColBat = false;


    Clock clock;
    while (window.isOpen())
    {
        Time dt = clock.restart();
        float deltaTime = dt.asSeconds();

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

       //input
        Sides dir = Sides::NONE;
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            dir = Sides::LEFT;
        }

        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            dir = Sides::RIGHT;
        }
        bat.SetMoveDir(dir);

        FloatRect ballBound = ball.GetGlobalBounds();
        Vector2u windowSize = window.getSize();

        bool colSide = ballBound.left < 0.f || ballBound.left + ballBound.width > windowSize.x;
        bool colTop = ballBound.top < 0.f;
        bool colBat = ballBound.intersects(bat.GetGlobalBounds());

        //오른쪽, 왼쪽 벽에 부딪혔을때.
        if (!prevColSide && colSide)
        {
            ball.ReboundSides();
        }

        if (!prevColTop && colTop)
        {
            ball.ReboundBatOrTop();
        }
        
        if (!prevColBat && colBat)
        {
            ball.ReboundBatOrTop();
        }
        else if (ballBound.top + ballBound.height > windowSize.y)
        {
            ball.Reboundbottom();
        }
        prevColSide = colSide;
        prevColTop = colTop;
        prevColBat = colBat;

        if()


        //update
        bat.Update(deltaTime);
        ball.Update(deltaTime);

        //draw
        window.clear();
        window.draw(bat.GetShape());
        window.draw(ball.GetShape());
        window.display();
    }

    return 0;
}