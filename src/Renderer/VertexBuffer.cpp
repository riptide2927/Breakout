#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const Vertex* data, int size, GLenum usage)
    : m_Size(size), usage(usage)
{
    glGenBuffers(1, &m_Buffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::VertexBuffer(GLenum usage)
    : usage(usage)
{
    glGenBuffers(1, &m_Buffer);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_Buffer);
}

void VertexBuffer::Bind() const
{
    if(m_Size == 0)
        throw std::runtime_error("If you did not provide data during object construction you should call Setdata before calling any other function");
    
    glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);
}

void VertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::Setdata(const Vertex* data, int size)
{
    if(m_Size != 0)
        throw std::runtime_error("If data was provided during object construction you should not call Setdata");
    
    glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}