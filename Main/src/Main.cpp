#include "Caro.h"
#include <glad\glad.h>
#include <GLFW\glfw3.h>

using namespace std;

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(int argc, char **argv)
{
	// string player1, player2;
	// int Cgame = 0, Cscore = 0;
	// int color = 1, sized = 1;
	// int check[100][100];
	// int minimax[100][100];
	// int find[100][100];
	// int mode = 1;
	// for (int k = 0; k < 100; k++)
	// {
	// 	for (int i = 0; i < 100; i++)
	// 	{
	// 		check[k][i] = 0;
	// 	}
	// }
	// display_splash();
	// initialize(argc, argv);
	// Menu(sized, color, player1, player2, check, mode, find, minimax, Cgame, Cscore);
	// system("pause");
	// return 0;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, " LearnOpenG:", NULL, NULL);
	if (window == NULL)
	{
		cout << "Failed to create GLFW Window" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0f, 1.f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}