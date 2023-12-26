#include "triangle.h"

//Triangle::Triangle(Eigen::Vector2f a, Eigen::Vector2f b, Eigen::Vector2f c, TGAImage& image)
//	:ma(a),mb(b),mc(c),image(image)
//{
//}

void Triangle::line(int x1, int y1, int x2, int y2, TGAImage& image, TGAColor color)
{
	//����Bresenham�㷨
	//���и����Ĳ���������Ļ�ռ����ֵ
	bool steep = false;
	if (std::abs(x1 - x2) < std::abs(y1 - y2))//��֤б����[0,1]֮��
	{
		std::swap(x1, y1);
		std::swap(x2, y2);
		steep = true;
	}
	if (x1 > x2)
	{
		//��֤������
		std::swap(x1, x2);
		std::swap(y1, y2);
	}
	auto y = y1;
	int dx = x2 - x1;
	int dy = y2 - y1;
	double error = 0.0;//����
	double derror = std::abs((double)dy / (double)dx);//б�ʵľ���ֵ
	for (int x = x1; x <= x2; x++)
	{
		if (steep)
		{
			image.set(y, x, color);
		}
		else
		{
			image.set(x, y, color);
		}
		error += derror;
		if (error > 0.5)
		{
			y += y2 > y1 ? 1 : -1;
			error--;
		}
	}
}

//bool Triangle::inside(const Eigen::Vector2f& p)
//{
//	
//}

//void Triangle::Draw(const TGAColor& color)
//{
//	//flat shading,����������ʹ��һ����ɫ
//	//�ҳ���Χ��Ȼ���ڰ�Χ����һ��һ���ж�
//	
//}
//	
