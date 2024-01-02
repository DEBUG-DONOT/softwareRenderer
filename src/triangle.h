#pragma once
#include"tgaimage.h"
#include"Buffer.h"
#include<Eigen/Dense>
/*
* ʵ�������ǵĲ���Ӧ������������Ϊһ��������λ�ģ����������line����Ӧ�������Ϊһ��private�ĺ�������triangle����
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


