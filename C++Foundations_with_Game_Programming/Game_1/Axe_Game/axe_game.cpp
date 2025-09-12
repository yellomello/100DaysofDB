#include "raylib.h"
int main()

{   
    //Window Dimensions
    int width = 800;
    int height = 450;
    InitWindow(width,height, "Game");
   
    //Circle Coordinates
    int circleY = 100;
    int circleX2 = 775;
    int circleX = 175;
    int circleY2 = 225;
    int circleRadius = 25;  
    
    //Square Coordinates
    // DrawRectange(posX, posY, width, height, color);
    int square1X = 750;
    int square2X = 650;
    int square1Y = 400;  
    int square2Y = 0;  
    int squareWidth = 50;
    int squareHeight = 50;
    int direction1 = 20;  //Increase by 10 pixels every frame
    int direction2= 20;  //Increase by 10 pixels every frame
    int counter = 0;

    bool collision = false;
    bool win = false;


    SetTargetFPS(60);
    int circle_moving_factor = 5;
    // int square_moving_factor = 10;
    while (WindowShouldClose() == false){
        if( win == true) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("You Win!", 350, 200, 50, BLACK);
            DrawText(TextFormat("%d", counter), 20, 20, 50, BLACK);
            DrawText("Press R to Restart", 300, 300, 20, BLACK);
            if (IsKeyDown(KEY_R)){
                    win = false;
                    circleX = 175;
                    circleY = 100;
                    square1Y = 400;  
                    square2Y = 0;  
                    direction1 = 20;  
                    direction2= 20;  
                    counter = 0;
                }
            EndDrawing();

        }
         else{
        if (collision == false ){
 
       
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle  (circleX, circleY, circleRadius, BLUE);
        DrawText(TextFormat("%d", counter), 20, 20, 50, BLACK);
        DrawCircle  (circleX2, circleY2, circleRadius, GREEN);

        if (IsKeyDown(KEY_RIGHT)&& circleX < width - circleRadius) circleX += circle_moving_factor;
        if (IsKeyDown(KEY_LEFT)&&circleX > 0 + circleRadius) circleX -= circle_moving_factor ;      
        if (IsKeyDown(KEY_UP)&& circleY > 0 + circleRadius) circleY -= circle_moving_factor  ;
        if (IsKeyDown(KEY_DOWN)&& circleY < height - circleRadius ) circleY += circle_moving_factor ;

        

        DrawRectangle(square1X, square1Y, squareWidth, squareHeight, RED);
        square1Y +=direction1;
        if ((square1Y > height - squareHeight) || (square1Y < 0)) direction1 = - direction1;

        DrawRectangle(square2X, square2Y, squareWidth, squareHeight, RED);
        square2Y +=direction2;       
        if ((square2Y > height - squareHeight) || (square2Y < 0)) direction2 = - direction2;

        


        // if (IsKeyDown(KEY_D)&& squareX < width - squareWidth) squareX += square_moving_factor ;
        // if (IsKeyDown(KEY_A)&& squareX > 0 ) squareX -= square_moving_factor ;     
        // if (IsKeyDown(KEY_W)&& squareY > 0 ) squareY -= square_moving_factor ;     
        // if (IsKeyDown(KEY_S) && squareY < height - squareHeight ) squareY += square_moving_factor;

         if (circleX + circleRadius >= square1X &&
            circleX-circleRadius <= square1X + squareWidth &&
            circleY + circleRadius >= square1Y &&
            circleY - circleRadius <= square1Y + squareHeight) {
            
            
            collision = true;
            counter += 1;
        }
        if (circleX + circleRadius >= square2X &&
            circleX-circleRadius <= square2X + squareWidth &&
            circleY + circleRadius >= square2Y &&
            circleY - circleRadius <= square2Y + squareHeight) {
            collision = true;
            counter += 1;
        }
        if (circleX + circleRadius >= circleX2 - circleRadius &&
            circleX - circleRadius <= circleX2 + circleRadius &&
            circleY + circleRadius >= circleY2 - circleRadius &&
            circleY - circleRadius <= circleY2 + circleRadius) {
            win = true;
        }


        EndDrawing();
         }
            else {
                
                // if (IsKeyDown(KEY_R)){
                    collision = false;
                    circleX = 175;
                    circleY = 100;
                    square1Y = 400;  
                    square2Y = 0;  
                    direction1 = 20;  
                    direction2= 20;  
                // }
                 
            }
        
        }
    }
}

