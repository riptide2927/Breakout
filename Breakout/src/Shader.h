#pragma once
#include <GL/glew.h>
#include <unordered_map>
#include <string>
#include <iostream>

class Shader
{
public:
    Shader(const std::string& verfilepath, const std::string& fragfilepath);
    ~Shader();
    int GetUniformLocation(const std::string& name);
    void Bind() const;
    void Unbind() const;
private:
    void CreateProgram(const std::string& verfilepath, const std::string& fragfilepath);
    uint32_t CreateShader(const std::string& shadersrc_path, GLenum type);
    std::string ParseFile(const std::string& filepath);
private:
    std::unordered_map<std::string, int> m_UniformLocationCache;
    uint32_t m_Program;
};