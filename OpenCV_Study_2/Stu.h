#include "pch.h"
#pragma once
#ifndef STU_H_
#define STU_H_
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
class Stu
{
private:
	std::string FileName;
	cv::Mat src,gray;
	int check(cv::Mat src);//检查图片是否加载成功
public:
	Stu();
	void get_reasonable_img();//生成两张合适的图像
	void get_pix_1();//获取单通道像素
	void get_pix_3();//获取三通道像素
	//第五课 图像混合
	void mix_Image();//图像混合
	void Print_img();//绘制图像

	~Stu();
};


#endif // !STU_H_


