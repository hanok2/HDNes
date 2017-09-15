#ifndef __hdnesPackEditormainForm__
#define __hdnesPackEditormainForm__

#define COLOUR_CLIENT_ROM_VIEW_BG   0
#define COLOUR_CLIENT_ROM_VIEW_1    1
#define COLOUR_CLIENT_ROM_VIEW_2    2
#define COLOUR_CLIENT_ROM_VIEW_3    3

/**
@file
Subclass of mainForm, which is generated by wxFormBuilder.
*/

#include "common.h"
#include "mainForm.h"
#include "colourDialogClient.h"

//// end generated include

/** Implementing mainForm */
class hdnesPackEditormainForm : public mainForm, public colourDialogClient
{
	protected:
		// Handlers for mainForm events.
		void MenuFileNew( wxCommandEvent& event );
		void MenuFileOpen( wxCommandEvent& event );
		void MenuFileSave( wxCommandEvent& event );
		void MenuFileSaveAs( wxCommandEvent& event );
		void MenuFileGen( wxCommandEvent& event );
		void MenuFileExit( wxCommandEvent& event );
		void zoomRomChanged( wxSpinEvent& event );
		void romBGColour( wxCommandEvent& event );
		void romColour1( wxCommandEvent& event );
		void romColour2( wxCommandEvent& event );
		void romColour3( wxCommandEvent& event );
		void rowViewSizeChanged( wxSizeEvent& event );
        void romViewVScrolled( wxScrollEvent& event );
        void romViewHScrolled( wxScrollEvent& event );
        void closeWindow( wxCloseEvent& event );
	public:
		/** Constructor */
		hdnesPackEditormainForm( wxWindow* parent );
	//// end generated class members


        string lastDir;
        string romDir;
        string packDir;

        Uint16 colourSelectSource;
        Uint32 tileCnt;

        Uint8 romViewColours[4];
        int romViewDisplayWidth;
        int romViewDisplayHeight;

        void refreshCoreDataDisplay();
        void refreshROMView();
        void drawROMView();
        void openColourDialog(Uint16 clientID);
        virtual void colourSelected(Uint8 selectedColour);
        void paintTile(wxImage &img, Uint8* tileData, Uint16 x, Uint16 y, wxColour cBG, wxColour c1, wxColour c2, wxColour c3);
};

#endif // __hdnesPackEditormainForm__
