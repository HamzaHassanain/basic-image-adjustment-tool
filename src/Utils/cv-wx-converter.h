#pragma once
#include <opencv2/opencv.hpp>
#include <wx/wx.h>
wxImage wx_from_mat(cv::Mat &img)
{
    cv::Mat im2;
    if (img.channels() == 1)
    {

        cvtColor(img, im2, cv::COLOR_GRAY2RGB);
    }
    else if (img.channels() == 4)
    {
        cvtColor(img, im2, cv::COLOR_BGRA2RGB);
    }
    else
    {
        cvtColor(img, im2, cv::COLOR_BGR2RGB);
    }
    long imsize = im2.rows * im2.cols * im2.channels();
    wxImage wx(im2.cols, im2.rows, (unsigned char *)malloc(imsize), false);
    unsigned char *s = im2.data;
    unsigned char *d = wx.GetData();
    for (long i = 0; i < imsize; i++)
    {
        d[i] = s[i];
    }
    return wx;
}
cv::Mat mat_from_wx(wxImage &wx)
{
    cv::Mat im2(cv::Size(wx.GetWidth(), wx.GetHeight()), CV_8UC3, wx.GetData());
    cvtColor(im2, im2, cv::COLOR_RGB2BGR);
    return im2;
}
