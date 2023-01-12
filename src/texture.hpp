/*
 * @Author: discodyer cody23333@gmail.com
 * @Date: 2023-01-12 01:24:47
 * @LastEditors: discodyer cody23333@gmail.com
 * @LastEditTime: 2023-01-13 01:52:50
 * @FilePath: \parabola-OpenGL\src\texture.hpp
 * @Description: texture class header file
 */
#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_
#include <glad/glad.h> // 包含glad来获取所有的必须OpenGL头文件
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "stb_image.h"

class Texture
{
public:
    // 程序ID
    unsigned int ID;
    int width, height, nrChannels;
    Texture(const char* texturePath);
    void bind();
};

#endif