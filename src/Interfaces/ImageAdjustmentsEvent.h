#pragma once
#include "../Constants/adjustmentType.h"
#include "AdjustmentData.h"
#include <wx/wx.h>

class ImageAdjustmentsEvent
{

public:
    AdjustmentType type;
    AdjustmentData data;
    ImageAdjustmentsEvent(AdjustmentType type, AdjustmentData data);
};
