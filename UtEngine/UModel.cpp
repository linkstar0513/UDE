//
// Created by link on 18年7月6日.
//

#include "UModel.h"
#include <stb_image_config.h>

UModel::UModel() {

}

UModel::UModel(char *path) {




    loadModel(path);

}

void UModel::draw(UShader *shader) {
   // std::cout<<"model is drawing"<<std::endl;
    for(uint32_t i=0;i<meshes.size();i++){
        meshes[i].model=model;
        meshes[i].view=view;
        meshes[i].projection=projection;
        meshes[i].draw(shader);
    }
}

void UModel::loadModel(string path) {
    Assimp::Importer importer;//Assimp的导入工具

    /*
     *
     * 我们首先声明了Assimp命名空间内的一个Importer，之后调用了它的ReadFile函数。
     * 这个函数需要一个文件路径，它的第二个参数是一些后期处理(Post-processing)的选项。
     * 除了加载文件之外，Assimp允许我们设定一些选项来强制它对导入的数据做一些额外的计算或操作。
     * 通过设定aiProcess_Triangulate，我们告诉Assimp，如果模型不是（全部）由三角形组成，它需要将模型所有的图元形状变换为三角形。
     * aiProcess_FlipUVs将在处理的时候翻转y轴的纹理坐标（你可能还记得我们在纹理教程中说过，在OpenGL中大部分的图像的y轴都是反的，所以这个后期处理选项将会修复这个）。
     * 其它一些比较有用的选项有：

    aiProcess_GenNormals：如果模型不包含法向量的话，就为每个顶点创建法线。
    aiProcess_SplitLargeMeshes：将比较大的网格分割成更小的子网格，如果你的渲染有最大顶点数限制，只能渲染较小的网格，那么它会非常有用。
    aiProcess_OptimizeMeshes：和上个选项相反，它会将多个小网格拼接为一个大的网格，减少绘制调用从而进行优化。
     */
    const aiScene *scene=importer.ReadFile(path, aiProcess_Triangulate);//aiProcess_Triangulate|aiProcess_FlipUVs|aiProcess_CalcTangentSpace
    //检查场景与根节点是否为null,检查flag看返回的数据是否完整

    if(!scene||scene->mFlags&AI_SCENE_FLAGS_INCOMPLETE||!scene->mRootNode){
        std::cout<<"ERROR:ASSIMP::"<<importer.GetErrorString()<<std::endl;
        return;
    }
    directory=path.substr(0,path.find_last_of('/'));
    //遍历所有数据节点
    processNode(scene->mRootNode,scene);
}

void UModel::processNode(aiNode *node, const aiScene *scene) {
    //遍历节点中的所有网格（如果有）
    if(!node||!scene){
        return;
    }
    for(uint32_t i=0;i< node->mNumMeshes;i++){//先处理自身的节点
        //node中的mesh是对scene中mesh的索引
        aiMesh *mesh=scene->mMeshes[node->mMeshes[i]];
        if(mesh){
            meshes.push_back(processMesh(mesh,scene));
        }
    }
//接下来对它的子节点重复这一过程
    for (uint32_t j=0;j<node->mNumChildren;j++){
        processNode(node->mChildren[j],scene);
    }

}

UMesh UModel::processMesh(aiMesh *mesh, const aiScene *scene) {
    if(!mesh||!scene){
    }
    //处理网格的过程主要有三部分：获取所有的顶点数据，获取它们的网格索引，并获取相关的材质数据。
    // 处理后的数据将会储存在三个vector当中，我们会利用它们构建一个Mesh对象，并返回它到函数的调用者那里。
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
    std::vector<Texture> textures;

    //初始化内存预留空间防止内存溢出分配内存失败
    //vertices.reserve(1000000);
   // indices.reserve(100000);
   // textures.reserve(100000);
    //struct前三个值代表顶点的空间坐标
    for(uint32_t i=0;i<mesh->mNumVertices;i++) {
        Vertex vertex;
       //获取顶点位置
        glm::vec3 vectorTemp;
        if(mesh->HasPositions()){//获取顶点
            vectorTemp.x = mesh->mVertices[i].x;
            vectorTemp.y = mesh->mVertices[i].y;
            vectorTemp.z = mesh->mVertices[i].z;
        }
        vertex.position = vectorTemp;
        //每个面4个顶点，所有的顶点坐标obj文件
        //std::cout<<"位置坐标为："<<vectorTemp.x<<","<<vectorTemp.y<<","<<vectorTemp.z<<std::endl;

        if(mesh->HasNormals()){//获取法向量
            vertex.normal.x = mesh->mNormals[i].x;
            vertex.normal.y = mesh->mNormals[i].y;
            vertex.normal.z = mesh->mNormals[i].z;
        }

        //网格是否有纹理坐标
        if (mesh->HasTextureCoords(0)) {
            vertex.texcorrds.x = mesh->mTextureCoords[0][i].x;
            vertex.texcorrds.y = mesh->mTextureCoords[0][i].y;
        } else {
            vertex.texcorrds = glm::vec2(0.0f, 0.0f);
        }

        vertex.texcorrds = glm::vec2(-0.5f, -0.5f);
        /** tangent与bitangent均为空
        // tangent
        vectorTemp.x = mesh->mTangents[i].x;


        vectorTemp.y = mesh->mTangents[i].y;
        vectorTemp.z = mesh->mTangents[i].z;
        vertex.tangent = vectorTemp;


        // bitangent
        vectorTemp.x = mesh->mBitangents[i].x;
        vectorTemp.y = mesh->mBitangents[i].y;
        vectorTemp.z = mesh->mBitangents[i].z;
        vertex.bitangent = vectorTemp;
         */
        vertices.push_back(vertex);


    }
    //获取索引数据
    for(uint32_t i=0;i<mesh->mNumFaces;i++){
            aiFace face=mesh->mFaces[i];
            if(face.mNumIndices!=3){
                std::cout<<"该表面不是三角形"<<std::endl;
            }
            for (uint32_t j = 0; j < face.mNumIndices ; j++) {
                indices.push_back(face.mIndices[j]);
               // std::cout<<"添加索引后的索引数组大小"<<indices.size()<<"值"<< face.mIndices[j]<<std::endl;
            }
        }


        //处理材质纹理数据
     if(mesh->mMaterialIndex>=0){
            aiMaterial *material=scene->mMaterials[mesh->mMaterialIndex];
            // 1获取diffuse类型 diffuse maps
           std::vector<Texture> diffuseMaps =
                    loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
            textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
            //2 获取specular类型specular maps
            std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
            textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
            //3获取normal类型normal maps
            std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_normal");
            textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
            //4 获取height类型height maps
            std::vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_height");
            textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
        }
    return UMesh(vertices,indices,textures);
}

std::vector<Texture> UModel::loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName) {
    std::vector<Texture> textures;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        bool skip= false;//检查纹理之前是否被加载过，如果被加载过就跳过这次迭代，加载新的贴图
        for(uint32_t j=0;j<textures_load.size();j++){
            if(std::strcmp(textures_load[j].path.data(),str.C_Str())==0){
                textures.push_back(textures_load[j]);
                skip=true;
                break;
            }
        }
        if(!skip){
            Texture texture;
            texture.id = TextureFromFile(str.C_Str(), directory, false);
            texture.type = typeName;
           texture.path = str.C_Str();
            textures.push_back(texture);
            textures_load.push_back(texture);// store it as texture loaded for entire model, to ensure we won't unnecesery load duplicate textures.
        }

    }

    return textures;
}



unsigned int TextureFromFile(const char *path, const string &directory, bool gamma)
{
    string filename = string(path);
    filename = directory + '/' + filename;

    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}
