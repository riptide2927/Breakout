#include "Texture.h"
#include <assert.h>

Texture::Texture(const std::string& imgfilepath)
	: m_Texture(0), m_Image(nullptr), m_Width(0), m_Height(0)
{
	PopulateMImage(imgfilepath);
	CreateTexture();
}

Texture::~Texture()
{

}


void Texture::PopulateMImage(const std::string& filepath)
{
	m_Image = SOIL_load_image(filepath.c_str(), &m_Width, &m_Height, &m_Channels, 0);
}

void Texture::CreateTexture()
{
	assert(m_Image != nullptr);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glGenTextures(1, &m_Texture);

	glBindTexture(GL_TEXTURE_2D, m_Texture);
	glTexImage2D(m_Texture, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_Image);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	SOIL_free_image_data(m_Image);

}

void Texture::Bind(int texture_unit, GLenum type) const
{
	glActiveTexture(GL_TEXTURE0 + texture_unit);
	glBindTexture(type, m_Texture);
}

void Texture::Unbind(GLenum type) const
{
	glActiveTexture(0);
	glBindTexture(type, 0);
}