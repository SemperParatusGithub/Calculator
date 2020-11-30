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
		int width, height, bpp;
		unsigned char *buffer = stbi_load(filepath.c_str(), &width, &height, &bpp, 4);

		glCreateTextures(GL_TEXTURE_2D, 1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
		glBindTexture(GL_TEXTURE_2D, 0);

		if (buffer)
			stbi_image_free(buffer);
		else
			std::cout << "Failed to load Texture: " << filepath << std::endl;

		return textureID;
	}
}
