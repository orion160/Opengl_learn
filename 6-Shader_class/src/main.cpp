// main.cpp : Defines the entry point for the application.
//
#include <filesystem>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader_class.h"

void framebuffer_size_callback(GLFWwindow* window, const int width, const int height)
{
	glViewport(0, 0, width, height);
}

int main(int argc, char** argv)
{
	if (glfwInit() != GLFW_TRUE)
	{
		// Initialization failed
		return -1;
	}

	const int width = 640;
	const int height = 480;

	GLFWwindow* window = glfwCreateWindow(width, height, "Shader class", nullptr, nullptr);
	if (window == nullptr)
	{
		// Window or OpenGL context creation failed
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
	{
		std::cout << "Failed to initialize GLAD\n";
		glfwTerminate();
		return -1;
	}

	std::cout << "GLFW-version: " << glfwGetVersionString() << '\n';
	std::cout << "Opengl-version: " << glGetString(GL_VERSION) << '\n';
	namespace fs = std::filesystem;
	std::cout << "Current path is " << fs::current_path() << '\n';
	Shader shader("C:/dev/c++/Opengl_learn/6-Shader_class/resources/shaders/vertex/vertex_color.vs", "C:/dev/c++/Opengl_learn/6-Shader_class/resources/shaders/fragment/vertex_color.fs");

	GLfloat vertices[] =
	{
		-0.5F, -0.5F, 0.0F, 1.0F, 0.0F, 0.0F,
		 0.5F, -0.5F, 0.0F, 0.0F, 1.0F, 0.0F,
		 0.0F,  0.5F, 0.0F, 0.0F, 0.0F, 1.0F
	};

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), reinterpret_cast<GLvoid*>(0));
	glEnableVertexAttribArray(0);

	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), reinterpret_cast<GLvoid*>(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use();

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}


	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();

	return 0;
}
