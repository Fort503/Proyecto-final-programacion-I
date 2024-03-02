#ifndef LISTADELLAMADASFRAME_H
#define LISTADELLAMADASFRAME_H

//(*Headers(listaDeLLamadasFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)

class listaDeLLamadasFrame: public wxFrame
{
	public:

		listaDeLLamadasFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~listaDeLLamadasFrame();

		//(*Declarations(listaDeLLamadasFrame)
		wxButton* cargarBoton;
		wxButton* regresarBoton;
		wxListCtrl* listaControl;
		wxPanel* Panel1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(listaDeLLamadasFrame)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_LISTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(listaDeLLamadasFrame)
		void OnPanel1Paint(wxPaintEvent& event);
		void OncargarBotonClick(wxCommandEvent& event);
		void OnregresarBotonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
