#include "listaDeClientesFrame.h"
#include "estructuras.h"
#include "wx/msgdlg.h"
#include <wx/msgdlg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//(*InternalHeaders(llamadasFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*InternalHeaders(listaDeClientesFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(listaDeClientesFrame)
const long listaDeClientesFrame::ID_STATICBITMAP1 = wxNewId();
const long listaDeClientesFrame::ID_STATICTEXT1 = wxNewId();
const long listaDeClientesFrame::ID_BUTTON1 = wxNewId();
const long listaDeClientesFrame::ID_BUTTON2 = wxNewId();
const long listaDeClientesFrame::ID_LISTCTRL1 = wxNewId();
const long listaDeClientesFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(listaDeClientesFrame,wxFrame)
	//(*EventTable(listaDeClientesFrame)
	//*)
END_EVENT_TABLE()

listaDeClientesFrame::listaDeClientesFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(listaDeClientesFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(500,350));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(312,200), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(254,247,255));
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/lista-de-verificacion.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(32,24), wxSize(64,64), 0, _T("ID_STATICBITMAP1"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Ver lista de clientes registrados"), wxPoint(112,40), wxSize(336,35), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(17,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	cargarBoton = new wxButton(Panel1, ID_BUTTON1, _("Cargar lista"), wxPoint(32,296), wxSize(200,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont cargarBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	cargarBoton->SetFont(cargarBotonFont);
	Button1 = new wxButton(Panel1, ID_BUTTON2, _("Regresar"), wxPoint(264,296), wxSize(200,40), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button1->SetBackgroundColour(wxColour(247,242,250));
	wxFont Button1Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);
	datosListControl = new wxListCtrl(Panel1, ID_LISTCTRL1, wxPoint(32,104), wxSize(432,176), wxLC_LIST, wxDefaultValidator, _T("ID_LISTCTRL1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&listaDeClientesFrame::OncargarBotonClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&listaDeClientesFrame::OnButton1Click);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&listaDeClientesFrame::OndatosListControlBeginDrag);
	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&listaDeClientesFrame::OnPanel1Paint,0,this);
	//*)
}

listaDeClientesFrame::~listaDeClientesFrame()
{
	//(*Destroy(listaDeClientesFrame)
	//*)
}

void listaDeClientesFrame::OnButton1Click(wxCommandEvent& event)
{
    Close();
}

void listaDeClientesFrame::OnPanel1Paint(wxPaintEvent& event)
{
}

void listaDeClientesFrame::OncargarBotonClick(wxCommandEvent& event)
{
    FILE* arch = fopen("clientes.dat", "rb");

    if (arch == NULL) {
        wxMessageBox("Error al abrir el archivo", "Error", wxOK | wxICON_ERROR);
    }

    clientes cliente;

    int index = 0;

    while (fread(&cliente, sizeof(clientes), 1, arch) == 1) {
        wxString codigo = cliente.codigo;
        wxString nombre = cliente.nombre;
        wxString telefono = cliente.numeroDeTelefono;
        wxString item = "Codigo: " + codigo + " | Nombre: " + nombre +  " | Telefono: " + telefono;

        datosListControl->InsertItem(index, item);
        index++;
    }

    fclose(arch);
}

void listaDeClientesFrame::OndatosListBoxSelect(wxCommandEvent& event)
{
}

void listaDeClientesFrame::OndatosListControlBeginDrag(wxListEvent& event)
{
}
