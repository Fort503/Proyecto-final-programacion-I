#ifndef GESTIONARSERVICIOSFRAME_H
#define GESTIONARSERVICIOSFRAME_H

//(*Headers(gestionarServiciosFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)

class gestionarServiciosFrame: public wxFrame
{
	public:

		gestionarServiciosFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~gestionarServiciosFrame();

		//(*Declarations(gestionarServiciosFrame)
		wxButton* regresarBoton;
		wxButton* verListaBoton;
		wxPanel* Panel1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticBitmap* StaticBitmap2;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(gestionarServiciosFrame)
		static const long ID_STATICTEXT1;
		static const long ID_STATICBITMAP1;
		static const long ID_STATICBITMAP2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(gestionarServiciosFrame)
		void OnPanel1Paint(wxPaintEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnverListaBotonClick(wxCommandEvent& event);
		void OnregresarBotonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
