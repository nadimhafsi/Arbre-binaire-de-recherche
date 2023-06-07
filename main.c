//Pour Tester les Fonctions Primitives de l'Arbre et de Dictionnaire
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "lib/arbre.h"
#include "lib/dico.c"


#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"


int main(){
    TArbre dico;
	dico = arbreConsVide();



int i=0,j=0;
srand(time(NULL));

	char *mot= malloc( 255 );
	char *motinsert=malloc( 255 );
	char *motsearch=malloc( 255 );






	int choix;




    do
    {  system("clear");
      printf("\n\n \n##################################################\n\n\n");
      printf(ANSI_COLOR_GREEN"\n1 : Piocher un mot\n");
      printf("\n2 : Afficher Arbre\n");
      printf("\n3 : Afficher Dictionnaire\n");
      printf("\n4 : Nbre de mots different dans dictionnaire\n");
      printf("\n5 : Frequences de lettres dans dictionnaire\n");
      printf("\n6 : Inserer mot dans le dictionnaire\n");
      printf("\n7 : Afficher nombre de mots total\n");
      printf("\n8 : Supprimer dictionnaire\n");
      printf("\n9 : chercher un mot\n");
      printf("\n10 : Hauteur de l'arbre\n");
      printf("\n11 : Test du programme d'enoncé\n");
      printf("\n0 : Fin du programme\n"ANSI_COLOR_RESET);
      printf("\n\nVotre choix :");
      scanf("%d",&choix);

      switch(choix)
      {
          case 1 :  {      {
                            int x=piocherMot(mot);
	                        if(x==1){
	                       	dicoInsererMot(mot,&dico);
	                                }

                             afficherArbre(dico);
                             printf("Mot piocher : ");
                             printf(ANSI_COLOR_RED   "%s\n" ANSI_COLOR_RESET,mot );

                             dicoAfficher(dico);


                             printf("nombre de occurrence de ''" ANSI_COLOR_RED "%s" ANSI_COLOR_RESET  "'' dans le dictionnaire est : %i \n",mot,dicoNbOccMot(mot,dico));
                             }  break;

                             }
          case 2 :  {        afficherArbre(dico);                ;break;}

          case 3 :  {        dicoAfficher(dico);                ;break;}

          case 4 :  {        printf(ANSI_COLOR_BLUE"\nNbr de mots different est: "ANSI_COLOR_RESET"%i\n",dicoNbMotsDifferents(dico))  ;break;}
          case 5 :  {        lettrespercentage(dico);               ;break;}

          case 6 :  {        printf(ANSI_COLOR_BLUE"\n donner le mot a inserer : "ANSI_COLOR_RESET);
                             scanf("%s",motinsert);
                             dicoInsererMot(motinsert,&dico);break;}

          case 7 :  {       printf(ANSI_COLOR_BLUE"le nobre total de mots est : "ANSI_COLOR_RESET"%d\n",dicoNbMotsTotal(dico) )     ;break;}

          case 8 :  {    arbreSuppr(&dico);
                         printf(ANSI_COLOR_RED"le dictionnaire est supprimee "ANSI_COLOR_RESET);
                            ;break;}

         case 9 :  {    printf(ANSI_COLOR_BLUE"\ndonner le mot a chercher : "ANSI_COLOR_RESET);
                             scanf("%s",motsearch);
                                if (strcmp(motsearch,DicSearch(motsearch,j,dico)) == 0)
                                    printf(ANSI_COLOR_GREEN"\ncette mot est existe deja et le nombre d'occurence est:"ANSI_COLOR_RESET" %d\n",dicoNbOccMot(motsearch,dico));
                                else
                                    printf(ANSI_COLOR_RED"\ncette mot n'existe pas dans le dictionnaire\n"ANSI_COLOR_RESET);
                                 ;break;}
          case 10 :  { printf(ANSI_COLOR_BLUE"\nla hauteur de l'arbre est : "ANSI_COLOR_RESET" %d\n",hauteurArbre(dico) );
                              ;break;}
          case 11 :  { TArbre dico; char buffer[100];
                        dico = arbreConsVide();
                        strcpy(buffer, "gallon");
                        dicoInsererMot(buffer, &dico);
                        dicoAfficher(dico); printf("\n");
                        strcpy(buffer, "munier");
                        dicoInsererMot(buffer, &dico);
                        dicoAfficher(dico); printf("\n");
                        strcpy(buffer, "abenia");
                        dicoInsererMot(buffer, &dico);
                        dicoAfficher(dico); printf("\n");
                        strcpy(buffer, "munier");
                        dicoInsererMot(buffer, &dico);
                        dicoAfficher(dico); printf("\n");
                        strcpy(buffer, "mumu");
                        dicoInsererMot(buffer, &dico);
                        dicoAfficher(dico); printf("\n");
                        strcpy(buffer, "alpha");
                        dicoInsererMot(buffer, &dico);
                        strcpy(buffer, "alphabeta");
                        dicoInsererMot(buffer, &dico);
                        strcpy(buffer, "al");
                        dicoInsererMot(buffer, &dico);
                        dicoAfficher(dico); printf("\n");
                        printf("\"%s\" \t -> %d\n", "gallon", dicoNbOccMot("gallon",dico));
                        printf("\"%s\" \t\t -> %d\n", "mumu", dicoNbOccMot("mumu",dico));
                        printf("\"%s\" \t -> %d\n", "munier", dicoNbOccMot("munier",dico));
                        printf("\"%s\" \t -> %d\n", "gastro", dicoNbOccMot("gastro",dico));
                        printf("\"%s\" \t -> %d\n", "lespine", dicoNbOccMot("lespine",dico));
                        printf("\"%s\" \t\t -> %d\n", "aaa", dicoNbOccMot("aaa",dico)); printf("\n");
                        /* -------------------------------------------------------*/
                              ;break;}

          case 0 :  {        printf("\n\nfin du prgramme\n")   ;break;}
          default : printf("choix errone\n\n\n");
      }

    getch();
    }
    while(choix!=0);






return 0;
}
