//
// Created by fifal on 19.11.17.
//

#ifndef VULPES_ENGINE_SHADERLOADER_H
#define VULPES_ENGINE_SHADERLOADER_H


#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <fstream>

class ShaderLoader {
public:
    static GLuint load_shaders(std::string vertex_path, std::string fragment_path);
};


#endif //VULPES_ENGINE_SHADERLOADER_H
