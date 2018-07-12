//
// Created by link on 18年7月6日.
//

#ifndef UT_SDL2_UMESH_H
#define UT_SDL2_UMESH_H

#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "UShader.h"

#include <glad/glad.h>
using std::string;


/*
 * 利用assimp加载模型
 */

//定义一个网格
struct Vertex{
    glm::vec3 position;//位置向量
    glm::vec3 normal;//法向量
    glm::vec2 texcorrds;//纹理坐标向量
    //模型顶点中的纹理坐标，就定义于切线空间。普通2维纹理坐标包含U、V两项，其中U坐标增长的方向， 即切线空间中的tangent轴，V坐标增加的方向，为切线空间中的bitangent轴。
    //模型中不同的三角形，都有对应的切线空间，其tangent轴和bitangent轴分别位于三角形所在平面上，结合三角形面对应的法线，
    // 我们称tangant轴（T）、bitangent轴（B）及法线轴（N）所组成的坐标系，即切线空间（TBN）。
    //glm::vec3 tangent;//切线空间T周
    //glm::vec3 bitangent;//切线空间B轴
};

//纹理数据
struct Texture{
    uint32_t id;
    std::string type;//纹理类型
    std::string path;//纹理地址
};
class UMesh {

public:

    uint32_t VAO,VBO,EBO;

    glm::mat4 model{glm::mat4(1.0f)},
            view{glm::mat4(1.0f)},
            projection{glm::mat4(1.0f)};

    UMesh();
    UMesh(std::vector<Vertex> vetices,std::vector <uint32_t> indices,std::vector<Texture> textures);
    ~UMesh();




    //写到缓存中

    /*
     * 网格数据
     */
    std::vector<Vertex> vetices;
    std::vector<uint32_t >indices;
    std::vector<Texture> textures;
    /*
     * 函数
     */

    void draw(UShader *shader);//shader采用着色器
    /*
 * 渲染数据
 */

    /*
     * 函数
     */
    void setupMesh();

private:



};


#endif //UT_SDL2_UMESH_H
