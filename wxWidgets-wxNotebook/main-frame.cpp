#include "main-frame.h"
#include <wx/notebook.h>

MainFrame::MainFrame(const wxString &title)
	: wxFrame(nullptr, wxID_ANY, title) {
	CreateStatusBar();

	wxScrolledWindow *scroll1 = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxSize(150, -1));	// left
	//wxScrolledWindow *scroll2 = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 100));	// top
	wxNotebook *notebookMain = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 100));
	wxScrolledWindow *scroll3 = new wxScrolledWindow(this);													// center
	scroll1->SetBackgroundColour(wxColour(10, 20, 20));
	notebookMain->SetBackgroundColour(wxColour(20, 120, 120));
	scroll3->SetBackgroundColour(wxColour(10, 20, 30));

	/*wxNotebook *notebookMain = new wxNotebook(scroll2, wxID_ANY, wxDefaultPosition, wxSize(250, 50));*/
	wxScrolledWindow *note1 = new wxScrolledWindow(notebookMain);
	wxScrolledWindow *note2 = new wxScrolledWindow(notebookMain);
	note1->SetBackgroundColour(wxColour(50, 50, 50));
	note2->SetBackgroundColour(wxColour(10, 10, 10));
	notebookMain->AddPage(note1, "Pitch", true, wxID_ANY);
	notebookMain->AddPage(note2, "Roll", false, wxID_ANY);

	wxBoxSizer *sizerMain = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(notebookMain, 0, wxEXPAND | wxALL);
	sizer->Add(scroll3, 1, wxEXPAND | wxALL);
	sizerMain->Add(scroll1, 0, wxEXPAND | wxALL);
	sizerMain->Add(sizer, 1, wxEXPAND | wxALL);


	this->SetSizer(sizerMain);
	
}
