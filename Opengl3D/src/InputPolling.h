#pragma once
static float deltatime = 0.0f;
static float lastFrame = 0.0f;

static void ProcessInput(GLFWwindow* window, Esm::Vec3& cameraPos, Esm::Vec3& cameraFront, Esm::Vec3& cameraUp)
{
	float CurrentFrame = glfwGetTime();
	deltatime = CurrentFrame - lastFrame;
	lastFrame = CurrentFrame;

	float cameraSpeed = 2.5f * deltatime;

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraFront;

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraFront;

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		cameraPos -= Esm::CrossProduct(cameraFront, cameraUp)*cameraSpeed;
	}

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		cameraPos += Esm::CrossProduct(cameraFront, cameraUp)*cameraSpeed;
	}
}