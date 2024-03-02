#ifndef LISTADECLIENTESFRAME_H
#define LISTADECLIENTESFRAME_H

//(*Headers(listaDeClientesFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)

class listaDeClientesFrame: public wxFrame
{
	public:

		listaDeClientesFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~listaDeClientesFrame();

		//(*Declarations(listaDeClientesFrame)
		wxButton* Button1;
		wxButton* cargarBoton;
		wxListCtrl* datosListControl;
		wxPanel* Panel1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(listaDeClientesFrame)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_LISTCTRL1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(listaDeClientesFrame)
		void OnButton1Click(wxCommandEvent& event);
		void OnPanel1Paint(wxPaintEvent& event);
		void OncargarBotonClick(wxCommandEvent& event);
		void OndatosListBoxSelect(wxCommandEvent& event);
		void OndatosListControlBeginDrag(wxListEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
