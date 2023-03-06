#pragma once
#include <GL/glew.h>
#include <stdexcept>
#include <glm.hpp>
#include <vector>

struct LayoutElement
{
    GLenum type;
    uint32_t count;
    bool normalized;

    int GetSizeofType(GLenum type)
    {
        switch(type)
        {
        case GL_FLOAT:  return sizeof(float);
        case GL_INT:    return sizeof(int);
        case GL_UNSIGNED_INT:   return sizeof(unsigned int);
        case GL_UNSIGNED_BYTE:  return sizeof(unsigned char);
        default:    static_assert(false);     
        }
    }
};

struct Vertex
{
public:
    virtual std::vector<LayoutElement>& GetLayout() const = 0;
protected:
    std::vector<LayoutElement> m_Layout;
};

struct BaseVertexType : public Vertex
{
public:
    BaseVertexType()
    {
        m_Layout.push_back( {GL_FLOAT, 3, false} );
        m_Layout.push_back( {GL_FLOAT, 3, false} );
        m_Layout.push_back( {GL_FLOAT, 2, false} );        
    }
public:
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 tex_coords;
};

class VertexBuffer
{
public:
    VertexBuffer(const Vertex* data, int size, GLenum usage);
    VertexBuffer(GLenum usage);
    ~VertexBuffer();
    void Bind() const;
    void Unbind() const;
    void Setdata(const Vertex* data, int size);
private:
    int m_Size = 0;
    uint32_t m_Buffer;
    int usage;
};