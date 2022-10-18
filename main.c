#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#include"liste.h"
#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_EXIT 3
#include<conio.h>
#include"partie0.h"
#include"partie1.h"
#include"partie2.h"
#include"partie3.h"
#include"partie4.h"
#include<conio.h>


LRESULT CALLBACK windowProcedure(HWND,UINT,WPARAM,LPARAM );

void  AddMenus(HWND);
HMENU hMenu;

liste l=NULL;
tel x ;
int pos;
char c[9];

int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst, LPSTR args,int ncmdshow)
{
    WNDCLASS wc={0};

    wc.hbrBackground=(HBRUSH)COLOR_WINDOW;
    wc.hCursor=LoadCursor(NULL,IDC_ARROW);
    wc.hInstance=hInst;
    wc.lpszClassName=L"mywindowclass";
    wc.lpfnWndProc=windowProcedure;

    if(!RegisterClassW(&wc))
        return -1;
    CreateWindowW(L"mywindowclass",L"MINI_PROJET",WS_OVERLAPPEDWINDOW | WS_VISIBLE,100,100,2000,2000,NULL,NULL,NULL,NULL);

    MSG msg={0};

    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
LRESULT CALLBACK windowProcedure(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch(msg)
    {
    case WM_COMMAND:
    switch(wp)
    {
    case 1:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        l=creation(l);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 2:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        x=saisie_tel(l);
        l=insere_tete_tel(l,x);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
   case 3:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        x=saisie_tel (l);
        l=insere_queue_tel(l,x);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 4:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        x=saisie_tel (l);
       do
        {
            printf("donner une position:");
            fflush(stdin);
            scanf("%d",&pos);
        }while(!(pos>=1&&pos<=taille_liste_rep(l)+1));
        insere_pos_tel(l,x,pos);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 5:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        l=supprimer_tete_tel(l);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 6:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        l=supprimer_queue_tel(l);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 7:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        do
        {
            printf("donner une position:");
            fflush(stdin);
            scanf("%d",&pos);
        }while(!(pos>=1&&pos<=taille_liste_rep(l)+1));
        supprimer_pos_tel(l,pos);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 8:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        printf("donner un numero de telephone:");
        fflush(stdin);
        gets(c);
        l=supprimer_tel_donner(l,c);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 9:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        printf("donner une ville a supprimer:");
        fflush(stdin);
        gets(c);
        l=supprimer_ville_donner(l,c);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 10:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        printf("donner un indecatif:");
        fflush(stdin);
        gets(c);
        l=supprimer_tel_ind_donner(l,c);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 11:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        printf("donner un telephone :");
        fflush(stdin);
        gets(c);
        modif_adress(l,c);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 12:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        printf("donner un telephone :");
        fflush(stdin);
        gets(c);
        modif_tel(l,c);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 13:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        printf("donner un telephone :");
        fflush(stdin);
        gets(c);

        rech_num_tel(l,c);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 14:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        printf("donner le nom:");
        fflush(stdin);
        gets(c);
        rech_nom_tel (l,c);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 15:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        printf("donner un indecatif:");
        fflush(stdin);
        gets(c);
        rech_ind_tel(l,c);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 16:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        printf("donner une ville:");
        fflush(stdin);
        gets(c);
        rech_ville_tel(l,c);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 17:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);

        affiche_liste(l);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 18:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        tri1(l);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 19:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        tri1(l);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 20:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        enregistrement_etudiant(l);
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 21:
        system("cls");
        ShowWindow(hWnd,SW_HIDE);
        l=recuperation_telephone();
        system("PAUSE");
        ShowWindow(hWnd,SW_NORMAL);
        break;
    case 5000 :
        DestroyWindow(hWnd) ;
        break ;
    }
        break;
    switch(wp)
    {
    case FILE_MENU_EXIT:
        DestroyWindow(hWnd);
        break;
    case FILE_MENU_NEW:
        MessageBeep(MB_ICONINFORMATION);
    }
        break;
    case WM_CREATE:
        AddMenus(hWnd);
        break;
    case WM_DESTROY :
        PostQuitMessage(0);
        break;
    case WM_CLOSE :
        DestroyWindow(hWnd) ;
        break ;
    default:
        return DefWindowProcW(hWnd,msg,wp,lp);
    }
}
void AddMenus(HWND hWnd)
{
    hMenu=CreateMenu();
    HMENU hFileMenu1=CreateMenu();
    HMENU hFileMenu2=CreateMenu();
    HMENU hFileMenu3=CreateMenu();
    HMENU hFileMenu4=CreateMenu();
    HMENU hFileMenu5=CreateMenu();
    HMENU hFileMenu6=CreateMenu();

    HMENU hSubMenu1=CreateMenu();
    HMENU hSubMenu2=CreateMenu();
    HMENU hSubMenu3=CreateMenu();

    AppendMenu(hMenu,MF_STRING,1,"Creation");
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hFileMenu1,"Mise a jour");
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hFileMenu2,"Affichage et tri");
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hFileMenu3,"Enregistrement et Chargement ");

    AppendMenu(hMenu,MF_STRING,(UINT_PTR) 5000,"Quitter");

    AppendMenu(hFileMenu1,MF_POPUP,(UINT_PTR)hSubMenu1,"ajouter un nouvel telephone");
    AppendMenu(hSubMenu1,MF_STRING,2,"ajout en tete");
    AppendMenu(hSubMenu1,MF_STRING,3,"ajout en queue");
    AppendMenu(hSubMenu1,MF_STRING,4,"ajout pos");

    AppendMenu(hFileMenu1,MF_SEPARATOR,NULL,NULL);

    AppendMenu(hFileMenu1,MF_POPUP,(UINT_PTR)hSubMenu2,"supprimer un telephone");
    AppendMenu(hSubMenu2,MF_STRING,5,"suppression en tete");
    AppendMenu(hSubMenu2,MF_STRING,6,"suppression en queue");
    AppendMenu(hSubMenu2,MF_STRING,7,"suppression a partir d'une position");
    AppendMenu(hSubMenu2,MF_STRING,8,"suppression d'un telephone donné");
    AppendMenu(hSubMenu2,MF_STRING,9,"suppression des telephones d'une ville donné");
    AppendMenu(hSubMenu2,MF_STRING,10,"suppression des telephones d'un indicatif donné");

    AppendMenu(hFileMenu1,MF_SEPARATOR,NULL,NULL);

    AppendMenu(hFileMenu1,MF_POPUP,(UINT_PTR)hSubMenu3,"modifier les données d'un telephone");
    AppendMenu(hSubMenu3,MF_STRING,11,"addresse");
    AppendMenu(hSubMenu3,MF_STRING,12,"telephone");

    AppendMenu(hFileMenu1,MF_SEPARATOR,NULL,NULL);
        AppendMenu(hFileMenu2,MF_STRING,17,"contenu de la liste de telephone");
    AppendMenu(hFileMenu2,MF_SEPARATOR,NULL,NULL);

    AppendMenu(hFileMenu2,MF_STRING,13," recherche par numero de telephone");
    AppendMenu(hFileMenu2,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hFileMenu2,MF_STRING,14," recherche par  nom");
    AppendMenu(hFileMenu2,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hFileMenu2,MF_STRING,15,"recherche par  indicatif telephone");
    AppendMenu(hFileMenu2,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hFileMenu2,MF_STRING,16,"recherche par  ville");
    AppendMenu(hFileMenu2,MF_SEPARATOR,NULL,NULL);



    AppendMenu(hFileMenu2,MF_STRING,18,"tri1");
    AppendMenu(hFileMenu2,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hFileMenu2,MF_STRING,19,"tri2");
    AppendMenu(hFileMenu2,MF_SEPARATOR,NULL,NULL);

    AppendMenu(hFileMenu3,MF_STRING,20,"Enregistrement");
    AppendMenu(hFileMenu3,MF_STRING,21,"Chargement");

    SetMenu(hWnd,hMenu);
}
