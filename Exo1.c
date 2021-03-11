#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

int nbr_arg = argc-1 ; // nbr_arg : contient le nombre d'argument passer par l'utilisateur qui exclue le nom du programe 
        switch (argc)  // Gerer le cas d'absence d'argument 
        {
        case 1: { // Cas d'abssance d'argument 
            printf("INFO : Vous n'avez pas saisie d'argument \n" );
            printf(" \nINFO : veuillez saisire la commande de de la maniere suivante :");
            printf(" \n \t  $./<Nom_du_programme> <Argument1> <Argument2> ...ext \n ");
            break;
                 }   
            
        default: { 
            printf(" Vous venez de saisire  %d Argumant(s) :  \n", nbr_arg ); // nombre d'argument
               // Affichage des argument saisie a l'aide d'un boucle
            for (int j = 1; j < argc; j++)
            {
                printf("\tL'argument numero %d = %s. \n",j, argv[j]);
            }
                    }  
           
      } 
           
       printf("\n\n\t______________Fin du programme___________________\n\n");
       exit(0);
    }

