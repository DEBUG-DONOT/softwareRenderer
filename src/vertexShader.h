#pragma once
#include<Eigen/Dense>
#include"Buffer.h"
#include"triangle.h"
#include"Camera.h"
/*
* �𶥵����
* ���ͼԪ�Ĵ���
* ��ģ�͵Ķ��������Ļ������
*/
class VertexShader
{
public:
	VertexShader(const std::vector<Eigen::Vector3f>& wordCoord, ZBuffer& zbuffer);
	void CalScreenCoord();
	const std::vector<Eigen::Vector3f>& GetScreenCoord();
private:
	ZBuffer& zBuffer;
	const std::vector<Eigen::Vector3f>& wordCoord;
	std::vector<Eigen::Vector3f> screenCoord;
};