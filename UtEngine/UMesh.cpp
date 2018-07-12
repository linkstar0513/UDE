//
// Created by link on 18年7月6日.
//

#include "UMesh.h"
UMesh::UMesh(std::vector<Vertex> vetices,std::vector <uint32_t> indices,std::vector<Texture> textures){
    this->vetices.assign(vetices.begin(),vetices.end());//通过=号赋值会增加size的大小?
    this->indices.assign(indices.begin(),indices.end());//indices;
    this->textures.assign(textures.begin(),textures.end());//textures;

    //std::cout<<"构造成功"<<"顶点数组大小"<<vetices.size()<<std::endl;
    //std::cout<<"构造成功"<<"顶点数组大小"<<this->vetices.size()<<std::endl;
    std::cout<<"构造成功"<<"顶点数组大小"<<this->indices.size()<<std::endl;
    setupMesh();
    //std::cout<<"单独狗仔"<<"顶点数组大小"<<this->indices.size()<<std::endl;

}



void UMesh::setupMesh() {

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&EBO);

    glBindVertexArray(VAO);


    //-----------------------------------------------------绑定vbo，ebo设置熟悉

    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,vetices.size()* sizeof(Vertex),&vetices[0],GL_STATIC_DRAW);
    std::cout<<"绑定的数组大小"<<vetices.size()<<"indecs:"<<indices.size()<<std::endl;

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,indices.size()* sizeof(uint32_t),&indices[0],GL_STATIC_DRAW);
    //顶点位置
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, sizeof(Vertex),(void*)0);
    glEnableVertexAttribArray(0);
    //顶点法线
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE, sizeof(Vertex),(void*)offsetof(Vertex,normal));
    glEnableVertexAttribArray(1);
    //顶点纹理坐标

    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE, sizeof(Vertex),(void*)offsetof(Vertex,texcorrds));
    glEnableVertexAttribArray(2);
    // vettex tangent
    //glEnableVertexAttribArray(3);
   // glVertexAttribPointer(3,3,GL_FLOAT,GL_FALSE, sizeof(Vertex),(void*)offsetof(Vertex,tangent));
    //vertex bitangent
   // glEnableVertexAttribArray(4);
   // glVertexAttribPointer(4,3,GL_FLOAT,GL_FALSE, sizeof(Vertex),(void*)offsetof(Vertex,bitangent));

//-------------------------

        /*
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexevo),vertexevo,GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indecis1),indecis1,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_TRUE, sizeof(float)*6,(void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_TRUE, sizeof(float)*6,(void*)(sizeof(float)*3));
    glEnableVertexAttribArray(1);

         */






   // glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);

}
void UMesh::draw(UShader *shader) {

    if(VAO==0||VBO==0||EBO==0){
        return;
    }
    shader->use();
    shader->setMat4("projection",projection);
    shader->setMat4("view",view);
    shader->setMat4("model",model);
  //  shader->use();


    uint32_t diffuseNr=1;//漫反射
    uint32_t  specularNr=1;//镜面反射
    uint32_t normalNr=1;
    uint32_t heightNr=1;
    for(uint32_t i=0;i<textures.size();i++){
        glActiveTexture(GL_TEXTURE0+i);//在绑定之前激活对应的纹理单元
        std::string number;
        std::string name=textures[i].type;
        if(name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else if(name == "texture_specular")
            number = std::to_string(specularNr++);
        else if(name == "texture_normal")
            number = std::to_string(normalNr++); // transfer unsigned int to stream
        else if(name == "texture_height")
            number = std::to_string(heightNr++); // transfer unsigned int to stream
       // shader.setFloat(("material." + name + number).c_str(), i);
        glUniform1i(glGetUniformLocation(shader->getShaderId(), (name + number).c_str()), i);
        glBindTexture(GL_TEXTURE_2D,textures[i].id);
    }
    glActiveTexture(GL_TEXTURE0);

    //绘制网格
   // shader->use();//在设置model,view,projection之前只能使用一次次

    glBindVertexArray(VAO);
    //glDrawArrays(GL_TRIANGLES,0,vetices.size());
  //  std::cout<<"draw:"<<indices.size()<<std::endl;
    glDrawElements(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0);
    //glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
    //std::cout <<"mesh绘制ing"<<std::endl;


}

UMesh::UMesh():VAO(0),VBO(0),EBO(0){
setupMesh();
std::cout<<"已经调用构造函数"<<std::endl;
//init();
}







UMesh::~UMesh() {
    //// 不要再这里释放VBO等空间 因为Mesh对象传递时 临时对象销毁后这里会清理VBO等空间
    //析构时删除对应的资源
    //glDeleteVertexArrays(1,&VAO);
    //glDeleteBuffers(1,&VBO);
    //glDeleteBuffers(1,&EBO);
}
