#pragma once
#include"tgaimage.h"
#include<Eigen/Dense>
/*
* 实际上我们的操作应该是以三角形为一个基本单位的，所以这里的line函数应该最后作为一个private的函数放在triangle类中
*/
class Triangle
{
public:
	Triangle(TGAImage& t) :image(t) {}
	/*@parm a,b,c 三个屏幕空间的坐标，因为从模型到屏幕空间这一块应该交给别的函数来处理
	* 这个函数单纯的只是执行从屏幕空间的三角形画出三角形这一步
	*/
	//Triangle(Eigen::Vector2f a, Eigen::Vector2f b, Eigen::Vector2f c,TGAImage& image);
	//void Draw(const TGAColor& color);
	void line(int x1, int y1, int x2, int y2, TGAImage& image, TGAColor color);
private:
	//bool inside(const Eigen::Vector2f& p);

	TGAImage& image;
	//const Eigen::Vector2f& ma;
	//const Eigen::Vector2f& mb;
	//const Eigen::Vector2f& mc;
};


