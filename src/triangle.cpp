#include "triangle.h"
#include<math.h>
float crossDot(const Eigen::Vector3d& a, const Eigen::Vector3d& b)
{
	return a.x() * b.y() - a.y() * b.x();
}

Triangle::Triangle(const std::vector<Eigen::Vector3d>& screenCoord, TGAImage& image,ZBuffer& zBuffer, const std::vector<Eigen::Vector3d>& wordCoord)
	:screenCoord(screenCoord), ma(screenCoord[0]), mb(screenCoord[1]), mc(screenCoord[2]), 
	image(image), zBuffer(zBuffer),wordCoord(wordCoord)
{
}

bool Triangle::inside(const Eigen::Vector3d& p)
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
	left = std::max(0.0, std::min(ma.x(), std::min(mb.x(), mc.x())));
	right = std::min(image.get_width() - 1.0, std::max(ma.x(), std::max(mb.x(), mc.x())));
	top= std::min(image.get_height() - 1.0, std::max(ma.y(), std::max(mb.y(), mc.y())));
	bottom= std::max(0.0, std::min(ma.y(), std::min(mb.y(), mc.y())));
	for (int x = left; x <= right; x++)
	{
		for (int y = bottom; y <= top; y++)
		{
			if (inside(Eigen::Vector3d(x, y,0)))
			{
				auto temp = calBarycentricCoord(Eigen::Vector3d(x, y,0));
				auto currZ = temp[0] * wordCoord[0].z() + temp[1] * wordCoord[1].z() + temp[2] * wordCoord[2].z();
				if(zBuffer.Set(x, y, currZ))
					image.set(x, y, color);
			}
		}
	}
}

void Triangle::Draw(const VertexShader& vs, const FragmentShader& fs)
{
	//frag持有tex
	int left, right, top, bottom;
	left = std::max(0.0, std::min(ma.x(), std::min(mb.x(), mc.x())));
	right = std::min(image.get_width() - 1.0, std::max(ma.x(), std::max(mb.x(), mc.x())));
	top = std::min(image.get_height() - 1.0, std::max(ma.y(), std::max(mb.y(), mc.y())));
	bottom = std::max(0.0, std::min(ma.y(), std::min(mb.y(), mc.y())));

	for (int x = left; x <= right; x++)
	{
		for (int y = bottom; y <= top; y++)
		{
			if (inside(Eigen::Vector3d(x, y, 0)))
			{
				auto temp = calBarycentricCoord(Eigen::Vector3d(x, y, 0));
				auto currZ = temp[0] * wordCoord[0].z() + temp[1] * wordCoord[1].z() + temp[2] * wordCoord[2].z();
				if (zBuffer.Set(x, y, currZ))
				{
					int u = image.get_width() * (temp[0] * vs.GetTexCoord()[0].x()+
						temp[1]*vs.GetTexCoord()[1].x()+
						vs.GetTexCoord()[2].x()*temp[2]);
					int v = image.get_height() * (temp[0] * vs.GetTexCoord()[0].y()
						+ temp[1] * vs.GetTexCoord()[1].y() +
						vs.GetTexCoord()[2].y() * temp[2]);
					auto color = fs.CalColor(u, v);
					//auto color = TGAColor(255, 255, 255, 255);
					image.set(x, y, color);
				}
			}
		}
	}
}

void Triangle::DrwaLine(TGAColor color)
{
	line(screenCoord[0].x(), screenCoord[0].y(), screenCoord[1].x(), screenCoord[1].y(), image, color);
	line(screenCoord[1].x(), screenCoord[1].y(), screenCoord[2].x(), screenCoord[2].y(), image, color);
	line(screenCoord[0].x(), screenCoord[0].y(), screenCoord[2].x(), screenCoord[2].y(), image, color);

}



std::vector<double> Triangle::calBarycentricCoord(const Eigen::Vector3d& curr)
{
	auto N = (mb - curr).cross(mc - curr);
	auto areaV = (mb - ma).cross(mc - ma);
	auto area = std::sqrt(areaV.dot(areaV));
	auto areaAV = (mb - curr).cross(mc - curr);
	auto areaA = std::sqrt(areaAV.dot(areaAV));
	auto areaBV = (mc - curr).cross(ma - curr);
	auto areaB = std::sqrt(areaBV.dot(areaBV));
	auto areaCV = (ma - curr).cross(mb - curr);
	auto areaC = std::sqrt(areaCV.dot(areaCV));
	return std::vector<double> {areaA / area, areaB / area, areaC / area };
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