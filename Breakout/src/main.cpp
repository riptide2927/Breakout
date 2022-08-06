#include "Window.h"

int main()
{
	Window window("Breakout", 800, 600);
	while (window.ProcessEvents())
	{
		window.SwapBuffers();
	}

	return 0;
}