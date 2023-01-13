/*
 * @Author: discodyer cody23333@gmail.com
 * @Date: 2023-01-12 01:24:47
 * @LastEditors: discodyer cody23333@gmail.com
 * @LastEditTime: 2023-01-13 16:17:15
 * @FilePath: \parabola-OpenGL\src\texture.hpp
 * @Description: 材质类
 */
#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_
#include <glad/glad.h> // 包含glad来获取所有的必须OpenGL头文件
#include <iostream>
#include "stb_image.h"

/*!
 * @brief 贴图类
 * 自动加载贴图
 */
class Texture
{
public:
    // 程序ID
    unsigned int ID;
    // 图片宽度，高度和颜色通道数量
    int width, height, nrChannels;
    
    /*!
     * @brief Construct a new Texture object
     * 
     * @param texturePath Path to Texture file
     * @param RGB_MODE GL_RGB* mode, Default to GL_RGB
     */
    Texture(const char* texturePath, int RGB_MODE = GL_RGB);

    /*!
     * @brief bind a Texture
     * use GL_TEXTURE0
     */
    void bind();

    /*!
     * @brief bind a Texture
     * 
     * @param unit GL_TEXTURE from 0 to 15
     */
    void bind(int unit);
};

#endif