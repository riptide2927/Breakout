#include "VertexArray.h"
#include <iostream>

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
		if (elements.size() > 1)
		{
			glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStrid(), 0);
		}
		else
		{
			offset += element.count * VertexLayoutElement::GetSizeOfType(element.type);
			glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStrid(), (const void*)offset);
		}
	}

}
