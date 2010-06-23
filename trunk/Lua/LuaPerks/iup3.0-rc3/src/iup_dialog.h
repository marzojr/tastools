/** \file
 * \brief Dialog Public and Private Declarations
 *
 * See Copyright Notice in "iup.h"
 */
 
#ifndef __IUP_DIALOG_H 
#define __IUP_DIALOG_H

#ifdef __cplusplus
extern "C" {
#endif


/* PUBLIC */

/* Shows the dialog in the given position and disable interaction with other dialogs.
 * The element must be already mapped.
 * Must return IUP_ERROR or IUP_NOERROR.
 * Called only from IupPopup. */
int iupDialogPopup(Ihandle* ih, int x, int y);

/* Shows the dialog in the given position.
 * The dialog must be already mapped.
 * Must return IUP_ERROR or IUP_NOERROR.
 * Called only from IupShow and IupShowXY. */
int iupDialogShowXY(Ihandle* ih, int x, int y);

/* Hides the dialog.
 * Called only from IupHide. */
void iupDialogHide(Ihandle* ih);

/* Returns a unique number to be as child id. */
int iupDialogGetChildId(Ihandle* ih);
char* iupDialogGetChildIdStr(Ihandle* ih);

/* Returns the size of the decoration */
void iupdrvDialogGetDecoration(Ihandle* ih, int *border, int *caption, int *menu);

/* Returns the native parent. Can be PARENTDIALOG or NATIVEPARENT attributes. Parent must be mapped. */
InativeHandle* iupDialogGetNativeParent(Ihandle* ih);

/* Updates the dialog initial position from internal attributes.
   Used mostly by the native pre-defined dialogs. */
void iupDialogUpdatePosition(Ihandle* ih);


/*********************************************************************/
                        /* PRIVATE */
/*********************************************************************/

#ifdef _IUPDLG_PRIVATE

/* retrieve the decorations size that offsets the window size of the client size. */
void iupDialogGetDecorSize(Ihandle* ih, int *decorwidth, int *decorheight);

struct _IcontrolData 
{
  int show_state,     /* save the state to be used used in SHOW_CB */
      first_show,     /* boolean flag to indicate that the dialog was shown for the first time */
      ignore_resize,  /* flag to ignore the next resize */
      popup_level,    /* popup level of the dialog if IupPopup used */
      child_id,       /* serial number used by child controls */
      cmd_show;       /* parameters for ShowWindow in Windows driver */
  Ihandle* menu;
};


/******************************/
/* Driver dependent functions */
/******************************/

void iupdrvDialogInitClass(Iclass* iclass);

void iupdrvDialogGetPosition(InativeHandle* handle, int *x, int *y);
void iupdrvDialogSetVisible(Ihandle* ih, int visible);
int iupdrvDialogSetPlacement(Ihandle* ih);
void iupdrvDialogSetPosition(Ihandle *ih, int x, int y);
void iupdrvDialogUpdateSize(Ihandle* ih);
void iupdrvDialogGetSize(InativeHandle* handle, int *w, int *h);
int iupdrvDialogIsVisible(Ihandle* ih);

#endif

#ifdef __cplusplus
}
#endif

#endif