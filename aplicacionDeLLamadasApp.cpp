/***************************************************************
 * Name:      aplicacionDeLLamadasApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-11-23
 * Copyright:  ()
 * License:
 **************************************************************/

#include "aplicacionDeLLamadasApp.h"

//(*AppHeaders
#include "aplicacionDeLLamadasMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(aplicacionDeLLamadasApp);

bool aplicacionDeLLamadasApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	aplicacionDeLLamadasFrame* Frame = new aplicacionDeLLamadasFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
