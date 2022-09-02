#include "Window.h"

int main()
{
	Window window("Breakout", 800, 600);


	glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
	while (window.ProcessEvents())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		window.SwapBuffers();
	}

	return 0;
}