/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.44                          *
*        Compiled Nov 10 2017, 08:53:57                              *
*        (c) 2017 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
#include "pub_array.c"
#include <stdlib.h>
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0 (GUI_ID_USER + 0x00)
#define ID_TEXT_0 (GUI_ID_USER + 0x01)
#define ID_TEXT_1 (GUI_ID_USER + 0x02)
#define ID_TEXT_2 (GUI_ID_USER + 0x03)


// USER START (Optionally insert additional defines)
WM_HWIN hWin_;
WM_HWIN hWinOld_;
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "MAINGUI", ID_WINDOW_0, 0, 1, 480, 272, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "title", ID_TEXT_0, 23, 15, 272, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "email", ID_TEXT_1, 137, 242, 230, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "classify", ID_TEXT_2, 115, 81, 61, 69, 0, 0x64, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'MAINGUI'
    //
    hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem, GUI_MAKE_COLOR(0x00000000));
    //
    // Initialization of 'title'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetText(hItem, "AI Mnist Handwriting Recognition");
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
    TEXT_SetFont(hItem, GUI_FONT_20_1);
    //
    // Initialization of 'email'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
    TEXT_SetText(hItem, "Contact:rojarsmith@gmail.com");
    TEXT_SetFont(hItem, GUI_FONT_8X18);
    //
    // Initialization of 'classify'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FDFDFD));
    TEXT_SetText(hItem, " ");
    TEXT_SetFont(hItem, GUI_FONT_D64);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateMAINGUI
*/
WM_HWIN CreateMAINGUI(void);
WM_HWIN CreateMAINGUI(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  hWin_ = WM_GetClientWindow(hWin);
  return hWin;
}

// USER START (Optionally insert additional public code)
void set_classify(WM_HWIN *hWin, char *classify);
void set_classify(WM_HWIN *hWin, char *classify) {
	WM_HWIN      hItem;

	hItem = WM_GetDialogItem(hWin, ID_TEXT_2);
	TEXT_SetText(hItem, classify);
}

void clear(WM_HWIN *hWin);
void clear(WM_HWIN *hWin) {
	WM_HWIN      hItem;

	if (status != 0)
	{
		hItem = WM_GetDialogItem(hWin, ID_TEXT_2);
		TEXT_SetText(hItem, " ");

		hWinOld_ = WM_SelectWindow(hWin_);
		GUI_SetColor(GUI_BLACK);  //GUI_RED  GUI_WHITE  GUI_YELLOW  GUI_BLUE
		GUI_FillRect(289, 50, 467, 228);
		WM_SelectWindow(hWinOld_);
	}
}
// USER END

/*************************** End of file ****************************/
