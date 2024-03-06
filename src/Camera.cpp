#include"Camera.h"

void Light::operator=(const Light& l)
{
	this->fromPoint = l.fromPoint;
	this->toPoint = l.toPoint;
	this->Dir = l.Dir;
}

void Camera::ViewMatrix()
{
	//º∆À„viewæÿ’Û
	Eigen::Matrix4d t, r;
	t << 1, 0, 0, -pos.x(), 0, 1, 0, -pos.y(), 0, 0, 1, -pos.z(), 0, 0, 0, 1;
	Eigen::Vector3d gt = lookAt.cross(up);
	r << gt.x(),gt.y(),gt.z(), 0, up.x(),up.y(),up.z(), 0, -lookAt.x(),lookAt.y(),lookAt.z(), 0, 0, 0, 0, 1;
	//ViewM = r * t;
	ViewM = t * r;
}

void SceneSetting::CalProjectionMatrix()
{
	Eigen::Matrix4d MO, MPtoO;
	MO << 2 / (right - left), 0, 0, -(right + left) / (right - left),
		0, 2 / (top - bottom), 0, -(top + bottom) / (top - bottom),
		0, 0, 2 / (near - far), -(near + far) / (near - far),
		0, 0, 0, 1;
	MPtoO << near, 0, 0, 0,
		0, near, 0, 0,
		0, 0, near + far, -near * far,
		0, 0, 1, 0;
	projectionMatrix = MO * MPtoO;
}
