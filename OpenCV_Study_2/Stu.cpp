#include "pch.h"
#include "Stu.h"
#include <iomanip>

Stu::Stu()
{
	FileName = "C:\\Users\\86130\\Desktop\\thumb.jpg";
	src = cv::imread(FileName);
	cv::cvtColor(src, gray, CV_BGR2GRAY);//原图在前，输出在后
	int statu=check(src);
}
int Stu::check(cv::Mat src)
{
	//检查图片是否加载成功
	if (src.data) return 1;
	else return 0;	
}
void Stu::get_reasonable_img()
{
	cv::Mat src1, src2;
	src1 = cv::imread("D:\\document\\Python\\GUIdesign\\img\\微信图片_20180830201407.jpg");
	src2 = cv::imread("D:\\document\\Python\\GUIdesign\\img\\微信图片_20180830201433.jpg");
	cv::imshow("1", src1);
	cv::imshow("2", src2);
	cv::pyrDown(src1, src1);
	cv::pyrDown(src2, src2);
	//cv::imshow("1",src1);
	//cv::imshow("2",src2);

}
void Stu::get_pix_1()
{
/*
获取单通道像素
唐明弘 2018.10.13
*/
	cv::imshow("原图", src);
	cv::imshow("灰度图", gray);
	int Hight = gray.rows;
	int Weight = gray.cols;
	for (int row = 0; row < Hight; row++)
	{
		for (int clo = 0; clo < Weight; clo++)
		{
			int gray_num=gray.at<uchar>(row, clo);
			gray.at<uchar>(row, clo) = 255 - gray_num;
			//std::cout << std::setw(2)<<gray_num<<"  ";//setw(x) 按x位输出数字，不够的默认补空格
		}
		//std::cout << std::endl;
	}
	cv::imshow("灰度图的反相图", gray);
}
void Stu::get_pix_3()
{
	cv::Mat dst,dst_r;
	dst.create(src.size(), src.type());
	dst_r.create(src.size(), src.type());
	//自己写的
	int Hight = src.rows;
	int Weight = src.cols;
	for (int row = 0; row < Hight; row++)
	{
		for (int col = 0; col < Weight; col++)
		{
			dst.at<cv::Vec3b>(row, col)[0] = 255 - src.at<cv::Vec3b>(row, col)[0];
			dst.at<cv::Vec3b>(row, col)[1] = 255 - src.at<cv::Vec3b>(row, col)[1];
			dst.at<cv::Vec3b>(row, col)[2] = 255 - src.at<cv::Vec3b>(row, col)[2];
			dst_r.at<cv::Vec3b>(row, col)[0] = src.at<cv::Vec3b>(row, col)[1];
		}
	}
	cv::imshow("彩图反相图", dst);
	cv::imshow("彩图反相图2", dst_r);
	//调用API的
	cv::bitwise_not(gray, dst);//位取反
	cv::imshow("调用API的灰度图反相图", dst);
	cv::bitwise_not(src, dst);
	cv::imshow("调用API的彩图反相图", dst);
}
void Stu::mix_Image()
{
/*
图像混合
唐明弘 2018.10.13
现行混合理论：
	G(x)=(1-a)f1(x)+af2(x);  a为0~1的数
相关API:addWeighted(线性相加),add（直接相加）,multiply（相乘）
注意：
	两张图大小类型必须一致才可以
*/
	cv::Mat src1, src2,dst;
	src1 = cv::imread("D:\\document\\Python\\GUIdesign\\img\\微信图片_20180830201407.jpg");
	src2 = cv::imread("D:\\document\\Python\\GUIdesign\\img\\微信图片_20180830201433.jpg");
	cv::imshow("1", src1);
	cv::imshow("2", src2);
	cv::addWeighted(src1, 0.5, src2, 0.5, 1.0, dst);
	cv::imshow("线性相加", dst);
	cv::add(src1, src2, dst);
	cv::imshow("直接相加", dst);
	cv::multiply(src1, src2, dst);
	cv::imshow("想乘", dst);
}
void Stu::Print_img()
{
	//在背景图上画一条线
	cv::Point p1 = cv::Point(20, 20);
	cv::Point p2;
	p2.x = 300;
	p2.y = 300;
	cv::Scalar color = cv::Scalar(0, 0, 255);
	cv::line(src, p1, p2, color, 2, cv::LINE_AA);
	cv::imshow("画线", src);
	//在背景图上画一个矩形
	cv::Rect R = cv::Rect(20, 20, 300, 300);
	cv::Scalar S = cv::Scalar(255, 0, 0);
	cv::rectangle(src, R, S, 3, cv::LINE_8);
	cv::imshow("画线+矩形", src);
	//在背景图上画一个椭圆
	cv::ellipse(src, cv::Point(src.cols/2,src.rows/2), cv::Size(src.cols / 4, src.rows / 4), 135, 0, 360, cv::Scalar(0, 255, 0), 2, cv::LINE_AA);
	cv::imshow("曲线+矩形+椭圆", src);
	//在背景图上画一个圆
	cv::circle(src, cv::Point(src.cols / 2, src.rows / 2), 150, cv::Scalar(0, 0, 255), 2, 8);
	cv::imshow("曲线+矩形+椭圆+圆", src);
	//在背景图上填充一个多边形
	cv::Point pts[1][5];
	pts[0][0] = cv::Point(30, 30);
	pts[0][1] = cv::Point(30, 180);
	pts[0][2] = cv::Point(180, 180);
	pts[0][3] = cv::Point(180, 30);
	pts[0][4] = cv::Point(30, 30);
	int npt[] = { 5 };
	const cv::Point* ppts[] = { pts[0] };
	cv::fillPoly(src, ppts, npt, 1,color, 8);
	cv::imshow("曲线+矩形+椭圆+圆+多边形", src);
	//在背景图上显示文字
	cv::putText(src, "Hello OpenCV!!", cv::Point(200,200),CV_FONT_BLACK, 1.0, cv::Scalar(255,255,0), 2, 8);
	cv::imshow("曲线+矩形+椭圆+圆+多边形+文字", src);
}
Stu::~Stu()
{
}
