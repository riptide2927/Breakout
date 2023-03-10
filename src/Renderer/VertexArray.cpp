#include "VertexArray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_VertexArray);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_VertexArray);
}

void VertexArray::Bind() const
{
    glBindVertexArray(m_VertexArray);
}

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
    Bind();
    vb.Bind();
    const auto elements = layout.GetElements();
    uint32_t offset = 0;
    for(unsigned int i = 0; i < elements.size(); i++)
    {
        const auto element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset);
        offset += element.count * LayoutElement::GetSizeofType(element.type);
    }
    Unbind();
    vb.Unbind();
}
