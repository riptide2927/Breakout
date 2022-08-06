#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Window
{
public:
    Window(const std::string& Title, int Width, int Height);
    ~Window();
    bool ProcessEvents();
    void SwapBuffers();
private:
    void CreateWindow(); 
private:
    GLFWwindow* m_Window;
    std::string m_Title;
    int m_Width;
    int m_Height;
};