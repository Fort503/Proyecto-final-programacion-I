#ifndef GESTIONARCLIENTESFRAME_H
#define GESTIONARCLIENTESFRAME_H

//(*Headers(gestionarClientesFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)

class gestionarClientesFrame: public wxFrame
{
	public:

		gestionarClientesFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~gestionarClientesFrame();

		//(*Declarations(gestionarClientesFrame)
		wxButton* editarDatosBoton;
		wxButton* registrarClienteBoton;
		wxButton* regresarBoton;
		wxButton* verListaBoton;
		wxPanel* Panel1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticBitmap* StaticBitmap2;
		wxStaticBitmap* StaticBitmap3;
		wxStaticBitmap* StaticBitmap4;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(gestionarClientesFrame)
		static const long ID_STATICTEXT1;
		static const long ID_STATICBITMAP1;
		static const long ID_STATICBITMAP2;
		static const long ID_STATICBITMAP3;
		static const long ID_STATICBITMAP4;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(gestionarClientesFrame)
		void OnPanel1Paint(wxPaintEvent& event);
		void OnregistrarClienteBotonClick(wxCommandEvent& event);
		void OnregresarBotonClick(wxCommandEvent& event);
		void OnverListaBotonClick(wxCommandEvent& event);
		void OneditarDatosBotonClick(wxCommandEvent& event);
		void OnregresarBotonClick1(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
