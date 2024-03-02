#include "listaDeLLamadasFrame.h"
#include "wx/msgdlg.h"
#include "estructuras.h"

//(*InternalHeaders(listaDeLLamadasFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(listaDeLLamadasFrame)
const long listaDeLLamadasFrame::ID_STATICBITMAP1 = wxNewId();
const long listaDeLLamadasFrame::ID_STATICTEXT1 = wxNewId();
const long listaDeLLamadasFrame::ID_LISTCTRL1 = wxNewId();
const long listaDeLLamadasFrame::ID_BUTTON1 = wxNewId();
const long listaDeLLamadasFrame::ID_BUTTON2 = wxNewId();
const long listaDeLLamadasFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(listaDeLLamadasFrame,wxFrame)
	//(*EventTable(listaDeLLamadasFrame)
	//*)
END_EVENT_TABLE()

listaDeLLamadasFrame::listaDeLLamadasFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(listaDeLLamadasFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(500,350));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(288,344), wxSize(500,350), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(254,247,255));
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/lista-de-verificacion.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(16,16), wxSize(64,64), 0, _T("ID_STATICBITMAP1"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Ver lista de llamas frame"), wxPoint(80,32), wxSize(272,40), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	listaControl = new wxListCtrl(Panel1, ID_LISTCTRL1, wxPoint(16,96), wxSize(464,176), wxLC_LIST, wxDefaultValidator, _T("ID_LISTCTRL1"));
	cargarBoton = new wxButton(Panel1, ID_BUTTON1, _("Cargar lista"), wxPoint(16,288), wxSize(218,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	regresarBoton = new wxButton(Panel1, ID_BUTTON2, _("Regresar"), wxPoint(264,288), wxSize(218,35), 0, wxDefaultValidator, _T("ID_BUTTON2"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&listaDeLLamadasFrame::OncargarBotonClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&listaDeLLamadasFrame::OnregresarBotonClick);
	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&listaDeLLamadasFrame::OnPanel1Paint,0,this);
	//*)
}

listaDeLLamadasFrame::~listaDeLLamadasFrame()
{
	//(*Destroy(listaDeLLamadasFrame)
	//*)
}


void listaDeLLamadasFrame::OnPanel1Paint(wxPaintEvent& event)
{
}

void listaDeLLamadasFrame::OncargarBotonClick(wxCommandEvent& event)
{
    FILE* arch = fopen("llamadas.dat", "rb");

    if (arch == NULL) {
        wxMessageBox("Error al abrir el archivo", "Error", wxOK | wxICON_ERROR);
    }

    llamadas llamada;

    int index = 0;

    while (fread(&llamada, sizeof(llamada), 1, arch) == 1) {
        wxString codigoCliente = llamada.codigoCliente;
        wxString codigoServicio = llamada.codigoServicio;
        wxString fecha = llamada.fecha;
        wxString hora = llamada.hora;

        wxString item = "Cliente: " + codigoCliente + " | Servicio: " + codigoServicio +  " | fecha: " + fecha +  " | hora: " + hora;

        listaControl->InsertItem(index, item);
        index++;
    }

    fclose(arch);
}

void listaDeLLamadasFrame::OnregresarBotonClick(wxCommandEvent& event)
{
    Close();
}
