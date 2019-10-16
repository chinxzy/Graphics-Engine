#include "Renderer.h"
#include "../../STB_IMAGE/stb_image.h"
#include <iostream>
#include "../../Esm/Esm/Esmath/Esmath.h"
#include "Window.h"


//*****************
#include <glad/glad.h>
#include <GLFW/glfw3.h>
//*****************
#include "InputPolling.h"


//Temporary
Renderer* Renderer::s_Instance = nullptr;
Renderer::Renderer()
{
	s_Instance = this;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	std::cout << VBO << std::endl;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	std::cout << VBO << std::endl;
	float Vertices[] = {
		// positions          // normals           // texture coords
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	//************Load Texture*************
	glGenTextures(2, Texture);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Texture[0]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	int Height, Width, Channels;
	unsigned char* Data = stbi_load("src/wood.png", &Width, &Height, &Channels, 0);
	if (Data)
	{
		GLenum format;
		if (Channels== 1)
			format = GL_RED;
		else if (Channels == 3)
			format = GL_RGB;
		else if (Channels == 4)
			format = GL_RGBA;
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, format, GL_UNSIGNED_BYTE, Data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cerr << "Texture Failed to Load...\n";
	}
	stbi_image_free(Data);

	//*********Load Second Texture*********
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, Texture[1]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int h, w, c;
	stbi_set_flip_vertically_on_load(true);
	Data = stbi_load("src/metal.png", &w, &h, &c, 0);
	if (Data)
	{
		GLenum format;
		if (Channels == 1)
			format = GL_RED;
		else if (Channels == 3)
			format = GL_RGB;
		else if (Channels == 4)
			format = GL_RGBA;

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, format, GL_UNSIGNED_BYTE, Data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cerr << "Texture Failed to Load...\n";
	}
	stbi_image_free(Data);
	glEnable(GL_DEPTH_TEST);

	glUniform1i(glGetUniformLocation(CubeShader.Program, "material.diffuse"), 0);
	glUniform1i(glGetUniformLocation(CubeShader.Program, "material.Specular"), 1);

}

Renderer::~Renderer()
{
}

void Renderer::OnUpdate()
{

	float Rotate = glfwGetTime();
	float Z = sin(Rotate) * 2.0f;
	float X = cos(Rotate) * 2.0f;

	Perspective.SetPerspective(Esm::Radian(72.0f), 800 / 600, 0.1f, 100.0f);
	View.SetToLookAt(cameraPos,cameraPos+cameraFront,cameraUp);
	
		Model.SetToIdentity();
		CubeShader.Use();
		
		glUniformMatrix4fv(glGetUniformLocation(CubeShader.Program, "Projection"), 1, GL_FALSE, Esm::Value_Ptr(Perspective));
		glUniformMatrix4fv(glGetUniformLocation(CubeShader.Program, "View"), 1, GL_FALSE, Esm::Value_Ptr(View));

		
		//Esm::Vec3 lightColor;
		//lightColor.x = sin(glfwGetTime() * 2.0f);
		//lightColor.y = sin(glfwGetTime() * 0.7f);
		//lightColor.z = sin(glfwGetTime() * 1.3f);

	    //Esm::Vec3 Diffuse = lightColor;
		//Esm::Vec3 Ambient = Diffuse * Esm::Vec3(0.2f, 0.2f, 0.2f);
		//Type of Light emitted From The Light Source;
		glUniform3f(glGetUniformLocation(CubeShader.Program, "LightSource.Ambient"), 0.2f, 0.2f, 0.2f);
		glUniform3f(glGetUniformLocation(CubeShader.Program, "LightSource.Diffuse"), 0.5f, 0.5f, 0.5f);
		glUniform3f(glGetUniformLocation(CubeShader.Program, "LightSource.Specular"), 1.0f, 1.0f, 1.0f);
		glUniform3f(glGetUniformLocation(CubeShader.Program, "LightSource.LightPosition"), GetCamPos().x, GetCamPos().y, GetCamPos().z);
		glUniform3f(glGetUniformLocation(CubeShader.Program, "LightSource.Direction"), cameraFront.x, cameraFront.y, cameraFront.z);
		glUniform1f(glGetUniformLocation(CubeShader.Program, "LightSource.Cutoff"), cos(Esm::Radian(12.5)));
		glUniform1f(glGetUniformLocation(CubeShader.Program, "LightSource.OuterCutoff"), cos(Esm::Radian(17.5)));

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture[0]);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, Texture[1]);
		//Material Type and Shiness Value;
		//glUniform3f(glGetUniformLocation(CubeShader.Program, "material.Ambient"), 1.0f, 0.0f, 0.0f);
	//	glUniform3f(glGetUniformLocation(CubeShader.Program, "material.Diffuse"), 1.0f, 0.0f, 0.0f);
		//glUniform3f(glGetUniformLocation(CubeShader.Program, "material.Specular"), 3.5f, 3.5f, 3.5f);
		glUniform1f(glGetUniformLocation(CubeShader.Program, "material.Shine"), 32.0f);
		
		glUniform3f(glGetUniformLocation(CubeShader.Program, "ViewPos"), GetCamPos().x, GetCamPos().y, GetCamPos().z);
		glBindVertexArray(VAO);
	
		for (int i = 0; i < 10; i++)
		{
			Model.Translate(cubePositions[i]);
			Model.Rotate(Esm::Vec3(0, 1.0, 0), glfwGetTime());
			glUniformMatrix4fv(glGetUniformLocation(CubeShader.Program, "Model"), 1, GL_FALSE, Esm::Value_Ptr(Model));
			Draw();
		}

	//	cubePositions[0].x = X;
	//	cubePositions[0].z = Z;
		Model.Translate(Esm::Vec3(1.2f, 1.0f, 2.0f));
		Model.Scale(Esm::Vec3(0.2f, 0.2f, 0.2f));
		LightShader.Use();
		glUniformMatrix4fv(glGetUniformLocation(LightShader.Program, "Model"), 1, GL_FALSE, Esm::Value_Ptr(Model));
		glUniformMatrix4fv(glGetUniformLocation(LightShader.Program, "Projection"), 1, GL_FALSE, Esm::Value_Ptr(Perspective));
		glUniformMatrix4fv(glGetUniformLocation(LightShader.Program, "View"), 1, GL_FALSE, Esm::Value_Ptr(View));
		glBindVertexArray(VAO);
		//Draw();

		ProcessInput(static_cast<GLFWwindow*>(Window::GetRunningWindow_Ptr()),cameraPos, cameraFront, cameraUp);
}

void Renderer::Draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
