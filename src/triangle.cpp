#include "triangle.h"

float crossDot(const Eigen::Vector2f& a, const Eigen::Vector2f& b)
{
	return a.x() * b.y() - a.y() * b.x();
}

Triangle::Triangle(Eigen::Vector2f a, Eigen::Vector2f b, Eigen::Vector2f c, TGAImage& image,ZBuffer& zBuffer)
	:ma(a),mb(b),mc(c),image(image),zBuffer(zBuffer)
{
}



bool Triangle::inside(const Eigen::Vector2f& p)
{
	auto r1 = crossDot(p - ma, mb - ma);
	auto r2 = crossDot(p - mb, mc - mb);
	auto r3 = crossDot(p - mc, ma - mc);
	if (r1 >= 0 && r2 >= 0 && r3 >= 0 || r1 <= 0 && r2 <= 0 && r3 <= 0)return true;
	return false;
}



void Triangle::Draw(const TGAColor& color)
{
	//flat shading,整个三角形使用一个颜色
	//找出包围盒然后在包围盒内一个一个判断
	int left, right, top, bottom;
	left = std::max(0.0f, std::min(ma.x(), std::min(mb.x(), mc.x())));
	right = std::min(image.get_width() - 1.0f, std::max(ma.x(), std::max(mb.x(), mc.x())));
	top= std::min(image.get_height() - 1.0f, std::max(ma.y(), std::max(mb.y(), mc.y())));
	bottom= std::max(0.0f, std::min(ma.y(), std::min(mb.y(), mc.y())));
	for (int x = left; x <= right; x++)
	{
		for (int y = bottom; y <= top; y++)
		{
			if (inside(Eigen::Vector2f(x, y)))
			{
				image.set(x, y, color);
			}
		}
	}
}
	
void Triangle::line(int x1, int y1, int x2, int y2, TGAImage& image, TGAColor color)
{
	//采用Bresenham算法
	//其中给出的参数都是屏幕空间的数值
	bool steep = false;
	if (std::abs(x1 - x2) < std::abs(y1 - y2))//保证斜率在[0,1]之间
	{
		std::swap(x1, y1);
		std::swap(x2, y2);
		steep = true;
	}
	if (x1 > x2)
	{
		//保证从左到右
		std::swap(x1, x2);
		std::swap(y1, y2);
	}
	auto y = y1;
	int dx = x2 - x1;
	int dy = y2 - y1;
	double error = 0.0;//计数
	double derror = std::abs((double)dy / (double)dx);//斜率的绝对值
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