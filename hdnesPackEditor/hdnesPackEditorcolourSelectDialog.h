#ifndef __hdnesPackEditorcolourSelectDialog__
#define __hdnesPackEditorcolourSelectDialog__

/**
@file
Subclass of colourSelectDialog, which is generated by wxFormBuilder.
*/

#include "mainForm.h"

//// end generated include

/** Implementing colourSelectDialog */
class hdnesPackEditorcolourSelectDialog : public colourSelectDialog
{
	protected:
		// Handlers for colourSelectDialog events.
		void colourSelectInit( wxInitDialogEvent& event );
	public:
		/** Constructor */
		hdnesPackEditorcolourSelectDialog( wxWindow* parent );
	//// end generated class members

        void setSelectedCell(Uint8 index);
};

#endif // __hdnesPackEditorcolourSelectDialog__
