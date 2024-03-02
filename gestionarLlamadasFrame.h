#ifndef GESTIONARLLAMADASFRAME_H
#define GESTIONARLLAMADASFRAME_H

//(*Headers(gestionarLlamadasFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)

class gestionarLlamadasFrame: public wxFrame
{
	public:

		gestionarLlamadasFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~gestionarLlamadasFrame();

		//(*Declarations(gestionarLlamadasFrame)
		wxButton* registrarLlamadaBoton;
		wxButton* regresarBoton;
		wxButton* verListaBoton;
		wxPanel* Panel1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticBitmap* StaticBitmap2;
		wxStaticBitmap* StaticBitmap3;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(gestionarLlamadasFrame)
		static const long ID_STATICTEXT1;
		static const long ID_STATICBITMAP1;
		static const long ID_STATICBITMAP2;
		static const long ID_STATICBITMAP3;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(gestionarLlamadasFrame)
		void OnButton3Click(wxCommandEvent& event);
		void OnPanel1Paint(wxPaintEvent& event);
		void OnregistrarLlamadaBotonClick(wxCommandEvent& event);
		void OnverListaBotonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
