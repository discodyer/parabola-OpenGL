/*
 * @Author: discodyer cody23333@gmail.com
 * @Date: 2023-01-12 01:24:47
 * @LastEditors: discodyer cody23333@gmail.com
 * @LastEditTime: 2023-01-13 15:22:43
 * @FilePath: \parabola-OpenGL\src\texture.hpp
 * @Description: 材质类
 */
#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_
#include <glad/glad.h> // 包含glad来获取所有的必须OpenGL头文件
#include <iostream>
#include "stb_image.h"

class Texture
{
public:
    // 程序ID
    unsigned int ID;
    // 图片宽度，高度和颜色通道数量
    int width, height, nrChannels;
    Texture(const char* texturePath);
    Texture(const char* texturePath, int RGB_MODE);
    void bind();
    void bind(int unit);
};

#endif