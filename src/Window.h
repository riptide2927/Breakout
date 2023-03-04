#pragma once
#include <GLFW/glfw3.h>
#include <tuple>

struct WindowInfo
{
    uint32_t Width;
    uint32_t Height;
    const char* Title;
    bool Resizeable = true;
    int ContexVersionMajor = 4;
    int ContexVersionMinor = 4;
};

class Window
{
public:
    Window(const WindowInfo& createInfo);
    ~Window();
    bool ProcessEvents();
    void SwapBuffers();
    inline std::pair<int, int> GetDimensions() const { return std::pair<int, int>(m_Info.Width, m_Info.Height); }
private:
    void CreateWindow();
    WindowInfo m_Info;
    GLFWwindow* m_Window;
};