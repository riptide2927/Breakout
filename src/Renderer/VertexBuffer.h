#pragma once
#include <GL/glew.h>
#include <stdexcept>
#include <glm.hpp>
#include <vector>
#include <assert.h>

struct LayoutElement
{
    GLenum type;
    int count;
    bool normalized;

    static uint32_t GetSizeofType(GLenum type)
    {
        switch(type)
        {
        case GL_FLOAT:  return sizeof(float);
        case GL_INT:    return sizeof(int);
        case GL_UNSIGNED_INT:   return sizeof(unsigned int);
        case GL_UNSIGNED_BYTE:  return sizeof(unsigned char);
        default:    assert(false);     
        }
    }
};

class VertexBufferLayout
{
public:

    VertexBufferLayout()
        : m_Stride(0) {}

    template<typename T>
    void Push(int count)
    {
        assert(false);
    }

    template<>
    void Push<float>(int count)
    {
        m_Layout.push_back({GL_FLOAT, count, false});
        m_Stride += LayoutElement::GetSizeofType(GL_FLOAT) * count;
    }

    template<>
    void Push<uint32_t>(int count)
    {
        m_Layout.push_back({GL_UNSIGNED_INT, count, false});
        m_Stride += LayoutElement::GetSizeofType(GL_UNSIGNED_INT) * count;
    }

    template<>
    void Push<unsigned char>(int count)
    {
        m_Layout.push_back({GL_UNSIGNED_BYTE, count, true});
        m_Stride += LayoutElement::GetSizeofType(GL_UNSIGNED_BYTE) * count;
    }

    inline const std::vector<LayoutElement>& GetElements() const { return m_Layout; }
    inline uint32_t GetStride() const { return m_Stride; }

private:
    std::vector<LayoutElement> m_Layout;
    uint32_t m_Stride;
};

class VertexBuffer
{
public:
    VertexBuffer(const void* data, int size, GLenum usage);
    VertexBuffer(GLenum usage);
    ~VertexBuffer();
    void Bind() const;
    void Unbind() const;
    void Setdata(const void* data, int size);
private:
    int m_Size = 0;
    uint32_t m_Buffer;
    int usage;
};