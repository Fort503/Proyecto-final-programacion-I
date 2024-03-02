#include "nuevoClienteFrame.h"
#include "estructuras.h"
#include <wx/msgdlg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//(*InternalHeaders(llamadasFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>

//(*InternalHeaders(nuevoClienteFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(nuevoClienteFrame)
const long nuevoClienteFrame::ID_STATICBITMAP1 = wxNewId();
const long nuevoClienteFrame::ID_STATICTEXT1 = wxNewId();
const long nuevoClienteFrame::ID_STATICTEXT2 = wxNewId();
const long nuevoClienteFrame::ID_TEXTCTRL1 = wxNewId();
const long nuevoClienteFrame::ID_STATICTEXT3 = wxNewId();
const long nuevoClienteFrame::ID_TEXTCTRL2 = wxNewId();
const long nuevoClienteFrame::ID_BUTTON1 = wxNewId();
const long nuevoClienteFrame::ID_BUTTON2 = wxNewId();
const long nuevoClienteFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(nuevoClienteFrame,wxFrame)
	//(*EventTable(nuevoClienteFrame)
	//*)
END_EVENT_TABLE()

nuevoClienteFrame::nuevoClienteFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(nuevoClienteFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(500,350));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(288,240), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(254,247,255));
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/nuevo-producto.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(72,48), wxSize(64,64), 0, _T("ID_STATICBITMAP1"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Registrar un nuevo cliente"), wxPoint(64,72), wxSize(432,32), wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(17,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Nombre del cliente"), wxPoint(40,144), wxSize(144,19), 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	nombreTextControl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(184,136), wxSize(272,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Numero de telefono"), wxPoint(40,200), wxSize(152,19), 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	numeroTextControl = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(184,192), wxSize(272,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	registrarBoton = new wxButton(Panel1, ID_BUTTON1, _("Registrar Usuario"), wxPoint(40,248), wxSize(200,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	registrarBoton->SetBackgroundColour(wxColour(247,242,250));
	wxFont registrarBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	registrarBoton->SetFont(registrarBotonFont);
	regresarBoton = new wxButton(Panel1, ID_BUTTON2, _("Regresar"), wxPoint(256,248), wxSize(200,40), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	regresarBoton->SetBackgroundColour(wxColour(247,242,250));
	wxFont regresarBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	regresarBoton->SetFont(regresarBotonFont);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nuevoClienteFrame::OnregistrarBotonClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nuevoClienteFrame::OnregresarBotonClick);
	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&nuevoClienteFrame::OnPanel1Paint,0,this);
	//*)
}

nuevoClienteFrame::~nuevoClienteFrame()
{
	//(*Destroy(nuevoClienteFrame)
	//*)
}


void nuevoClienteFrame::OnPanel1Paint(wxPaintEvent& event)
{
}

void nuevoClienteFrame::OnregresarBotonClick(wxCommandEvent& event)
{
    Close();
}

int ultimoCodigoAsignado = 0;

void GuardarUltimoCodigo()
{
    FILE* archivoCodigo = fopen("ultimo_codigo.dat", "wb");
    if (archivoCodigo != NULL) {
        fwrite(&ultimoCodigoAsignado, sizeof(ultimoCodigoAsignado), 1, archivoCodigo);
        fclose(archivoCodigo);
    }
}

void CargarUltimoCodigo()
{
    FILE* archivoCodigo = fopen("ultimo_codigo.dat", "rb");
    if (archivoCodigo != NULL) {
        fread(&ultimoCodigoAsignado, sizeof(ultimoCodigoAsignado), 1, archivoCodigo);
        fclose(archivoCodigo);
    }
}

void nuevoClienteFrame::OnregistrarBotonClick(wxCommandEvent& event)
{
    FILE* arch = fopen("clientes.dat", "ab");
    if (arch == NULL) {
        wxMessageBox("Error al abrir el archivo", "Error", wxOK | wxICON_ERROR);
        return;
    }

    CargarUltimoCodigo();
    ultimoCodigoAsignado++;

    clientes cliente;
    snprintf(cliente.codigo, sizeof(cliente.codigo), "%d", ultimoCodigoAsignado);
    wxStrcpy(cliente.nombre, nombreTextControl->GetValue().ToUTF8());
    wxStrcpy(cliente.numeroDeTelefono, numeroTextControl->GetValue().ToUTF8());

    fwrite(reinterpret_cast<const void*>(&cliente), sizeof(clientes), 1, arch);
    wxMessageBox("Cliente registrado", "Information", wxOK | wxICON_INFORMATION);

    nombreTextControl->Clear();
    numeroTextControl->Clear();

    GuardarUltimoCodigo();

    fclose(arch);
}


