#include "Window.h"
#include "Renderer.h"

int main()
{
	Window* window = new Window();
	Renderer* Instance = new Renderer();
	//To Do change the Esm Normalize member work. 

	while (!glfwWindowShouldClose(static_cast<GLFWwindow*>(window->GetRunningWindow_Ptr())))
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Instance->OnUpdate();
		window->OnUpdate();
	}
	delete window;
	delete Instance;
}
