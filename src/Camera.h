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
	void operator =(const Light& l);

private:
	Eigen::Vector3f& fromPoint;
	Eigen::Vector3f& toPoint;
	Eigen::Vector3f Dir;
};


class Camera
{

};

class SceneSeeting
{
	//ligth camera
public:
	SceneSeeting(Light l,Camera c):light(l),camera(c) {};
	void SetLight(Light l) { light = l; }

private:
	Light& light;
	Camera& camera;
};
