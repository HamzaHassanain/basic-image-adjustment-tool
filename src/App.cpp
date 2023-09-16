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
        mainFrame->SetClientSize(800, 600);
        mainFrame->Show(true);

        return true;
    }
};
wxIMPLEMENT_APP(App);