#include "lib/glfw-3.2.1/include/GLFW/glfw3.h"


float lightPos [4] = {0.0f, 0.0f, 2.0f, 1.0f};
float lightAmb[4] = {0.5f, 0.5f, 0.5f, 1.0f};
float lightDiff [4] = {1.0f, 1.0f, 1.0f, 1.0f};

float vertices [8][3] {
        {0, 0, 0},      //V1 viz obrázek ID 0
        {1, 0, 0},      //V2 - 1
        {1, 0, -1},     //V3 - 2
        {0, 0, -1},     //V4 - 3
        {0, 1, 0},      //V5 - 4
        {1, 1, 0},      //V6 - 5
        {1, 1, -1},     //V7 - 6
        {0, 1, -1}      //V8 - 7
};

int faces [12][3]={
        //Spodni plocha--------
        {0, 1, 2}, //V1, V2, V3
        {2, 3, 0}, //V1, V2, V4
        //---------------------
        //Prava stena----------
        {1, 2, 5}, //V2, V3, V6
        {5, 2, 6}, //V3, V6, V7
        //---------------------
        //Leva stena-----------
        {0, 3, 4}, //V1, V4, V5
        {4, 3, 7}, //V4, V5, V8
        //---------------------
        //Horni stena----------
        {4, 5, 7}, //V5, V6, V8
        {7, 5, 6}, //V6, V8, V7
        //---------------------
        //Zadni stena----------
        {2, 3, 6}, //V3, V4, V7
        {6, 3, 7}, //V7, V8, V4
        //---------------------
        //Predni stena---------
        {0, 1, 5}, //V1, V2, V6
        {5, 0, 4}, //V1, V6, V5
};

float normals[6][3]  = {
        {0, 0, -1}, //Spodni stena
        {1, 0, 0},  //Prava stena
        {-1, 0, 0}, //Leva stena
        {0, 1, 0},  //Horni stena
        {0, 0, -1}, //Zadni stena
        {0, 0, 1},  //Predni stena
};

void drawCube() {
    // máme dvanáct faceů
    float r = 0.0f;
    float g = 1.0f;
    for (int i = 0; i < 12; i++) {
        glBegin(GL_TRIANGLES);
        glNormal3f(normals[i / 2][0], normals[i / 2][1], normals[i / 2][2]);
        glColor3f(r, g, 0.0f);
        glVertex3fv(vertices[faces[i][0]]);
        glVertex3fv(vertices[faces[i][1]]);
        glVertex3fv(vertices[faces[i][2]]);
       glEnd();
    }
}

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
    glClearDepth(100.0f);// Nastavení hloubkového bufferu
    glEnable(GL_DEPTH_TEST);// Zapne hloubkové testování
    glDepthFunc(GL_LEQUAL);// Typ hloubkového testování
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);// Nejlepší perspektivní korekce

    glLightfv(GL_LIGHT0,GL_AMBIENT, lightAmb);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
   glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glTranslatef(0,0,1.0f);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        drawCube();

        /* !Rotace okolo osy X*/
        glRotatef(rotate, 1, 1, 1);

        glfwSwapBuffers(window);
        /* Zpracování eventů GLFW */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}