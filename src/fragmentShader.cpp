#include"fragmentShader.h"

TGAColor FragmentShader::CalColor(int x, int y)const
{
	//�����������ֵ
	return tex.Get(x, y);
}
