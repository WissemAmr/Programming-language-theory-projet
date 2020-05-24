#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#define MAX 40

typedef struct Alphabet Alphabet;
struct Alphabet
{
    char lettre;
    Alphabet *suiv;
};

typedef struct Etat Etat;
struct Etat
{
    char nom[MAX];
};

typedef struct listEtats listEtats;
struct listEtats
{
    Etat etat;
    listEtats *suiv;
};

typedef struct Instruction Instruction;
struct Instruction
{
    Etat Si;
    char lettre[MAX]; //Automate de depart est non deterministe
    Etat Sj;
};

typedef struct listInstructions listInstructions;
struct listInstructions
{
    Instruction instruction;
    listInstructions *suiv;
};

typedef struct Automate Automate;
struct Automate
{
    Alphabet *X;         // L'ensemble de l'alphabet de l'automate
    listEtats *S;        // L'ensemble des etats de l'automate
    Etat S0;             // L'etat initiale de l'automate
    listInstructions *I; // L'ensemble des instructions de l'automate
    listEtats *F;        // L'ensemble des etats finaux de l'automate
}A;

//Declaration of functions
void ecrireFichier(char *fichier);
void lireFichier(char *fichier);
void lireAutomate();
void afficheAutomate();
void afficheX();
void afficheEtat();
void afficheEtatFinaux();
void afficheInstruction();
int cardF();
void automateMiroir();
Etat existInstruction(Etat state, char lettre[MAX] , int *trouv);
int nbPos(char mot[MAX]);
int existEtat (listEtats *i1, Etat state);
int reconnaitreMot (char mot[MAX]);
void ajouterEtat (listEtats *liste, Etat state);
void ajouterInstruction (listInstructions *i1, Instruction ins);
void automateComplet();
void retirerEtatFinal(listEtats *e1, Etat state);
void automateComplement();
void retirerInstruction(Instruction ins);
void automatePGeneralise();



#endif // FUNCTIONS_H_INCLUDED
