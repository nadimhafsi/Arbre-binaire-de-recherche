//Primitives de l'Arbre
#ifndef DEF_ARBRE
#define DEF_ARBRE
#define MAX(x, y) (((x) > (y)) ? (x) : (y))


#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"


//
//typedef struct Noeud Noeud;
typedef struct Noeud
{
    char caractere;
    struct Noeud *filsDroit;
    struct Noeud *filsGauche;
    int nbrOccurrence;
}Noeud;

typedef  Noeud * TArbre;


TArbre arbreConsVide();
bool arbreEstVide(TArbre a);
TArbre arbreCons(char caractere, int entier, TArbre filsGauche, TArbre filsDroite);
char arbreRacineLettre(TArbre a);
int arbreRacineNbOcc(TArbre a);
TArbre arbreFilsGauche(TArbre a);
TArbre arbreFilsDroit(TArbre a);
void arbreSuppr(TArbre *arbre);
void afficherArbre(TArbre a);
void afficherNoeuds(TArbre a, int espace);
int hauteurArbre(TArbre a);
#endif



//Construire Arbre Vide
TArbre arbreConsVide()
{
    return NULL;
}


//Retourne si l'arbre est vide
bool arbreEstVide(TArbre a)
{
    if (a == NULL)
    {
        return true;
    }
    return false;
}


//Construire noeud
TArbre arbreCons(char caractere, int entier, TArbre filsGauche, TArbre filsDroit)
{
    TArbre a = (Noeud *)malloc(sizeof(Noeud));
    a->caractere = caractere;
    a->nbrOccurrence = entier;
    a->filsGauche = filsGauche;
    a->filsDroit = filsDroit;
    return a;
}

//retorune le caractere du racine
char arbreRacineLettre(TArbre a)
{
    if (!arbreEstVide(a))
    {
        return a->caractere;
    }
    return '\0';
}

//retorune le nombre d'occurence du racine
int arbreRacineNbOcc(TArbre a)
{
    if (!arbreEstVide(a))
    {
        return a->nbrOccurrence;
    }
    return 0;
}

//Retourne fils Gauche
TArbre noeudFilsGauche(TArbre a)
{
    if (a != NULL)
    {
        return a->filsGauche;
    }
    return NULL;
}
//Retourne fils Droit

TArbre noeudFilsDroit(TArbre a)
{
    if (a != NULL)
    {
        return a->filsDroit;
    }
    return NULL;
}

//Permet de supprimer l'arbre
void arbreSuppr(TArbre *noeud)
{
    if (*noeud != NULL)
    {       arbreSuppr(&((*noeud)->filsGauche));
            arbreSuppr(&((*noeud)->filsDroit));
            free(*noeud);
            *noeud = NULL;
    }
}


//Retroune l'hauteur de l'arbre
int hauteurArbre(TArbre a)
{
    if (a != NULL)
    {
        return 1 + MAX(hauteurArbre(a->filsGauche), hauteurArbre(a->filsDroit));
    }
    return -1;
}

// permet d'afficher une noeud
void afficherNoeuds(TArbre noeud, int espace)
{
    if (noeud != NULL)
    {
    	int i;
        for (i = 0; i < espace; i++)
            printf("-");

        if (noeud->caractere != '\0')
        {

            if(noeud->caractere == ' '){
                printf("NULL\n");
            }else{
                printf("%c\n", noeud->caractere);
            }
        }
        else
        {
            printf("\\0\n");
        }
        if (noeud->filsGauche != NULL)
            printf("(G)"); //Fils Gauche
        afficherNoeuds(noeud->filsGauche, espace + 1);
        if (noeud->filsDroit != NULL)
            printf("(D)"); //Fils Droit
        afficherNoeuds(noeud->filsDroit, espace + 1);
    }
}

//Permet d'afficher l'arbre
void afficherArbre(TArbre a)
{
    if (a != NULL)
    {
        printf(ANSI_COLOR_GREEN "*******************************ARBRE*******************************\n" ANSI_COLOR_RESET);
        printf("(R)"); //racine
        afficherNoeuds(a, 1);
        printf(ANSI_COLOR_GREEN "*******************************ARBRE*******************************\n" ANSI_COLOR_RESET);
    }

    else
        printf(ANSI_COLOR_BLUE "Arbre vide !\n" ANSI_COLOR_RESET);
}




