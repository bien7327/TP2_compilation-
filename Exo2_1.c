#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Prototype
void Test_arg (int nbr) ;
int Test_num (char par[]);

//Variables-Global 
char * nombre;  // Le Nombre saisie
int len_arg;    // La Langeur de l'argument saisie

//____________Programe Pricipale________________
int main(int argc, char* argv[]) {

    int nbr_arg = argc - 1 ;  //Nombre d'argument saisie    
    int valeur ;              //La valeur entiere de l'argument 
    int _double;              //Le double du nombre saisie   
    
    Test_arg(nbr_arg);        // Tester si l'utilisateur a saisie un et un seul argument

    // Initialisation
    len_arg = strlen(argv[1]); // largeur de l'argument saisie
    nombre = (char*) malloc((len_arg+1)*sizeof(char)); // Allocation d'un espace memoir de la tail de L'argument +1 (pour le caractere FIN'\0')  
    
    
    strcpy(nombre,argv[1]);  // copier la valeur de l'argument ver la variable nombre
    valeur=Test_num(nombre); // tester si la chaine contien que des valeur decimal puit l'affecter 
    _double = valeur*2;      // calcule du double
    
    printf(" Le Double du nobre que vous avez saisie [%d] est : %d  => [ %d * 2 = %d ].\n" , valeur,_double,valeur,_double); // Affichage de resultat

    
    

    //_________________________________________________________________

    printf("\n\n\t______________Fin du programme___________________\n\n");
    free(nombre); // Liberation de l'espace allouer
    exit(0); // fin du programme avec succee
    }



void Test_arg(int nbr) {
    /*
    Procedure qui tesque que l'tilisateur a saisie un et un seul arguemnt
    Teste du nombre d'argument : 
            Renvois un erreur si le nbr depasse 1 arg
            Sinon ne renvois rien (test passer) 
    */

            switch (nbr)  
            {
            case 0:{ // cas aucun argument n'est saisie
                printf("ERROR : Argument manquant !\n");
                break;
                }
            case 1: // cas de saise d'un unique argument (le cas souhaiter) 
                    return; //sortie de la procedure 
            default: // cas de saise de plus d'un argument
                printf("ERROR : Trop d'arguments !\n ");
                break;  
            }

            // Rappele de la syntaxe a l'utilisateur et arret du programme     
            printf(" \nINFO : veuillez saisire la commande de de la maniere suivante :");
            printf(" \n \t  $./<Nom_du_programme> <Nombre_choisie>\n ");
            exit(-1);
        }


int Test_num(char par[]){
    /*
    fonction qui teste si l'argument est constituer que de caractere decimeaux
    et si oui renvois sa valeur decimale
    */
            char cc;    //caractere courant
            int num;    //Contindra la valeur decimal de l'argument
            int i=0;    // Initialisation du compteur


            // Parcour de la chaine
            while (i< len_arg){ 
                            cc=par[i] ; // Initialisation 

                            // Test si le caracter est dans l'intervale [0-9] 
                            if ((cc < 48 ) ||  (cc > 57 ))  { // ASCI => '0' = 48 '9'= 57
                                    printf("Error : le caractere a la position %d  [_%c_]  n est pas un chiffre. " , i , cc );
                                    printf(" \n\nINSTUCTION : veuillez saisire que des chiffre. \n");
                                    exit(1); // arret du programme si l'arg contien un caractere autre qu'un entier
                                    }
                            i++;     // caractere suivant   
                            }
            num= atoi(par); // Recupere le nombre en valeur entiere
            return num ;    // le retourner
        }

