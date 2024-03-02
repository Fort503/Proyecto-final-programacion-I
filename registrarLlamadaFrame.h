#ifndef REGISTRARLLAMADAFRAME_H
#define REGISTRARLLAMADAFRAME_H

//(*Headers(registrarLlamadaFrame)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class registrarLlamadaFrame: public wxFrame
{
	public:

		registrarLlamadaFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~registrarLlamadaFrame();

		//(*Declarations(registrarLlamadaFrame)
		wxButton* registrarBoton;
		wxButton* regresarBoton;
		wxComboBox* servicioComboBox;
		wxPanel* Panel1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* usuarioTextControl;
		//*)

	protected:

		//(*Identifiers(registrarLlamadaFrame)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_COMBOBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(registrarLlamadaFrame)
		void OnregresarBotonClick(wxCommandEvent& event);
		void OnregistrarBotonClick(wxCommandEvent& event);
		void OnservicioComboBoxSelected(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
