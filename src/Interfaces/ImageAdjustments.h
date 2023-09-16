#pragma once
#include <string>
#include "AdjustmentData.h"
struct ImageAdjustments
{
    std::string image_path;

    AdjustmentData isGrayScale;
    AdjustmentData brightness;
    AdjustmentData contrast;
    AdjustmentData saturation;
    AdjustmentData emboos;
    AdjustmentData hue;
    AdjustmentData vibarance;
    AdjustmentData sharpness;
    AdjustmentData blur;
    AdjustmentData noise;
    AdjustmentData pixelate;
    AdjustmentData gamma;
};
