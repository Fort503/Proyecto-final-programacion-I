#include "gestionarServiciosFrame.h"
#include "aplicacionDeLLamadasMain.h"
#include "listaDeServiciosFrame.h"

//(*InternalHeaders(gestionarServiciosFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(gestionarServiciosFrame)
const long gestionarServiciosFrame::ID_STATICTEXT1 = wxNewId();
const long gestionarServiciosFrame::ID_STATICBITMAP1 = wxNewId();
const long gestionarServiciosFrame::ID_STATICBITMAP2 = wxNewId();
const long gestionarServiciosFrame::ID_BUTTON1 = wxNewId();
const long gestionarServiciosFrame::ID_BUTTON2 = wxNewId();
const long gestionarServiciosFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(gestionarServiciosFrame,wxFrame)
	//(*EventTable(gestionarServiciosFrame)
	//*)
END_EVENT_TABLE()

gestionarServiciosFrame::gestionarServiciosFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(gestionarServiciosFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,400));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(192,208), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(254,247,255));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Gestionar servicios "), wxPoint(0,0), wxSize(400,32), wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
	StaticText1->SetBackgroundColour(wxColour(243,237,247));
	wxFont StaticText1Font(17,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/lista-de-verificacion.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(32,128), wxSize(64,64), 0, _T("ID_STATICBITMAP1"));
	StaticBitmap2 = new wxStaticBitmap(Panel1, ID_STATICBITMAP2, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/salida.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(24,224), wxSize(64,64), 0, _T("ID_STATICBITMAP2"));
	verListaBoton = new wxButton(Panel1, ID_BUTTON1, _("Ver lista de servicios"), wxPoint(112,144), wxSize(248,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont verListaBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	verListaBoton->SetFont(verListaBotonFont);
	regresarBoton = new wxButton(Panel1, ID_BUTTON2, _("Regresar"), wxPoint(112,240), wxSize(248,35), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	regresarBoton->SetBackgroundColour(wxColour(247,242,250));
	wxFont regresarBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	regresarBoton->SetFont(regresarBotonFont);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gestionarServiciosFrame::OnverListaBotonClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gestionarServiciosFrame::OnregresarBotonClick);
	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&gestionarServiciosFrame::OnPanel1Paint,0,this);
	//*)
}

gestionarServiciosFrame::~gestionarServiciosFrame()
{
	//(*Destroy(gestionarServiciosFrame)
	//*)
}


void gestionarServiciosFrame::OnPanel1Paint(wxPaintEvent& event)
{
}

void gestionarServiciosFrame::OnverListaBotonClick(wxCommandEvent& event)
{
    listaDeServiciosFrame* listaFrame = new listaDeServiciosFrame(0);
    listaFrame->Show(true);
}

void gestionarServiciosFrame::OnregresarBotonClick(wxCommandEvent& event)
{
    aplicacionDeLLamadasFrame* mainFrame = new aplicacionDeLLamadasFrame(0);
    mainFrame->Show(true);
    Close();
}
