#include "../Interfaces/AdjustmentTypesConverter.h"
#include <iostream>
int GetGrayScale(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    return enabled;
}
int GetBrightness(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return 0;
}
double GetContrast(AdjustmentData data)
{
    bool enabled = data.isApplied;
    double value = data.value;
    if (value < 0)
        value = 1.0 / (-1.0 * value);

    if (enabled)
        return value;
    return 0;
}
int GetSaturation(AdjustmentData data)
{
    bool enabled = data.isApplied;
    double value = data.value;
    if (enabled)
        return value;
    return 0;
}
int GetEmboos(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return 0;
}
int GetHue(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return 0;
}
int GetVibarance(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return 0;
}
int GetSharpness(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return 0;
}
int GetBlur(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return 0;
}
int GetNoise(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return 0;
}
int GetPixelate(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return 0;
}
