#pragma once
#include"tgaimage.h"
#include"Buffer.h"
class FragmentShader
{
public:
	FragmentShader(TGAImage& image,Texture& t):image(image),tex(t) {};
	TGAColor CalColor(int x, int y) const ;



private:
	TGAImage& image;
	Texture& tex;
};


