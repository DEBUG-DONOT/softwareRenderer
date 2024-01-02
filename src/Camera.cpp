#include"Camera.h"

void Light::operator=(const Light& l)
{
	this->fromPoint = l.fromPoint;
	this->toPoint = l.toPoint;
	this->Dir = l.Dir;
}
