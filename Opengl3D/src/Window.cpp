#include <iostream>
#include "Window.h"
#include "Esmath/Esmath.h"
#include "Renderer.h"

Window* Window::s_Window = nullptr;

//*******Temp********
float LastX = 800.0f / 2.0f;
float LastY = 600.0f / 2.0f;

float Heading=-90.0f;
float Pitch=0.0f;
bool FirstMouse_Use = true;
//*******************

Window::Window(float Height, float Width, const char* Title)
	:Height(Height), Width(Width), Title(Title)
{
	s_Window = this;
	Init();
	m_Running = true;
}

Window::~Window()
{
}

void Window::Init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(Width, Height, Title, NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	glfwSetWindowSizeCallback(window, [](GLFWwindow* Window, int height, int width)
	{
		glViewport(0, 0, width, height);
	});

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwSetCursorPosCallback(window, [](GLFWwindow* Window, double xpos, double ypos)
	{

		Esm::Vec3 Front;
		if (FirstMouse_Use)
		{
			LastX = xpos;
			LastY = ypos;
		    FirstMouse_Use = false;
		}

		float Xoffset = xpos - LastX;
		float Yoffset = LastY - ypos;

		LastX = xpos;
		LastY = ypos;

		float Sensitivity = 0.05;
		Xoffset *= Sensitivity;
		Yoffset *= Sensitivity;

			Heading += Xoffset;
			Pitch += Yoffset;

			if (Pitch >= 89.0f)
				Pitch = 89.0f;
			if (Pitch <= -89.0f)
				Pitch = -89.0f;

		
		Front.x = cos(Esm::Radian(Heading)) * cos(Esm::Radian(Pitch));
		Front.y = sin(Esm::Radian(Pitch));
		Front.z = sin(Esm::Radian(Heading)) * cos(Esm::Radian(Pitch));
		Front.Normalize();
		Renderer::s_GetCamFront() = Front;

		Esm::Vec3 Right = Esm::CrossProduct(Esm::Vec3(0.0f, 1.0f, 0.0f), Front);
		Renderer::s_GetCamUP() = Esm::CrossProduct(Front, Right);

		Renderer::s_GetCamUP().Normalize();
	});

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
	glViewport(0, 0, 800, 600);

}

void Window::OnUpdate()
{
	glfwPollEvents();
	glfwSwapBuffers(window);
}
