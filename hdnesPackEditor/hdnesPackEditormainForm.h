#ifndef __hdnesPackEditormainForm__
#define __hdnesPackEditormainForm__

#define COLOUR_CLIENT_ROM_VIEW_BG   0
#define COLOUR_CLIENT_ROM_VIEW_1    1
#define COLOUR_CLIENT_ROM_VIEW_2    2
#define COLOUR_CLIENT_ROM_VIEW_3    3
#define COLOUR_CLIENT_GAME_OBJ_BG   4

#define GAME_OBJ_PNL_PASTE  0
#define GAME_OBJ_PNL_COPY   1
#define GAME_OBJ_PNL_CONFIRM_PASTE  2
#define GAME_OBJ_PNL_CANCEL_PASTE   3

/**
@file
Subclass of mainForm, which is generated by wxFormBuilder.
*/

#include "common.h"
#include "mainForm.h"
#include "colourDialogClient.h"
#include "gameObjNode.h"

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
		void romViewPaletteHexChanged( wxCommandEvent& event );
		void romViewSizeChanged( wxSizeEvent& event );
        void romViewVScrolled( wxScrollEvent& event );
        void romViewHScrolled( wxScrollEvent& event );
		void romViewLDown( wxMouseEvent& event );
		void romViewLUp( wxMouseEvent& event );
		void romViewRUp( wxMouseEvent& event );
		void romViewMove( wxMouseEvent& event );
		void romViewEnter( wxMouseEvent& event );

		void zoomGameObjsChanged( wxSpinEvent& event );
        void gameObjTItemBeginEdit( wxTreeEvent& event );
		void gameObjTItemChangeName( wxTreeEvent& event );
		void gameObjTItemOpenMenu( wxTreeEvent& event );
		void gameObjTItemSelected( wxTreeEvent& event );
        void gameObjsRawRUp( wxMouseEvent& event );
		void gameObjBGColour( wxCommandEvent& event );
		void gameObjsRawMove( wxMouseEvent& event );
		void gameObjsRawEnter( wxMouseEvent& event );
		void gameObjsRawSizeChanged( wxSizeEvent& event );
		void gameObjsRawVScrolled( wxScrollEvent& event );
		void gameObjsRawHScrolled( wxScrollEvent& event );


        void closeWindow( wxCloseEvent& event );
	public:
		/** Constructor */
		hdnesPackEditormainForm( wxWindow* parent );
	//// end generated class members


        //--general session
        string lastDir;
        string romDir;
        string packDir;

        bool notSaved;

        Uint16 colourSelectSource;
        Uint32 tileCnt;

        void initGeneral();
        void configGeneral(string lineHdr, string lineTail);
        void saveCfgGeneral(fstream& inifile);
        void refreshCoreDataDisplay();
        void openColourDialog(Uint16 clientID);
        virtual void colourSelected(Uint8 selectedColour);
        void paintTile(wxImage &img, Uint8* tileData, int x, int y, wxColour c1, wxColour c2, wxColour c3);
        void drawLine(wxImage &img, wxPoint pt, int len, wxColour c, bool hDir);
        void drawRect(wxImage &img, wxPoint pt, wxPoint rectSize, wxColour c);

        void romChanged();
        void dataChanged();
        void dataSaved();
        //--end general session

        //--rom view session
        int romViewColours[4];
        int romViewDisplayRows;
        int romViewDisplayWidth;
        int romViewDisplayHeight;
        int romViewCurrentRow;
        int romViewTileSize;
        wxImage romViewImage;

        //selection
        vector<Uint32> romViewSelectedTiles;
        wxPoint romViewLDownPos;
        wxPoint romViewLCurrPos;
        bool romViewClicked;
        Uint32 rightClickedID;
        int rightClickedTileX;
        int rightClickedTileY;
        wxImage romViewImageWithSelection;
        wxImage romViewImageDisplay;

        void initROMView();
        void configROMView(string lineHdr, string lineTail);
        void saveCfgROMView(fstream& inifile);
        void romViewROMChanged();
        void refreshROMView();
        void drawROMView();
        void drawROMViewSelection();
        void showROMView();
        void romViewPaletteToText();
        void romViewMenu( wxCommandEvent& event );
        //--end rom view session

        //--game objs session
        wxTreeItemId tItmGameObjRoot;
        wxTreeItemId tItmGameObjMenu;
        bool gameObjectTreeWillMove;
        wxTreeItemId tItmGameObjMove;

        int gameObjTileSize;
        wxImage gameObjRawImage;
        wxImage gameObjRawImage2;
        wxImage gameObjRawImageDisplay;
        int gameObjViewCentreX;
        int gameObjViewCentreY;
        int gameObjScrollMinH;
        int gameObjScrollMaxH;
        int gameObjScrollSizeH;
        int gameObjScrollMinV;
        int gameObjScrollMaxV;
        int gameObjScrollSizeV;
        int gameObjRawPasteX;
        int gameObjRawPasteY;
        int gameObjZoom;
        wxColor gameObjBlankColour;
        gameObjNode gameObjPasteData;

        wxPoint gameObjRawCurrPos;


        void initGameObjs();
        void configGameObjs(string lineHdr, string lineTail);
        void saveCfgGameObjs(fstream& inifile);
        void loadGameObjs(fstream& file);
        void loadGameObjItem(fstream& file, wxTreeItemId item);
        void saveGameObjs(fstream& file);
        void saveGameObjItem(fstream& file, wxTreeItemId item);
        void gameObjsROMChanged();
        void gameObjsTreeMenu( wxCommandEvent& event );
        void gameObjsMoveTreeItem(wxTreeItemId item, wxTreeItemId newParent, wxTreeItemId previousItem);
        void gameObjsSetWillMove(wxTreeItemId item);
        void gameObjsCancelWillMove(wxTreeItemId item);
        void gameObjsRawMenu( wxCommandEvent& event );
        bool checkPasteValid(string content);
        void updateGameObjRawMousePosition(wxPoint pos);
        gameObjNode* getGameObjsSelectedObjectTreeNode();

        void refreshGameObj();
        void clearGameObj();
        void drawGameObj();
        void adjustGameObjSize();
        void drawGameObjEdits();
        void drawGameObjPasteTiles();
        void drawGameObjSelection();
        void showGameObj(wxImage& displayImg, int x, int y);
        //--end game objs session

};

#endif // __hdnesPackEditormainForm__
