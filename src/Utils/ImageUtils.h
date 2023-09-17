#pragma once

#include <opencv2/opencv.hpp>

void ApplayGrayScale(cv::Mat &mat)
{
    cv::cvtColor(mat, mat, cv::COLOR_BGR2GRAY);
}
void ApplayBrightness(cv::Mat &mat, int value)
{
    cv::Mat brightnessMat;
    mat.convertTo(brightnessMat, -1, 1, value);
    mat = brightnessMat;
}
void ApplayContrast(cv::Mat &mat, double value)
{
    cv::Mat contrastMat;
    mat.convertTo(contrastMat, -1, value, 0);
    mat = contrastMat;
}
void ApplayHue(cv::Mat &mat, int value)
{
    cv::Mat hueMat;
    cv::cvtColor(mat, hueMat, cv::COLOR_BGR2HSV);
    std::vector<cv::Mat> channels;
    cv::split(hueMat, channels);
    channels[0] += value;
    cv::merge(channels, hueMat);
    cv::cvtColor(hueMat, hueMat, cv::COLOR_HSV2BGR);
    mat = hueMat;
}
void ApplaySaturation(cv::Mat &mat, int value)
{
    cv::Mat saturationMat;
    cv::cvtColor(mat, saturationMat, cv::COLOR_BGR2HSV);
    std::vector<cv::Mat> channels;
    cv::split(saturationMat, channels);
    channels[1] += value;
    cv::merge(channels, saturationMat);
    cv::cvtColor(saturationMat, saturationMat, cv::COLOR_HSV2BGR);
    mat = saturationMat;
}
void ApplayVibarance(cv::Mat &mat, int value)
{
    cv::Mat vibaranceMat;
    cv::cvtColor(mat, vibaranceMat, cv::COLOR_BGR2HSV);
    std::vector<cv::Mat> channels;
    cv::split(vibaranceMat, channels);
    channels[2] += value;
    cv::merge(channels, vibaranceMat);
    cv::cvtColor(vibaranceMat, vibaranceMat, cv::COLOR_HSV2BGR);
    mat = vibaranceMat;
}
void ApplayEmboos(cv::Mat &mat, int value)
{
    cv::Mat emboosMat;
    if (value == 1)
    {
        cv::Mat kernel = (cv::Mat_<float>(3, 3) << -2, -1, 0,
                          -1, 1, 1,
                          0, 1, 2);
        cv::filter2D(mat, emboosMat, -1, kernel);
    }
    else if (value == 2)
    {
        cv::Mat kernel = (cv::Mat_<float>(3, 3) << -1, -1, -1,
                          -1, 8, -1,
                          -1, -1, -1);
        cv::filter2D(mat, emboosMat, -1, kernel);
    }
    else if (value == 3)
    {
        cv::Mat kernel = (cv::Mat_<float>(3, 3) << 0, 1, 0,
                          1, -4, 1,
                          0, 1, 0);
        cv::filter2D(mat, emboosMat, -1, kernel);
    }
    mat = emboosMat;
}
void ApplaySharpness(cv::Mat &mat, int value)
{
    cv::Mat sharpnessMat;
    if (value == 1)
    {
        cv::Mat kernel = (cv::Mat_<float>(3, 3) << 0, -1, 0,
                          -1, 5, -1,
                          0, -1, 0);
        cv::filter2D(mat, sharpnessMat, -1, kernel);
    }
    else if (value == 2)
    {
        cv::Mat kernel = (cv::Mat_<float>(3, 3) << -1, -1, -1,
                          -1, 9, -1,
                          -1, -1, -1);
        cv::filter2D(mat, sharpnessMat, -1, kernel);
    }
    mat = sharpnessMat;
}

void ApplayBlur(cv::Mat &mat, int value)
{
    cv::Mat blurMat;
    cv::blur(mat, blurMat, cv::Size(value, value));
    mat = blurMat;
}
void ApplayPixlate(cv::Mat &mat, int value)
{
    cv::Mat pixlateMat;
    cv::resize(mat, pixlateMat, cv::Size(), 1.0 / value, 1.0 / value, cv::INTER_NEAREST);
    cv::resize(pixlateMat, mat, cv::Size(), value, value, cv::INTER_NEAREST);
}
void ApplayNoise(cv::Mat &mat, int value)
{
    cv::Mat noiseMat = cv::Mat(mat.size(), CV_8UC3);
    cv::randn(noiseMat, cv::Scalar::all(0), cv::Scalar::all(value));
    cv::add(mat, noiseMat, mat);
}