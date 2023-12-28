#pragma once

class ZBuffer
{
public:

	ZBuffer(int w, int h);
	~ZBuffer();
	float Get(int x, int y)const;
	bool Set(int x, int y, float z);


private:
	int width=0, height=0;
	float* data=nullptr;
};
