#include "raylib.h"

int main(){
    const int windowWidth = 800;
    const int windowHeight = 600;


    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");
    SetTargetFPS(60);
  
    //rectangle dimensions
    const int gravity = 1; //acceleration due to gravity

    const int rectWidth = 20;
    const int rectHeight =50 ;
    // Grid settings
// int gridSpacing = 50;   // distance between grid lines in pixels

// // Draw vertical lines
// for (int x = 0; x < windowWidth; x += gridSpacing) {
//     DrawLine(x, 0, x, windowHeight, LIGHTGRAY);
// }

// // Draw horizontal lines
// for (int y = 0; y < windowHeight; y += gridSpacing) {
//     DrawLine(0, y, windowWidth, y, LIGHTGRAY);
// }


    int posY = windowHeight - rectHeight; //start at ground level
    int velocity = 0; 
    bool isInAir = false;

    while(!WindowShouldClose()){
        //start drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);
  // Grid settings
int gridSpacing = 50;   // distance between grid lines in pixels

// Draw vertical lines + labels
for (int x = 0; x < windowWidth; x += gridSpacing) {
    DrawLine(x, 0, x, windowHeight, LIGHTGRAY);
    DrawText(TextFormat("%d", x), x + 2, 2, 10, DARKGRAY);  // label x-axis
}

// Draw horizontal lines + labels
for (int y = 0; y < windowHeight; y += gridSpacing) {
    DrawLine(0, y, windowWidth, y, LIGHTGRAY);
    DrawText(TextFormat("%d", y), 2, y + 2, 10, DARKGRAY);  // label y-axis
}

        if (posY >= (windowHeight-rectHeight)){
             //stop at ground
            velocity = 0; 
            isInAir = false;
        }
        else{
            //apply gravity
        velocity += gravity; //velocity = velocity + gravity}
        }

        if (IsKeyPressed(KEY_SPACE)&&!isInAir){
            velocity -= 20;
            isInAir = true; //jump
        }
        if (posY < 0){
            posY = 0; //stop at top
            velocity = 0;

        }
        else if (posY > windowHeight - rectHeight){
            posY = windowHeight - rectHeight; //stop at ground
            velocity = 0;
            isInAir = false;
        }
        posY += velocity; 

        DrawRectangle(windowWidth/2, posY, rectWidth, rectHeight, RED);
//GRID
// Instructions at top-left
DrawText("Press SPACE to jump!", 20, 10, 20, DARKGRAY);

// Debug info aligned below each other
DrawText(TextFormat("y = %d", posY), 20, 40, 20, BLACK);
DrawText(TextFormat("velocity = %d", velocity), 20, 70, 20, BLACK);

EndDrawing(); 

    }//while
    CloseWindow();
    // return 0;
}//main