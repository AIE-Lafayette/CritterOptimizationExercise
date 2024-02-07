#include "Engine.h"
#include "CritterScene.h"

unsigned int Engine::m_screenHeight = 400;
unsigned int Engine::m_screenWidth = 800;

void Engine::start()
{
    m_scene = new CritterScene();
    m_scene->start();
}

void Engine::update()
{
    float delta = GetFrameTime();
    m_scene->update(delta);
}

void Engine::draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    m_scene->draw();

    DrawFPS(10, 10);
    //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
}

void Engine::end()
{
    m_scene->end();

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
}

void Engine::run()
{
    InitWindow(m_screenWidth, m_screenHeight, "raylib [core] example - basic window");

    start();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        update();
        draw();
    }

    end();
}
