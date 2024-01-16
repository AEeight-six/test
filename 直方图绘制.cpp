#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
void DrawGrayHist(const Mat& srcImg);

int main()
{
	Mat srcImg = imread("lena.jpg", 0);
	if (srcImg.empty())
	{
		std::cout << "ͼƬ��ȡʧ��" << std::endl;
		return -1;
	}
	DrawGrayHist(srcImg);
	waitKey(0);
	return 0;
}

void DrawGrayHist(const Mat& srcImg)

	{

		if (1 != srcImg.channels())
		{
			std::cout << "ͼƬͨ������Ϊ1" << std::endl;
		}

		Mat dstHist;
		int histSize[] = { 256 }; //ֱ��ͼ�ߴ�

		float midRanges[] = { 0,256 }; //����ֵ��Χ
		const float* ranges[] = { midRanges };
		calcHist(&srcImg, 1, 0, Mat(), dstHist, 1, histSize, ranges); //����ֱ��ͼ
		Mat histImage = Mat::zeros(Size(256, 256), CV_8UC1);
		double dblHistMaxValue;
		minMaxLoc(dstHist, 0, &dblHistMaxValue, 0, 0);
		for (int i = 0; i < 255; i++)
		{
			int value = cvRound(dstHist.at<float>(i) * 255 / dblHistMaxValue);//��һ��
			line(histImage, Point(i, histImage.rows - 1), Point(i, histImage.rows - 1 - value), Scalar(255));//����ֱ��ͼ

		}
		imshow("ֱ��ͼ�޸�", histImage);
	



	}

