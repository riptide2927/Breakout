#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <unordered_map>
#include <string>

class Shader
{
public:
    Shader(const std::string& vertfilepath, const std::string& fragfilepath);
    Shader(const char* vertsrc, const char* fragsrc);
    ~Shader();
    void Bind() const;
    void Unbind() const;
public:
    // Utils
    void SetMat3f(const std::string& name, glm::mat3 value);
    void SetInt(const std::string& name, int value);
    void SetFloat(const std::string& name, float value);
    void SetVec3f(const std::string& name, glm::vec3 value);
    void SetVec4f(const std::string& name, glm::vec4 value);
    void SetMat4f(const std::string& name, glm::mat4 value);
private:
    uint32_t GetUniformLocation(const std::string& name);
    static std::string ParseFile(const std::string& filepath);
private:
    std::unordered_map<std::string, uint32_t> m_Cache;
    uint32_t m_Program;
};