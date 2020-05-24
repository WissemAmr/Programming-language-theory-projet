#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void ecrireFichier(char *fichier)
{

    FILE *file;

    // open file for writing
    file = fopen(fichier, "w");
    if (file == NULL)
    {
        fprintf(stderr, "\nErreur lors de l'ouverture du fichier\n");
        exit(1);
    }

    // write struct to file
    fwrite(&A, sizeof(struct Automate), 1, file);

    if (fwrite != 0)
        printf("\nEcriture sur le fichier avec succes !\n");
    else
        printf("\nErreur lors de l'ecriture sur le fichier !\n");

    // close file
    fclose(file);
};

void lireFichier(char *fichier)
{

    FILE *infile;

    // Open automate.dat for reading
    infile = fopen(fichier, "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nErreur lors de l'ouverture du fichier\n");
        exit(1);
    }

    // read file contents till end of file
    while (fread(&A, sizeof(struct Automate), 1, infile))
        //afficheAutomate(A);

    // close file
    fclose(infile);
};

void lireAutomate()
{

    /*************************************************************************************************/

    char lettre;
    int nbr;
    Alphabet *X, *X1, *Q;
    X = malloc(sizeof(Alphabet));
    X1 = X;
    Q = NULL;
    printf("\nDonner le nombre de lettres de l'alphabet X (Card(X)) : ");
    scanf("%d", &nbr);

    for (int i = 0; i < nbr; i++)
    {
        printf("\nDonner la %ieme lettre : ", i + 1);
        scanf("%s", &lettre);
        X1->lettre = lettre;
        X1->suiv = malloc(sizeof(Alphabet));
        Q = X1;
        X1 = X1->suiv;
    }
    Q->suiv = NULL;

    /**********************************************************************************************/

    listEtats *S, *S1, *Q1;
    int nbr1;
    Etat state;
    char nomEtat[MAX];

    printf("\nDonner le nombre d'etats de l'automate A (Card(S)) : ");
    scanf("%d", &nbr1);

    S = malloc(sizeof(listEtats));
    S1 = S;
    Q1 = NULL;

    for (int i = 0; i < nbr1; i++)
    {
        printf("\nDonner le nom du %deme etat : ", i + 1);
        scanf("%s", nomEtat);

        strcpy(state.nom, nomEtat);

        S1->etat = state;

        Q1 = S1;
        S1->suiv = malloc(sizeof(listEtats));
        S1 = S1->suiv;
    }
    Q1->suiv = NULL;

    /**********************************************************************************************/

    printf("\n\n");

    Etat S0;
    char etatInitial[MAX];

    printf("\nDonner le nom de l'etat initial (S0) : ");
    scanf("%s", etatInitial);

    strcpy(S0.nom, etatInitial);

    /**********************************************************************************************/

    printf("\n\n");
    int nbr2;
    Instruction i1;
    char lettre1[MAX];
    Etat s10;
    listInstructions *I, *I1, *Q2;

    I = malloc(sizeof(listInstructions));
    I1 = I;
    Q2 = NULL;

    printf("\nDonner le nombre d'instruction de l'automate A (Card(I)) : ");
    scanf("%d", &nbr2);

    for (int i = 0; i < nbr2; i++)
    {
        char nomEtat1[MAX];

        printf("\nL'instruction N = %d [Si, w, Sj]", i + 1);

        printf("\n\tSi : ");
        scanf("%s", nomEtat1);
        strcpy(s10.nom, nomEtat1);
        i1.Si = s10;

        printf("\n\tw : ");
        scanf("%s", lettre1);
        //i1.lettre = lettre1;
        strcpy(i1.lettre, lettre1);
        printf("\n\tSj : ");
        scanf("%s", nomEtat1);
        strcpy(s10.nom, nomEtat1);
        i1.Sj = s10;

        I1->instruction = i1;

        I1->suiv = malloc(sizeof(listInstructions));
        Q2 = I1;
        I1 = I1->suiv;
    }
    Q2->suiv = NULL;

    /**********************************************************************************************/

    printf("\n\n");

    int nbr3;
    char nomEtat2[MAX];
    Etat s11;

    listEtats *F, *F1, *Q3;
    F = malloc(sizeof(listEtats));
    F1 = F;
    Q3 = NULL;

    printf("\nDonner le nombre d'etats finaux de l'automate A : ");
    scanf("%d", &nbr3);

    for (int i = 0; i < nbr3; i++)
    {
        printf("Donner le nom du %dieme etat final : ", i + 1);
        scanf("%s", nomEtat2);
        strcpy(s11.nom, nomEtat2);
        F1->etat = s11;
        F1->suiv = malloc(sizeof(listEtats));
        Q3 = F1;
        F1 = F1->suiv;
    }
    Q3->suiv = NULL;

    /**********************************************************************************************/

    //Remplir la structure le l'automate A avec tous les pointeurs crees precedement !
    A.X = X;
    A.S = S;
    A.S0 = S0;
    A.I = I;
    A.F = F;
};

void afficheAutomate()
{
    // Affiche X
    printf("\nL'ensemble X : ");
    /*************************/
    afficheX();

    // Affiche S
    printf("\nL'ensemble S : ");
    /***********************/
    afficheEtat();

    printf("\nL'etat initiale S0 : ");
    printf("%s", A.S0.nom);

    //Affiche F
    printf("\nL'ensemble des etats finaux F : ");
    /*************************/
    afficheEtatFinaux();

    //Affiche I
    printf("\nL'ensemble des instructions I : ");
    /*********************/
    afficheInstruction();
};

void afficheX()
{
    Alphabet *x1 = A.X;
    printf("{ ");
    while (x1 != NULL)
    {
        printf("%c, ", x1->lettre);
        x1 = x1->suiv;
    }
    printf("}");
};

void afficheEtat()
{
    listEtats *s1 = A.S;
    printf("{ ");
    while (s1 != NULL)
    {
        printf("%s, ", s1->etat.nom);
        s1 = s1->suiv;
    }
    printf("}");
};

void afficheEtatFinaux()
{
    listEtats *f1 = A.F;
    printf("{ ");
    while (f1 != NULL)
    {
        printf("%s, ", f1->etat.nom);
        f1 = f1->suiv;
    }
    printf("}");
};

void afficheInstruction()
{

    listInstructions *i1 = A.I;

    printf("{ ");
    while (i1 != NULL)
    {
        printf("(");
        printf("%s, ", i1->instruction.Si.nom);
        printf("%s, ", i1->instruction.lettre);
        printf("%s, ", i1->instruction.Sj.nom);
        printf("), ");

        i1 = i1->suiv;
    }
    printf("}");
};

int cardF(){
    listEtats *f1 = A.F;
    int cpt = 0;
    while(f1!=NULL){
        cpt++;
        f1 = f1->suiv;
    }
    return cpt;
};

void automateMiroir()
{
    Etat sauv;
    listEtats *f = A.F;
    listInstructions *i = A.I;

    sauv = A.S0; //Sauvegarder l'etat initiale

    Etat state;
    //On inverse les instructions
    while(i != NULL){
        state = i->instruction.Si;
        i->instruction.Si = i->instruction.Sj;
        i->instruction.Sj = state;

        i = i->suiv;
    }

    i = A.I;

    //On traverse toute la liste des instructions jusqu'a arriver a la fin
    while(i->suiv != NULL){
        i = i->suiv;
    } //i pointera a la fin de la boucle vers le dernier maillon

    Instruction i1;
    Etat state1;

    if(cardF() >= 2){

        Etat state;

        strcpy(state.nom, "S0*");

        A.S0 = state; //Rendre le nouveau etat comme etat initial

        for(int j = 0; j < cardF(); j++){

            strcpy(state1.nom, "S0*");
            i1.Si = state1;
            strcpy(i1.lettre, "0"); //0 represente le mot vide
            strcpy(state1.nom, f->etat.nom);
            i1.Sj = state1;

            f = f->suiv;

            i->suiv = malloc(sizeof(listInstructions));
            i = i->suiv;
            i->instruction = i1;
        }
        i->suiv = NULL;

        f = malloc(sizeof(listEtats));
        f->etat = sauv; //sauv contient l'etat initial S0
        f->suiv = NULL;
        A.F = f;
    }else{ //cardF = 1

        A.S0 = A.F->etat;
        A.F->etat = sauv; //sauv contient l'etat initial S0
    }
};

Etat existInstruction(Etat state, char lettre[MAX] , int *trouv){

    listInstructions *i1 = A.I;
    *trouv = 0;

    while(i1 != NULL && !*trouv){
        if (strcmp(i1->instruction.Si.nom, state.nom) == 0 && strcmp(i1->instruction.lettre, lettre) == 0){
            *trouv = 1;
            return i1->instruction.Sj;
        }else{
            i1 = i1->suiv;
        }
    }
};

int nbPos(char mot[MAX]){
    int i = 0;
    while(mot[i] != '\0'){
        i ++;
    }
    return i;
};

int existEtat (listEtats *i1, Etat state){
    while(i1 != NULL){
        if (strcmp(i1->etat.nom, state.nom) == 0) return 1;
        else i1 = i1->suiv;
    }
    return 0;
};

int reconnaitreMot (char mot[MAX]){

    int i = 0;
    Etat state;
    int trouv;
    int tailleMot = nbPos(mot);

    char str[2] = "\0";
    str[0] = mot[0];

    state = existInstruction(A.S0, str, &trouv);
    if (trouv == 1){

        i++;

        while( i <= tailleMot - 1){

            trouv = 0;
            str[0] = mot[i];
            state = existInstruction(state, str, &trouv);

            if(trouv == 1){
                    i ++;
            }else{
                return 0;
            }
        }
        if (existEtat(A.F, state)){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
};

void ajouterEtat (listEtats *liste, Etat state){

    while(liste->suiv != NULL){
        liste = liste->suiv;
    }

    liste->suiv = malloc(sizeof(listEtats));
    liste = liste->suiv;
    liste->etat = state;
    liste->suiv = NULL;
};

void ajouterInstruction (listInstructions *i1, Instruction ins){

    while(i1->suiv != NULL){
        i1 = i1->suiv;
    }

    i1->suiv = malloc(sizeof(listInstructions));
    i1 = i1->suiv;
    i1->instruction = ins;
    i1->suiv = NULL;
};

void automateComplet(){

    Etat P;
    strcpy(P.nom, "P");
    Instruction ins;
    int entrer = 0;

    listEtats *s1 = A.S;
    Alphabet *x1 = A.X;
    char str[2] = "\0";
    int trouv;

    while(s1 != NULL){

        while(x1 != NULL){

            str[0] = x1->lettre;

            existInstruction(s1->etat, str, &trouv);

            if (!trouv){

                entrer = 1; //Pour savoir si on rajoute P a S ou non

                ins.Si = s1->etat;
                ins.Sj = P; //Etat puit
                strcpy(ins.lettre, str);

                ajouterInstruction(A.I, ins);
            }

            x1 = x1->suiv;
        }

        x1 = A.X; // Reinistialisation de la liste des alphabets
        s1 = s1->suiv;
    }

    if (entrer) ajouterEtat(A.S, P);

    //Ajouter les instructions de P
    x1 = A.X;
    str[2] = "\0";

    while(x1 != NULL){

        str[0] = x1->lettre;

        ins.Si = P;
        ins.Sj = P;
        strcpy(ins.lettre, str);

        ajouterInstruction(A.I, ins);

        x1 = x1->suiv;
    }

    //Ajouter P a L'ensemble des etats finaux
    ajouterEtat(A.F, P);
};

void retirerEtatFinal(listEtats *e1, Etat state){

    listEtats *q = NULL;
    int trouv = 0;

    if (existEtat(e1, state)){

        while(e1 != NULL && !trouv){
            if (strcmp(e1->etat.nom, state.nom) == 0){

                trouv = 1;

                if (strcmp(A.F->etat.nom, e1->etat.nom) == 0){
                A.F = A.F->suiv;

                }else{
                    q->suiv = e1->suiv;
                }
            }else{
                q = e1;
                e1 = e1->suiv;
            }
        }
    }
};

void automateComplement(){

    automateComplet();
    listEtats *s1 = A.S;
    while(s1 != NULL){
        if (existEtat(A.F, s1->etat)){
            retirerEtatFinal(A.F, s1->etat);
        }else{
            ajouterEtat(A.F, s1->etat);
        }

        s1 = s1->suiv;
    }
};

void retirerInstruction(Instruction ins){

    listInstructions *i1 = A.I;
    int trouv = 0;
    listInstructions *q = NULL;

    while(i1 != NULL && !trouv){
        if ( (strcmp(i1->instruction.Si.nom, ins.Si.nom) == 0) && (strcmp(i1->instruction.Sj.nom, ins.Sj.nom) == 0) && (strcmp(i1->instruction.lettre, ins.lettre) == 0)){

            trouv = 1;

            if(A.I == i1){
                A.I = i1->suiv;
            }else{
                q->suiv = i1->suiv;
            }
        }else{
            q = i1;
            i1 = i1->suiv;
        }
    }
};

void automatePGeneralise(){

    listInstructions *i1 = A.I;
    Etat state;
    Instruction ins;
    char lettre[2] = "\0";
    int i = 0;
    int taille;

    while(i1 != NULL){

        if(nbPos(i1->instruction.lettre) >= 2){

            taille = nbPos(i1->instruction.lettre); //La taille du champ lettre de l'instruction

            Etat st1 = i1->instruction.Si;
            for(int j = 0; j < taille - 1; j++){
                snprintf(state.nom, MAX, "S0*%d", i);
                i++;
                ins.Si = st1;
                ins.Sj = state;

                lettre[0] = i1->instruction.lettre[j];
                strcpy(ins.lettre, lettre);

                ajouterInstruction(A.I, ins);
                ajouterEtat(A.S, state);

                st1 = state;
            }
            ins.Si = state;
            ins.Sj = i1->instruction.Sj;
            lettre[0] = i1->instruction.lettre[taille-1];
            strcpy(ins.lettre, lettre);

            ajouterInstruction(A.I, ins);

            retirerInstruction(i1->instruction);
        }
        i1 = i1->suiv;
    }
};
