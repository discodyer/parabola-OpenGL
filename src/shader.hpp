/*
 * @Author: discodyer cody23333@gmail.com
 * @Date: 2023-01-12 01:24:47
 * @LastEditors: discodyer cody23333@gmail.com
 * @LastEditTime: 2023-01-14 01:24:41
 * @FilePath: \parabola-OpenGL\src\shader.hpp
 * @Description: 着色器类
 */
#ifndef SHADER_HPP_
#define SHADER_HPP_
#include <glad/glad.h> // 包含glad来获取所有的必须OpenGL头文件

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*!
 * @brief 着色器类
 * 自动从文件读取并加载着色器
 */
class Shader
{
public:
    // 程序ID
    unsigned int ID;

    /*!
     * @brief 构造器读取并构建着色器
     * 
     * @param vertexPath 顶点着色器文件位置
     * @param fragmentPath 片段着色器文件位置
     */
    Shader(const char* vertexPath, const char* fragmentPath);

    /*!
     * @brief 使用/激活程序
     * 
     */
    void use();

    /*!
     * @brief uniform工具函数
     * Set the Uniform object
     * Using glUniform1i
     * @param name Uniform name
     * @param value Bool
     */
    void setUniform(const std::string &name, bool value) const;

    /*!
     * @brief uniform工具函数
     * Set the Uniform object
     * Using glUniform1i
     * @param name Uniform name
     * @param value int
     */
    void setUniform(const std::string &name, int value) const;

    /*!
     * @brief uniform工具函数
     * Set the Uniform object
     * Using glUniform1f
     * @param name Uniform name
     * @param value float
     */
    void setUniform(const std::string &name, float value) const;

    /*!
     * @brief uniform工具函数
     * Set the Uniform object
     * Using glUniform4f
     * @param name Uniform name
     * @param vec0 float
     * @param vec1 float
     * @param vec2 float
     * @param vec3 float
     */
    void setUniform(const std::string &name, float vec0, float vec1, float vec2, float vec3) const;

    void setUniformMatrix(const std::string &name, glm::mat4 &transform, int matNum = 1 , int ifTranspose = GL_FALSE) const;
private:

    /*!
     * @brief 打印编译错误（如果有的话）
     * 
     * @param shader 
     * @param type 
     */
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif