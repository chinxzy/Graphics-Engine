#pragma once
#include "Shader.h"
#include <Esmath/Esmath.h>

static Esm::Vec3 cubePositions[] = {
	    Esm::Vec3(0.0f,  0.0f,  0.0f),
		Esm::Vec3(2.0f,  5.0f, -15.0f),
		Esm::Vec3(-1.5f, -2.2f, -2.5f),
		Esm::Vec3(-3.8f, -2.0f, -12.3f),
		Esm::Vec3(2.4f, -0.4f, -3.5f),
		Esm::Vec3(-1.7f,  3.0f, -7.5f),
		Esm::Vec3(1.3f, -2.0f, -2.5f),
		Esm::Vec3(1.5f,  2.0f, -2.5f),
		Esm::Vec3(1.5f,  0.2f, -1.5f),
		Esm::Vec3(-1.3f,  1.0f, -1.5f) };

class Renderer
{
public:
	Renderer();
	~Renderer();

	void OnUpdate();
	void Draw();
	Esm::Vec3& GetCamPos() { return cameraPos; }
	Esm::Vec3& GetCamFront() { return cameraFront; }
	Esm::Vec3& GetCamUP() { return cameraUp; }
	static Esm::Vec3& s_GetCamFront() { return s_Instance->cameraFront; }
	static Esm::Vec3& s_GetCamUP() { return s_Instance->cameraUp; }
	static Esm::Vec3& s_GetCamPos() { return s_Instance->cameraPos; }

private:
	static Renderer* s_Instance;

private:
	unsigned int Texture[2];
	unsigned int VAO;
	unsigned int VBO;
	Shader CubeShader = "src/Shaders.shader";
	Shader LightShader = "src/LightShaders.shader";
	Esm::Vec3 cameraPos = Esm::Vec3(0.0f, 0.0f, 3.0f);
	Esm::Vec3 cameraFront = Esm::Vec3(0.0f, 0.0f, -1.0f);
	Esm::Vec3 cameraUp = Esm::Vec3(0.0f, 1.0f, 0.0f);

	Esm::Mat4x4 Slew;
	Esm::Quaternion Q;
	Esm::Mat4x4 Model;
	Esm::Mat4x4 Perspective;
	Esm::Mat4x4 View;

};