#ifndef EDITARCLIENTEFRAME_H
#define EDITARCLIENTEFRAME_H

//(*Headers(editarClienteFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/srchctrl.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class editarClienteFrame: public wxFrame
{
	public:

		editarClienteFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~editarClienteFrame();

		//(*Declarations(editarClienteFrame)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* regresarBoton;
		wxPanel* Panel1;
		wxSearchCtrl* buscarSearchControl;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* nombreTextControl;
		wxTextCtrl* numeroTextControl;
		//*)

	protected:

		//(*Identifiers(editarClienteFrame)
		static const long ID_STATICTEXT1;
		static const long ID_STATICBITMAP1;
		static const long ID_SEARCHCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(editarClienteFrame)
		void OnregresarBotonClick(wxCommandEvent& event);
		void OnPanel1Paint(wxPaintEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnbuscarSearchControlText(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
