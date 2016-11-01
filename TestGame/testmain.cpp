#define GLEW_STATIC
#include "GL/glew.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/constants.hpp>
#include <SOIL.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

GLuint loadShader(string filePath, GLenum shaderType) {
    GLuint shaderID = 0;
    string shaderString;
    ifstream sourceFile(filePath.c_str());
    if (sourceFile) {
        shaderString.assign(
                            (istreambuf_iterator<char>(sourceFile)),
                            (istreambuf_iterator<char>()));
        shaderID = glCreateShader(shaderType);
        const GLchar* shaderSource = shaderString.c_str();
        glShaderSource(shaderID, 1, (const GLchar**) &shaderSource, NULL);
        glCompileShader(shaderID);
        GLint shaderCompiled = GL_FALSE;
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &shaderCompiled);
        if (shaderCompiled != GL_TRUE) {
            cout << "cannot compiled" << endl;
            glDeleteShader(shaderID);
            shaderID = 0;
        }
        sourceFile.close();
    } else {
        cout << "cannot open file" << endl;
    }
    return shaderID;
}

int main(int argc, char** argv) {
    float width = 800;
    float height = 600;
    
    GLFWwindow* window;
    if (!glfwInit())
        return EXIT_FAILURE;
    
    window = glfwCreateWindow((int) width, (int) height, "OpenGL Rotate 3D cube", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return EXIT_FAILURE;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwMakeContextCurrent(window);
    
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        cout << "error in glewInit " << glewGetErrorString(err) << endl;
        return EXIT_FAILURE;
    }
    
    cout << "start cooking" << endl;
    
    GLuint programID = glCreateProgram();
    cout << "created program : " << programID << endl;
    GLuint vertexShader = loadShader("simple.vert.glsl", GL_VERTEX_SHADER);
    if (vertexShader == 0) {
        glDeleteProgram(programID);
        programID = 0;
        return EXIT_FAILURE;
    }
    glAttachShader(programID, vertexShader);
    GLuint fragmentShader = loadShader("simple.frag.glsl", GL_FRAGMENT_SHADER);
    if (fragmentShader == 0) {
        glDeleteProgram(programID);
        programID = 0;
        return EXIT_FAILURE;
    }
    glAttachShader(programID, fragmentShader);
    glLinkProgram(programID);
    glUseProgram(programID);
    GLint programSuccess = GL_TRUE;
    glGetProgramiv(programID, GL_LINK_STATUS, &programSuccess);
    if (programSuccess != GL_TRUE) {
        cout << "error in linkin program " << programID << endl;
        glDeleteProgram(programID);
        programID = 0;
        return EXIT_FAILURE;
    }
    
    
    GLuint vbo_cube_vertices, vbo_cube_texcoords;
    GLuint ibo_cube_elements;
    GLuint texture_id;
    GLint attribute_coord3d, attribute_texcoord;
    GLint uniform_mvp, uniform_mytexture;
    GLfloat cube_vertices[] = {
        // нүүр тал
        -1.0, -1.0, 1.0,
        1.0, -1.0, 1.0,
        1.0, 1.0, 1.0,
        -1.0, 1.0, 1.0,
        // дээд тал
        -1.0, 1.0, 1.0,
        1.0, 1.0, 1.0,
        1.0, 1.0, -1.0,
        -1.0, 1.0, -1.0,
        // ар тал
        1.0, -1.0, -1.0,
        -1.0, -1.0, -1.0,
        -1.0, 1.0, -1.0,
        1.0, 1.0, -1.0,
        // доод тал
        -1.0, -1.0, -1.0,
        1.0, -1.0, -1.0,
        1.0, -1.0, 1.0,
        -1.0, -1.0, 1.0,
        // зүүн тал
        -1.0, -1.0, -1.0,
        -1.0, -1.0, 1.0,
        -1.0, 1.0, 1.0,
        -1.0, 1.0, -1.0,
        // баруун тал
        1.0, -1.0, 1.0,
        1.0, -1.0, -1.0,
        1.0, 1.0, -1.0,
        1.0, 1.0, 1.0,
    };
    
    glGenBuffers(1, &vbo_cube_vertices);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_cube_vertices);
    glBufferData(GL_ARRAY_BUFFER, sizeof (cube_vertices), cube_vertices, GL_STATIC_DRAW);
    GLfloat cube_texcoords[2 * 4 * 6] = {
        // нүүр
        0.0, 0.0,
        1.0, 0.0,
        1.0, 1.0,
        0.0, 1.0,
    };
    for (int i = 1; i < 6; i++)
        memcpy(&cube_texcoords[i * 4 * 2], &cube_texcoords[0], 2 * 4 * sizeof (GLfloat));
    glGenBuffers(1, &vbo_cube_texcoords);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_cube_texcoords);
    glBufferData(GL_ARRAY_BUFFER, sizeof (cube_texcoords), cube_texcoords, GL_STATIC_DRAW);
    
    GLushort cube_elements[] = {
        // нүүр тал
        0, 1, 2,
        2, 3, 0,
        // дээд тал
        4, 5, 6,
        6, 7, 4,
        // ар тал
        8, 9, 10,
        10, 11, 8,
        // доод тал
        12, 13, 14,
        14, 15, 12,
        // зүүн тал
        16, 17, 18,
        18, 19, 16,
        // баруун тал
        20, 21, 22,
        22, 23, 20,
    };
    glGenBuffers(1, &ibo_cube_elements);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_cube_elements);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof (cube_elements), cube_elements, GL_STATIC_DRAW);
    
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    GLint texture_width, texture_height;
    unsigned char* img = SOIL_load_image("texture.jpg", &texture_width, &texture_height, NULL, 0);
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGB,
                 texture_width,
                 texture_height,
                 0,
                 GL_RGB,
                 GL_UNSIGNED_BYTE,
                 img);
    
    
    const char* attribute_name;
    attribute_name = "coord3d";
    attribute_coord3d = glGetAttribLocation(programID, attribute_name);
    attribute_name = "texcoord";
    attribute_texcoord = glGetAttribLocation(programID, attribute_name);
    const char* uniform_name;
    uniform_name = "mvp";
    uniform_mvp = glGetUniformLocation(programID, uniform_name);
    uniform_name = "mytexture";
    uniform_mytexture = glGetUniformLocation(programID, uniform_name);
    
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glEnable(GL_DEPTH_TEST);
    
    float deltaTime = 0.0f;
    float startTime = glfwGetTime();
    float buffTime = 0.0;
    int counter = 0;
    while (!glfwWindowShouldClose(window)) {
        static float angle = 0.0f;
        angle += deltaTime * 15;
        glm::mat4 anim =
        glm::rotate(glm::mat4(1.0f), angle * 3.0f, glm::vec3(1, 0, 0)) * // X тэнхлэг
        glm::rotate(glm::mat4(1.0f), angle * 2.0f, glm::vec3(0, 1, 0)) * // Y тэнхлэг
        glm::rotate(glm::mat4(1.0f), angle * 4.0f, glm::vec3(0, 0, 1)); // Z тэнхлэг
        
        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, -4.0));
        glm::mat4 view = glm::lookAt(glm::vec3(0.0, 2.0, 0.0), glm::vec3(0.0, 0.0, -4.0), glm::vec3(0.0, 1.0, 0.0));
        glm::mat4 projection = glm::perspective(45.0f, 1.0f * width / height, 0.1f, 10.0f);
        
        glm::mat4 mvp = projection * view * model * anim;
        glUseProgram(programID);
        glUniformMatrix4fv(uniform_mvp, 1, GL_FALSE, glm::value_ptr(mvp));
        
        
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glUseProgram(programID);
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture_id);
        glUniform1i(uniform_mytexture, /*GL_TEXTURE*/0);
        
        glEnableVertexAttribArray(attribute_coord3d);
        glBindBuffer(GL_ARRAY_BUFFER, vbo_cube_vertices);
        glVertexAttribPointer(
                              attribute_coord3d,
                              3,
                              GL_FLOAT,
                              GL_FALSE,
                              0,
                              0
                              );
        
        glEnableVertexAttribArray(attribute_texcoord);
        glBindBuffer(GL_ARRAY_BUFFER, vbo_cube_texcoords);
        glVertexAttribPointer(
                              attribute_texcoord,
                              2,
                              GL_FLOAT,
                              GL_FALSE,
                              0,
                              0
                              );
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_cube_elements);
        int size;
        glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
        glDrawElements(GL_TRIANGLES, size / sizeof (GLushort), GL_UNSIGNED_SHORT, 0);
        
        glDisableVertexAttribArray(attribute_coord3d);
        glDisableVertexAttribArray(attribute_texcoord);
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        
        double lastTime = glfwGetTime();
        deltaTime = lastTime - startTime;
        startTime = lastTime;
        counter++;
        buffTime += deltaTime;
        if (buffTime > 1.0f) {
            buffTime = 0.0f;
            cout << "fps " << counter << endl;
            counter = 0;
        }
    }
    
    
    SOIL_free_image_data(img);
    glDeleteBuffers(1, &vbo_cube_vertices);
    glDeleteBuffers(1, &vbo_cube_texcoords);
    glDeleteBuffers(1, &ibo_cube_elements);
    glDeleteTextures(1, &texture_id);
    
    // shader ээ устгах
    glUseProgram(0);
    glDetachShader(programID, vertexShader);
    glDetachShader(programID, fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteProgram(programID);
    
    glfwTerminate();
    return 0;
}