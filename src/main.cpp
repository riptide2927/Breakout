#include <iostream>
#include <GL/glew.h>
#include "Window.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

int main()
{
    
    WindowInfo info{};
    info.Width = 800;
    info.Height = 600;
    info.ContexVersionMajor = 4;
    info.ContexVersionMinor = 4;
    info.Resizeable = false;
    info.Title = "Breakout";

    Window window(info);

    glewInit();

    glClearColor(0.5f, 0.25f, 0.2f, 1.0f);
    while(window.ProcessEvents())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        window.SwapBuffers();
    }

    stbi_set_flip_vertically_on_load(true);
}