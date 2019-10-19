#include "pch.h"
#include "Texture.h"
#include <GL/glew.h>
#include <stb_image.h>

namespace Demo
{
	Texture::Texture(const std::string& filepath, bool flippedVertically)
		: id(0), target(GL_TEXTURE_2D)
	{
		const Image& image = Load(filepath, flippedVertically);
		Init(image);
		Free(image);
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &id);
	}

	void Texture::Bind(unsigned int textureUnit) const
	{
		glActiveTexture(GL_TEXTURE0 + textureUnit);
		glBindTexture(target, id);
	}

	void Texture::Unbind() const
	{
		glBindTexture(target, 0);
	}

	Image Texture::Load(const std::string& filepath, bool flippedVertically)
	{
		stbi_set_flip_vertically_on_load(flippedVertically ? 1 : 0);
		int width = 0;
		int height = 0;
		int channels = 0;
		unsigned char* pixels = stbi_load(filepath.c_str(), &width, &height, &channels, STBI_rgb);
		return { pixels, width, height, channels };
	}

	void Texture::Init(const Image& image)
	{
		glGenTextures(1, &id);
		glBindTexture(target, id);
		glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(
			target,
			LEVEL_OF_DETAIL,
			GL_RGB,
			image.Width,
			image.Height,
			BORDER,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			image.Pixels
		);
	}

	void Texture::Free(const Image& image)
	{
		if (image.Pixels)
		{
			stbi_image_free(image.Pixels);
		}
	}
}