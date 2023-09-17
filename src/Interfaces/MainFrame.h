#include <wx/wx.h>
#include <wx/colordlg.h>
#include <wx/fontdlg.h>
#include "ImageAdjustmentPanel.h"
#include "ImageAdjustmentsEvent.h"
#include "ImageAdjustments.h"
#include "../Utils/bufferedbitmap.h"
#include "../Utils/DataController.h"
#include <map>
#include "Subscriber.h"
const std::string ALLOWED_TYPES = "Image Files (*.png;*.jpg;*.jpeg;*.bmp)|*.png;*.jpg;*.jpeg;*.bmp";
const std::string PROJECT_FILE_TYPE = "Project Files (*.prj)|*.prj";
class MainFrame : Subscriber<ImageAdjustmentsEvent>, public wxFrame
{
    std::map<AdjustmentType, AdjustmentData> imageData;

    wxImage loadedImage;
    wxImage displayImage;
    std::string curImagePath;
    BufferedBitmap *staticBitmap;

    wxPanel *panel;
    wxScrolled<wxPanel> *adjustmentsPanel;

    wxButton *loadImageButton;
    wxButton *saveImageButton;
    wxButton *loadProjectButton;
    wxButton *saveProjectButton;
    wxButton *clearAdjustmentsButton;

    wxButton *zoomInButton;
    wxButton *zoomOutButton;

    wxSizer *mainSizer;
    wxSizer *panelSizer;
    wxSizer *imageAdjustmentsSizer;
    wxSizer *buttonsSizer;

    ImageAdjustmentPanel *isGrayScalePanel;
    ImageAdjustmentPanel *brightnessPanel;
    ImageAdjustmentPanel *contrastPanel;
    ImageAdjustmentPanel *saturationPanel;
    ImageAdjustmentPanel *emboosPanel;
    ImageAdjustmentPanel *huePanel;
    ImageAdjustmentPanel *vibarancePanel;
    ImageAdjustmentPanel *sharpnessPanel;
    ImageAdjustmentPanel *blurPanel;
    ImageAdjustmentPanel *noisePanel;
    ImageAdjustmentPanel *pixelatePanel;

    void InitalizeComponents();
    void InitalizeSizers();
    void BindEvents();

    void OnLoadImageButtonClick(wxCommandEvent &event);
    void OnSaveImageButtonClick(wxCommandEvent &event);
    void OnLoadProjectButtonClick(wxCommandEvent &event);
    void OnSaveProjectButtonClick(wxCommandEvent &event);
    void OnClearAdjustmentsButtonClick(wxCommandEvent &event);
    void OnImageAdjustment(ImageAdjustmentsEvent &event);
    void OnZoomInButtonClick(wxCommandEvent &event);
    void OnZoomOutButtonClick(wxCommandEvent &event);

    void SetImageData();
    void DisplayImage();

    void ResetSliders();

public:
    MainFrame();
    void Notify(ImageAdjustmentsEvent &event);
};
