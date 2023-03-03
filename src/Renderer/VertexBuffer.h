#pragma once
#include <GL/glew.h>
#include <stdexcept>

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