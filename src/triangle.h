#pragma once
#include"tgaimage.h"
#include"Buffer.h"
#include<Eigen/Dense>
/*
* 实际上我们的操作应该是以三角形为一个基本单位的，所以这里的line函数应该最后作为一个private的函数放在triangle类中
*/
class Triangle
{
public:	
	Triangle(const std::vector<Eigen::Vector3f>& screenCoord,TGAImage& image,ZBuffer& zbuffer, const std::vector<Eigen::Vector3f>& wordCoord);
	void Draw(const TGAColor& color);
private:
	bool inside(const Eigen::Vector3f& p);
	//void line(int x1, int y1, int x2, int y2, TGAImage& image, TGAColor color);
	std::vector<float> calBarycentricCoord(const Eigen::Vector3f& curr);
	TGAImage& image;
	ZBuffer& zBuffer;
	const Eigen::Vector3f& ma;
	const Eigen::Vector3f& mb;
	const Eigen::Vector3f& mc;
	const std::vector<Eigen::Vector3f>& screenCoord;
	const std::vector<Eigen::Vector3f>& wordCoord;
};						 


