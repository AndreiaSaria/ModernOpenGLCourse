// OpenGLCourseApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <glfw3.h>

// window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    // initialize glfw
    if (!glfwInit())
    {
        printf("GLFW initialization failed!");
        glfwTerminate();
        return 1;
    }

    //Setup glfw window properties
    //OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //core profile = no backwards compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //allow forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
    if (!mainWindow)
    {
        printf("GLFW window creation failed!");
        glfwTerminate();
        return 1;
    }

    //get buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    //set context for glew to use
    glfwMakeContextCurrent(mainWindow);

    //allow modern externsion features
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
    {
        printf("GLEW initialization failed!");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    //setup viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    //loop until window closed
    while (!glfwWindowShouldClose(mainWindow))
    {
        //get + handle user input events
        glfwPollEvents();

        //clear window
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mainWindow);

    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
