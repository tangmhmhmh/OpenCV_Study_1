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
	int check(cv::Mat src);//���ͼƬ�Ƿ���سɹ�
public:
	Stu();
	void get_reasonable_img();//�������ź��ʵ�ͼ��
	void get_pix_1();//��ȡ��ͨ������
	void get_pix_3();//��ȡ��ͨ������
	//����� ͼ����
	void mix_Image();//ͼ����
	void Print_img();//����ͼ��

	~Stu();
};


#endif // !STU_H_


