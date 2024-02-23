#pragma once
#include<Eigen/Dense>
#include"Buffer.h"
#include"Camera.h"
/*
* �𶥵����
* ���ͼԪ�Ĵ���
* ��ģ�͵Ķ��������Ļ������
*/
class VertexShader
{
public:
	VertexShader(const std::vector<Eigen::Vector3d>& wordCoord, ZBuffer& zbuffer,const std::vector<Eigen::Vector2d>& TexCoord);
	void CalScreenCoord();
	const std::vector<Eigen::Vector3d>& GetScreenCoord();
	const std::vector<Eigen::Vector2d>& GetTexCoord() const;
private:
	ZBuffer& zBuffer;
	const std::vector<Eigen::Vector3d>& wordCoord;
	std::vector<Eigen::Vector3d> screenCoord;
	const std::vector<Eigen::Vector2d>& TexCoord;
};
