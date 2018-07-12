//
// Created by link on 18年7月6日.
//

#ifndef UT_SDL2_UMODEL_H
#define UT_SDL2_UMODEL_H

#include <vector>
#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

//预处理stb_image函数使其成为hpp

//#define STB_IMAGE_IMPLEMENTATION
//#include <stb/stb_image.h>

#include "UShader.h"

#include "UMesh.h"

unsigned int TextureFromFile(const char *path, const string &directory, bool gamma = false);


//用于存储加载UMesh,有统一的mvp,并且可以改变，可以draw到平面上
class UModel {
public:

    glm::mat4 model{glm::mat4(1.0f)},
            view{glm::mat4(1.0f)},
            projection{glm::mat4(1.0f)};
    std::vector<Texture> textures_load;
    bool gammaCorrection;

    UModel();
    UModel(char* path);
    void draw(UShader *shader);


   // std::vector<Vertex> vertices;
  //  std::vector<uint32_t> indices;
    //std::vector<Texture> textures;


    /*
     * 模型数据
     */
    std::vector<UMesh> meshes;

private:


    //目录
    string directory;
    /*
     * 函数
     */
    void loadModel(string path);
    void processNode(aiNode *node, const aiScene *scene);
    UMesh processMesh(aiMesh *mesh,const aiScene *scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat,aiTextureType type,string typeName);


};




#endif //UT_SDL2_UMODEL_H
