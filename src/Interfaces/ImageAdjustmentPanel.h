#include <wx/wx.h>
#include <iostream>
#include "AdjustmentData.h"

#include "Subscriber.h"
#include "../Constants/adjustmentType.h"
#include "ImageAdjustmentsEvent.h"
class ImageAdjustmentPanel : public wxPanel
{

    wxPanel *panel;
    wxSizer *sizer;
    wxSlider *slider;
    wxStaticText *label;
    wxCheckBox *checkBox;
    Subscriber<ImageAdjustmentsEvent> *subscriber;

    AdjustmentType adjustmentsType;

    void OnCheckBox(wxCommandEvent &event);
    void OnSliderChange(wxCommandEvent &event);

    void EmitEvent();

public:
    ImageAdjustmentPanel(wxWindow *parent, Subscriber<ImageAdjustmentsEvent> *mainFrame, std::string label, int sliderMin, int sliderMax, AdjustmentType adjustmentsType);

    AdjustmentData GetValue();
    void SetSliderValue(AdjustmentData);
};
