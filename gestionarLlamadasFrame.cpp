#include "gestionarLlamadasFrame.h"
#include "aplicacionDeLLamadasMain.h"
#include "registrarLlamadaFrame.h"
#include "lisaDeLlamadasFrame.h"
#include "listaDeLLamadasFrame.h"
#include "nuevaLlamadaFrame.h"

//(*InternalHeaders(gestionarLlamadasFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(gestionarLlamadasFrame)
const long gestionarLlamadasFrame::ID_STATICTEXT1 = wxNewId();
const long gestionarLlamadasFrame::ID_STATICBITMAP1 = wxNewId();
const long gestionarLlamadasFrame::ID_STATICBITMAP2 = wxNewId();
const long gestionarLlamadasFrame::ID_STATICBITMAP3 = wxNewId();
const long gestionarLlamadasFrame::ID_BUTTON1 = wxNewId();
const long gestionarLlamadasFrame::ID_BUTTON2 = wxNewId();
const long gestionarLlamadasFrame::ID_BUTTON3 = wxNewId();
const long gestionarLlamadasFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(gestionarLlamadasFrame,wxFrame)
	//(*EventTable(gestionarLlamadasFrame)
	//*)
END_EVENT_TABLE()

gestionarLlamadasFrame::gestionarLlamadasFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(gestionarLlamadasFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,400));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(96,144), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(254,247,255));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Gestionar llamadas"), wxPoint(0,0), wxSize(400,32), wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
	StaticText1->SetBackgroundColour(wxColour(243,237,247));
	wxFont StaticText1Font(17,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/nuevo-producto.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(16,104), wxSize(64,64), 0, _T("ID_STATICBITMAP1"));
	StaticBitmap2 = new wxStaticBitmap(Panel1, ID_STATICBITMAP2, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/lista-de-verificacion.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(16,184), wxSize(64,64), 0, _T("ID_STATICBITMAP2"));
	StaticBitmap3 = new wxStaticBitmap(Panel1, ID_STATICBITMAP3, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/salida.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(16,264), wxSize(64,64), 0, _T("ID_STATICBITMAP3"));
	registrarLlamadaBoton = new wxButton(Panel1, ID_BUTTON1, _("Registrar una nueva llamada"), wxPoint(96,128), wxSize(248,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont registrarLlamadaBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	registrarLlamadaBoton->SetFont(registrarLlamadaBotonFont);
	verListaBoton = new wxButton(Panel1, ID_BUTTON2, _("Ver lista de llamadas registradas"), wxPoint(96,200), wxSize(248,35), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	wxFont verListaBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	verListaBoton->SetFont(verListaBotonFont);
	regresarBoton = new wxButton(Panel1, ID_BUTTON3, _("Regresar"), wxPoint(96,272), wxSize(248,35), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	regresarBoton->SetBackgroundColour(wxColour(247,242,250));
	wxFont regresarBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	regresarBoton->SetFont(regresarBotonFont);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gestionarLlamadasFrame::OnregistrarLlamadaBotonClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gestionarLlamadasFrame::OnverListaBotonClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gestionarLlamadasFrame::OnButton3Click);
	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&gestionarLlamadasFrame::OnPanel1Paint,0,this);
	//*)
}

gestionarLlamadasFrame::~gestionarLlamadasFrame()
{
	//(*Destroy(gestionarLlamadasFrame)
	//*)
}


void gestionarLlamadasFrame::OnButton3Click(wxCommandEvent& event)
{
    aplicacionDeLLamadasFrame* mainFrame = new aplicacionDeLLamadasFrame(0);
    mainFrame->Show(true);
    Close();
}

void gestionarLlamadasFrame::OnPanel1Paint(wxPaintEvent& event)
{
}

void gestionarLlamadasFrame::OnregistrarLlamadaBotonClick(wxCommandEvent& event)
{
    nuevaLlamadaFrame* registrarFrame = new nuevaLlamadaFrame(0);
    registrarFrame->Show(true);
}

void gestionarLlamadasFrame::OnverListaBotonClick(wxCommandEvent& event)
{
    listaDeLLamadasFrame* listaFrame = new listaDeLLamadasFrame(0);
    listaFrame->Show(true);
}
