//Definir et Declarer :
typedef struct
{
    char rue[20];
    char ville[20] ;
    char codePostal[5];
}adresse;

typedef struct
{
    char num[9];
    char nom[20];
    char prenom[20];
    char dn[11];
    adresse ad;
    char email[30];
}telephone;

struct cellule
{
    telephone info;
    struct cellule *suivant;
};
typedef struct cellule* LSC_T;



LSC_T insere_tete_tel(LSC_T ,telephone );
int taille_liste_rep(LSC_T );
LSC_T insere_queue_tel(LSC_T , telephone  );
void insere_pos_tel(LSC_T , int ,telephone );
int test(LSC_T , char [] );
int BISSEXTILE(int );
int JOUR_MAX(int , int , int );
int VALIDE_DATE(int , int , int );
int verif(char *);
telephone saisie_tel(LSC_T );
LSC_T supprimer_tete_tel(LSC_T );
LSC_T supprimer_queue_tel(LSC_T );
void suppression_pos_tel(LSC_T ,int );
LSC_T suppression_tel_donnee(LSC_T ,char [] );
LSC_T suppression_ville_donnee(LSC_T ,char [] );
LSC_T suppression_indicatif_donnee(LSC_T,char [] );
LSC_T modifier_tel_donnee(LSC_T ,char [] );
void recherche_indicatif_donnee(LSC_T ,char [] );
void recherche_ville_donnee(LSC_T ,char [] );
void recherche_tel_donnee(LSC_T ,char [] );
void recherche_nom_donnee(LSC_T ,char [] );
void enregistrement(LSC_T );
LSC_T recuperation();
LSC_T creation(LSC_T );
void affiche(LSC_T );
void tri_croiss(LSC_T );
void tri_decroiss(LSC_T );
int verif_format_date(char []);
int verif_num(char []);
int verif_espace(char []);
int verif_point(char ch[]);


