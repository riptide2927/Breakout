#include "VertexArray.h"
#include "Shader.h"
#include "Window.h"

int main()
{
	Window window("Breakout", 800, 600);

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	VertexArray va;
	VertexBuffer vb(vertices, sizeof(vertices));
	VertexBufferLayout vertexLayout;
	vertexLayout.Push<float>(3);
	va.AddLayout(vb, vertexLayout);

	Shader myShader("VertexShader.glsl", "FragmentShader.glsl");


	while (window.ProcessEvents())
	{
		glClearColor(0.5f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		va.Bind();
		myShader.Bind();

		glDrawArrays(GL_TRIANGLES, 0, 3);

		va.Unbind();
		myShader.Unbind();

		window.SwapBuffers();
	}

	return 0;
}