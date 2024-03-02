#ifndef LISTADESERVICIOSFRAME_H
#define LISTADESERVICIOSFRAME_H

//(*Headers(listaDeServiciosFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)

class listaDeServiciosFrame: public wxFrame
{
	public:

		listaDeServiciosFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~listaDeServiciosFrame();

		//(*Declarations(listaDeServiciosFrame)
		wxButton* regresarBoton;
		wxPanel* Panel1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticBitmap* StaticBitmap2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		//*)

	protected:

		//(*Identifiers(listaDeServiciosFrame)
		static const long ID_STATICTEXT1;
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICBITMAP2;
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(listaDeServiciosFrame)
		void OnPanel1Paint(wxPaintEvent& event);
		void OnregresarBotonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
