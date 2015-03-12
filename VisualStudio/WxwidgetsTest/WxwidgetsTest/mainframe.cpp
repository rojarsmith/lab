#include "mainframe.h"

MainFrame::MainFrame( wxWindow* parent )
:
GUI_MainFrame( parent )
{

}

void MainFrame::OnCalculateClick( wxCommandEvent& event )
{
// TODO: Implement OnCalculateClick
	wxArrayString output;
	wxString command;

	m_tcMD5->Clear();

	if (m_fpFile->GetPath().IsEmpty()){
		return;
	}

	command = wxString(wxT("md5sum ")) + m_fpFile->GetPath();

	
		m_tcMD5->SetValue(command);
	

	if (wxExecute(command, output) == 0){
		m_tcMD5->SetValue(output[0].BeforeFirst(wxChar(' ')));
	}
}

void MainFrame::OnExitClick( wxCommandEvent& event )
{
// TODO: Implement OnExitClick
	Close();
	exit(0);
}
