#pragma once
#include <GL/glew.h>
#include "stb_image.h"
#include <string>


class Texture
{
public:
	Texture(const std::string& imgfilepath);
	~Texture();
	inline const std::string& GetName() const { return m_Name; }
	inline void SetName(const std::string& name) { m_Name = name; }
	void Bind(int texture_unit, GLenum type) const;
	void Unbind(GLenum type) const;
private:
	void PopulateMImage(const std::string& filepath);
	void CreateTexture();
private:
	int m_Channels;
	uint32_t m_Texture;
	unsigned char* m_Image;
	int m_Width;
	int m_Height;
	std::string m_Name;
};

