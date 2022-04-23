#include "repertoire.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<windows.h>
LSC_T insere_tete_tel(LSC_T l, telephone t )
{
LSC_T p;
p=(struct cellule*)malloc(sizeof(struct cellule));
p->suivant=l;
p->info=t;
l=p;
return l;
}


/* num bech to93ed 7ata fi tel??
int recherche_tel(LSC_T l , int num)
{
    LSC_T p=l;
    while(p!=NULL)
    {
        if (p->info.ref==num)
            return 1;
        p=p->suiv;

    }
    return 0;
}
*/


int taille_liste_rep(LSC_T l)
{
    LSC_T p=l;
    int t=0;
    while(p != NULL)
    { t++;
        p=p->suivant;
    }
    return t;
}

LSC_T insere_queue_tel(LSC_T l, telephone t )
{ LSC_T p1,p2;
    p1=(struct cellule*)malloc(sizeof(struct cellule));
    p1->info=t;
    p1->suivant=NULL;
    if(l==NULL)
        l=p1;
    else
    {
        p2=l;
        while(p2->suivant!=NULL)
            p2=p2->suivant;
        p2->suivant=p1;
    }
    return l;
}

void insere_pos_tel(LSC_T l, int pos,telephone t )
{ LSC_T p2,p1=l;
    int i=1;
    if(pos!=1 && pos!=taille_liste_rep(l)+1)
    {
        while(i<pos-1)
        {
        p1=p1->suivant;
        i++;
        }
        p2=(struct cellule*)malloc(sizeof(struct cellule));
        p2->info=t;
        p2->suivant=p1->suivant;
        p1->suivant=p2;
    }
}

 // a faire l'implementation (controle de saisie)

 int test(LSC_T l, char num[9])
{
    LSC_T p=l;
    while(p!=NULL)
    {
        if (strcmp(p->info.num,num)==0)
            return 1;
        p=p->suivant;
    }
    return 0;
}

/*test date*/
/*****FONCTION BISSEXTILE******/
int BISSEXTILE(int A)
{
    if((A%4==0 && A%100!=0)||A%400==0)
        return 1;
    return 0;
}
/*****FONCTION BISSEXTILE******/
int JOUR_MAX(int J, int M , int A)
{
   int jmax;
   switch(M)
   {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: jmax =31;break;
        case 4:
        case 6:
        case 9:
        case 11: jmax =30;break;
        case 2 :
                if (BISSEXTILE(A)==1)
                    jmax=29;
                else
                    jmax=28;
   }
   return jmax;
}
/*****FONCTION VALIDE_DATE*****/
int VALIDE_DATE(int J, int M , int A)
{
    int jmax=JOUR_MAX(J,M,A);
    return J>=1 && J<=jmax && M>=1 && M<=12 && A>=1900;
}

/*verif chaine de caractere (composée que des lettres alphabétiques    */

int verif(char *ch)
{
    char *p=ch;
    do
    {
        if(!(isalpha(*p) || *p==' '))
            return 0;
        p++;
    }while(*p);
    return 1 ;
}

int nbrOccurences( char *chaine, char caractere )
{ int compteur = 0,i;

for( i = 0; i < strlen( chaine); i++ )
{
if( chaine[i] == caractere ) compteur++;
}
return compteur;
}

telephone saisie_tel(LSC_T l)
{
    telephone tel;
    int taille,i,J,M,A,k,ad;
    long tell;
    char j[3],m[3],a[5];
    setlocale (LC_ALL,"");


printf("Donner le nom :");
    do{
        fflush(stdin);
        gets(tel.nom);
    //scanf("%s",tel.nom);
    }while(!verif(tel.nom) || !verif_espace(tel.nom) );

    printf("Donner le prenom :");
    do{
        fflush(stdin);
        gets(tel.prenom);
    //scanf("%s",tel.prenom);
    }while(!verif(tel.prenom) || !verif_espace(tel.prenom) );

    printf("Donner la date de naissance sous la forme jj/mm/aaaa :");
    do{
    //scanf("%s",tel.dn);
    fflush(stdin);
    gets(tel.dn);

    for(i=0;i<2;i++)
        j[i]=tel.dn[i];
    j[i]='\0';
    for(i++,k=0;i<5;i++)
        m[k++]=tel.dn[i];
    m[k]='\0';
    for(i++,k=0;tel.dn[i];i++)
        a[k++]=tel.dn[i];
    a[k]='\0';
//printf("%s \t %s \t %s \n",j,m,a);
    J=atoi(j);
    M=atoi(m);
    A=atoi(a);
    //printf("%d \t %d \t %d \n",J,M,A);
    /*for(i=0;i<=9;i++)
    {
        if(i<2)
            {j[i]=tel.dn[i];}
        else if((i>=3) && (i<=4))
        {m[i-3]=tel.dn[i];}
        else if(i>=6) {a[i-6]=tel.dn[i];}
    }
    printf("%s \t %s \t %s \n",j,m,a);
    j[3]='\0';
    m[3]='\0';
    a[5]='\0';
    printf("%s \t %s \t %s \n",j,m,a);
    J=atoi(j);
    M=atoi(m);
    A=atoi(a);*/

    }while(VALIDE_DATE(J,M,A)==0 || verif_format_date(tel.dn)==0 || strlen(a)!=4 );
    //printf("%d\t%d\t%d\n",J,M,A);

    printf("Donner le numero :");
    do{
        fflush(stdin);
        gets(tel.num);
        //scanf("%s",tel.num);
        //taille = strlen(tel.num);//numéro est composé de 8 chiffres
        //tell=atol(tel.num);
    }while( test(l,tel.num)==1 || verif_num(tel.num)==0 );

    printf("Donner la rue :");
    do{
        fflush(stdin);
        gets(tel.ad.rue);
    //scanf("%s",tel.ad.rue);
    }while(!verif(tel.ad.rue) || !verif_espace(tel.ad.rue));

    printf("Donner la ville :");
    do{
    fflush(stdin);
    gets(tel.ad.ville);
    //scanf("%s",tel.ad.ville);
    }while(!verif(tel.ad.ville) || !verif_espace(tel.ad.ville));

    printf("Donner le code Postal :");
    do{
    fflush(stdin);
    gets(tel.ad.codePostal);
    //scanf("%s",tel.ad.codePostal);
    taille = strlen(tel.ad.codePostal);
    ad=atoi(tel.ad.codePostal);
    }while((taille!=4)|| ad<=1000);

    printf("Donner l'email :");
    do{
    fflush(stdin);
    gets(tel.email);
    //scanf("%s",tel.email);
    }while(nbrOccurences(tel.email,'@')!=1 || nbrOccurences(tel.email,' ')!=0 || verif_point(tel.email)==0);

    return tel;
}



LSC_T supprimer_tete_tel(LSC_T l )
{
    LSC_T p=l ;
    if ( l==NULL)
        //printf(" liste vide \n " );
        MessageBox(0," liste vide \n","Information",MB_ICONSTOP );
    else
    {
        l=l->suivant;
        free(p);
        MessageBox(0," Suppression en tete avec succes","Information",MB_ICONINFORMATION );
    }
    return (l);
}


LSC_T supprimer_queue_tel(LSC_T l)
{ LSC_T p=l ;
    if ( l==NULL)
        //printf (" Suppression impossible \n " ) ;
        MessageBox(0," liste vide \n","Information",MB_ICONSTOP );
    else
        if(l->suivant==NULL)
        {   l=l->suivant ;
            free(p);
            }
        else
            {while( ( p->suivant)->suivant != NULL )
                p=p->suivant;
                free(p->suivant);
                p->suivant=NULL;
                MessageBox(0," Suppression en queue avec succes","Information",MB_ICONINFORMATION );
            }
    return l ;
}


void suppression_pos_tel(LSC_T l ,int pos )
{ LSC_T p1=l,p2;int i =1;
    if(pos!=1 && pos!=taille_liste_rep(l))
    {
        while(i<pos-1)
        { i++;
        p1=p1->suivant ;
        }
        p2=p1->suivant;
        p1->suivant=p2->suivant ;
        free(p2);
        MessageBox(0," Suppression à cette position avec succes","Information",MB_ICONINFORMATION );
    }
}


/* remplacer int x => char t et voir commentaire 7.4 cour imprimé   puis les x avec t */
LSC_T suppression_tel_donnee(LSC_T l,char num[9] )
{ LSC_T p=l,q; int ok =0;
 if(strcmp(p->info.num,num)==0)
    { l=p->suivant;
      free(p);
      MessageBox(0," Suppression de ce telephone avec succes","Information",MB_ICONINFORMATION );
    }
 else
    { while(p->suivant!=NULL)
        if(strcmp((p->suivant)->info.num,num)==0)
            { ok=1;
             break;
            }
        else
            p=p->suivant;
    if(ok)
    { q=p->suivant;
        p->suivant=q->suivant;
        free(q);
        MessageBox(0," Suppression de ce telephone avec succes","Information",MB_ICONINFORMATION );
    }
    else
        printf("%s n existe pas dans la liste\n",num);
    }

return l;
}

//suppression des telephone d'une ville donnée:
LSC_T suppression_ville_donnee(LSC_T l,char ville[20] )
{
    LSC_T p=l, prec=NULL;
    int nbr=0;
    while(p)
    {
        if(strcmp(p->info.ad.ville,ville)==0)
        {
            if(prec==NULL)
            {
                l=l->suivant;
                free(p);
                p=l;
            }
            else
            {
                prec->suivant=p->suivant;
                free(p);
                p=prec->suivant;
            }
        nbr++;
        }
        else
        {
            prec=p;
            p=p->suivant;
        }
    }
    //MessageBox(0," Suppression des telephones de cette ville avec succes","Information",MB_ICONINFORMATION );
    if(nbr!=0) printf("\nSuppression de %d telephones de la ville %s avec succes\n",nbr,ville);
     else printf("%s nexiste pas dans la liste\n",ville);
    return l;
}

LSC_T suppression_indicatif_donnee(LSC_T l,char ch1[] )
{
    LSC_T p=l, prec=NULL;
    int nbr=0;
    char ch[3];
    while(p)
    {
        strncpy(ch,p->info.num,2);
        if(strcmp(ch,ch1)==0)
        {
            if(prec==NULL)
            {
                l=l->suivant;
                free(p);
                p=l;
            }
            else
            {
                prec->suivant=p->suivant;
                free(p);
                p=prec->suivant;
            }
        nbr++;
        }
        else
        {
            prec=p;
            p=p->suivant;
        }
    }
    //MessageBox(0," Suppression des telephones de cette ville avec succes","Information",MB_ICONINFORMATION );
    if(nbr!=0) printf("\nSuppression de %d telephones de l'indicatif %s avec succes\n",nbr,ch1);
     else printf("\n%s n existe pas dans la liste\n\n",ch1);
    return l;
}

/**************Recherche***************/
void recherche_indicatif_donnee(LSC_T l,char ch1[] )
{
    LSC_T p=l, prec=NULL;
    int nbr=0;
    char ch[3];
    while(p)
    {
        strncpy(ch,p->info.num,2);
        //printf("%s\n",ch);
        //printf("%d\n",strcmp(ch,ch1));
        if(strcmp(ch,ch1)==0)
        {
            if(prec==NULL)
            {
                l=l->suivant;
                //printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",l->info.num,l->info.nom,l->info.prenom,l->info.dn,l->info.ad.rue,l->info.ad.ville,l->info.ad.codePostal,l->info.email);
                printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->info.num,p->info.nom,p->info.prenom,p->info.dn,p->info.ad.rue,p->info.ad.ville,p->info.ad.codePostal,p->info.email);
                p=l;
            }
            else
            {

                prec->suivant=p->suivant;
                printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->info.num,p->info.nom,p->info.prenom,p->info.dn,p->info.ad.rue,p->info.ad.ville,p->info.ad.codePostal,p->info.email);
                p=prec->suivant;
            }
        nbr++;
        }
        else
        {
            prec=p;
            p=p->suivant;
        }
    }
    //MessageBox(0," Suppression des telephones de cette ville avec succes","Information",MB_ICONINFORMATION );
    if(nbr!=0) printf("\n Il existe %d resultat de recherche de ce indicatif %s \n\n",nbr,ch1);
    else printf("\n%s n existe pas dans la liste\n\n",ch1);

}

void recherche_tel_donnee(LSC_T l,char num[9] )
{ LSC_T p=l,q; int ok =0;
 if(strcmp(p->info.num,num)==0)
    { l=p->suivant;
      printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->info.num,p->info.nom,p->info.prenom,p->info.dn,p->info.ad.rue,p->info.ad.ville,p->info.ad.codePostal,p->info.email);
    }
 else
    { while(p->suivant!=NULL)
        if(strcmp((p->suivant)->info.num,num)==0)
            { ok=1;
             break;
            }
        else
            p=p->suivant;
    if(ok)
    { q=p->suivant;
        p->suivant=q->suivant;
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",q->info.num,q->info.nom,q->info.prenom,q->info.dn,q->info.ad.rue,q->info.ad.ville,q->info.ad.codePostal,q->info.email);
    }
    else
        printf("\n%s n existe pas dans la liste\n\n",num);
    }

}


void recherche_nom_donnee(LSC_T l,char nom[20] )
{ LSC_T p=l, prec=NULL;
    int nbr=0;
    while(p)
    {

        if(strcmp(p->info.nom,nom)==0)
        {
            if(prec==NULL)
            {
                l=l->suivant;
                //printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",l->info.num,l->info.nom,l->info.prenom,l->info.dn,l->info.ad.rue,l->info.ad.ville,l->info.ad.codePostal,l->info.email);
                printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->info.num,p->info.nom,p->info.prenom,p->info.dn,p->info.ad.rue,p->info.ad.ville,p->info.ad.codePostal,p->info.email);
                p=l;
            }
            else
            {

                prec->suivant=p->suivant;
                printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->info.num,p->info.nom,p->info.prenom,p->info.dn,p->info.ad.rue,p->info.ad.ville,p->info.ad.codePostal,p->info.email);
                p=prec->suivant;
            }
        nbr++;
        }
        else
        {
            prec=p;
            p=p->suivant;
        }
    }
    //MessageBox(0," Suppression des telephones de cette ville avec succes","Information",MB_ICONINFORMATION );
    if(nbr!=0) printf("\n Il existe %d resultat de recherche de ce nom %s \n\n",nbr,nom);
     else printf("\n%s n existe pas dans la liste\n\n",nom);

}

void recherche_ville_donnee(LSC_T l,char ville[20] )
{ LSC_T p=l, prec=NULL;
    int nbr=0;
    while(p)
    {

        if(strcmp(p->info.ad.ville,ville)==0)
        {
            if(prec==NULL)
            {
                l=l->suivant;
                //printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",l->info.num,l->info.nom,l->info.prenom,l->info.dn,l->info.ad.rue,l->info.ad.ville,l->info.ad.codePostal,l->info.email);
                printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->info.num,p->info.nom,p->info.prenom,p->info.dn,p->info.ad.rue,p->info.ad.ville,p->info.ad.codePostal,p->info.email);
                p=l;
            }
            else
            {

                prec->suivant=p->suivant;
                printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->info.num,p->info.nom,p->info.prenom,p->info.dn,p->info.ad.rue,p->info.ad.ville,p->info.ad.codePostal,p->info.email);
                p=prec->suivant;
            }
        nbr++;
        }
        else
        {
            prec=p;
            p=p->suivant;
        }
    }

    if(nbr!=0) printf("\n Il existe %d resultat de recherche de ce nom %s \n\n",nbr,ville);
     else printf("\n%s nexiste pas dans la liste\n\n",ville);

}

/**************Modification***************/



LSC_T modifier_tel_donnee(LSC_T l,char num[9] )
{ LSC_T p=l,q; int ok =0;
    telephone tel;

while(p&&ok==0)
{

 if(strcmp(p->info.num,num)==0)
    {
      printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->info.num,p->info.nom,p->info.prenom,p->info.dn,p->info.ad.rue,p->info.ad.ville,p->info.ad.codePostal,p->info.email);
        tel=saisie_tel(l);

        strcpy(p->info.nom,tel.nom);
        strcpy(p->info.prenom,tel.prenom);
        strcpy(p->info.dn,tel.dn);
        strcpy(p->info.num,tel.num);
        strcpy(p->info.ad.rue,tel.ad.rue);
        strcpy(p->info.ad.ville,tel.ad.ville);
        strcpy(p->info.ad.codePostal,tel.ad.codePostal);
        strcpy(p->info.email,tel.email);

        ok=1;
    }
 else
    p=p->suivant;
}
if(ok==1) printf("\n La modification du %s s effectue  avec succes\n\n",num);
else printf("\n%s n existe pas dans la liste\n\n",num);
return l;
}

/**************enregistrement/recuperation***************/
void enregistrement(LSC_T l)
{   FILE *f;
    LSC_T p=l;
    f=fopen("Contact.txt","w");
    while(p)
    {
        fprintf(f,"%s|%s|%s|%s|%s|%s|%s|%s\n",p->info.num,p->info.nom,p->info.prenom,p->info.dn,p->info.ad.rue,p->info.ad.ville,p->info.ad.codePostal,p->info.email);
        p=p->suivant;
    }
       fclose(f);
}



/*void enregistrement(LSC_T l)
{   FILE *f;
    int i,n;

     if (l == NULL)
        printf("Liste Vide");
    else
      {
        f=fopen("Contact.txt","w");
        while(l!=NULL)
        {
            fprintf(f,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",l->info.num,l->info.nom,l->info.prenom,l->info.dn,l->info.ad.rue,l->info.ad.ville,l->info.ad.codePostal,l->info.email);
            l=l->suivant;
        }
       fclose(f);
       //blaka
      }
}
*/


//[^|]|:( ^ copier toute la chaine jusqu'à on trouve | )
// le separateur | dans notre fichier.
LSC_T recuperation()
{
    FILE *f;
    f=fopen("Contact.txt","r"); //ouvrir le fichier en mode ecriture(r)
    telephone tel;
    LSC_T l=NULL;
    if(f!=NULL){
        while(!feof(f))
        {
            fscanf(f,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%s\n",tel.num,tel.nom,tel.prenom,tel.dn,tel.ad.rue,tel.ad.ville,tel.ad.codePostal,tel.email);
            l=insere_queue_tel(l,tel);
        }
    }
    fclose(f);
    return l;
}

/*LSC_T recuperation()
{
    FILE *f;
    int i,n,j=1;
    LSC_T l=NULL;
    telephone tel;
    int nbrL=0;
    char c;

     if (l == NULL) //Verifier que notre Liste est vide au début
      {
            //etape 1: determiner nbr de ligne dans le fichier "Contact.txt"
            f=fopen("Contact.txt","r"); //ouvrir le fichier en mode ecriture(r)
                            while((c=fgetc(f))!=EOF){
                                if(c=='\n') nbrL++;
                            }
                printf("%d",nbrL);

        //etape 2: récupération
        f=fopen("Contact.txt","r");//ré-ouvrir le fichier en mode ecriture(r)
            if(f!=NULL)
                {

                   while(j!=nbrL+2)  //taille_liste_rep(l)
                    {
                        fscanf(f,"%s%s%s%s%s%s%s%s",tel.num,tel.nom,tel.prenom,tel.dn,tel.ad.rue,tel.ad.ville,tel.ad.codePostal,tel.email);
                        l=insere_queue_tel(l,tel);
                        //insere_pos_tel(l,j,tel);
                       // j++;

                        j++;
                        //l=l->suivant;
                    }
                    //affiche(l);
                }
            else {MessageBox(0," Le fichier est deja vide","Information",MB_ICONSTOP ); }   //documentation : http://www.progmatique.fr/article-7-Cpp-afficher-boite-dialogue-message.html
      }
       fclose(f);
       return l;
}

*/


/**Partie 1**/

LSC_T creation(LSC_T l)
{
    int rep,pos ,t;
    telephone tel;
    setlocale(LC_ALL,"");
    do
    {
        t=taille_liste_rep(l);
        do
        {
            printf("Donner une position entre 1 et %d : ",t+1);
            scanf("%d",&pos);
        }while(!(pos>=1 && pos<=t+1));
        tel=saisie_tel(l);
        if(pos==1)
            l=insere_tete_tel(l,tel);
        else
            if(pos==t+1)
                l=insere_queue_tel(l,tel);
            else
                insere_pos_tel(l,pos,tel);
        do
        {
            printf("Voulez vous ajouter un autre telephone 1/0 » (1 pour Oui, O pour Non):");
            scanf("%d",&rep);
        }while(!(rep==1 || rep==0));
    }while(rep);
    return l;
}

void affiche(LSC_T l)
{
    if (l == NULL)
        printf("Liste Vide\n");
    else
       { textcolor(4);
           printf("Numero\t\tNom\tPrenom\tDate Nai\tRue\tVille\tCodePo\tEmail\n");
           printf("-----------------------------------------------------------------------------\n");
          textcolor(0);
           while(l!=NULL)
        {
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",l->info.num,l->info.nom,l->info.prenom,l->info.dn,l->info.ad.rue,l->info.ad.ville,l->info.ad.codePostal,l->info.email);
          l=l->suivant;

        }
       }
}

//Verifier le numero
int verif_num(char ch [])
{
    int i,ok=1;
    for(i=0;ch[i];i++)
        if(ch[i]<'0' || ch [i]>'9')     //pour verifier que le numéro se compose que avec des numeros
            ok=0;
    return (ok==1) && (strlen(ch)==8);
}

//verifier format de la date dd/mm/aaaa
int verif_format_date(char ch[])
{
    int i;
    for(i=0;i<10;i++)
        if(i==2 || i==5)
    {
            if(ch[i]!='/')
                return 0;
    }
        else
            if(ch[i]<'0' || ch[i]>'9')
                return 0;
    return 1;
}

int verif_espace(char ch[])
{
    return (nbrOccurences(ch,' ')==1 || nbrOccurences(ch,' ')==0) && ch[0]!=' ' && ch[strlen(ch)-1]!=' ';
}

int verif_point(char ch[])
{int nbr=0,i,pos1,pos2,j;
    for(i=0;i<=strlen(ch);i++)
    {
        if(ch[i]=='@')
        pos1=i;
    }

    pos2=strlen(ch);

    for(j=pos1;j<=pos2;j++)
    {
        if(ch[j]=='.') nbr++;
    }

    return nbr==1;
}
void tri_croiss(LSC_T l)
{

    LSC_T p1,p2;
    telephone aux;
    p1=l;
    while(p1->suivant!=NULL)
    {
        p2=p1->suivant;
        while(p2!=NULL)
        {
            if(strcmp((p1->info).num,(p2->info).num)>0)
            {
                aux=p1->info;
                p1->info=p2->info;
                p2->info=aux;
            }
            p2=p2->suivant;
        }
        p1=p1->suivant;
    }
}

void tri_decroiss(LSC_T l)
{

    LSC_T p1,p2;
    telephone aux;
    p1=l;
    while(p1->suivant!=NULL)
    {
        p2=p1->suivant;
        while(p2!=NULL)
        {
            if(strcmp((p1->info).num,(p2->info).num)<0)
            {
                aux=p1->info;
                p1->info=p2->info;
                p2->info=aux;
            }
            p2=p2->suivant;
        }
        p1=p1->suivant;
    }
}
