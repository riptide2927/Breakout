#pragma once
#include <GL/glew.h>
#include <stdint.h>

class IndexBuffer
{
public:
    IndexBuffer(const void* data, int count);
    ~IndexBuffer();
    inline int GetCount() const { return m_Count; }
    void Bind();
    void Unbind();
private:
    int m_Count;
    uint32_t m_Buffer;
};