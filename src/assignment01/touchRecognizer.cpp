#include "touchRecognizer.hpp"

#include <algorithm>
#include <iostream>
#include <Windows.h>

using namespace cv;
using namespace std;

void TouchRecognizer::createHistogram(const cv::Mat&depthFrame) {

	/*
	My attempt at creating a histogram for the background:
	every 16 values get put into one array field, 
	I iterate over the function and increase the corresponding field by one.

	After that print it into console
	*/

	int dim = 1;
	//the kinect has a depth of 11 bits, but for the luls we will only use 16 bins
	int histSize = 2 ^ 11 / 2 ^ 4;
	float histRangeArray[] = { 0, 2 ^ 11 };
	const float* histRange = { histRangeArray };

	short histogram[128] = { 0 };

	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			histogram[depthFrame.at<unsigned short>(i, j) / 16]++;
		}
	}

	for (int i = 0; i < 128; i++) {
		cout << i * 16 << " " << histogram[i] << endl;
	}


}

void TouchRecognizer::calibrate(const cv::Mat& background)
{
	background.copyTo(m_background);

	int backgroundDepth = 0;

	

	Mat backgroundHist;
	cout << m_background.at<unsigned short>(m_background.rows/2,m_background.cols/2);


	
	for (int i = 1; i < m_background.rows; i++) {
		for (int j = 1; j < m_background.cols; j++) {

			//cout << i << " " << j << " " << m_background.at<unsigned short>(i, j) << endl;
			if (m_background.at<unsigned short>(i, j) > backgroundDepth) {

				backgroundDepth = m_background.at<unsigned short>(i, j);

			}
		}
	}
	cout << backgroundDepth;
}

std::vector<cv::RotatedRect> TouchRecognizer::recognize(const cv::Mat& depthFrame) const
{
	std::vector<cv::RotatedRect> positions;

	//remove the background from the current frame
	Mat legFrame = m_background - depthFrame;
	imshow("withoutBackground", legFrame);
	Mat footFrame = Mat(depthFrame.rows, depthFrame.cols, CV_16UC1);
	legFrame.copyTo(footFrame);

	threshold(footFrame, footFrame, backgroundDepth-100, 0, 4);
	imshow("thresh1", footFrame);






	//cv::GaussianBlur(legFrame, legFrame, cv::Size(5, 5), 0, 0);
	//cv::imshow("blur", legFrame);
	//Use a threshold to whiten the foot
	//cv::Mat footFrame;
	//std::cout << legFrame;
	//cv::threshold(legFrame, footFrame, 800, 100000, 0);
	//std::vector<std::vector<cv::Point>>  contours[100];
	//cv::findContours(footFrame, contours , CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE,cv::Point(0,0));

    /*~~~~~~~~~~~*
     * YOUR CODE *
     * GOES HERE *
     *~~~~~~~~~~~*/

    return positions;
}
