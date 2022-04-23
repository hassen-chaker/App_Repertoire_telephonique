#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <myconio.h>
#include <stdio.h>
#include <windows.h>
#include "repertoire.h"
#include <locale.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void addmenus(HWND);
void CreateBtt(HWND hwnd) ;

HWND hname ,hage,hout,hogo,Add,Finnish;
 HDC hdc;
HMENU hmenu ;

HBITMAP hlogoImage , hgenerateImage;
int intro=1 ;
char ch[30] ;
long p ;
LSC_T l=NULL;
telephone tel1;
a=0;

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("my project");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND+7;


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("my project"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1250,                 /* The programs width */
           768,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{static HBITMAP  hBmp;


   /* if(intro)
    {
        system("start test.exe") ;
        intro=0;
    }*/

    switch (message)                  /* handle the messages */
    {

        case WM_COMMAND:
        switch(wParam)
        {
         // 1-Création
        case 1:
        if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(2,2);

                if(l==NULL)
                {
                l=creation(l);
                affiche(l);
                }
                else {MessageBox(0," Fichier deja créé","Information",MB_ICONSTOP );}

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");

                }
                break;

        //2-Mise à jour
            //Ajouter un téléphone
        case 11:    //Ajouter tête
            if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                    if(l!=NULL){
                    system("color F9");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(2,2);

                       // tel1=saisie_tel(l);
                        l=insere_tete_tel(l,saisie_tel(l));
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        case 12:    //Ajouter pos
            if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                    if(l!=NULL){
                    system("color F9");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(2,2);

                    int t,pos;
                    t=taille_liste_rep(l);
                    if(t>=2)    //Il faut que la liste contient plus de deux contacts
                       {
                        do
                        {
                            printf("Donner une position entre 2 et %d : ",t);
                            scanf("%d",&pos);
                        }while(!(pos>1 && pos<=t));
                        insere_pos_tel(l,pos,saisie_tel(l));
                       }
                    else {printf("\n L'ajout impossible à une position donnée car la liste contient moins de deux contact\n Veuillez choisir une autre option d'ajout\n");}
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        case 13:    //Ajouter queue
            if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(2,2);

                l=insere_queue_tel(l,saisie_tel(l));

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
            //Supprimer un téléphone
        case 14:    //En tête
            if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                /*system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);*/

                l=supprimer_tete_tel(l);

                /*system("pause");
                ShowWindow(hwnd,SW_NORMAL);*/
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        case 15:    //En queue
            if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                /*system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);*/

                l=supprimer_queue_tel(l);

               /* system("pause");
                ShowWindow(hwnd,SW_NORMAL);*/
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        case 16:    //À partir d'une position
            if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(2,2);

                    int t2,pos2;
                    t2=taille_liste_rep(l);
                if(t2>=2)    //Il faut que la liste contient plus de deux contacts
                   {
                    do
                    {
                        printf("Donner une position entre 2 et %d : ",t2-1);
                        scanf("%d",&pos2);
                    }while(!(pos2>1 && pos2<=t2));
                    suppression_pos_tel(l,pos2 );
                   }
                else {printf("\n Suppression impossible à une position donnée car la liste contient moins de deux contact\n Veuillez choisir une autre option de suppression\n");}

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        case 17:    //À partir d'un téléphone (num tel)
            if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(2,2);

                char num[9];
                int taille;
                printf("Donner un numero :");
                do{
                 fflush(stdin);
                gets(num);
                }while( verif_num(num)==0 );
                l=suppression_tel_donnee(l,num);


                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        case 18:    //À partir d'une ville
            if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(2,2);

                char ville[20];
                printf("Donner la ville :");
                do{
                fflush(stdin);
                gets(ville);
                }while(!verif(ville) || !verif_espace(ville));
                l= suppression_ville_donnee(l,ville);


                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        case 19:    //À partir d'un indicatif
            if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(2,2);

                char ind[3];
                int taille4;
                printf("Donner un indicatif :");
                do{
                 fflush(stdin);
                 gets(ind);
                 taille4 = strlen(ind);//numéro est composé de 8 chiffres
                }while( (taille4!=2) || atol(ind)<10 );
                l=suppression_indicatif_donnee(l,ind);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        case 20:    //Modifier les données d'un téléphone
            if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(2,2);


                char num1[9];

                printf("Donner un numero :");
                do{
                 fflush(stdin);
                gets(num1);
                }while( verif_num(num1)==0 );
                l=modifier_tel_donnee( l, num1 );

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;

        //Recherche, affichage et tri
        case 21:    //Tous les contacts
            if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(2,2);
                printf("       \n");
            setlocale (LC_ALL,"");
                affiche(l);
                printf("       \n");

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        case 22:    //Recherche par numéro
            if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(2,2);
                //printf("    BONJOUR 3   \n");

                char num2[9];
                printf("Donner un numero :");
                do{
                 fflush(stdin);
                gets(num2);
                }while( verif_num(num2)==0 );
                recherche_tel_donnee(l,num2);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        case 23:    //Recherche par indicatif
             if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(2,2);

                char ind2[3];
                int taille3;
                printf("Donner un indicatif :");
                do{
                 fflush(stdin);
                 gets(ind2);
                 taille3 = strlen(ind2);//numéro est composé de 8 chiffres
                }while( (taille3!=2) || atol(ind2)<10 );
                recherche_indicatif_donnee( l, ind2 );

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        case 24:    //Recherche par nom
             if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(2,2);

                char nom[20];
                printf("Donner le nom :");
                do{
                    fflush(stdin);
                    gets(nom);
                }while(!verif(nom) || !verif_espace(nom) );

                recherche_nom_donnee( l, nom );

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        case 25:    //Recherche par ville
             if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(2,2);

                char ville2[20];
                printf("Donner la ville :");
                do{
                fflush(stdin);
                gets(ville2);
                //scanf("%s",tel.ad.ville);
                }while(!verif(ville2) || !verif_espace(ville2));
                recherche_ville_donnee( l,ville2 );

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                 }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        //Trier la liste
        case 26:   // Tri Croiss
             if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(2,2);

                printf("\n");
                tri_croiss(l);
                affiche(l);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        case 27:   // Tri decroiss
            if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(2,2);

                printf("\n");
                tri_decroiss(l);
                affiche(l);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        //Enregistrement et récupération
        case 31:    //Enregistrement
             if(a==0){MessageBox(0," Il faut charger un fichier","Information",MB_ICONSTOP );}
            else{
                if(l!=NULL){
                /*system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);*/

                enregistrement(l);
                MessageBox(0," Enregistrement","Information",MB_ICONINFORMATION );
                /*system("pause");
                ShowWindow(hwnd,SW_NORMAL);*/
                system("cls");
                }
                    else {MessageBox(0,"Il faut faire la création","Information",MB_ICONSTOP );}
                }
                break;
        case 32:    //Récupération
                /*system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);*/

                l=recuperation();
                MessageBox(0," Recuperation","Information",MB_ICONINFORMATION );    //MB_ICONEXCLAMATION
                a=1;
                /*system("pause");
                ShowWindow(hwnd,SW_NORMAL);*/
                system("cls");
                break;
            //Plus++
        case 41:    //Enoncer
                /*system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);*/
                ShellExecute(NULL, "open", "projet.pdf", NULL, NULL, SW_SHOWNORMAL);
                /*system("pause");
                ShowWindow(hwnd,SW_NORMAL);*/
                system("cls");
                break;
        case 42:    //Ouvrir la liste du téléphone
                /*system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);*/
                ShellExecute(NULL, "open", "Contact.txt", NULL, NULL, SW_SHOWNORMAL);
               /* system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");*/
                break;

        case 70:    //Quitter
                if (MessageBox(hwnd,"       Vous voulez quitter ?", "QUITTER", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                {

                    DestroyWindow(hwnd);
                    system("cls");
                }
            break;



        }
    case WM_CREATE :
        addmenus(hwnd);
//         CreateBtt(hwnd) ;
            /*****************ajouter fond **********************/
            hBmp=LoadImage(NULL,"pr.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);

            break;

        case WM_PAINT :
            {



         PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);

            DrawState(hdc,NULL,NULL,(long)hBmp,0,0,0,0,0,DST_BITMAP);

            EndPaint(hwnd, &ps);}
        break;
        case WM_DESTROY:
            PostQuitMessage (0);        /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void addmenus(HWND hwnd)
{
    hmenu=CreateMenu();
    HMENU htp=CreateMenu();
    HMENU htp1=CreateMenu();
    HMENU hex2=CreateMenu();
    HMENU hex3=CreateMenu();
    HMENU hex4=CreateMenu();
    HMENU htp2=CreateMenu();
    HMENU htp3=CreateMenu();
    HMENU htp4=CreateMenu();
    HMENU htp5=CreateMenu();

    //AppendMenu(hmenu,MF_STRING,0,"création du repertoire");
    /*******************************************************/
    AppendMenu(hmenu,MF_STRING,1,"Création");

    /*AppendMenu(htp,MF_STRING,1,"EXERCICE 1");
    AppendMenu(htp,MF_STRING,2,"EXERCICE 2");
    AppendMenu(htp,MF_POPUP,(UINT_PTR)hex3,"EXERCICE 3");
        AppendMenu(hex3,MF_STRING,3,"PARTIE 1");
        AppendMenu(hex3,MF_STRING,4,"PARTIE 2");
        AppendMenu(hex3,MF_STRING,5,"PARTIE 3");
    AppendMenu(htp,MF_STRING,6,"EXERCICE 4");*/
/***************************************************************/

     AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp1,"Mise à jour");

      AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex2,"Ajouter un téléphone");
        AppendMenu(hex2,MF_STRING,11,"Ajouter tête");
        AppendMenu(hex2,MF_STRING,12,"Ajouter pos");
        AppendMenu(hex2,MF_STRING,13,"Ajouter queue");
      AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex4,"Supprimer un téléphone");
        AppendMenu(hex4,MF_STRING,14,"En tête");
        AppendMenu(hex4,MF_STRING,15,"En queue");
        AppendMenu(hex4,MF_STRING,16,"À partir d'une position");
        AppendMenu(hex4,MF_STRING,17,"À partir d'un téléphone");
        AppendMenu(hex4,MF_STRING,18,"À partir d'une ville");
        AppendMenu(hex4,MF_STRING,19,"À partir d'un indicatif");
      AppendMenu(htp1,MF_STRING,20,"Modifier les données d'un téléphone");
/***************************************************************/
     AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp3,"Recherche, affichage et tri");

      AppendMenu(htp3,MF_STRING,21,"Tous les contacts");
      AppendMenu(htp3,MF_STRING,22,"Recherche par numéro");
      AppendMenu(htp3,MF_STRING,23,"Recherche par indicatif");
       AppendMenu(htp3,MF_STRING,24,"Recherche par nom");
      AppendMenu(htp3,MF_STRING,25,"Recherche par ville");
      AppendMenu(htp3,MF_STRING,26,"Trier la liste 1");
      AppendMenu(htp3,MF_STRING,27,"Trier la liste 2");

/***************************************************************/
     AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp4,"Enregistrement et récupération");

      AppendMenu(htp4,MF_STRING,31,"Enregistrement");
      AppendMenu(htp4,MF_STRING,32,"Récupération");

/***************************************************************/
     AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp5,"Plus++");

      AppendMenu(htp5,MF_STRING,41,"Enoncer");
      AppendMenu(htp5,MF_STRING,42,"Ouvrir la liste du téléphone");

/***************************************************************/
/*     AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp2,"TP3");

      AppendMenu(htp2,MF_STRING,11,"EXERCICE 1");
      AppendMenu(htp2,MF_STRING,12,"EXERCICE 2");
      AppendMenu(htp2,MF_STRING,13,"EXERCICE 3");
      AppendMenu(htp2,MF_STRING,14,"EXERCICE 4");
      AppendMenu(htp2,MF_STRING,15,"EXERCICE 5");
      AppendMenu(htp2,MF_STRING,16,"EXERCICE 6");   */
/***************************************************************/
    AppendMenu(hmenu,MF_STRING,70,"Quitter");
    SetMenu(hwnd,hmenu);
}

