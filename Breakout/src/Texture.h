#pragma once
#include <GL/glew.h>
#include <SOIL2/SOIL2.h>
#include <string>


class Texture
{
public:
	Texture(const std::string& imgfilepath);
	~Texture();
	inline const std::string& GetName() const { return m_Name; }
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

