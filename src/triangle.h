#pragma once
#include"tgaimage.h"
#include"Buffer.h"
#include"fragmentShader.h"
#include<Eigen/Dense>
/*
* 实际上我们的操作应该是以三角形为一个基本单位的，所以这里的line函数应该最后作为一个private的函数放在triangle类中
*/
class Triangle
{
public:	
	Triangle(const std::vector<Eigen::Vector3d>& screenCoord,TGAImage& image,ZBuffer& zbuffer, const std::vector<Eigen::Vector3d>& wordCoord);
	void Draw(const TGAColor& color);
	void Draw(const FragmentShader& fs);
private:
	bool inside(const Eigen::Vector3d& p);
	//void line(int x1, int y1, int x2, int y2, TGAImage& image, TGAColor color);
	std::vector<double> calBarycentricCoord(const Eigen::Vector3d& curr);
	TGAImage& image;
	ZBuffer& zBuffer;
	const Eigen::Vector3d& ma;
	const Eigen::Vector3d& mb;
	const Eigen::Vector3d& mc;
	const std::vector<Eigen::Vector3d>& screenCoord;
	const std::vector<Eigen::Vector3d>& wordCoord;
};						 


