#pragma once

#include <vector>
#include <opencv2/opencv.hpp>

class TouchRecognizer
{
public:
    void calibrate(const cv::Mat & background);
    std::vector<cv::RotatedRect> recognize(const cv::Mat & depthFrame) const;
	void createHistogram(const cv::Mat&depthFrame);
private:
    cv::Mat m_background;
	int backgroundDepth;
	int poop = 3;
    /*~~~~~~~~~~~~~~~~*
     * YOU MAY DEFINE *
     * CONSTANTS HERE *
     *~~~~~~~~~~~~~~~~*/
};
