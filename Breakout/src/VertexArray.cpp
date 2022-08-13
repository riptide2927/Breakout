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
	glBindVertexArray(m_VertexArray);
}

void VertexArray::Unbind() const
{
}

void VertexArray::AddLayout(const VertexBuffer& buffer, const VertexBufferLayout& layout)
{
	Bind();
	buffer.Bind();
	const auto& elements = layout.GetElements();

	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStrid(), (const void*)(offset += element.count * VertexLayoutElement::GetSizeOfType(element.type)));
	}

}
