#include"triangle.h"
#include"model.h"
#include"vertexShader.h"
#include"fragmentShader.h"
#include<Eigen/Dense>
#define WriteToFile image.flip_vertically();image.write_tga_file("output.tga");
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
    std::vector<Eigen::Vector2d> mtexCoord(3);
    FragmentShader fs(image, *texture);

    Eigen::Vector3d pos, lookAt, up;
    pos = Eigen::Vector3d(0, 0, 1);
    lookAt = Eigen::Vector3d(0, 0, -1);
    up = Eigen::Vector3d(0, -1, 0);
    double left=-2, right=2, top=2, bottom=-2;
    Camera camera(pos, lookAt, up);
    SceneSetting scS(camera, left, right, top, bottom);
    for (int i = 0; i < m->nfaces(); i++)
    {
        auto currFace = m->face(i);
        auto currTex = m->texIndex(i);
        for (int j = 0; j < 3; j++)
        {
            wordCoord[j] = m->vert(currFace[j]);//在0-1之间
            mtexCoord[j] = m->TexVert(currTex[j]);
        }
        //下面就是vertexshader做的，处理单个的点
        VertexShader v(wordCoord, zBuffer,mtexCoord);
        v.SetSceneSetting(scS);
        v.CalScreenCoord();
        //////////////这一部分要放到fragmentshader或者vertexshader中，取决于shader的种类
        //auto n = (wordCoord[2] - wordCoord[0]).cross((wordCoord[1] - wordCoord[0])).normalized();
        //auto intensity = n.dot(mLight.GetDir());
        /////////////////
        Triangle t(v.GetScreenCoord(), image, zBuffer,v.GetNewWordCoord());
        //t.Draw(v,fs);
        //随机产生颜色
        t.DrwaLine(white);
    }
    WriteToFile
    return 0;
}
