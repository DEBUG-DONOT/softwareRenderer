#pragma once
#include"tgaimage.h"
#include"Buffer.h"
class FragmentShader
{
public:
	FragmentShader(TGAImage& image,Texture& t):image(image),tex(t) {};
	void CalColor(int x, int y);



private:
	TGAImage& image;
	Texture& tex;
};


