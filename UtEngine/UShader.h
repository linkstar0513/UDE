//
// Created by link on 18年7月2日.
//

#ifndef UT_SDL2_USHADER_H
#define UT_SDL2_USHADER_H
//#include <GL/glew.h>
#include <glad.h>



#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class UShader {


        uint32_t shader_id;

    public:
    UShader();
        // 使用/激活程序
        void use();
        // uniform工具函数
        void setBool(const std::string &name, bool value) const;

        // ------------------------------------------------------------------------
        void setInt(const std::string &name, int value) const;

        // ------------------------------------------------------------------------
        void setFloat(const std::string &name, float value) const;

        // ------------------------------------------------------------------------
        void setVec2(const std::string &name, const glm::vec2 &value) const;

        void setVec2(const std::string &name, float x, float y) const;

        // ------------------------------------------------------------------------
        void setVec3(const std::string &name, const glm::vec3 &value) const;

        void setVec3(const std::string &name, float x, float y, float z) const;

        // ------------------------------------------------------------------------
        void setVec4(const std::string &name, const glm::vec4 &value) const;

        void setVec4(const std::string &name, float x, float y, float z, float w);

        // ------------------------------------------------------------------------
        void setMat2(const std::string &name, const glm::mat2 &mat) const;

        // ------------------------------------------------------------------------
        void setMat3(const std::string &name, const glm::mat3 &mat) const;

        // ------------------------------------------------------------------------
        void setMat4(const std::string &name, const glm::mat4 &mat) const;







        uint32_t getShaderId() const;

    public:
        // 构造器读取并构建着色器
        UShader(const GLchar* vertexPath, const GLchar* fragmentPath);

};


#endif //UT_SDL2_USHADER_H
