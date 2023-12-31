#include <wx/wx.h>
#include "./Interfaces/ImageAdjustmentsEvent.h"

#include "./Interfaces/MainFrame.h"

class App : public wxApp
{
public:
    bool OnInit()
    {
        wxInitAllImageHandlers();

        MainFrame *mainFrame = new MainFrame();
        mainFrame->SetClientSize(1280, 720);
        mainFrame->SetMinSize(wxSize(1280, 720));
        mainFrame->SetPosition(wxPoint(0, 0));
        mainFrame->Show(true);

        return true;
    }
};
wxIMPLEMENT_APP(App);