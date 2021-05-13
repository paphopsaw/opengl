#ifndef TEXTURE_H
#define TEXTURE_H
#include <iostream>
#include <glad/glad.h>
#include "stb_image.h"


class Texture2D {
	private:
		unsigned int ID;
		unsigned char* data;
		int width;
		int height;
		int nrChannels;
		unsigned int wrap_s;
		unsigned int wrap_t;
		unsigned int min_filter;
		unsigned int max_filter;

	public:
		Texture2D(const char* filePath, unsigned int format);
		~Texture2D();
		void bind(unsigned int slot);
		void unbind();
};


#endif

