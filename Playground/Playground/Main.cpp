#include "libs.h"

void frameBufferResizeCallback(GLFWwindow* window, int fbW, int fbH);

int main() {
	//Init GLFW
	glfwInit();

	//Create Window
	//Window Options
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;
	int framebufferWidth = 0;
	int framebufferHeight = 0;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	//Pointer
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "HelloWorld", NULL, NULL);

	glfwSetFramebufferSizeCallback(window, frameBufferResizeCallback);

	glfwMakeContextCurrent(window);
	//Error Checking
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//Init GLEW
	glewExperimental = GL_TRUE;
	//Error Checking
	if (glewInit() != GLEW_OK) {
		std::cout << "ERROR::MAIN.CPP::GLEW_INIT_FAILED" << std::endl;
		glfwTerminate();
	}

	//Main Loop
	while (!glfwWindowShouldClose(window)) {
		//UPDATE INPUT ---
		glfwPollEvents();
		//UPDATE ---

		//DRAW ---
		//Clear Old Frame
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		//Clear Buffers in Use
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		//Draw New Frame
		

		//End Draw
		//Swap Buffers, Flush GL
		glfwSwapBuffers(window);
		glFlush();
	}

	//End of Program
	glfwTerminate();

	return 0;
}

void frameBufferResizeCallback(GLFWwindow* window, int fbW, int fbH) {
	glViewport(0, 0, fbW, fbH);
}
