#include"vertexShader.h"

VertexShader::VertexShader(const std::vector<Eigen::Vector3d>& wordCoord, ZBuffer& zbuffer, const std::vector<Eigen::Vector2d>& TexCoord)
	:wordCoord(wordCoord),zBuffer(zbuffer),TexCoord(TexCoord)
{
	screenCoord = std::vector<Eigen::Vector3d>(3);
	NewWordCoord = std::vector<Eigen::Vector3d>(3);
}

const std::vector<Eigen::Vector3d>& VertexShader::GetScreenCoord()
{
	return screenCoord;
}

const std::vector<Eigen::Vector2d>& VertexShader::GetTexCoord()const
{
	return this->TexCoord;
}

const std::vector<Eigen::Vector2d> VertexShader::MVP(const SceneSetting& st)
{
	//����camera�������ӽǵı任
	return std::vector<Eigen::Vector2d>();
}

void VertexShader::SetSceneSetting(SceneSetting& sceneS)
{
	sceneSetting = &sceneS;
}



void VertexShader::CalScreenCoord()
{
	//MVP
	if (this->sceneSetting != nullptr)//�������
	{
		//std::vector<Eigen::Vector3d> tempWord(3);
		auto mvp = sceneSetting->GetMVP();
		for (int i = 0; i < wordCoord.size(); i++)
		{
			Eigen::Vector4d temp(wordCoord[i].x(),wordCoord[i].y(), wordCoord[i].z(), 1.0);
			temp = mvp * temp;
			NewWordCoord[i] = Eigen::Vector3d(temp.x() / temp.w(), temp.y() / temp.w(), temp.z() / temp.w());
		}
		auto width = zBuffer.GetWidth();
		auto height = zBuffer.GetHeight();
		for (int i = 0; i < 3; i++)
		{
			screenCoord[i] = Eigen::Vector3d((NewWordCoord[i].x() + 1) * width / 2.0,
				(NewWordCoord[i].y() + 1) * height / 2.0, NewWordCoord[i].z());
		}
	}
	else
	{
		auto width = zBuffer.GetWidth();
		auto height = zBuffer.GetHeight();
		for (int i = 0; i < 3; i++)
		{
			screenCoord[i] = Eigen::Vector3d((wordCoord[i].x() + 1) * width / 2.0, (wordCoord[i].y() + 1) * height / 2.0, wordCoord[i].z());
		}
	}
	
}
