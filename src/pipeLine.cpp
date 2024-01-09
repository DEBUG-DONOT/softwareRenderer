#include"triangle.h"
#include"model.h"
#include"vertexShader.h"
const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
int main() 
{
    const int height = 1024;
    const int width = 1024;
    TGAImage image(width, height, TGAImage::RGB);
    ZBuffer zBuffer(width, height);
    auto m = new Model("src/OBJ/african_head.obj");
    auto texture = new Texture("src/OBJ/african_head_diffuse.tga");
    Light mLight(Eigen::Vector3d(0, 0, 0), Eigen::Vector3d(0, 0, -1));
    std::vector<Eigen::Vector3d> wordCoord(3);
    for (int i = 0; i < m->nfaces(); i++)
    {
        auto currFace = m->face(i);
        for (int j = 0; j < 3; j++)
        {
            wordCoord[j] = m->vert(currFace[j]);
        }
        VertexShader v(wordCoord, zBuffer);
        v.CalScreenCoord();

        //////////////这一部分要放到fragmentshader或者vertexshader中，取决于shader的种类
        auto n = (wordCoord[2] - wordCoord[0]).cross((wordCoord[1] - wordCoord[0])).normalized();
        auto intensity = n.dot(mLight.GetDir());
        /////////////////

        Triangle t(v.GetScreenCoord(), image, zBuffer,wordCoord);
        if (intensity > 0)t.Draw(TGAColor(255 * intensity, 255 * intensity, 255 * intensity, 255));
    }
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    return 0;
}


