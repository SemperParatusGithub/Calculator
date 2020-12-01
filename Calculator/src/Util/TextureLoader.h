#pragma once
#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>

namespace Util
{
	static unsigned int LoadTexture(const std::string &filepath)
	{
		stbi_set_flip_vertically_on_load(1);
		unsigned int textureID;
		int width, height, channels;
		unsigned char *buffer = stbi_load(filepath.c_str(), &width, &height, &channels, 4);


		GLenum internalFormat = 0, dataFormat = 0;
		if (channels == 4)
		{
			internalFormat = GL_RGBA8;
			dataFormat = GL_RGBA;
		}
		else if (channels == 3)
		{
			internalFormat = GL_RGB8;
			dataFormat = GL_RGB;
		}

		glCreateTextures(GL_TEXTURE_2D, 1, &textureID);
		glTextureStorage2D(textureID, 1, internalFormat, width, height);

		glTextureParameteri(textureID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(textureID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureParameteri(textureID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(textureID, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTextureSubImage2D(textureID, 0, 0, 0, width, height, dataFormat, GL_UNSIGNED_BYTE, buffer);

		if (buffer)
			stbi_image_free(buffer);
		else
			std::cout << "Failed to load Texture: " << filepath << std::endl;

		return textureID;
	}
}
