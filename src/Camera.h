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


//决定相机的位置
//需要的值：
//view:pos,look-at,up
//projection: r,l,t,b,n,f

class Camera
{
public:
	Camera(Eigen::Vector3d pos_, Eigen::Vector3d lookAt_, Eigen::Vector3d up_)
		:pos(pos_),lookAt(lookAt_),up(up_)
	{
		ViewMatrix();
	}
	inline const Eigen::Matrix4d GetViewMatrix() const { return ViewM; }
	inline void setPos(Eigen::Vector3d newPos) { pos = newPos; ViewMatrix(); }
	inline void setLookAt(Eigen::Vector3d newlookAt) { lookAt = newlookAt; ViewMatrix();
	}
	inline void setUp(Eigen::Vector3d newUp) { up = newUp; ViewMatrix();
	}
private:
	void ViewMatrix();
	Eigen::Matrix4d ViewM;
	Eigen::Vector3d pos;
	Eigen::Vector3d lookAt;
	Eigen::Vector3d up;
};

class SceneSetting
{
	//ligth camera
public:
	SceneSetting(Camera c, double left, double right, double top, double  bottom) :camera(c),
		left(left), right(right), top(top), bottom(bottom)
	{
		CalProjectionMatrix();
	};
	inline const Eigen::Matrix4d GetProjectionMatrix() const { return projectionMatrix; }
	inline const Eigen::Matrix4d GetMVP()const { return GetProjectionMatrix() * camera.GetViewMatrix(); }
	//set
private:
	void CalProjectionMatrix();
	Camera& camera;
	Eigen::Matrix4d projectionMatrix;
	double near=-1, far=-100;
	double left, right, top, bottom;
};
