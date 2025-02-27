#include <wx/wx.h>
#include <wx/button.h>

class ChessApp : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(ChessApp);

class MainFrame : public wxFrame
{
public:
    MainFrame();

private:
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxButton* board[9][9];
};

enum
{
    ID_Hello = 1
};

bool ChessApp::OnInit()
{
    MainFrame* frame = new MainFrame();
    frame->Show(true);
    return true;
}

MainFrame::MainFrame()
    : wxFrame(nullptr, wxID_ANY, "The Chess", wxDefaultPosition, wxSize(800, 600))
{
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to play chess!");

    //TODO:∆Â≈Ã
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            board[i][j] = new wxButton(this, wxID_ANY, wxEmptyString, wxPoint(i * 50, j * 50), wxSize(50, 50));
        }
    }

    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a chess GUI",
        "About the Chess", wxOK | wxICON_INFORMATION);
}