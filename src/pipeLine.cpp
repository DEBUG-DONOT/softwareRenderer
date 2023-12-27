#include"triangle.h"
#include"model.h"
#include<iostream>
#include<memory>
//#include <iostream>
//#include <filesystem>
const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
int main() 
{
    const int height = 1024;
    const int width = 1024;
    TGAImage image(width, height, TGAImage::RGB);
    auto m = new Model("src/OBJ/african_head.obj");
    //Triangle t(Eigen::Vector2f(100, 20), Eigen::Vector2f(680, 680), Eigen::Vector2f(6, 369), image);
    //t.Draw(red);
    bool decide = false;
    for (int i = 0; i < m->nfaces(); i++)
    {
        auto currFace = m->face(i);
        Eigen::Vector2f v1((m->vert(currFace[0]).x()+1)*width/2, (m->vert(currFace[0]).y()+1)*height/2);
        Eigen::Vector2f v2((m->vert(currFace[1]).x()+1)*width/2, (m->vert(currFace[1]).y()+1)*height/2);
        Eigen::Vector2f v3((m->vert(currFace[2]).x()+1)*width/2, (m->vert(currFace[2]).y()+1)*height/2);
        Triangle t(v1, v2, v3, image);
        if (decide) { t.Draw(red); decide = false; }
        else { t.Draw(white); decide = true; }
    }
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    return 0;
}


//bool decide = false;
   //for (int i = 0; i < m->nfaces(); i++)
   //{
   //    auto currFace = m->face(i);
   //    Vec2f v1 (m->vert(currFace[0]).x, m->vert(currFace[0]).y);
   //    Vec2f v2 (m->vert(currFace[1]).x, m->vert(currFace[1]).y);
   //    Vec2f v3 (m->vert(currFace[2]).x, m->vert(currFace[2]).y);
   //    v1.adjust(weigh, height);
   //    v2.adjust(weigh, height);
   //    v3.adjust(weigh, height);
   //    Triangle t(v1, v2, v3, image);
   //    if (decide)
   //    {
   //        t.Draw(red);
   //        decide = false;
   //    }
   //    else
   //    {
   //        t.Draw(white);
   //        decide = true;
   //    }
   //    //std::cout << decide << std::endl;
   //}
   //Triangle t(Vec2f(100, 20), Vec2f(680, 680), Vec2f(580, 666), image);
   //t.Draw(red);
   //Triangle t(image);
/*for (int i = 0; i < m->nfaces(); i++)
   {
       auto face = m->face(i);
       for (int j = 0; j < 3; j++)
       {
           auto v1 = m->vert(face[j]);
           auto v2 = m->vert(face[(j + 1) % 3]);
           int x1 = (v1.x() + 1.0) * width/2;
           int y1 = (v1.y() + 1.0) * height / 2;
           int x2 = (v2.x() + 1.0) * width / 2;
           int y2 = (v2.y() + 1.0) * height / 2;
           t.line(x1, y1, x2, y2, image, white);

       }
   }*/