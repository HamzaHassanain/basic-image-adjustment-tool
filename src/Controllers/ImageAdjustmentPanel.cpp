#include "../Interfaces/ImageAdjustmentPanel.h"
#include "../Interfaces/ImageAdjustmentsEvent.h"

ImageAdjustmentPanel::ImageAdjustmentPanel(wxWindow *parent, Subscriber<ImageAdjustmentsEvent> *sub, std::string label, int sliderMin, int sliderMax, AdjustmentType adjustmentsType) : wxPanel(parent)
{
    this->adjustmentsType = adjustmentsType;
    this->subscriber = sub;

    this->label = new wxStaticText(this, wxID_ANY, label);
    this->slider = new wxSlider(this, wxID_ANY, sliderMin, sliderMin, sliderMax, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS);
    this->checkBox = new wxCheckBox(this, wxID_ANY, "On/Off");

    this->slider->SetValue(0);

    this->sizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *hSizer = new wxBoxSizer(wxHORIZONTAL);
    hSizer->Add(slider, 4, wxEXPAND | wxALL, 5);
    hSizer->Add(checkBox, 1, wxEXPAND | wxALL, 5);

    sizer->Add(this->label, 0, wxEXPAND);
    sizer->Add(hSizer, 0, wxEXPAND);

    this->SetSizerAndFit(sizer);

    slider->Bind(wxEVT_SLIDER, &ImageAdjustmentPanel::OnSliderChange, this);
    checkBox->Bind(wxEVT_CHECKBOX, &ImageAdjustmentPanel::OnCheckBox, this);
}

void ImageAdjustmentPanel::OnCheckBox(wxCommandEvent &event)
{
    EmitEvent();
}
void ImageAdjustmentPanel::OnSliderChange(wxCommandEvent &event)
{
    EmitEvent();
}
void ImageAdjustmentPanel::EmitEvent()
{
    std::cout << "Event emmited" << std::endl;
    ImageAdjustmentsEvent event(this->adjustmentsType, this->GetValue());
    this->subscriber->Notify(event);
}

void ImageAdjustmentPanel::SetSliderValue(AdjustmentData data)
{
    this->slider->SetValue(data.value);
    this->checkBox->SetValue(data.isApplied);
};
AdjustmentData ImageAdjustmentPanel::GetValue()
{

    AdjustmentData data;
    data.isApplied = this->checkBox->GetValue();
    data.value = this->slider->GetValue();
    return data;
}