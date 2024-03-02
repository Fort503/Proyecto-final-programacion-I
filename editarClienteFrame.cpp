#include "editarClienteFrame.h"
#include "estructuras.h"

#include <wx/msgdlg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//(*InternalHeaders(editarClienteFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(editarClienteFrame)
const long editarClienteFrame::ID_STATICTEXT1 = wxNewId();
const long editarClienteFrame::ID_STATICBITMAP1 = wxNewId();
const long editarClienteFrame::ID_SEARCHCTRL1 = wxNewId();
const long editarClienteFrame::ID_STATICTEXT2 = wxNewId();
const long editarClienteFrame::ID_STATICTEXT3 = wxNewId();
const long editarClienteFrame::ID_TEXTCTRL1 = wxNewId();
const long editarClienteFrame::ID_TEXTCTRL2 = wxNewId();
const long editarClienteFrame::ID_BUTTON1 = wxNewId();
const long editarClienteFrame::ID_BUTTON2 = wxNewId();
const long editarClienteFrame::ID_BUTTON3 = wxNewId();
const long editarClienteFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(editarClienteFrame,wxFrame)
	//(*EventTable(editarClienteFrame)
	//*)
END_EVENT_TABLE()

editarClienteFrame::editarClienteFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(editarClienteFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(500,350));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(16,184), wxSize(504,352), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(254,247,255));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Editar datos de un cliente"), wxPoint(88,16), wxSize(280,32), wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(17,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/editar-codigo.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(16,8), wxSize(64,64), 0, _T("ID_STATICBITMAP1"));
	buscarSearchControl = new wxSearchCtrl(Panel1, ID_SEARCHCTRL1, wxEmptyString, wxPoint(48,96), wxSize(312,35), 0, wxDefaultValidator, _T("ID_SEARCHCTRL1"));
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Nombre del cliente"), wxPoint(48,160), wxSize(136,19), 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Numero de telefono"), wxPoint(48,216), wxSize(144,19), 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	nombreTextControl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(192,152), wxSize(264,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	numeroTextControl = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(192,208), wxSize(264,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Editar Informacion"), wxPoint(48,264), wxSize(200,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetBackgroundColour(wxColour(247,242,250));
	wxFont Button1Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);
	regresarBoton = new wxButton(Panel1, ID_BUTTON2, _("Regresar"), wxPoint(256,264), wxSize(200,40), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	regresarBoton->SetBackgroundColour(wxColour(247,242,250));
	Button2 = new wxButton(Panel1, ID_BUTTON3, _("Buscar"), wxPoint(368,96), wxSize(85,32), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button2->SetBackgroundColour(wxColour(247,242,250));
	wxFont Button2Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	Button2->SetFont(Button2Font);

	Connect(ID_SEARCHCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&editarClienteFrame::OnbuscarSearchControlText);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editarClienteFrame::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editarClienteFrame::OnregresarBotonClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editarClienteFrame::OnButton2Click);
	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&editarClienteFrame::OnPanel1Paint,0,this);
	//*)
}

editarClienteFrame::~editarClienteFrame()
{
	//(*Destroy(editarClienteFrame)
	//*)
}

int BuscarUsuarioPorCodigo(const wxString& codigoABuscar, clientes& clienteEncontrado) {
    FILE* arch = fopen("clientes.dat", "rb");
    if (arch == NULL) {
        wxMessageBox("Error al abrir el archivo para buscar", "Error", wxOK | wxICON_ERROR);
        return -1;
    }

    int posicionCliente = 0;
    while (fread(&clienteEncontrado, sizeof(clientes), 1, arch) == 1) {
        if (wxString(clienteEncontrado.codigo) == codigoABuscar || wxString(clienteEncontrado.nombre) == codigoABuscar) {
            fclose(arch);
            return posicionCliente * sizeof(clientes);
        }
        posicionCliente++;
    }

    fclose(arch);
    return -1;

}


void editarClienteFrame::OnregresarBotonClick(wxCommandEvent& event)
{
    Close();
}

void editarClienteFrame::OnPanel1Paint(wxPaintEvent& event)
{
}

void editarClienteFrame::OnButton2Click(wxCommandEvent& event)
{
    wxString codigoABuscar = buscarSearchControl->GetValue();

    clientes clienteEncontrado;

    int posicion = BuscarUsuarioPorCodigo(codigoABuscar, clienteEncontrado);

    if (posicion != -1) {
        nombreTextControl->SetValue(wxString(clienteEncontrado.nombre, wxConvUTF8));
        numeroTextControl->SetValue(wxString(clienteEncontrado.numeroDeTelefono, wxConvUTF8));
    } else {
        wxMessageBox("Usuario no encontrado", "Información", wxOK | wxICON_INFORMATION);
    }
}

void editarClienteFrame::OnbuscarSearchControlText(wxCommandEvent& event)
{
}

void editarClienteFrame::OnButton1Click(wxCommandEvent& event)
{
    wxString codigoABuscar = buscarSearchControl->GetValue();
    clientes clienteEncontrado;

    int posicionCliente = BuscarUsuarioPorCodigo(codigoABuscar, clienteEncontrado);

    if (posicionCliente != -1) {

        wxString codigoABuscar = buscarSearchControl->GetValue();
        clientes clienteEncontrado;

        int posicionCliente = BuscarUsuarioPorCodigo(codigoABuscar, clienteEncontrado);

        if (posicionCliente != -1) {
            wxString nuevoNombre = nombreTextControl->GetValue();
            wxString nuevoNumero = numeroTextControl->GetValue();

            wxStrcpy(clienteEncontrado.nombre, nuevoNombre.ToUTF8());
            wxStrcpy(clienteEncontrado.numeroDeTelefono, nuevoNumero.ToUTF8());

            FILE* arch = fopen("clientes.dat", "r+b");
            if (arch == NULL) {
                wxMessageBox("Error al abrir el archivo para editar", "Error", wxOK | wxICON_ERROR);
                return;
            }

            fseek(arch, posicionCliente, SEEK_SET);

            fwrite(&clienteEncontrado, sizeof(clientes), 1, arch);

            fclose(arch);

            wxMessageBox("Usuario editado exitosamente", "Información", wxOK | wxICON_INFORMATION);
        } else {
            wxMessageBox("Usuario no encontrado", "Información", wxOK | wxICON_INFORMATION);
        }
    }

}
