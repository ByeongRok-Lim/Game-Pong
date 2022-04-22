#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"
#include "brick.h"
#include "brickMgr.h"
using namespace sf;

#define xSize 5
#define ySize 10

int main()
{

    RenderWindow window(VideoMode(1920, 1080), "Pong!", Style::Fullscreen);
    /*RectangleShape blks[rows][col];
    blocks(blks);*/
    
    Bat bat(1920.f * 0.5f, 1080.f - 100.f);
    Ball ball(1920.f*0.5f, 0.f);
    //brick brick(50.f, 50.f);
    brickMgr brickArr(xSize, ySize);
   /* for (int i = 0; i < xSize; i++)
    {
        for (int j = 0; j < ySize; j++)
        {
            brickArr(&i, &j)
        }
    }*/
    


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




        //update
        bat.Update(deltaTime);
        ball.Update(deltaTime);

        //draw
        window.clear();
        window.draw(bat.GetShape());
        window.draw(ball.GetShape());
        for (int i = 0; i < xSize * ySize; i++)
        {
            window.draw(brickArr.GetShape(i));

        }
        //DrawBlocks(blks);
        window.display();
    }

    return 0;
}