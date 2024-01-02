#include"vertexShader.h"

VertexShader::VertexShader(const std::vector<Eigen::Vector3f>& wordCoord, ZBuffer& zbuffer)
	:wordCoord(wordCoord),zBuffer(zbuffer)
{
	screenCoord = std::vector<Eigen::Vector3f>(3);
}

const std::vector<Eigen::Vector3f>& VertexShader::GetScreenCoord()
{
	return screenCoord;
}

void VertexShader::CalScreenCoord()
{
	auto width = zBuffer.GetWidth();
	auto height = zBuffer.GetHeight();
	for (int i = 0; i < 3; i++)
	{
		screenCoord[i] = Eigen::Vector3f((wordCoord[i].x() + 1) * width / 2.0, (wordCoord[i].y() + 1) * height / 2.0,wordCoord[i].z());
	}
}
