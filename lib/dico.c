
int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}

int piocherMot(char *motPioche)
{

 FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
 int nombreMots = 0, numMotChoisi = 0, i = 0;
 int caractereLu = 0;
 dico = fopen("Dictionnaire.txt", "r"); // On ouvre le dictionnaire en lecture seule
 // On v�rifie si on a r�ussi � ouvrir le dictionnaire

if (dico == NULL) // Si on n'a PAS r�ussi � ouvrir le fichier
 {
 printf("\nImpossible de charger le dictionnaire de mots");
 return 0; // On retourne 0 pour indiquer que la fonction a �chou�
 // � la lecture du return, la fonction s'arr�te imm�diatement.
 }

 // On compte le nombre de mots dans le fichier (il suffit de compter les
 // entr�es \n
 do
 {
 caractereLu = fgetc(dico);
 if (caractereLu == '\n')
 nombreMots++;
 } while(caractereLu != EOF);

 numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard
 // On recommence � lire le fichier depuis le d�but. On s'arr�te lorsqu'on est arriv� au bon mot
 //printf("random number=%d\n",numMotChoisi);
 rewind(dico);

 while (numMotChoisi > 0)
 {

 caractereLu = fgetc(dico);

if (caractereLu == '\n')
 numMotChoisi--;
 }


 /* Le curseur du fichier est positionn� au bon endroit.
 On n'a plus qu'� faire un fgets qui lira la ligne */
fgets(motPioche,100, dico);

 // On vire le \n � la fin



 motPioche[strlen(motPioche) - 2] = '\0';

 fclose(dico);
 return 1; // Tout s'est bien pass�, on retourne 1
}

// pour inserer un mot dans l'arbre
void insererMot(char *mot, TArbre *noeud)
{
    if (*noeud != NULL)
    {
        if (mot[0] != '\0') //pas fin de mot
        {
            if ((*noeud)->caractere == mot[0])
            {
                mot++;
                insererMot(mot, &((*noeud)->filsGauche));
            }
            else
            {
                if ((*noeud)->filsDroit != NULL)
                {
                    insererMot(mot, &((*noeud)->filsDroit));
                }
                else
                {
                    (*noeud)->filsDroit = arbreCons(mot[0], 0, NULL, NULL);
                    insererMot(mot, &(*noeud));
                }
            }
        }
        else if (mot[0] == '\0' && (*noeud)->caractere != '\0')
        {
                    TArbre n = arbreCons('\0', 1, NULL, *noeud);
                    *noeud = n;
        }
        else if (mot[0] == '\0' && (*noeud)->caractere == '\0') //fin de mot
        {
            (*noeud)->nbrOccurrence++;
        }
    }
    else
    {
        if (mot[0] != '\0')
        {
            *noeud = arbreCons(mot[0], 0, NULL, NULL);
            mot++;
            insererMot(mot, &((*noeud)->filsGauche));
        }
        else
        {
            *noeud = arbreCons('\0', 1, NULL, NULL);
        }
    }
}


//Permet d'ajouter un mot au dictionnaire
void dicoInsererMot(char *mot, TArbre*arbre)
{
    if (strlen(mot) > 0)
    {
        if (*arbre == NULL)
            *arbre = arbreConsVide();

        insererMot(mot, arbre);

    }
}


void afficherMots(char *mot, Noeud *noeud)
{
    if (noeud != NULL)
    {
        if (noeud->caractere != '\0')
        {
            if (noeud->filsDroit != NULL) //fait rien
            {
                afficherMots(mot, noeud->filsDroit);
            }
            if (noeud->filsGauche != NULL) //ajouter caractere à mot
            {
                strcat(mot, (char[2]){noeud->caractere, '\0'});
                afficherMots(mot, noeud->filsGauche);
            }
            mot[strlen(mot) - 1] = '\0'; //supprimer caractere
        }
        else
        {
            printf("(%i) %s\n", noeud->nbrOccurrence,mot);//aficher mot
            if (noeud->filsDroit != NULL)
                afficherMots(mot, noeud->filsDroit);
        }
    }

    else
        printf(ANSI_COLOR_BLUE "Dictionnaire vide !\n" ANSI_COLOR_RESET);
}

//Permet d'afficher le dictionnaire
void dicoAfficher(TArbre a)
{
    printf(ANSI_COLOR_GREEN "*******************************DICTIONNAIRE*******************************\n" ANSI_COLOR_RESET);
    char mot[100] = "";
    afficherMots(mot, a);
     printf(ANSI_COLOR_GREEN "*******************************DICTIONNAIRE*******************************\n" ANSI_COLOR_RESET);
}





int dicoNbMotsDifferents(TArbre a){

    if (a == NULL)
        return 0;
	int test=(a->caractere == '\0')?1:0;
    return  test+dicoNbMotsDifferents(a->filsGauche)  + dicoNbMotsDifferents(a->filsDroit);
}

int dicoNbMotsTotal(TArbre a){

    if (a == NULL)
        return 0;
	int test=(a->caractere == '\0')?a->nbrOccurrence:0;
    return  test+dicoNbMotsTotal(a->filsGauche)  + dicoNbMotsTotal(a->filsDroit);
}







int dicoNbOccMot(char mot[],TArbre noeud){

	  if(noeud != NULL){
        if(mot[0] == noeud->caractere ){
            if(mot[0] == '\0'){
                  return noeud->nbrOccurrence;
            }else{
                mot++;
                return dicoNbOccMot(mot,noeud->filsGauche);
            }
        }
        return dicoNbOccMot(mot,noeud->filsDroit);
      }
      return 0;
}




////////////
int occchar(TArbre a,char c){

    if (a == NULL)
        return 0;
	int test=(a->caractere == c)?1:0;
    return  test+occchar(a->filsGauche,c)  + occchar(a->filsDroit,c);
}
int totalchar(TArbre a){

    if (a == NULL)
        return 0;
	int test=(a->caractere != '\0')?1:0;
    return  test+totalchar(a->filsGauche)  + totalchar(a->filsDroit);
}
void lettrespercentage( TArbre a){
	 char c;

	         printf(ANSI_COLOR_GREEN"_______________________________\nFrequence des lettres\n_______________________________\n" ANSI_COLOR_RESET);

    for (c = 'a'; c <= 'z'; ++c)
        printf("\t%c:%.1f%% \n", c,( (double)occchar(a,c)/ (double)totalchar(a))*100);

}


char* DicSearch(char * mot, int currentLetter, TArbre pa) {
    char *ch="no";
  if (pa != NULL) {
    if (currentLetter < strlen(mot)) {
      if (mot[currentLetter] == pa ->caractere) {

        DicSearch(mot, currentLetter + 1, pa ->filsGauche);
      } else {
        DicSearch(mot, currentLetter, pa ->filsDroit);
      }

    } else {
      if (pa ->caractere == '\0') {return mot;}
      else   return ch;
    }
  } else {return ch;}

}


