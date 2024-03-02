/***************************************************************
 * Name:      aplicacionDeLLamadasMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2023-11-23
 * Copyright:  ()
 * License:
 **************************************************************/

#include "aplicacionDeLLamadasMain.h"
#include <wx/msgdlg.h>
#include "gestionarClientesFrame.h"
#include "gestionarServiciosFrame.h"
#include "gestionarLlamadasFrame.h"

//(*InternalHeaders(aplicacionDeLLamadasFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(aplicacionDeLLamadasFrame)
const long aplicacionDeLLamadasFrame::ID_STATICTEXT1 = wxNewId();
const long aplicacionDeLLamadasFrame::ID_STATICBITMAP1 = wxNewId();
const long aplicacionDeLLamadasFrame::ID_STATICBITMAP2 = wxNewId();
const long aplicacionDeLLamadasFrame::ID_STATICBITMAP3 = wxNewId();
const long aplicacionDeLLamadasFrame::ID_STATICBITMAP4 = wxNewId();
const long aplicacionDeLLamadasFrame::ID_BUTTON1 = wxNewId();
const long aplicacionDeLLamadasFrame::ID_BUTTON2 = wxNewId();
const long aplicacionDeLLamadasFrame::ID_BUTTON3 = wxNewId();
const long aplicacionDeLLamadasFrame::ID_BUTTON4 = wxNewId();
const long aplicacionDeLLamadasFrame::ID_PANEL1 = wxNewId();
const long aplicacionDeLLamadasFrame::idMenuQuit = wxNewId();
const long aplicacionDeLLamadasFrame::idMenuAbout = wxNewId();
const long aplicacionDeLLamadasFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(aplicacionDeLLamadasFrame,wxFrame)
    //(*EventTable(aplicacionDeLLamadasFrame)
    //*)
END_EVENT_TABLE()

aplicacionDeLLamadasFrame::aplicacionDeLLamadasFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(aplicacionDeLLamadasFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(400,400));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(280,288), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxColour(254,247,255));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Apicacion de gestion de llamadas"), wxPoint(0,0), wxSize(400,35), wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
    StaticText1->SetBackgroundColour(wxColour(243,237,247));
    wxFont StaticText1Font(17,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/kyc.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(24,48), wxSize(64,64), 0, _T("ID_STATICBITMAP1"));
    StaticBitmap2 = new wxStaticBitmap(Panel1, ID_STATICBITMAP2, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/llamada-telefonica(1).png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(24,120), wxSize(64,64), 0, _T("ID_STATICBITMAP2"));
    StaticBitmap3 = new wxStaticBitmap(Panel1, ID_STATICBITMAP3, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/llamada-telefonica.png_")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(24,192), wxSize(64,64), 0, _T("ID_STATICBITMAP3"));
    StaticBitmap4 = new wxStaticBitmap(Panel1, ID_STATICBITMAP4, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/reiniciar.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(24,264), wxSize(64,64), 0, _T("ID_STATICBITMAP4"));
    gestionarClientesBoton = new wxButton(Panel1, ID_BUTTON1, _("Gestionar clientes"), wxPoint(120,64), wxSize(248,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    wxFont gestionarClientesBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
    gestionarClientesBoton->SetFont(gestionarClientesBotonFont);
    gestionarServiciosBoton = new wxButton(Panel1, ID_BUTTON2, _("Gestionar Servicios"), wxPoint(120,136), wxSize(248,35), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    wxFont gestionarServiciosBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
    gestionarServiciosBoton->SetFont(gestionarServiciosBotonFont);
    registrarLLamaBoton = new wxButton(Panel1, ID_BUTTON3, _("Registrar una llamada"), wxPoint(120,208), wxSize(248,35), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    registrarLLamaBoton->SetBackgroundColour(wxColour(247,242,250));
    wxFont registrarLLamaBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
    registrarLLamaBoton->SetFont(registrarLLamaBotonFont);
    reiniciarDatosBoton = new wxButton(Panel1, ID_BUTTON4, _("Reiniciar datos"), wxPoint(120,272), wxSize(248,35), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    reiniciarDatosBoton->SetBackgroundColour(wxColour(247,242,250));
    wxFont reiniciarDatosBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
    reiniciarDatosBoton->SetFont(reiniciarDatosBotonFont);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("Acerca de nosotros\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&aplicacionDeLLamadasFrame::OngestionarClientesBotonClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&aplicacionDeLLamadasFrame::OngestionarServiciosBotonClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&aplicacionDeLLamadasFrame::OnregistrarLLamaBotonClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&aplicacionDeLLamadasFrame::OnreiniciarDatosBotonClick);
    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&aplicacionDeLLamadasFrame::OnPanel1Paint,0,this);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&aplicacionDeLLamadasFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&aplicacionDeLLamadasFrame::OnAbout);
    //*)
}

aplicacionDeLLamadasFrame::~aplicacionDeLLamadasFrame()
{
    //(*Destroy(aplicacionDeLLamadasFrame)
    //*)
}

void aplicacionDeLLamadasFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void aplicacionDeLLamadasFrame::OnAbout(wxCommandEvent& event)
{

    wxMessageBox("Programadores:\nChristopher Briyant Alvarez Moz\nMiguel Steven Flores Arana \nNayeli Madai Guzman Magana\nCarlos Francisco Chavarria Hernandez");
}

void aplicacionDeLLamadasFrame::OnreiniciarDatosBotonClick(wxCommandEvent& event)
{
    FILE *archClientes = fopen("clientes.dat", "wb");
    if (archClientes == NULL) {
        wxMessageBox("error archivo clientes", "Information", wxOK | wxICON_INFORMATION);
    } else {
        wxMessageBox("el archivo de clientes ha sido reiniciado exitosamente", "Información", wxOK | wxICON_INFORMATION);
    }

    FILE *archLlamadas = fopen("llamadas.dat", "wb");
    if (archLlamadas == NULL) {
        wxMessageBox("error archivo llamadas", "Information", wxOK | wxICON_INFORMATION);
    } else {
        wxMessageBox("el archivo de llamadas ha sido reiniciado exitosamente", "Información", wxOK | wxICON_INFORMATION);
    }

    fclose(archClientes);
    fclose(archLlamadas);
}

void aplicacionDeLLamadasFrame::OngestionarClientesBotonClick(wxCommandEvent& event)
{
    gestionarClientesFrame* clientesFrame = new gestionarClientesFrame(0);
    clientesFrame->Show(true);
    Close();
}

void aplicacionDeLLamadasFrame::OnPanel1Paint(wxPaintEvent& event)
{
}

void aplicacionDeLLamadasFrame::OngestionarServiciosBotonClick(wxCommandEvent& event)
{
    gestionarServiciosFrame* serviciosFrame = new gestionarServiciosFrame(0);
    serviciosFrame->Show(true);
    Close();
}

void aplicacionDeLLamadasFrame::OnregistrarLLamaBotonClick(wxCommandEvent& event)
{
    gestionarLlamadasFrame* llamadasFrame = new gestionarLlamadasFrame(0);
    llamadasFrame->Show(true);
    Close();
}
