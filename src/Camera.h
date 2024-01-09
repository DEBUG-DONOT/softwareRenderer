#pragma once
#include<Eigen/Dense>

class Light
{
public:
	Light(Eigen::Vector3d origin, Eigen::Vector3d destination)
		:fromPoint(origin),toPoint(destination)
	{
		Dir = toPoint - fromPoint;
	}
	inline Eigen::Vector3d GetDir()const { return Dir; };
	void operator =(const Light& l);

private:
	Eigen::Vector3d& fromPoint;
	Eigen::Vector3d& toPoint;
	Eigen::Vector3d Dir;
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
