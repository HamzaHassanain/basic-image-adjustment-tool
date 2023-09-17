#include "../Interfaces/MainFrame.h"
#include "../Interfaces/ImageAdjustmentsEvent.h"
#include "../Interfaces/AdjustmentTypesConverter.h"
#include "../Utils/cv-wx-converter.h"
#include "../Utils/ImageUtils.h"
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
    staticBitmap = new wxStaticBitmap(panel, wxID_ANY, wxBitmap(wxSize(1, 1)));
    loadImageButton = new wxButton(panel, wxID_ANY, "Load Image");
    saveImageButton = new wxButton(panel, wxID_ANY, "Save Image");
    loadProjectButton = new wxButton(panel, wxID_ANY, "Load Project");
    saveProjectButton = new wxButton(panel, wxID_ANY, "Save Project");
    clearAdjustmentsButton = new wxButton(panel, wxID_ANY, "Clear Adjustments");

    isGrayScalePanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Gray Scale", 0, 0, AdjustmentType::isGrayScale);
    brightnessPanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Brightness", -255, 255, AdjustmentType::brightness);
    contrastPanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Contrast", -4, 4, AdjustmentType::contrast);
    huePanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Hue", -255, 255, AdjustmentType::hue);
    saturationPanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Saturation", -255, 255, AdjustmentType::saturation);
    vibarancePanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Vibarance", -255, 255, AdjustmentType::vibarance);
    emboosPanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Emboos", 0, 3, AdjustmentType::emboos);
    sharpnessPanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Sharpness", 0, 2, AdjustmentType::sharpness);
    blurPanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Blur", 0, 10, AdjustmentType::blur);
    noisePanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Noise", 0, 200, AdjustmentType::noise);
    pixelatePanel = new ImageAdjustmentPanel(adjustmentsPanel, this, "Pixelate", 0, 200, AdjustmentType::pixelate);

    adjustmentsPanel->SetScrollRate(0, FromDIP(10));
}

void MainFrame::BindEvents()
{
    loadImageButton->Bind(wxEVT_BUTTON, &MainFrame::OnLoadImageButtonClick, this);
    saveImageButton->Bind(wxEVT_BUTTON, &MainFrame::OnSaveImageButtonClick, this);
    loadProjectButton->Bind(wxEVT_BUTTON, &MainFrame::OnLoadProjectButtonClick, this);
    saveProjectButton->Bind(wxEVT_BUTTON, &MainFrame::OnSaveProjectButtonClick, this);
    clearAdjustmentsButton->Bind(wxEVT_BUTTON, &MainFrame::OnClearAdjustmentsButtonClick, this);
}
void MainFrame::InitalizeSizers()
{
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
    imageAdjustmentsSizer->Add(brightnessPanel, 0, wxEXPAND | wxTOP, FromDIP(25));
    imageAdjustmentsSizer->Add(contrastPanel, 0, wxEXPAND | wxTOP, FromDIP(25));
    imageAdjustmentsSizer->Add(huePanel, 0, wxEXPAND | wxTOP, FromDIP(25));
    imageAdjustmentsSizer->Add(saturationPanel, 0, wxEXPAND | wxTOP, FromDIP(25));
    imageAdjustmentsSizer->Add(vibarancePanel, 0, wxEXPAND | wxTOP, FromDIP(25));
    imageAdjustmentsSizer->Add(emboosPanel, 0, wxEXPAND | wxTOP, FromDIP(25));
    imageAdjustmentsSizer->Add(sharpnessPanel, 0, wxEXPAND | wxTOP, FromDIP(25));
    imageAdjustmentsSizer->Add(blurPanel, 0, wxEXPAND | wxTOP, FromDIP(25));
    imageAdjustmentsSizer->Add(noisePanel, 0, wxEXPAND | wxTOP, FromDIP(25));
    imageAdjustmentsSizer->Add(pixelatePanel, 0, wxEXPAND | wxTOP, FromDIP(25));

    subSizer->Add(buttonsSizer, 1, wxALIGN_RIGHT);
    subSizer->Add(staticBitmap, 10, wxEXPAND);

    panelSizer->Add(adjustmentsPanel, 1, wxEXPAND);
    panelSizer->Add(subSizer, 10, wxEXPAND);

    mainSizer->Add(panel, 1, wxEXPAND);
    adjustmentsPanel->SetSizerAndFit(imageAdjustmentsSizer);
    panel->SetSizerAndFit(panelSizer);
    this->SetSizerAndFit(mainSizer);
}

void MainFrame::Notify(ImageAdjustmentsEvent &event)
{
    OnImageAdjustment(event);
}

void MainFrame::OnImageAdjustment(ImageAdjustmentsEvent &event)
{
    AdjustmentType type = event.type;
    AdjustmentData data = event.data;

    imageData[type] = data;

    SetImageData();
}

void MainFrame::OnLoadImageButtonClick(wxCommandEvent &event)
{
    wxFileDialog openFileDialog(this, _("Open Image file"), "", "", ALLOWED_TYPES, wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    wxString filePath = openFileDialog.GetPath();

    loadedImage = wxImage(filePath);
    curImagePath = filePath.ToStdString();

    if (!loadedImage.IsOk())
    {
        wxMessageBox("Failed to load image file", "Error", wxOK | wxICON_ERROR);
        return;
    }

    SetImageData();
}
void MainFrame::OnSaveImageButtonClick(wxCommandEvent &event)
{
    if (!displayImage.IsOk())
        return;

    wxFileDialog saveFileDialog(this, _("Save Image file"), "", "", ALLOWED_TYPES, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;

    wxString filePath = saveFileDialog.GetPath();
    displayImage.SaveFile(filePath);
}
void MainFrame::OnLoadProjectButtonClick(wxCommandEvent &event)
{
    wxFileDialog openFileDialog(this, _("Open Project file"), "", "", PROJECT_FILE_TYPE, wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    wxString filePath = openFileDialog.GetPath();
    std::string path = filePath.ToStdString();

    std::pair<std::string, std::map<AdjustmentType, AdjustmentData>> readData = DataController::Read(path);

    loadedImage = wxImage(readData.first);

    imageData = readData.second;
    curImagePath = readData.first;

    ResetSliders();

    SetImageData();
}
void MainFrame::OnSaveProjectButtonClick(wxCommandEvent &event)
{
    wxFileDialog saveFileDialog(this, _("Save Project file"), "", "", "Project Files (*.prj)|*.prj", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;

    wxString filePath = saveFileDialog.GetPath();
    std::string path = filePath.ToStdString();

    std::string end = path.substr(path.find_last_of(".") + 1);
    if (end != "prj")
    {
        filePath += ".prj";
        path += ".prj";
    }
    DataController::Write(path, imageData, curImagePath);
}
void MainFrame::OnClearAdjustmentsButtonClick(wxCommandEvent &event)
{
    imageData.clear();
    ResetSliders();
    SetImageData();
}
void MainFrame::SetImageData()
{
    if (!loadedImage.IsOk())
        return;

    int grayScale = GetGrayScale(imageData[AdjustmentType::isGrayScale]);
    int brightness = GetBrightness(imageData[AdjustmentType::brightness]);
    int blur = GetBlur(imageData[AdjustmentType::blur]);
    double contrast = GetContrast(imageData[AdjustmentType::contrast]);
    int saturation = GetSaturation(imageData[AdjustmentType::saturation]);
    int emboos = GetEmboos(imageData[AdjustmentType::emboos]);
    int hue = GetHue(imageData[AdjustmentType::hue]);
    int vibarance = GetVibarance(imageData[AdjustmentType::vibarance]);
    int sharpness = GetSharpness(imageData[AdjustmentType::sharpness]);
    int noise = GetNoise(imageData[AdjustmentType::noise]);
    int pixelate = GetPixelate(imageData[AdjustmentType::pixelate]);

    displayImage = loadedImage.Copy();
    try
    {

        cv::Mat mat = mat_from_wx(displayImage);

        if (grayScale)
            ApplayGrayScale(mat);
        if (brightness)
            ApplayBrightness(mat, brightness);
        if (blur)
            ApplayBlur(mat, blur);
        if (contrast)
            ApplayContrast(mat, contrast);
        if (hue)
            ApplayHue(mat, hue);
        if (saturation)
            ApplaySaturation(mat, saturation);
        if (vibarance)
            ApplayVibarance(mat, vibarance);
        if (emboos)
            ApplayEmboos(mat, emboos);
        if (sharpness)
            ApplaySharpness(mat, sharpness);
        if (noise)
            ApplayNoise(mat, noise);
        if (pixelate)
            ApplayPixlate(mat, pixelate);
        if (noise)
            ApplayNoise(mat, noise);

        displayImage = wx_from_mat(mat);
    }
    catch (cv::Exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    DisplayImage();
}

void MainFrame::DisplayImage()
{
    if (!displayImage.IsOk())
        return;

    staticBitmap->SetBitmap(wxBitmap(displayImage));

    staticBitmap->Refresh();
    this->Layout();
    this->Refresh();
}

void MainFrame::ResetSliders()
{
    isGrayScalePanel->SetSliderValue(imageData[AdjustmentType::isGrayScale]);
    brightnessPanel->SetSliderValue(imageData[AdjustmentType::brightness]);
    contrastPanel->SetSliderValue(imageData[AdjustmentType::contrast]);
    saturationPanel->SetSliderValue(imageData[AdjustmentType::saturation]);
    emboosPanel->SetSliderValue(imageData[AdjustmentType::emboos]);
    huePanel->SetSliderValue(imageData[AdjustmentType::hue]);
    vibarancePanel->SetSliderValue(imageData[AdjustmentType::vibarance]);
    sharpnessPanel->SetSliderValue(imageData[AdjustmentType::sharpness]);
    blurPanel->SetSliderValue(imageData[AdjustmentType::blur]);
    noisePanel->SetSliderValue(imageData[AdjustmentType::noise]);
    pixelatePanel->SetSliderValue(imageData[AdjustmentType::pixelate]);
}