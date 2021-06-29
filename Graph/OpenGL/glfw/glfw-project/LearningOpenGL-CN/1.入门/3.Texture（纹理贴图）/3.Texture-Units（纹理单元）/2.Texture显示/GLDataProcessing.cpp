#include "GLDataProcessing.h"

GLDataProcessing::GLDataProcessing()
{
	spX = -100;
	spY = -200;
}
GLDataProcessing::~GLDataProcessing()
{

}

void GLDataProcessing::processInput(GLFWwindow* window)
{
    //Esc关闭窗口
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        spY += 1;
        return;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        spY -= 1;
        return;
    } 
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        spX -= 1;
        return;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        spX += 1;
        return;
    }
       
    
}
