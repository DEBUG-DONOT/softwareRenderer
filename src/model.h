#ifndef __MODEL_H__
#define __MODEL_H__

#include <vector>
#include<Eigen/Dense>

class Model {
private:
	std::vector<Eigen::Vector3d> verts_;
	std::vector<Eigen::Vector2d> TexVerts_;//��������
	std::vector<std::vector<int>> faces_;
	std::vector<std::vector<int>> TexIndex_;//����������obj�ļ��ж�Ӧ��index
public:
	Model(const char *filename);
	~Model();
	int nverts();
	int nfaces();
	int nTexVerts_();
	Eigen::Vector3d vert(int i);
	std::vector<int> face(int idx);
	Eigen::Vector2d TexVert(int i);
	std::vector<int> texIndex(int idx);
};

#endif //__MODEL_H__
