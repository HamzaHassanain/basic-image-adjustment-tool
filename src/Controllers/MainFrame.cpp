#include "../Interfaces/MainFrame.h"
#include "../Interfaces/ImageAdjustmentsEvent.h"

#include <iostream>

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Simple Photo Editor")
{
    InitalizeComponents();
    InitalizeSizers();
    BindEvents();
}
void MainFrame::InitalizeComponents()
{

    panel = new wxPanel(this, wxID_ANY);
    adjustmentsPanel = new wxScrolled<wxPanel>(panel, wxID_ANY);
    staticBitmap = new BufferedBitmap(panel, wxID_ANY, wxBitmap(wxSize(1, 1)), wxDefaultPosition, FromDIP(wxSize(500, 200)));
    loadImageButton = new wxButton(panel, wxID_ANY, "Load Image");
    saveImageButton = new wxButton(panel, wxID_ANY, "Save Image");
    loadProjectButton = new wxButton(panel, wxID_ANY, "Load Project");
    saveProjectButton = new wxButton(panel, wxID_ANY, "Save Project");
    clearAdjustmentsButton = new wxButton(panel, wxID_ANY, "Clear Adjustments");

    isGrayScalePanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Gray Scale", 0, 0, AdjustmentType::isGrayScale);
    brightnessPanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Brightness", -255, 255, AdjustmentType::brightness);
    contrastPanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Contrast", -100, 100, AdjustmentType::contrast);
    saturationPanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Saturation", -100, 100, AdjustmentType::saturation);
    emboosPanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Emboos", 0, 0, AdjustmentType::emboos);
    huePanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Hue", -100, 100, AdjustmentType::hue);
    vibarancePanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Vibarance", -100, 100, AdjustmentType::vibarance);
    sharpnessPanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Sharpness", -100, 100, AdjustmentType::sharpness);
    blurPanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Blur", 0, 0, AdjustmentType::blur);
    noisePanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Noise", 0, 0, AdjustmentType::noise);
    pixelatePanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Pixelate", 0, 0, AdjustmentType::pixelate);
    gammaPanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Gamma", -100, 100, AdjustmentType::gamma);

    adjustmentsPanel->SetScrollRate(0, FromDIP(10));

    wxSizer *subSizer = new wxBoxSizer(wxVERTICAL);

    mainSizer = new wxBoxSizer(wxVERTICAL);
    panelSizer = new wxBoxSizer(wxHORIZONTAL);
    imageAdjustmentsSizer = new wxBoxSizer(wxVERTICAL);
    buttonsSizer = new wxBoxSizer(wxHORIZONTAL);

    buttonsSizer->Add(loadImageButton, 0, wxEXPAND | wxALL, 5);
    buttonsSizer->Add(saveImageButton, 0, wxEXPAND | wxALL, 5);
    buttonsSizer->Add(loadProjectButton, 0, wxEXPAND | wxALL, 5);
    buttonsSizer->Add(saveProjectButton, 0, wxEXPAND | wxALL, 5);
    buttonsSizer->Add(clearAdjustmentsButton, 0, wxEXPAND | wxALL, 5);

    imageAdjustmentsSizer->Add(isGrayScalePanel, 0, wxEXPAND);
    imageAdjustmentsSizer->Add(brightnessPanel, 0, wxEXPAND);
    imageAdjustmentsSizer->Add(contrastPanel, 0, wxEXPAND);
    imageAdjustmentsSizer->Add(saturationPanel, 0, wxEXPAND);
    imageAdjustmentsSizer->Add(emboosPanel, 0, wxEXPAND);
    imageAdjustmentsSizer->Add(huePanel, 0, wxEXPAND);
    imageAdjustmentsSizer->Add(vibarancePanel, 0, wxEXPAND);
    imageAdjustmentsSizer->Add(sharpnessPanel, 0, wxEXPAND);
    imageAdjustmentsSizer->Add(blurPanel, 0, wxEXPAND);
    imageAdjustmentsSizer->Add(noisePanel, 0, wxEXPAND);
    imageAdjustmentsSizer->Add(pixelatePanel, 0, wxEXPAND);
    imageAdjustmentsSizer->Add(gammaPanel, 0, wxEXPAND);

    subSizer->Add(buttonsSizer, 1, wxALIGN_LEFT, 5);
    subSizer->Add(staticBitmap, 10, wxEXPAND | wxALL, 5);

    panelSizer->Add(adjustmentsPanel, 1, wxEXPAND | wxALL, 5);
    panelSizer->Add(subSizer, 10, wxEXPAND | wxALL, 5);

    mainSizer->Add(panel, 1, wxEXPAND | wxALL, 5);
    adjustmentsPanel->SetSizerAndFit(imageAdjustmentsSizer);
    panel->SetSizerAndFit(panelSizer);
    this->SetSizerAndFit(mainSizer);
}

void MainFrame::BindEvents()
{
    loadImageButton->Bind(wxEVT_BUTTON, &MainFrame::OnLoadImageButtonClick, this);
    saveImageButton->Bind(wxEVT_BUTTON, &MainFrame::OnSaveImageButtonClick, this);
    loadProjectButton->Bind(wxEVT_BUTTON, &MainFrame::OnLoadProjectButtonClick, this);
    saveProjectButton->Bind(wxEVT_BUTTON, &MainFrame::OnSaveProjectButtonClick, this);
    clearAdjustmentsButton->Bind(wxEVT_BUTTON, &MainFrame::OnClearAdjustmentsButtonClick, this);
}
void MainFrame::InitalizeSizers() {}

void MainFrame::Notify(ImageAdjustmentsEvent &event)
{
    std::cout << "Notify" << std::endl;
    OnImageAdjustment(event);
}

void MainFrame::OnImageAdjustment(ImageAdjustmentsEvent &event)
{
    std::cout << "OnImageAdjustment" << std::endl;
}

void MainFrame::OnLoadImageButtonClick(wxCommandEvent &event)
{
    wxFileDialog openFileDialog(this, _("Open Image file"), "", "", ALLOWED_TYPES, wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    wxString filePath = openFileDialog.GetPath();

    loadedImage = wxImage(filePath);

    if (!loadedImage.IsOk())
    {
        wxMessageBox("Failed to load image file", "Error", wxOK | wxICON_ERROR);
        return;
    }

    SetImageData();
}
void MainFrame::OnSaveImageButtonClick(wxCommandEvent &event)
{
}
void MainFrame::OnLoadProjectButtonClick(wxCommandEvent &event)
{
}
void MainFrame::OnSaveProjectButtonClick(wxCommandEvent &event)
{
}
void MainFrame::OnClearAdjustmentsButtonClick(wxCommandEvent &event)
{
}
void MainFrame::SetImageData()
{
    staticBitmap->SetBitmap(wxBitmap(loadedImage));
}
