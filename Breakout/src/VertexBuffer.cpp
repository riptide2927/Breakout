#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, int size)
{
    glGenBuffers(1, &m_Buffer);
    Bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    Unbind();
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_Buffer);
}

void VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);
}

void VertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}