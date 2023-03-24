#include "Shader.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>

Shader::Shader(const std::string& vertfilepath, const std::string& fragfilepath)
{
    m_Program = glCreateProgram();
    uint32_t vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    uint32_t fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertex_src = Shader::ParseFile(vertfilepath);
    std::string fragment_src = Shader::ParseFile(fragfilepath);

    const char* pVertexSrc = vertex_src.c_str();
    const char* pFragmentSrc = fragment_src.c_str();

    glShaderSource(vertex_shader, 1, &pVertexSrc, nullptr);
    glShaderSource(fragment_shader, 1, &pFragmentSrc, nullptr);

    glCompileShader(vertex_shader);
    glCompileShader(fragment_shader);

    // TODO: ERROR CHECKING

    glAttachShader(m_Program, vertex_shader);
    glAttachShader(m_Program, fragment_shader);
    glLinkProgram(m_Program);

    // TODO: ERROR CHECKING

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

Shader::Shader(const char* vertsrc, const char* fragsrc)
{
    m_Program = glCreateProgram();
    uint32_t vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    uint32_t fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertex_shader, 1, &vertsrc, nullptr);
    glShaderSource(fragment_shader, 1, &fragsrc, nullptr);

    glCompileShader(vertex_shader);
    glCompileShader(fragment_shader);

    // TODO: ERROR CHECKING

    glAttachShader(m_Program, vertex_shader);
    glAttachShader(m_Program, fragment_shader);
    glLinkProgram(m_Program);

    // TODO: ERROR CHECKING

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

}

Shader::~Shader()
{
    glDeleteShader(m_Program);
}

void Shader::Bind() const
{
    glUseProgram(m_Program);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}

uint32_t Shader::GetUniformLocation(const std::string& name)
{
    if (m_Cache.find(name) != m_Cache.end())
    {
        return m_Cache[name];
    }

    uint32_t location = glGetUniformLocation(m_Program, name.c_str());
    m_Cache[name] = location;

    return location;

}

std::string Shader::ParseFile(const std::string& filepath)
{
    std::fstream file(filepath, std::ios::app | std::ios::in);

    if(!file.is_open()) {
        throw std::runtime_error("Failed to open the file: " + filepath);
    }

    std::string line;
    std::string src;

    while (std::getline(file, line))
    {
        src += line + '\n';
    }

    return src;
}

void Shader::SetMat3f(const std::string& name, glm::mat3 value)
{
    glUniformMatrix3fv(GetUniformLocation(name), 1, false, glm::value_ptr(value));
}

void Shader::SetInt(const std::string& name, int value)
{
    glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetFloat(const std::string& name, float value)
{
    glUniform1f(GetUniformLocation(name), value);
}

void Shader::SetVec3f(const std::string& name, glm::vec3 value)
{
    glUniform3fv(GetUniformLocation(name), 1, glm::value_ptr(value));
}

void Shader::SetVec4f(const std::string& name, glm::vec4 value)
{
    glUniform4fv(GetUniformLocation(name), 1, glm::value_ptr(value));
}

void Shader::SetMat4f(const std::string& name, glm::mat4 value)
{
    glUniformMatrix4fv(GetUniformLocation(name), 1, false, glm::value_ptr(value));
}