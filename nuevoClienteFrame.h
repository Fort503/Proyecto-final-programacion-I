#ifndef NUEVOCLIENTEFRAME_H
#define NUEVOCLIENTEFRAME_H

//(*Headers(nuevoClienteFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class nuevoClienteFrame: public wxFrame
{
	public:

		nuevoClienteFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~nuevoClienteFrame();

		//(*Declarations(nuevoClienteFrame)
		wxButton* registrarBoton;
		wxButton* regresarBoton;
		wxPanel* Panel1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* nombreTextControl;
		wxTextCtrl* numeroTextControl;
		//*)

	protected:

		//(*Identifiers(nuevoClienteFrame)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(nuevoClienteFrame)
		void OnPanel1Paint(wxPaintEvent& event);
		void OnregresarBotonClick(wxCommandEvent& event);
		void OnregistrarBotonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
