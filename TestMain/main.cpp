//Basic GLFW testing code
//You should see a red spinning triangle when you compile and run this

#define GLEW_STATIC

#include <stdlib.h>
#include <glfw/glfw3.h>

void init();
void killit(int return_code);
void drawScene();
void loadData();

GLuint myVBO;
GLuint myIndices;

float rotZ = 0;

int main()
{
    init();
    loadData();
    
    while(1)
    {
        if (glfwGetKey(GLFW_KEY_ESC) == GLFW_PRESS)
            break;
        
        rotZ += 0.5f;
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        drawScene();
        glfwSwapBuffers();
    }
    
    killit(0);
    return 0;
}

void init()
{
    if (glfwInit() != GL_TRUE)
        killit(1);
    
    if (glfwOpenWindow(800, 600, 8, 8, 8, 0, 0, 0, GLFW_WINDOW) != GL_TRUE)
        killit(1);
    
    //glewInit();
    
    glfwSetWindowTitle("GLFW HelloWorld");
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspectRatio = 600.0f / 800.0f;
    glFrustum(0.5f, -0.5f, -0.5f * aspectRatio, 0.5f * aspectRatio, 1.0f, 50.0f);
    glMatrixMode(GL_MODELVIEW);
}

void killit(int return_code)
{
    glDeleteBuffers(1, &myVBO);
    glDeleteBuffers(1, &myIndices);
    
    glfwTerminate();
    exit(return_code);
}

void drawScene()
{
    glLoadIdentity();
    glTranslatef(0, 0, -10);
    glRotatef(rotZ, 0, 0, 1);
    
    glColor3f(1, 0, 0);
    
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myIndices);
    
    glEnableVertexAttribArray(0);                                               //ENABLE VERTEX POSITION
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);      // VERTEX POSITION POINTER
    
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, 0);
}

void loadData()
{
    GLfloat vertexData[] = {0, 2, 0,  -2, -2, 0,   2, -2, 0};
    GLubyte indexData[] = {0, 1, 2};
    
    glGenBuffers(1, &myVBO);
    glGenBuffers(1, &myIndices);
    
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myIndices);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData), indexData, GL_STATIC_DRAW);
}