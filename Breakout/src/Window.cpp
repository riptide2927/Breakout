#include "Window.h"

Window::Window(const std::string& Title, int Width, int Height)
    : m_Title(Title), m_Width(Width), m_Height(Height)
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
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);

    glfwMakeContextCurrent(m_Window);

    glewExperimental = GL_TRUE;
    glewInit();
    glViewport(0, 0, m_Width, m_Height);

}