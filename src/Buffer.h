#pragma once
#include"tgaimage.h"
class ZBuffer
{
public:

	ZBuffer(int w, int h);
	~ZBuffer();
	double Get(int x, int y)const;
	bool Set(int x, int y, double z);
	inline int GetWidth()const { return width; };
	inline int GetHeight()const { return height; };
private:
	int width=0, height=0;
	double* data=nullptr;
};

class Texture
{
public:
	Texture(const char* filename);
	TGAColor Get(int x, int y);
private:
	TGAImage tex;
};