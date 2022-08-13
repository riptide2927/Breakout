#pragma once
#include <GL/glew.h>
#include <stdint.h>

class VertexBuffer
{
public:
    VertexBuffer(const void* data, int size);
    ~VertexBuffer();
    void Bind() const;
    void Unbind() const;
private:
    uint32_t m_Buffer;
};