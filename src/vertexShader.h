#pragma once
#include<Eigen/Dense>
#include"Buffer.h"
#include"Camera.h"
/*
* �𶥵����
* ���ͼԪ�Ĵ���
* ��ģ�͵Ķ��������Ļ������
* ����任
*/
class VertexShader
{
public:
	VertexShader(const std::vector<Eigen::Vector3d>& wordCoord, ZBuffer& zbuffer,
		const std::vector<Eigen::Vector2d>& TexCoord);
	void CalScreenCoord();
	const std::vector<Eigen::Vector3d>& GetScreenCoord();
	const std::vector<Eigen::Vector2d>& GetTexCoord() const;
	const std::vector<Eigen::Vector2d> MVP(const SceneSetting& st);
	void SetSceneSetting(SceneSetting& sceneS);
	inline const std::vector<Eigen::Vector3d>& GetNewWordCoord() { return NewWordCoord; }
private:
	ZBuffer& zBuffer;
	SceneSetting* sceneSetting=nullptr;
	const std::vector<Eigen::Vector3d>& wordCoord;
	std::vector<Eigen::Vector3d> NewWordCoord;
	std::vector<Eigen::Vector3d> screenCoord;
	const std::vector<Eigen::Vector2d>& TexCoord;
};
