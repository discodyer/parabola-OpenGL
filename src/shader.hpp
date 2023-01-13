/*
 * @Author: discodyer cody23333@gmail.com
 * @Date: 2023-01-12 01:24:47
 * @LastEditors: discodyer cody23333@gmail.com
 * @LastEditTime: 2023-01-13 15:15:37
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

class Shader
{
public:
    // 程序ID
    unsigned int ID;

    // 构造器读取并构建着色器
    Shader(const char* vertexPath, const char* fragmentPath);
    // 使用/激活程序
    void use();
    // uniform工具函数
    void setUniform(const std::string &name, bool value) const;
    void setUniform(const std::string &name, int value) const;
    void setUniform(const std::string &name, float value) const;
    void setUniform(const std::string &name, float vec0, float vec1, float vec2, float vec3) const;
private:
    // 打印编译错误（如果有的话）
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif