#pragma once
#include<Eigen/Dense>
#include"Buffer.h"
#include"Camera.h"
/*
* 逐顶点调用
* 逐个图元的处理
* 从模型的顶点给出屏幕的坐标
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
