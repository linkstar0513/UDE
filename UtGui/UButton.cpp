//
// Created by link on 18年7月5日.
//

#include "UButton.h"


UButton::UButton():UModel(){
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
    std::vector<Texture> textures;
    //Vertex vertextemp={glm::vec3(-0.5f, -0.5f, -0.5),glm::vec3(-0.5f, -0.5f, -0.5),glm::vec2(-0.5f, -0.5f)};

//长方形，标题拦
    vertices.push_back({glm::vec3(-1.0f, -0.8f, -1.0),glm::vec3(0.4f, 0.1f, 0.1f),glm::vec2(0.0f, 0.0f)});
    vertices.push_back({glm::vec3(-1.0f, 1.0f, -1.0),glm::vec3(0.2f, 0.9f, 0.2f),glm::vec2(0.0f, 1.0f)});
    vertices.push_back({glm::vec3(1.0f, -0.8f, -1.0),glm::vec3(0.9f, 0.2f, 0.2f),glm::vec2(1.0f, 0.0f)});
    vertices.push_back({glm::vec3(1.0f, 1.0f, -1.0),glm::vec3(0.3f, 0.3f, 0.3f),glm::vec2(1.0f, 1.0f)});

    //立方体
    //vertices.push_back({glm::vec3(-1.0f, -1.0f, -1.0),glm::vec3(0.4f, 0.1f, 0.1f),glm::vec2(0.0f, 0.0f)});
    //vertices.push_back({glm::vec3(-1.0f, 1.0f, -1.0),glm::vec3(0.2f, 0.9f, 0.2f),glm::vec2(0.0f, 1.0f)});
    //vertices.push_back({glm::vec3(1.0f, -1.0f, -1.0),glm::vec3(0.9f, 0.2f, 0.2f),glm::vec2(0.5f, 1.0f)});
    //vertices.push_back({glm::vec3(1.0f, 1.0f, -1.0),glm::vec3(0.3f, 0.3f, 0.3f),glm::vec2(1.0f, 0.0f)});

    //vertices.push_back({glm::vec3(-1.0f, -1.0f, 1.0),glm::vec3(0.1f, 0.4f, 0.9f),glm::vec2(0.0f, 0.0f)});
    //vertices.push_back({glm::vec3(-1.0f, 1.0f, 1.0),glm::vec3(0.3f, 0.5f, 0.8f),glm::vec2(0.0f, 1.0f)});
    //vertices.push_back({glm::vec3(1.0f, -1.0f, 1.0),glm::vec3(0.2f, 0.9f, 0.5f),glm::vec2(1.0f, 1.0f)});
    //vertices.push_back({glm::vec3(1.0f, 1.0f, 1.0),glm::vec3(0.6f, 0.1f, 0.8f),glm::vec2(1.0f, 0.0f)});

    indices.push_back(0);indices.push_back(1);indices.push_back(2);indices.push_back(1);indices.push_back(2);indices.push_back(3);
    //indices.push_back(2);indices.push_back(3);indices.push_back(6);indices.push_back(3);indices.push_back(6);indices.push_back(7);
    //indices.push_back(6);indices.push_back(7);indices.push_back(4);indices.push_back(7);indices.push_back(4);indices.push_back(5);
    //indices.push_back(4);indices.push_back(5);indices.push_back(0);indices.push_back(5);indices.push_back(0);indices.push_back(1);
    //indices.push_back(5);indices.push_back(1);indices.push_back(7);indices.push_back(1);indices.push_back(4);indices.push_back(3);
    //indices.push_back(0);indices.push_back(2);indices.push_back(4);indices.push_back(2);indices.push_back(7);indices.push_back(6);

    Texture texture1;
    texture1.id=TextureFromFile("05.jpg","/home/link/CLionProjects/UT_SDL2/resource",true);
    texture1.path="05.jpg";
    texture1.type="texture_diffuse";
    textures.push_back(texture1);

    meshes.push_back(UMesh(vertices,indices,textures));


}

UButton::~UButton() {


}

