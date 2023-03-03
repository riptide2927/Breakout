#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

int main()
{
    if(!glfwInit())
        std::cout << "Error initalizing glfw\n";

    GLFWwindow* window = glfwCreateWindow(800, 600, "Test", nullptr, nullptr);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwMakeContextCurrent(window);

    glewInit();

    glClearColor(0.5f, 0.25f, 0.2f, 1.0f);
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    stbi_set_flip_vertically_on_load(true);
}