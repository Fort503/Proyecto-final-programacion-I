#include "gestionarClientesFrame.h"
#include "nuevoClienteFrame.h"
#include "aplicacionDeLLamadasMain.h"
#include "listaDeClientesFrame.h"
#include "editarClienteFrame.h"

//(*InternalHeaders(gestionarClientesFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(gestionarClientesFrame)
const long gestionarClientesFrame::ID_STATICTEXT1 = wxNewId();
const long gestionarClientesFrame::ID_STATICBITMAP1 = wxNewId();
const long gestionarClientesFrame::ID_STATICBITMAP2 = wxNewId();
const long gestionarClientesFrame::ID_STATICBITMAP3 = wxNewId();
const long gestionarClientesFrame::ID_STATICBITMAP4 = wxNewId();
const long gestionarClientesFrame::ID_BUTTON1 = wxNewId();
const long gestionarClientesFrame::ID_BUTTON2 = wxNewId();
const long gestionarClientesFrame::ID_BUTTON3 = wxNewId();
const long gestionarClientesFrame::ID_BUTTON4 = wxNewId();
const long gestionarClientesFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(gestionarClientesFrame,wxFrame)
	//(*EventTable(gestionarClientesFrame)
	//*)
END_EVENT_TABLE()

gestionarClientesFrame::gestionarClientesFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(gestionarClientesFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,400));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(232,256), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(254,247,255));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Gestionar clientes"), wxPoint(0,0), wxSize(400,35), wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
	StaticText1->SetBackgroundColour(wxColour(243,237,247));
	wxFont StaticText1Font(17,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/nuevo-producto.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(16,64), wxSize(64,64), 0, _T("ID_STATICBITMAP1"));
	StaticBitmap2 = new wxStaticBitmap(Panel1, ID_STATICBITMAP2, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/editar-codigo.png")).Rescale(wxSize(64,63).GetWidth(),wxSize(64,63).GetHeight())), wxPoint(24,136), wxSize(64,63), 0, _T("ID_STATICBITMAP2"));
	StaticBitmap3 = new wxStaticBitmap(Panel1, ID_STATICBITMAP3, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/lista-de-verificacion.png")).Rescale(wxSize(64,63).GetWidth(),wxSize(64,63).GetHeight())), wxPoint(24,208), wxSize(64,63), 0, _T("ID_STATICBITMAP3"));
	StaticBitmap4 = new wxStaticBitmap(Panel1, ID_STATICBITMAP4, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/salida.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(16,280), wxSize(64,64), 0, _T("ID_STATICBITMAP4"));
	registrarClienteBoton = new wxButton(Panel1, ID_BUTTON1, _("Registrar nuevo cliente"), wxPoint(96,80), wxSize(248,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont registrarClienteBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	registrarClienteBoton->SetFont(registrarClienteBotonFont);
	editarDatosBoton = new wxButton(Panel1, ID_BUTTON2, _("Editar Datos de un cliente"), wxPoint(96,152), wxSize(248,35), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	wxFont editarDatosBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	editarDatosBoton->SetFont(editarDatosBotonFont);
	verListaBoton = new wxButton(Panel1, ID_BUTTON3, _("Ver lista de clientes"), wxPoint(96,224), wxSize(248,35), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	wxFont verListaBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	verListaBoton->SetFont(verListaBotonFont);
	regresarBoton = new wxButton(Panel1, ID_BUTTON4, _("Regresar"), wxPoint(96,296), wxSize(248,35), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	regresarBoton->SetBackgroundColour(wxColour(247,242,250));
	wxFont regresarBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	regresarBoton->SetFont(regresarBotonFont);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gestionarClientesFrame::OnregistrarClienteBotonClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gestionarClientesFrame::OneditarDatosBotonClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gestionarClientesFrame::OnverListaBotonClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gestionarClientesFrame::OnregresarBotonClick1);
	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&gestionarClientesFrame::OnPanel1Paint,0,this);
	//*)
}

gestionarClientesFrame::~gestionarClientesFrame()
{
	//(*Destroy(gestionarClientesFrame)
	//*)
}


void gestionarClientesFrame::OnPanel1Paint(wxPaintEvent& event)
{
}

void gestionarClientesFrame::OnregistrarClienteBotonClick(wxCommandEvent& event)
{
    nuevoClienteFrame* nuevoFrame = new nuevoClienteFrame(0);
    nuevoFrame->Show(true);
}

void gestionarClientesFrame::OnregresarBotonClick(wxCommandEvent& event)
{

}

void gestionarClientesFrame::OnverListaBotonClick(wxCommandEvent& event)
{
    listaDeClientesFrame* listaFrame = new listaDeClientesFrame(0);
    listaFrame->Show(true);
}

void gestionarClientesFrame::OneditarDatosBotonClick(wxCommandEvent& event)
{
    editarClienteFrame* editarFrame = new editarClienteFrame(0);
    editarFrame->Show(true);
}

void gestionarClientesFrame::OnregresarBotonClick1(wxCommandEvent& event)
{
    aplicacionDeLLamadasFrame* mainFrame = new aplicacionDeLLamadasFrame(0);
    mainFrame->Show(true);
    Close();
}
