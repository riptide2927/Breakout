#include <fstream>
#include <vector>

#include "Shader.h"

Shader::Shader(const std::string& verfilepath, const std::string& fragfilepath)
{
    CreateProgram(verfilepath, fragfilepath);
}

Shader::~Shader()
{
    glDeleteShader(m_Program);
}

int Shader::GetUniformLocation(const std::string& name)
{
    if(m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
    {
        return m_UniformLocationCache[name];
    }
    int Location = glGetUniformLocation(m_Program, name.c_str());
    m_UniformLocationCache.emplace(name, Location);
    return Location;
}

void Shader::CreateProgram(const std::string& verfilepath, const std::string& fragfilepath)
{
    m_Program = glCreateProgram();
    uint32_t vertexShader = CreateShader(verfilepath, GL_VERTEX_SHADER);
    uint32_t fragmentShader = CreateShader(fragfilepath, GL_FRAGMENT_SHADER);
    glAttachShader(m_Program, vertexShader);
    glAttachShader(m_Program, fragmentShader);

    glLinkProgram(m_Program);

    int sucess;
    glGetProgramiv(m_Program, GL_LINK_STATUS, &sucess);
    if(sucess == GL_FALSE)
    {
        int logsize = 0;
        glGetProgramiv(m_Program, GL_INFO_LOG_LENGTH, &logsize);
        char* InfoLog = (char*)alloca(logsize * sizeof(char));

        glGetProgramInfoLog(m_Program, logsize, &logsize, InfoLog);
        std::cout << InfoLog << '\n';
        glDeleteProgram(m_Program);
        exit(-1);
    }

}

uint32_t Shader::CreateShader(const std::string& shadersrc_path, GLenum type)
{
    const char* shader_src = ParseFile(shadersrc_path);
    uint32_t shader = glCreateShader(type);

    int sucess;
    glShaderSource(shader, 1, &shader_src, nullptr);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &sucess);

    if(sucess == GL_FALSE)
    {
        int logsize = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logsize);
        char* InfoLog = (char*)alloca(logsize * sizeof(char));
        
        glGetShaderInfoLog(shader, logsize, &logsize, InfoLog);
        std::cout << InfoLog << '\n';
        glDeleteShader(shader);
        exit(-1);
    }

    return shader;
    
}

const char* Shader::ParseFile(const std::string& filepath)
{
    std::ifstream file;
    file.open(filepath);

    std::string src;
    std::string line;

    while(getline(file, line))
    {
        src += line + '\n';
    }

    return src.c_str();

}