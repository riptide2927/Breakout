#pragma once
#include <GL/glew.h>
#include <stdint.h>
#include <assert.h>
#include <vector>

struct VertexLayoutElement
{
	uint32_t type;
	uint32_t count;
	uint8_t normalized;

	static unsigned int GetSizeOfType(uint32_t type)
	{
		switch (type)
		{
		case GL_FLOAT:			return 4;
		case GL_UNSIGNED_INT:	return 4;
		case GL_UNSIGNED_BYTE:	return 1;
		}

		assert(false);

		return 0;
	}

};

class VertexBufferLayout
{
public:
	VertexBufferLayout()
		: m_Stride(0) {}

	template<typename T>
	void Push(uint32_t count)
	{
		assert(false);
	}

	template<>
	void Push<float>(uint32_t count)
	{
		m_Element.push_back({ GL_FLOAT, count, GL_FALSE });
		m_Stride += VertexLayoutElement::GetSizeOfType(GL_FLOAT) * count;
	}

	template<>
	void Push<uint32_t>(uint32_t count)
	{
		m_Element.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		m_Stride += VertexLayoutElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
	}

	template<>
	void Push<unsigned char>(uint32_t count)
	{
		m_Element.push_back({ GL_UNSIGNED_BYTE, count, GL_FALSE });
		m_Stride += VertexLayoutElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
	}

	inline const std::vector<VertexLayoutElement>& GetElements() const { return m_Element; }
	inline unsigned int GetStrid() const { return m_Stride; }

private:
	std::vector<VertexLayoutElement> m_Element;
	unsigned int m_Stride;
};