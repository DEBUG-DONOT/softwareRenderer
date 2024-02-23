#include"fragmentShader.h"

TGAColor FragmentShader::CalColor(int x, int y)const
{
	//给出坐标计算值
	return tex.Get(x, y);
}
