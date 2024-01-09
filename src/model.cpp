#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "model.h"

Model::Model(const char *filename) : verts_(), faces_(),TexVerts_(),TexIndex_() {
    std::ifstream in;
    in.open (filename, std::ifstream::in);
    if (in.fail()) return;
    std::string line;
    while (!in.eof()) 
    {
        std::getline(in, line);
        std::istringstream iss(line.c_str());
        char trash;
        if (!line.compare(0, 2, "v ")) //vertex
        {
            iss >> trash;
            Eigen::Vector3d v;
            for (int i=0;i<3;i++) iss >> v[i];
            verts_.push_back(v);
        } 
        else if (!line.compare(0, 2, "f ")) 
        {
            std::vector<int> f;
            std::vector<int> t;
            int itrash, idx,iTex;
            iss >> trash;
            while (iss >> idx >> trash >> iTex >> trash >> itrash) 
            {
                idx--; // in wavefront obj all indices start at 1, not zero
                iTex--;
                f.push_back(idx);
                t.push_back(iTex);
            }
            faces_.push_back(f);
            TexIndex_.push_back(t);
        }
        else if (!line.compare(0, 3, "vt "))
        {
            double dTrash, u, v;
            iss >> trash >> trash;
            iss >> u >> v;
            Eigen::Vector2d temp(u, v);
            TexVerts_.push_back(temp);
        }
    }
    std::cerr << "# v# " << verts_.size() << " f# "  << faces_.size() <<"# vt#"<<TexVerts_.size() <<"# TexIndex#"<<TexIndex_.size() << std::endl;
}

Model::~Model() {
}

int Model::nverts() {
    return (int)verts_.size();
}

int Model::nfaces() {
    return (int)faces_.size();
}

int Model::nTexVerts_()
{
    return (int)TexVerts_.size();
}

std::vector<int> Model::face(int idx) {
    return faces_[idx];
}

Eigen::Vector2d Model::TexVert(int i)
{
    return TexVerts_[i];
}

Eigen::Vector3d Model::vert(int i) {
    return verts_[i];
}


