#include "Texture.h"



Texture::Texture(const char * a_path, const bool a_alpha) : Width(0), Height(0), Image_Format(GL_RGB), Internal_Format(GL_RGB), Wrap_S(GL_CLAMP_TO_BORDER), Wrap_T(GL_CLAMP_TO_BORDER), Filter_Min(GL_LINEAR), Filter_Max(GL_LINEAR)
{
	//flag to load in alpha component
	if (a_alpha)
	{
		Internal_Format = GL_RGBA;
		Image_Format = GL_RGBA;
	}

	//Create texture And bind it as the current 2D texture
	glGenTextures(1, &this->ID);
	glBindTexture(GL_TEXTURE_2D, this->ID);

	// set texture wrapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Wrap_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Wrap_T);

	//set testure filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Filter_Min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, Filter_Max);

	//Load image into byte array using SOIL
	unsigned char* image = SOIL_load_image(a_path, &this->Width, &this->Height, 0, Image_Format == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
	if (image == nullptr)
		std::cout << "SOIL error loading image: " << SOIL_last_result() << std::endl;

	//Load image data From SOIL into opengl and generate mipmaps
	glTexImage2D(GL_TEXTURE_2D, 0, Internal_Format, Width, Height, 0, Image_Format, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	//unload image data from SOIL and unbind texture2D target
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}


void Texture::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, this->ID);
}