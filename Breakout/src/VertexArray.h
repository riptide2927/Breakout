#pragma once
#include <GL/glew.h>
#include <stdint.h>
#include "VertexBufferLayout.h"
#include "VertexBuffer.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();
	void Bind() const;
	void Unbind() const;
	void AddLayout(const VertexBuffer& buffer, const VertexBufferLayout& layout);
private:
	uint32_t m_VertexArray;
};