#pragma once
#include<Eigen/Dense>
#include"Buffer.h"
#include"Camera.h"
/*
* 逐顶点调用
* 逐个图元的处理
* 从模型的顶点给出屏幕的坐标
* 坐标变换
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
	inline const std::vector<Eigen::Vector3d>& GetNewWordCoord() 
	{ 
		if (sceneSetting)
			return NewWordCoord;
		else
			return wordCoord;
	}
private:
	ZBuffer& zBuffer;
	SceneSetting* sceneSetting=nullptr;
	const std::vector<Eigen::Vector3d>& wordCoord;
	std::vector<Eigen::Vector3d> NewWordCoord;
	std::vector<Eigen::Vector3d> screenCoord;
	const std::vector<Eigen::Vector2d>& TexCoord;
};
