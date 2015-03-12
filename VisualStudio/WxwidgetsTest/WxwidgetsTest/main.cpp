#include "wx/wxprec.h"
#include "mainframe.h" //supplied by the user

class MyApp :public wxApp{
public:
	bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit(){
	MainFrame *frame = new MainFrame(NULL);
	frame->Show();
	return true;
}
