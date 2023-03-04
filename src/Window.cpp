#include "Window.h"

Window::Window(const WindowInfo& createInfo)
    : m_Info(createInfo)
{
    glfwInit();
    CreateWindow();
}

Window::~Window()
{
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

bool Window::ProcessEvents()
{
    if(!glfwWindowShouldClose(m_Window))
    {
        glfwPollEvents();
        return true;
    }
    return false;
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(m_Window);
}

void Window::CreateWindow()
{
    glfwWindowHint(GLFW_RESIZABLE, m_Info.Resizeable);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_Info.ContexVersionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_Info.ContexVersionMinor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(m_Info.Width, m_Info.Height, m_Info.Title, nullptr, nullptr);

    glfwMakeContextCurrent(m_Window);   
}