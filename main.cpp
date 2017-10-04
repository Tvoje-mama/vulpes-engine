#include "lib/glfw-3.2.1/include/GLFW/glfw3.h"

int main(int argc, char**argv){
    GLFWwindow* window;
    float rotate = 0.5f;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Zapnout jemný stínování*/
    glShadeModel(GL_SMOOTH);// Jemné stínování
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);// Černé pozadí
    glClearDepth(1.0f);// Nastavení hloubkového bufferu
    glEnable(GL_DEPTH_TEST);// Zapne hloubkové testování
    glDepthFunc(GL_LEQUAL);// Typ hloubkového testování
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);// Nejlepší perspektivní korekce

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);
        glVertex3f(-1,-1,0);
        glVertex3f(1,-1,0);
        glVertex3f(0,1,0);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0,1,0);
        glVertex3f(-1,1,0);
        glVertex3f(0,1,0);
        glVertex3f(-1,-1,0);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0,1,0);
        glVertex3f(1,1,0);
        glVertex3f(0,1,0);
        glVertex3f(1,-1,0);
        glEnd();
        glfwSwapBuffers(window);
        /* Zpracování eventů GLFW */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}