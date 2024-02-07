#pragma once

class CritterScene;

class Engine
{
public:

    void start();
    void update();
    void draw();
    void end();

    void run();

    static int getScreenWidth() { return m_screenWidth; }
    static int getScreenHeight() { return m_screenHeight; }

private:
    // Initialization
    //--------------------------------------------------------------------------------------
    static unsigned int m_screenWidth;
    static unsigned int m_screenHeight;
    CritterScene* m_scene;
};

