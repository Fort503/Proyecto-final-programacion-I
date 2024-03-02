#ifndef NUEVALLAMADAFRAME_H
#define NUEVALLAMADAFRAME_H

//(*Headers(nuevaLlamadaFrame)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class nuevaLlamadaFrame: public wxFrame
{
	public:

		nuevaLlamadaFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~nuevaLlamadaFrame();

		//(*Declarations(nuevaLlamadaFrame)
		wxButton* RegresarBoton;
		wxButton* guardarLlamadaBoton;
		wxComboBox* servicioCombo;
		wxPanel* Panel1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* clienteTextControl;
		//*)

	protected:

		//(*Identifiers(nuevaLlamadaFrame)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_COMBOBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(nuevaLlamadaFrame)
		void OnPanel1Paint(wxPaintEvent& event);
		void OnguardarLlamadaBotonClick(wxCommandEvent& event);
		void OnRegresarBotonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
