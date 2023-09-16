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
    return 0;
}
int GetContrast(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return 0;
}
int GetSaturation(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
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
int GetGamma(AdjustmentData data)
{
    bool enabled = data.isApplied;
    int value = data.value;
    if (enabled)
        return value;
    return 0;
}
