#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Window
{

public:
	Window(float Height=600,float Width=800, const char* Title="Opengl3D Practice");
	~Window();

	void Init();
	void OnUpdate();
	static void* GetRunningWindow_Ptr() { return s_Window->GetNativeWindow(); }
	bool m_Running;
private:
    void* GetNativeWindow() { return window; }
	float Height;
	float Width;
	const char* Title;
	GLFWwindow* window;
	static Window* s_Window;

};

