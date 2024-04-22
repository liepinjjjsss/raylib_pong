#include <iostream>
#include "raylib.h"

using namespace std;
int main() 
{
    
    InitWindow(1800, 800, "Pong");
    int screenHeight = GetScreenHeight();
    int screenWidth = GetScreenWidth();

    float posX = screenWidth/2;
    float posY = screenHeight/2;
    int borderRight = screenWidth-50;
    int borderLeft = 50;
    int borderTop = 50;
    int borderBottom = screenHeight-50;
    float velocityX = 0.02;
    float velocityY = 0.015;

    Rectangle paddle1 = {50,(screenHeight/2)-paddle1.height/2, 10, 120};
    Rectangle paddle2 = {screenWidth-50, screenHeight/2 - paddle2.height/2, 10, 120};

    Vector2 circle = {posX, posY};

    float paddle1CenterY = paddle1.y+(paddle1.height/2);
    float paddle2CenterY = paddle2.y+(paddle2.height/2);

    

    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawRectangleRec(paddle1, WHITE);
        DrawRectangleRec(paddle2, WHITE);
        DrawCircleV(circle, 20, BLUE);
        EndDrawing();
        ClearBackground(BLACK);

        circle.x += velocityX;
        circle.y += velocityY;

        if(IsKeyDown(KEY_UP))
        {
            paddle1.y -= 0.1;
        } else if (IsKeyDown(KEY_DOWN))
        {
            paddle1.y += 0.1;
        }

        if(circle.y >= borderBottom)
        {
            velocityY = -velocityY;
        } else if (circle.y <= borderTop)
        {
            velocityY = -velocityY;
        }

        paddle2.y = circle.y - paddle2.height/2;

        bool collision1 = CheckCollisionCircleRec(circle, 20, paddle1);
        bool collision2 = CheckCollisionCircleRec(circle, 20, paddle2);

        if (collision1) 
        {
            float collisionOffsetY = circle.y - paddle1CenterY;
            float reflectionAngle = collisionOffsetY*0.005;
            cout << reflectionAngle <<endl;
            if (reflectionAngle > 0.03) 
            {
                reflectionAngle = 0.03;
            }else if (reflectionAngle < -0.03)
            {
                reflectionAngle = -0.03;
            }

            velocityX = -velocityX;
            velocityY = reflectionAngle;
        }

        if (collision2)
        {
           float collisionOffsetY = circle.y - paddle2CenterY;
            float reflectionAngle = collisionOffsetY*0.005;
            cout << reflectionAngle <<endl;
            if (reflectionAngle > 0.03) 
            {
                reflectionAngle = 0.03;
            }else if (reflectionAngle < -0.03)
            {
                reflectionAngle = -0.03;
            }

            velocityX = -velocityX;
            velocityY = reflectionAngle;
        }

    }
    CloseWindow();
    return 0;
}