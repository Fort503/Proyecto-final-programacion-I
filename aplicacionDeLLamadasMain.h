/***************************************************************
 * Name:      aplicacionDeLLamadasMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-11-23
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef APLICACIONDELLAMADASMAIN_H
#define APLICACIONDELLAMADASMAIN_H

//(*Headers(aplicacionDeLLamadasFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)

class aplicacionDeLLamadasFrame: public wxFrame
{
    public:

        aplicacionDeLLamadasFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~aplicacionDeLLamadasFrame();

    private:

        //(*Handlers(aplicacionDeLLamadasFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnreiniciarDatosBotonClick(wxCommandEvent& event);
        void OngestionarClientesBotonClick(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OngestionarServiciosBotonClick(wxCommandEvent& event);
        void OnregistrarLLamaBotonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(aplicacionDeLLamadasFrame)
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
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(aplicacionDeLLamadasFrame)
        wxButton* gestionarClientesBoton;
        wxButton* gestionarServiciosBoton;
        wxButton* registrarLLamaBoton;
        wxButton* reiniciarDatosBoton;
        wxPanel* Panel1;
        wxStaticBitmap* StaticBitmap1;
        wxStaticBitmap* StaticBitmap2;
        wxStaticBitmap* StaticBitmap3;
        wxStaticBitmap* StaticBitmap4;
        wxStaticText* StaticText1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // APLICACIONDELLAMADASMAIN_H
