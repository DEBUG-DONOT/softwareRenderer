#include"Buffer.h"
#include <string.h>
#include <limits>
#include<math.h>
#include <algorithm>
#include<iostream>
ZBuffer::ZBuffer(int w, int h)
	:data(nullptr),width(w),height(h)
{
	unsigned long nBytes = w * h;
	data = new double[nBytes];
	if (!data) std::cerr << "ZBuffer:malloc data failed" << std::endl;
	memset(data, -std::numeric_limits<double>::max(), nBytes);
}

ZBuffer::~ZBuffer()
{
	if (data) delete[] data;
}

double ZBuffer::Get(int x, int y) const
{
	if (!data || x < 0 || y < 0 || x >= width || y >= height)
	{
		std::cerr << "Zbuffer:Get Error" <<"x "<<x<<" y "<<y << std::endl;
		return -std::numeric_limits<double>::max();
	}
	return data[x + width * y];
}

bool ZBuffer::Set(int x, int y, double z)
{
	auto curr = this->Get(x, y);
	if (z > curr)
	{//左下角为原点
		data[x+width*y] = z;
		return true;
	}
	return false;
}

Texture::Texture(const char* filename)
	:tex()
{
	//可以做一个mipmap
	if (!tex.read_tga_file(filename))
	{
		std::cerr << "texture::read_tga_file failed" << std::endl;
	}
	tex.flip_vertically();
}

TGAColor Texture::Get(int x, int y) 
{
	return this->tex.get(x,y);
}
