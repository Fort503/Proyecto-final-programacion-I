#include "nuevaLlamadaFrame.h"
#include "estructuras.h"
#include "wx/msgdlg.h"
#include <ctime>

//(*InternalHeaders(nuevaLlamadaFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(nuevaLlamadaFrame)
const long nuevaLlamadaFrame::ID_STATICBITMAP1 = wxNewId();
const long nuevaLlamadaFrame::ID_STATICTEXT1 = wxNewId();
const long nuevaLlamadaFrame::ID_STATICTEXT2 = wxNewId();
const long nuevaLlamadaFrame::ID_TEXTCTRL1 = wxNewId();
const long nuevaLlamadaFrame::ID_STATICTEXT3 = wxNewId();
const long nuevaLlamadaFrame::ID_COMBOBOX1 = wxNewId();
const long nuevaLlamadaFrame::ID_BUTTON1 = wxNewId();
const long nuevaLlamadaFrame::ID_BUTTON2 = wxNewId();
const long nuevaLlamadaFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(nuevaLlamadaFrame,wxFrame)
	//(*EventTable(nuevaLlamadaFrame)
	//*)
END_EVENT_TABLE()

nuevaLlamadaFrame::nuevaLlamadaFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(nuevaLlamadaFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(500,350));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(224,216), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(254,247,255));
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/nuevo-producto.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(64,16), wxSize(64,64), 0, _T("ID_STATICBITMAP1"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Registrar una llamada"), wxPoint(136,32), wxSize(240,40), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Nombre o codigo del cliente:"), wxPoint(16,112), wxSize(200,19), 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	clienteTextControl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(232,104), wxSize(248,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Servicio de la llamada: "), wxPoint(48,184), wxSize(160,19), 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	servicioCombo = new wxComboBox(Panel1, ID_COMBOBOX1, wxEmptyString, wxPoint(232,176), wxSize(248,35), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	servicioCombo->Append(_("Desarrollo de Software"));
	servicioCombo->Append(_("Soporte tecnico"));
	servicioCombo->Append(_("Consultoria"));
	servicioCombo->Append(_("Mantenimiento de Software"));
	servicioCombo->Append(_("Gestion de proyectos"));
	guardarLlamadaBoton = new wxButton(Panel1, ID_BUTTON1, _("Guardar llamada"), wxPoint(16,240), wxSize(218,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont guardarLlamadaBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	guardarLlamadaBoton->SetFont(guardarLlamadaBotonFont);
	RegresarBoton = new wxButton(Panel1, ID_BUTTON2, _("Regresar"), wxPoint(264,240), wxSize(218,35), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	RegresarBoton->SetBackgroundColour(wxColour(247,242,250));
	wxFont RegresarBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	RegresarBoton->SetFont(RegresarBotonFont);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nuevaLlamadaFrame::OnguardarLlamadaBotonClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nuevaLlamadaFrame::OnRegresarBotonClick);
	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&nuevaLlamadaFrame::OnPanel1Paint,0,this);
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

nuevaLlamadaFrame::~nuevaLlamadaFrame()
{
	//(*Destroy(nuevaLlamadaFrame)
	//*)
}


void nuevaLlamadaFrame::OnPanel1Paint(wxPaintEvent& event)
{
}

void nuevaLlamadaFrame::OnguardarLlamadaBotonClick(wxCommandEvent& event)
{
    wxString codigoABuscar = clienteTextControl->GetValue();
    clientes clienteABuscar;

    int posicionDelCliente = BuscarCliente(codigoABuscar, clienteABuscar);

    if(posicionDelCliente != -1) {

        FILE* arch = fopen("llamadas.dat", "ab");
        if (arch == NULL) {
            wxMessageBox("Error al abrir el archivo", "Error", wxOK | wxICON_ERROR);
            return;
        }

        wxString servicio = servicioCombo->GetValue();
        wxString codigoServicio = obtenerCodigoServicio(servicio);

        time_t tiempo = time(0);
        struct tm* tiempoAhora = localtime(&tiempo);

        llamadas llamada;

        strftime(llamada.fecha, sizeof(llamada.fecha), "%d-%m-%Y", tiempoAhora);
        strftime(llamada.hora, sizeof(llamada.hora), "%H:%M:%S", tiempoAhora);
        wxStrcpy(llamada.codigoCliente, clienteABuscar.codigo);
        wxStrcpy(llamada.codigoServicio, codigoServicio);

        fwrite(reinterpret_cast<const void*>(&llamada), sizeof(llamadas), 1, arch);
        wxMessageBox("Llamada registrada", "Information", wxOK | wxICON_INFORMATION);

        clienteTextControl->SetValue("");

        fclose(arch);
}

}

void nuevaLlamadaFrame::OnRegresarBotonClick(wxCommandEvent& event)
{
    Close();
}
