#pragma once
#include"tgaimage.h"
#include<Eigen/Dense>
/*
* ʵ�������ǵĲ���Ӧ������������Ϊһ��������λ�ģ����������line����Ӧ�������Ϊһ��private�ĺ�������triangle����
*/
class Triangle
{
public:
	Triangle(TGAImage& t) :image(t) {}
	/*@parm a,b,c ������Ļ�ռ�����꣬��Ϊ��ģ�͵���Ļ�ռ���һ��Ӧ�ý�����ĺ���������
	* �������������ֻ��ִ�д���Ļ�ռ�������λ�����������һ��
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


