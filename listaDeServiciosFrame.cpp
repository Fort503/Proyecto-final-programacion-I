#include "listaDeServiciosFrame.h"

//(*InternalHeaders(listaDeServiciosFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(listaDeServiciosFrame)
const long listaDeServiciosFrame::ID_STATICTEXT1 = wxNewId();
const long listaDeServiciosFrame::ID_STATICBITMAP1 = wxNewId();
const long listaDeServiciosFrame::ID_STATICTEXT2 = wxNewId();
const long listaDeServiciosFrame::ID_STATICBITMAP2 = wxNewId();
const long listaDeServiciosFrame::ID_BUTTON1 = wxNewId();
const long listaDeServiciosFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(listaDeServiciosFrame,wxFrame)
	//(*EventTable(listaDeServiciosFrame)
	//*)
END_EVENT_TABLE()

listaDeServiciosFrame::listaDeServiciosFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(listaDeServiciosFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(500,350));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(320,248), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(254,247,255));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Lista de Servicios ofrecidos"), wxPoint(128,48), wxSize(304,40), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/lista-de-verificacion.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(40,32), wxSize(64,64), 0, _T("ID_STATICBITMAP1"));
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Codigo: 01| Servicio: Desarrollo de Software\nCodigo: 02| Servicio: Soporte tecnico\nCodigo: 03| Servicio: Consultoria\nCodigo: 04| Servicio: Mantenimiento de software\nCodigo: 05| Servicio: Gestion de proyectos\n"), wxPoint(48,112), wxSize(392,112), 0, _T("ID_STATICTEXT2"));
	StaticText2->SetBackgroundColour(wxColour(255,255,255));
	wxFont StaticText2Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticBitmap2 = new wxStaticBitmap(Panel1, ID_STATICBITMAP2, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/salida.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(56,248), wxSize(64,64), 0, _T("ID_STATICBITMAP2"));
	regresarBoton = new wxButton(Panel1, ID_BUTTON1, _("Regresar"), wxPoint(144,264), wxSize(296,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	regresarBoton->SetBackgroundColour(wxColour(247,242,250));
	wxFont regresarBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	regresarBoton->SetFont(regresarBotonFont);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&listaDeServiciosFrame::OnregresarBotonClick);
	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&listaDeServiciosFrame::OnPanel1Paint,0,this);
	//*)
}

listaDeServiciosFrame::~listaDeServiciosFrame()
{
	//(*Destroy(listaDeServiciosFrame)
	//*)
}


void listaDeServiciosFrame::OnPanel1Paint(wxPaintEvent& event)
{
}

void listaDeServiciosFrame::OnregresarBotonClick(wxCommandEvent& event)
{
    Close();
}
