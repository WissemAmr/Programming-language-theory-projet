#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"





int main()
{
    lireAutomate();


    char *nom = "automate.dat";
    int choice = 1;
    char mot[MAX];

    while(choice){
        printf("\n************TP THP - PRESENTATION **************");
        printf("\n**************************************************");
        printf("\n1. Lire automate ");
        printf("\n2. Afficher automate ");
        printf("\n3. Automate Miroir");
        printf("\n4. Reconaitre mot d'un automate ");
        printf("\n5. Automate complet ");
        printf("\n6. Automate complement ");
        printf("\n7. Automate partiellement generalise ");
        printf("\n8. Sauvegarder l'automate dans un fichier (.dat) ");

        printf("\n\nVeuillez entrer votre choix : ");
        scanf("%d", &choice);
        switch(choice){

        case 1:
            lireAutomate();
            break;

        case 2:
            afficheAutomate();
            break;

        case 3:
            automateMiroir();
            break;

        case 4:
            printf("\nVeillez donner le mot : ");
            scanf("%s", mot);
            if (reconnaitreMot(mot)){
                printf("\nLe mot est reconnu par l'automate");
            }else{
                printf("\nLe mot n'et pas reconnu par l'automate");
            }
            break;

        case 5:
            automateComplet();
            break;

        case 6:
            automateComplement();
            break;

        case 7:
            automatePGeneralise();
            break;

        case 8:

            printf("\nVeillez donnez le nom du fichier : ");
            scanf("%s", mot);

            ecrireFichier(mot);
            break;


        default:
            printf("\nLe numero n'existe pas !");
        }

        printf("\n\nVoulez vous revenir au menuprincipale ? 1/0 : ");
        scanf("%d", &choice);
    }

    return 0;
}
