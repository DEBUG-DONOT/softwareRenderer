#pragma once
#include<Eigen/Dense>
#include"Buffer.h"
#include"triangle.h"
#include"Camera.h"
/*
* 逐顶点调用
* 逐个图元的处理
* 从模型的顶点给出屏幕的坐标
*/
class VertexShader
{
public:
	VertexShader(const std::vector<Eigen::Vector3d>& wordCoord, ZBuffer& zbuffer);
	void CalScreenCoord();
	const std::vector<Eigen::Vector3d>& GetScreenCoord();
private:
	ZBuffer& zBuffer;
	const std::vector<Eigen::Vector3d>& wordCoord;
	std::vector<Eigen::Vector3d> screenCoord;
};
