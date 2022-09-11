#include "Window.h"
#include "Shader.h"
#include "VertexType.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include <windows.h>
#include <iostream>

struct Ve
{
	glm::vec3 pos;
};

int main()
{
	Window window("Breakout", 800, 600);

	Vertex verticies[] = {
		{glm::vec3(0.5f,  0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		{glm::vec3(0.5f, -0.5f, 0.0f),  glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		{glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)}
	};

	uint32_t indicies[] = {
		0, 1, 3,
		1, 2, 3
	};

	VertexArray va;
	VertexBuffer vb(verticies, sizeof(Vertex) * ARRAYSIZE(verticies));
	VertexBufferLayout layout;
	IndexBuffer ib(indicies, 6);

	layout.Push<float>(3);
	layout.Push<float>(3);
	layout.Push<float>(2);

	va.AddLayout(vb, layout);

	Shader shader("vert.vert", "frag.frag");
	
	glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
	while (window.ProcessEvents())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		shader.Bind();
		va.Bind();
		ib.Bind();

		glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);

		window.SwapBuffers();
	}

	return 0;
}