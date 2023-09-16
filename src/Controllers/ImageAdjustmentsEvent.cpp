#include "../Interfaces/ImageAdjustmentsEvent.h"

ImageAdjustmentsEvent::ImageAdjustmentsEvent(AdjustmentType type, AdjustmentData data)
{
    this->type = type;
    this->data = data;
}