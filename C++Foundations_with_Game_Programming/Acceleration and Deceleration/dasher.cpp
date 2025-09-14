#include "raylib.h"

// Function to update velocity with acceleration
void ApplyAcceleration(int &velocity, int direction, int acceleration, int maxSpeed) {
    velocity += direction * acceleration;  // increase or decrease velocity
    if (velocity > maxSpeed) velocity = maxSpeed;
    if (velocity < -maxSpeed) velocity = -maxSpeed;
}

// Function to apply friction (slows down when no key is pressed)
void ApplyFriction(int &velocity, int friction) {
    if (velocity > 0) {
        velocity -= friction;
        if (velocity < 0) velocity = 0; // stop at 0
    } else if (velocity < 0) {
        velocity += friction;
        if (velocity > 0) velocity = 0;
    }
}

int main(){
    const int windowWidth = 1080;
    const int windowHeight = 720;
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");
    SetTargetFPS(60);

    int circleX = 100;
    int circleY = 100;
    int circleRadius = 15;

    int velocityX = 0;
    int velocityY = 0;
    int acceleration = 2;
    int maxSpeed = 15;
    int friction = 0.1;  // bigger number = slows down faster

    while (!WindowShouldClose()){
        // Input: accelerate when keys are pressed
        if(IsKeyDown(KEY_RIGHT)) ApplyAcceleration(velocityX, 1, acceleration, maxSpeed);
        else if(IsKeyDown(KEY_LEFT)) ApplyAcceleration(velocityX, -1, acceleration, maxSpeed);
        else ApplyFriction(velocityX, friction);

        if(IsKeyDown(KEY_DOWN)) ApplyAcceleration(velocityY, 1, acceleration, maxSpeed);
        else if(IsKeyDown(KEY_UP)) ApplyAcceleration(velocityY, -1, acceleration, maxSpeed);
        else ApplyFriction(velocityY, friction);

        // Update position
        circleX += velocityX;
        circleY += velocityY;

        // Boundaries
        if(circleX < circleRadius) circleX = circleRadius;
        if(circleX > windowWidth-circleRadius) circleX = windowWidth-circleRadius;
        if(circleY < circleRadius) circleY = circleRadius;
        if(circleY > windowHeight-circleRadius) circleY = windowHeight-circleRadius;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(circleX, circleY, circleRadius, BLUE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
