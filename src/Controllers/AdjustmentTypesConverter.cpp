#include "../Interfaces/AdjustmentTypesConverter.h"

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
    return INT_MAX;
}
int GetContrast(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return INT_MAX;
}
int GetSaturation(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return INT_MAX;
}
int GetEmboos(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return INT_MAX;
}
int GetHue(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return INT_MAX;
}
int GetVibarance(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return INT_MAX;
}
int GetSharpness(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return INT_MAX;
}
int GetBlur(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return INT_MAX;
}
int GetNoise(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return INT_MAX;
}
int GetPixelate(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return INT_MAX;
}
int GetGamma(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return INT_MAX;
}
