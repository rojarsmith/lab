///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/filepicker.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GUI_MainFrame
///////////////////////////////////////////////////////////////////////////////
class GUI_MainFrame : public wxDialog 
{
	private:
	
	protected:
		wxPanel* m_panel1;
		wxStaticText* m_staticText1;
		wxFilePickerCtrl* m_fpFile;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_tcMD5;
		wxStaticLine* m_staticline1;
		wxButton* m_button1;
		wxButton* m_button2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCalculateClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExitClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUI_MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MD5 Calculator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~GUI_MainFrame();
	
};

#endif //__GUI_H__
