#include"vertexShader.h"

VertexShader::VertexShader(const std::vector<Eigen::Vector3d>& wordCoord, ZBuffer& zbuffer, const std::vector<Eigen::Vector2d>& TexCoord)
	:wordCoord(wordCoord),zBuffer(zbuffer),TexCoord(TexCoord)
{
	screenCoord = std::vector<Eigen::Vector3d>(3);
}

const std::vector<Eigen::Vector3d>& VertexShader::GetScreenCoord()
{
	return screenCoord;
}

const std::vector<Eigen::Vector2d>& VertexShader::GetTexCoord()const
{
	return this->TexCoord;
}



void VertexShader::CalScreenCoord()
{
	auto width = zBuffer.GetWidth();
	auto height = zBuffer.GetHeight();
	for (int i = 0; i < 3; i++)
	{
		screenCoord[i] = Eigen::Vector3d((wordCoord[i].x() + 1) * width / 2.0, (wordCoord[i].y() + 1) * height / 2.0,wordCoord[i].z());
	}
}
