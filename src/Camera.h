#pragma once
#include<Eigen/Dense>

class Light
{
public:
	Light(Eigen::Vector3f origin, Eigen::Vector3f destination)
		:fromPoint(origin),toPoint(destination)
	{
		Dir = toPoint - fromPoint;
	}
	inline Eigen::Vector3f GetDir()const { return Dir; };

private:
	Eigen::Vector3f& fromPoint;
	Eigen::Vector3f& toPoint;
	Eigen::Vector3f Dir;
};


class Camera
{

};

