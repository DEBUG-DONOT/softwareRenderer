#pragma once
#include"tgaimage.h"
class FragmentShader
{
public:
	FragmentShader(TGAImage& image):image(image) {};
	void CalColor(int x, int y);

private:
	TGAImage& image;
};


