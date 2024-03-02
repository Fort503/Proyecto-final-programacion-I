#ifndef LISADELLAMADASFRAME_H
#define LISADELLAMADASFRAME_H

//(*Headers(lisaDeLlamadasFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)

class lisaDeLlamadasFrame: public wxFrame
{
	public:

		lisaDeLlamadasFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~lisaDeLlamadasFrame();

		//(*Declarations(lisaDeLlamadasFrame)
		wxButton* cargarBoton;
		wxButton* regresarBoton;
		wxListCtrl* listaLLamadasControl;
		wxPanel* Panel1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(lisaDeLlamadasFrame)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_LISTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(lisaDeLlamadasFrame)
		void OnregresarBotonClick(wxCommandEvent& event);
		void OncargarBotonClick(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
