#include"triangle.h"
#include"model.h"
#include"Camera.h"
#include"Buffer.h"
const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
int main() 
{
    const int height = 1024;
    const int width = 1024;
    TGAImage image(width, height, TGAImage::RGB);
    ZBuffer zBuffer(width, height);
    auto m = new Model("src/OBJ/african_head.obj");
    Light mLight(Eigen::Vector3f(0, 0, 0), Eigen::Vector3f(0, 0, -1));
    std::vector<Eigen::Vector3f> wordCoord(3);
    std::vector<Eigen::Vector2f> screenCoord(3);
    for (int i = 0; i < m->nfaces(); i++)
    {
        auto currFace = m->face(i);
        for (int j = 0; j < 3; j++)
        {
            wordCoord[j] = m->vert(currFace[j]);
            screenCoord[j] = Eigen::Vector2f((m->vert(currFace[j]).x() + 1) * width / 2,
                (m->vert(currFace[j]).y() + 1) * height / 2);
        }
        auto n = (wordCoord[2] - wordCoord[0]).cross((wordCoord[1] - wordCoord[0])).normalized();
        auto intensity = n.dot(mLight.GetDir());
        Triangle t(screenCoord[0], screenCoord[1], screenCoord[2], image,zBuffer);
        if (intensity > 0)t.Draw(TGAColor(255 * intensity, 255 * intensity, 255 * intensity, 255));
        //if (intensity > 0) t.Draw(red);
    }
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    return 0;
}


