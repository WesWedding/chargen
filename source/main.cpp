/*
 * main.cpp
 *
 *  Created on: Mar 27, 2009
 *      Author: Weston Wedding
 *
 *      Needs a main() to compile so here it is.
 */
// The following was copypasted from http://en.wikibooks.org/wiki/Windows_Programming/Window_Creation
#include <windows.h>
#include <sstream>
#include <string>
#include "resource.h"
//#include "Character.h"


LPSTR szClassName = "MyClass";
HINSTANCE hInstance;
LRESULT CALLBACK MyWndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK VersionDialogProc(HWND, UINT, WPARAM, LPARAM);
bool  showVersionWindow(HWND, HINSTANCE);
void MessageBoxErrorDisplay(void);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
   WNDCLASS wnd;
   MSG msg;
   HWND hwnd;
   HMENU hmenu;


   hInstance = hInst;

   wnd.style = CS_HREDRAW | CS_VREDRAW; //we will explain this later
   wnd.lpfnWndProc = MyWndProc;
   wnd.cbClsExtra = 0;
   wnd.cbWndExtra = 0;
   wnd.hInstance = hInstance;
   wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION); //default icon
   wnd.hCursor = LoadCursor(NULL, IDC_ARROW);   //default arrow mouse cursor
   wnd.hbrBackground = (HBRUSH)(COLOR_BACKGROUND+1);
   wnd.lpszMenuName = MAKEINTRESOURCE(IDM_CHARGEN_MENU);
   wnd.lpszClassName = szClassName;

   if(!RegisterClass(&wnd))                     //register the WNDCLASS
   {
       MessageBox(NULL, "This Program Requires Windows NT",
                        "Error", MB_OK);
       return 0;
   }

   hmenu = LoadMenu(hInst, MAKEINTRESOURCE(IDM_CHARGEN_MENU));

   hwnd = CreateWindow(szClassName,
                       "Window Title",
                       WS_OVERLAPPEDWINDOW, //basic window style
                       CW_USEDEFAULT,
                       CW_USEDEFAULT,       //set starting point to default value
                       CW_USEDEFAULT,
                       CW_USEDEFAULT,       //set all the dimensions to default value
                       NULL,                //no parent window
                       hmenu,
                       hInstance,
                       NULL);               //no parameters to pass
   ShowWindow(hwnd, iCmdShow);              //display the window on the screen
   UpdateWindow(hwnd);             //make sure the window is updated correctly

   while(GetMessage(&msg, NULL, 0, 0))      //message loop
   {
       TranslateMessage(&msg);
       DispatchMessage(&msg);
   }
   return msg.wParam;
}

LRESULT CALLBACK MyWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
   switch(msg)
   {
       case WM_DESTROY:
           PostQuitMessage(0);
           return 0;
           break;
       case WM_COMMAND:  //WM_COMMAND is a menu command
           switch(HIWORD(wParam))
           {
           case 0: //Menu command
               switch(LOWORD(wParam))
               {
               case IDC_QUIT_PROGRAM:
                   DestroyWindow(hwnd);
                   break;
               case IDC_VERSION:
                   /* int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_VERSION), hwnd,VersionDialogProc);
                   if (ret < 0)
                       {
                           MessageBoxErrorDisplay();
                       } TODO: remove this commented code if not needed anymore */
                   showVersionWindow(hwnd, hInstance);
                   break;
               }
           }
   }
   return DefWindowProc(hwnd, msg, wParam, lParam);
}

BOOL CALLBACK VersionDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_INITDIALOG:
            //DEBUG:  MessageBox(NULL, "Inside the DialogProc", "Inside Proc", MB_OK);
            return TRUE;
            break;
        case WM_CLOSE:
            //DEBUG: MessageBox(NULL, "Close Case", "Inside Proc", MB_OK);
            EndDialog(hwnd, WM_CLOSE);
            return TRUE;
            break;
        case WM_COMMAND:
            //DEBUG: MessageBox(NULL, "WM_COMMAND", "Inside Proc", MB_OK);
            switch(LOWORD(wParam))
            {
                case IDOK:
                    //DeBUG:: MessageBox(NULL, "IDOK case", "Inside Proc", MB_OK);
                    EndDialog(hwnd, IDOK);
                    return TRUE;
                    break;
                default:
                    //DEBUG: MessageBox(NULL, "Default Command Case", "Inside Proc", MB_OK);
                    return FALSE;
                    break;
            }
        default:
            return FALSE;
            break;
    }
}

bool showVersionWindow(HWND hwnd, HINSTANCE hInstance)
{
    int diagBoxID = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_VERSION), hwnd,(DLGPROC)VersionDialogProc);
    if (diagBoxID < 0)
    {
        MessageBoxErrorDisplay();
        return false;
    }

    return true;
}

// Used for debugging mostly, not intended as general purpose error catching
void MessageBoxErrorDisplay(void)
{
    std::stringstream aSStream;;
    std::string thestring;
    aSStream << "Error: " << GetLastError() << "IDD_VERSION: " << IDD_VERSION << " Is resource: " <<  IS_INTRESOURCE(IDD_VERSION);
    MessageBox(NULL, aSStream.str().c_str() , "Error Number", MB_OK);
}


