#include "pch.h"
#include "Stu.h"
#include <iomanip>

Stu::Stu()
{
	FileName = "C:\\Users\\86130\\Desktop\\thumb.jpg";
	src = cv::imread(FileName);
	cv::cvtColor(src, gray, CV_BGR2GRAY);//ԭͼ��ǰ������ں�
	int statu=check(src);
}
int Stu::check(cv::Mat src)
{
	//���ͼƬ�Ƿ���سɹ�
	if (src.data) return 1;
	else return 0;	
}
void Stu::get_reasonable_img()
{
	cv::Mat src1, src2;
	src1 = cv::imread("D:\\document\\Python\\GUIdesign\\img\\΢��ͼƬ_20180830201407.jpg");
	src2 = cv::imread("D:\\document\\Python\\GUIdesign\\img\\΢��ͼƬ_20180830201433.jpg");
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
��ȡ��ͨ������
������ 2018.10.13
*/
	cv::imshow("ԭͼ", src);
	cv::imshow("�Ҷ�ͼ", gray);
	int Hight = gray.rows;
	int Weight = gray.cols;
	for (int row = 0; row < Hight; row++)
	{
		for (int clo = 0; clo < Weight; clo++)
		{
			int gray_num=gray.at<uchar>(row, clo);
			gray.at<uchar>(row, clo) = 255 - gray_num;
			//std::cout << std::setw(2)<<gray_num<<"  ";//setw(x) ��xλ������֣�������Ĭ�ϲ��ո�
		}
		//std::cout << std::endl;
	}
	cv::imshow("�Ҷ�ͼ�ķ���ͼ", gray);
}
void Stu::get_pix_3()
{
	cv::Mat dst,dst_r;
	dst.create(src.size(), src.type());
	dst_r.create(src.size(), src.type());
	//�Լ�д��
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
	cv::imshow("��ͼ����ͼ", dst);
	cv::imshow("��ͼ����ͼ2", dst_r);
	//����API��
	cv::bitwise_not(gray, dst);//λȡ��
	cv::imshow("����API�ĻҶ�ͼ����ͼ", dst);
	cv::bitwise_not(src, dst);
	cv::imshow("����API�Ĳ�ͼ����ͼ", dst);
}
void Stu::mix_Image()
{
/*
ͼ����
������ 2018.10.13
���л�����ۣ�
	G(x)=(1-a)f1(x)+af2(x);  aΪ0~1����
���API:addWeighted(�������),add��ֱ����ӣ�,multiply����ˣ�
ע�⣺
	����ͼ��С���ͱ���һ�²ſ���
*/
	cv::Mat src1, src2,dst;
	src1 = cv::imread("D:\\document\\Python\\GUIdesign\\img\\΢��ͼƬ_20180830201407.jpg");
	src2 = cv::imread("D:\\document\\Python\\GUIdesign\\img\\΢��ͼƬ_20180830201433.jpg");
	cv::imshow("1", src1);
	cv::imshow("2", src2);
	cv::addWeighted(src1, 0.5, src2, 0.5, 1.0, dst);
	cv::imshow("�������", dst);
	cv::add(src1, src2, dst);
	cv::imshow("ֱ�����", dst);
	cv::multiply(src1, src2, dst);
	cv::imshow("���", dst);
}
void Stu::Print_img()
{
	//�ڱ���ͼ�ϻ�һ����
	cv::Point p1 = cv::Point(20, 20);
	cv::Point p2;
	p2.x = 300;
	p2.y = 300;
	cv::Scalar color = cv::Scalar(0, 0, 255);
	cv::line(src, p1, p2, color, 2, cv::LINE_AA);
	cv::imshow("����", src);
	//�ڱ���ͼ�ϻ�һ������
	cv::Rect R = cv::Rect(20, 20, 300, 300);
	cv::Scalar S = cv::Scalar(255, 0, 0);
	cv::rectangle(src, R, S, 3, cv::LINE_8);
	cv::imshow("����+����", src);
	//�ڱ���ͼ�ϻ�һ����Բ
	cv::ellipse(src, cv::Point(src.cols/2,src.rows/2), cv::Size(src.cols / 4, src.rows / 4), 135, 0, 360, cv::Scalar(0, 255, 0), 2, cv::LINE_AA);
	cv::imshow("����+����+��Բ", src);
	//�ڱ���ͼ�ϻ�һ��Բ
	cv::circle(src, cv::Point(src.cols / 2, src.rows / 2), 150, cv::Scalar(0, 0, 255), 2, 8);
	cv::imshow("����+����+��Բ+Բ", src);
	//�ڱ���ͼ�����һ�������
	cv::Point pts[1][5];
	pts[0][0] = cv::Point(30, 30);
	pts[0][1] = cv::Point(30, 180);
	pts[0][2] = cv::Point(180, 180);
	pts[0][3] = cv::Point(180, 30);
	pts[0][4] = cv::Point(30, 30);
	int npt[] = { 5 };
	const cv::Point* ppts[] = { pts[0] };
	cv::fillPoly(src, ppts, npt, 1,color, 8);
	cv::imshow("����+����+��Բ+Բ+�����", src);
	//�ڱ���ͼ����ʾ����
	cv::putText(src, "Hello OpenCV!!", cv::Point(200,200),CV_FONT_BLACK, 1.0, cv::Scalar(255,255,0), 2, 8);
	cv::imshow("����+����+��Բ+Բ+�����+����", src);
}
Stu::~Stu()
{
}
