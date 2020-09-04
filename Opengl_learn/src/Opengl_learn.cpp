// Opengl_learn.cpp : Defines the entry point for the application.
//

#include "Opengl_learn.h"

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

	GLFWwindow* window = glfwCreateWindow(width, height, "My Title", nullptr, nullptr);
	if (window == nullptr)
	{
		// Window or OpenGL context creation failed
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
	{
		std::cout << "Failed to initialize GLAD\n";
		glfwTerminate();
		return -1;
	}

	std::cout << glGetString(GL_VERSION) << '\n';

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);

		glColor3f(1.0F, 0.0F, 0.0F);
		glVertex3f(-0.6F, -0.4F, 0.0F);
		glColor3f(0.0F, 1.0F, 0.0F);
		glVertex3f(0.6F, -0.4F, 0.0F);
		glColor3f(0.0F, 0.0F, 1.0F);
		glVertex3f(0.0F, 0.6F, 0.0F);

		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
