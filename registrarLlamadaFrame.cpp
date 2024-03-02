#include "registrarLlamadaFrame.h"
#include "estructuras.h"
#include "wx/msgdlg.h"
#include <ctime>

using namespace std;

//(*InternalHeaders(registrarLlamadaFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(registrarLlamadaFrame)
const long registrarLlamadaFrame::ID_STATICBITMAP1 = wxNewId();
const long registrarLlamadaFrame::ID_STATICTEXT1 = wxNewId();
const long registrarLlamadaFrame::ID_STATICTEXT2 = wxNewId();
const long registrarLlamadaFrame::ID_STATICTEXT3 = wxNewId();
const long registrarLlamadaFrame::ID_TEXTCTRL1 = wxNewId();
const long registrarLlamadaFrame::ID_COMBOBOX1 = wxNewId();
const long registrarLlamadaFrame::ID_BUTTON1 = wxNewId();
const long registrarLlamadaFrame::ID_BUTTON2 = wxNewId();
const long registrarLlamadaFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(registrarLlamadaFrame,wxFrame)
	//(*EventTable(registrarLlamadaFrame)
	//*)
END_EVENT_TABLE()

registrarLlamadaFrame::registrarLlamadaFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(registrarLlamadaFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(500,350));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(264,176), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(254,247,255));
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/nuevo-producto.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(64,32), wxSize(64,64), 0, _T("ID_STATICBITMAP1"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Registrar nueva llamada"), wxPoint(144,48), wxSize(264,40), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Codigo o nombre del  cliente"), wxPoint(16,136), wxSize(208,24), 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Servicio solicitado"), wxPoint(88,192), wxSize(136,32), 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	usuarioTextControl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(232,128), wxSize(248,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	servicioComboBox = new wxComboBox(Panel1, ID_COMBOBOX1, wxEmptyString, wxPoint(232,184), wxSize(248,35), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	servicioComboBox->SetSelection( servicioComboBox->Append(_("Desarrollo de Software")) );
	servicioComboBox->Append(_("Soporte tecnico"));
	servicioComboBox->Append(_("Consultoria"));
	servicioComboBox->Append(_("Mantenimiento de Software"));
	servicioComboBox->Append(_("Gestion de proyectos"));
	registrarBoton = new wxButton(Panel1, ID_BUTTON1, _("Registrar Llamada"), wxPoint(16,264), wxSize(228,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont registrarBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	registrarBoton->SetFont(registrarBotonFont);
	regresarBoton = new wxButton(Panel1, ID_BUTTON2, _("Regresar"), wxPoint(256,264), wxSize(228,35), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	regresarBoton->SetBackgroundColour(wxColour(247,242,250));
	wxFont regresarBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	regresarBoton->SetFont(regresarBotonFont);

	Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&registrarLlamadaFrame::OnservicioComboBoxSelected);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&registrarLlamadaFrame::OnregistrarBotonClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&registrarLlamadaFrame::OnregresarBotonClick);
	//*)
}

bool BuscarCliente(const wxString& codigo, clientes& clienteEncontrado) {
    FILE* arch = fopen("clientes.dat", "rb");
    if (arch == NULL) {
        wxMessageBox("Error al abrir el archivo", "Error", wxOK | wxICON_ERROR);
        return false;
    }

    bool encontrado = false;

    while (fread(&clienteEncontrado, sizeof(clientes), 1, arch) == 1) {
        if (wxStrcmp(clienteEncontrado.codigo, codigo) == 0 || wxStrcmp(clienteEncontrado.nombre, codigo) == 0) {
            encontrado = true;
            break;
        }
    }

    fclose(arch);

    return encontrado;
}

wxString obtenerCodigoServicio(wxString nombreServicio) {
    if(nombreServicio == "Desarrollo de Software") {
        return "01";
    } else if(nombreServicio == "Soporte tecnico") {
        return "02";
    } else if(nombreServicio == "Consultoria") {
        return "03";
    } else if(nombreServicio == "Mantenimiento de Software") {
        return "04";
    }

    return "05";
}

registrarLlamadaFrame::~registrarLlamadaFrame()
{
	//(*Destroy(registrarLlamadaFrame)
	//*)
}


void registrarLlamadaFrame::OnregresarBotonClick(wxCommandEvent& event)
{
    Close();
}

void registrarLlamadaFrame::OnregistrarBotonClick(wxCommandEvent& event)
{

    wxString codigoABuscar = usuarioTextControl->GetValue();
    clientes clienteABuscar;

    int posicionDelCliente = BuscarCliente(codigoABuscar, clienteABuscar);

    if(posicionDelCliente != -1) {

        FILE* arch = fopen("llamadas.dat", "ab");
        if (arch == NULL) {
            wxMessageBox("Error al abrir el archivo", "Error", wxOK | wxICON_ERROR);
            return;
        }

        wxString servicio = servicioComboBox->GetValue();
        wxString codigoServicio = obtenerCodigoServicio(servicio);

        time_t tiempo = time(0);
        struct tm* tiempoAhora = localtime(&tiempo);

        llamadas llamada;

        strftime(llamada.fecha, sizeof(llamada.fecha), "%d-%m-%Y", tiempoAhora);
        strftime(llamada.hora, sizeof(llamada.hora), "%H:%M:%S", tiempoAhora);
        wxStrcpy(llamada.codigoCliente, clienteABuscar.codigo);
        wxStrcpy(llamada.codigoServicio, codigoServicio);

        fwrite(reinterpret_cast<const void*>(&llamada), sizeof(llamadas), 1, arch);
        wxMessageBox("llamada registrada", "Information", wxOK | wxICON_INFORMATION);

        usuarioTextControl->SetValue("");

        fclose(arch);

    }


//    time_t tiempo = time(0);
//    struct tm* tiempoAhora = localtime(&tiempo);
//
//    llamadas miLlamada;
//
//    char fecha[20];
//
//    strftime(fecha, sizeof(miLlamada.fecha), "%d-%m-%Y", tiempoAhora);
//
//    wxMessageBox(fecha, "Information", wxOK | wxICON_INFORMATION);
}

void registrarLlamadaFrame::OnservicioComboBoxSelected(wxCommandEvent& event)
{

}
