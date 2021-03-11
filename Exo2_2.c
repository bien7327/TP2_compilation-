#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Prototype
void Test_arg (int nbr) ;
int Test_num (char par[],int arg);
char* sous_chaine(const char * src, unsigned debut, unsigned fin);
void test_DF (int debut,int fin);

//variables-Global 
char * src;  // Chaine a traiter
int len_ch;     // Longeur de la chaine principale (a traiter)

//____________programe pricipale________________
int main(int argc, char* argv[]) {
    int debut_sch , fin_sch ; // Debut et fin de la sous chaine
    int nbr_arg = argc - 1 ; // nombre d'argument sans le nom du programme
    char *s_chaine;          // Sous chaine a extraire
    
    Test_arg(nbr_arg);       // Test si l'appel somme comme suit: ./<nom_prog> <chaine(scr)> <debut_s.chaine> <fin_s.chaine>
    
    //Initialisation apre test que c des valeur decimal
    debut_sch = Test_num(argv[2],2);// Debut  de la sous chaine
    fin_sch   = Test_num(argv[3],3);// Fin de la sous chaine
    test_DF(debut_sch,fin_sch); // tester si fin >= DEbut sion error et fin du prog
    
    len_ch = strlen(argv[1]);  // tail de la chaine principale src
    src = (char*) malloc((len_ch+1)*sizeof(char)); // Allocation d'un espace memoir de la tail de L'argument +1 (pour le caractere FIN'\0')  
    strcpy(src,argv[1]);  // copier la valeur de chaine ver la variable src 

    s_chaine= sous_chaine(src,debut_sch,fin_sch);  // Extraire la sous chaine
    
    printf(" La sous-chaine qui debut a la position %d qui fini a la position %d est : %s\n", debut_sch,fin_sch, s_chaine); 

    
     //_________________________________________________________________

    printf("\n\n\t______________Fin du programme___________________\n\n");
    free(src); // Liberation de l'espace allouer
    exit(0); // fin du programme avec succee
    }




void Test_arg(int nbr) {
    /*
    Procedure qui tesque si l'utilisateur  saisie les bon argument
    Teste du nombre d'argument : 
            Renvois une erreur si le nbr depasse 3 arg ou moin de 3 arg avec specification des erreur
            Sinon ne renvois rien (test passer) 
    */

            switch (nbr)  
            {// cas de manque d'argument 
            case 0: { 
                printf("ERROR : Aucun argument n'as ete saisie \n");
                break;
                }
            case 1: { 
                printf("ERROR : veiller delimiter le debut et la fin de la chaine \n");
                break;
                }
            case 2:{ 
                printf("ERROR : veiller delimiter la fin de la chaine \n");
                break;
                }
            case 3: // cas de saise d'un unique argument (le cas souhaiter) 
                    return; //sortie de la procedure 
            default: // cas de saise de plus de 3 arguments
                printf("ERROR : Trop d'arguments !\n ");
                break;  
            }

            // Rappele de la syntaxe a l'utilisateur et arret du programme    
            
            printf(" \nINFO : veuillez saisire la commande de de la maniere suivante :");
            printf(" \n \t  $./<nom_prog> <chaine(scr)> <debut_s.chaine> <fin_s.chaine>\n ");
            exit(-1);
        }



int Test_num(char par[],int arg){
    /*
    fonction qui teste si l'argument est constituer que de caractere decimeaux
    et si oui renvois sa valeur decimale
    */      
            int len_par = strlen(par);  // Tail du parametre
            char cc;    //caractere courant
            int num;    //Contindra la valeur decimal de l'argument
            int i=0;    // Initialisation du compteur

            // Parcour de la chaine
            while (i< len_par){ 
                            cc=par[i] ; // Initialisation 
                                       

                            // Test si le caracter est dans l'intervale [0-9] 
                            if ((cc < 48 ) ||  (cc > 57 ))  { // ASCI => '0' = 48 '9'= 57
                                    printf("Error : le caractere a la position %d  [_%c_] de l argument %d n est pas un chiffre. " , i , cc, arg );
                                    printf(" \n\nINSTUCTION : veuillez saisire que des chiffre. \n");
                                    exit(1); // arret du programme si l'arg contien un caractere autre qu'un entier
                                    }
                            i++;     // caractere suivant   
                            }
            num= atoi(par); // Recupere le nombre en valeur entiere
            return num ;    // le retourner
        }


char* sous_chaine(const char * src, unsigned debut, unsigned fin){
   /*
   Extrait le sous chaine de la chaine src qui debut de <debut> jusqu'a <fin>
   Retourne un chaine de caractere
   */
        char * sc; //Sous chaine
        int len_sc = fin-debut+1; //Tail de la sous chaine 

        sc=(char*)malloc(len_sc+1);  // Allocation d'un espace memoire de la tai de la sous chiane souhaiter + 1 (pour le caractere FIN'\0')  
        strncpy(sc,src+debut-1,len_sc); // extraire la sous chaine dans la variable sc 
        // (src+ debut) designe le caractere de debut de la sous chaine dans la chaine src qui sera de longeure (len_sc)
        sc[len_sc+1 ]='\0'; // ajout du caractere de FIN
     
        return sc; // retourner la sous chaine
        // pas besoin de la procefure free() puisque nous somme dans une procedure 
 }

void test_DF (int debut,int fin) { 
    if (fin < debut ){ // Rappele de la syntaxe a l'utilisateur et arret du programme   
            printf("ERROR : FIN de la sous chaine supperieure au DEBUt de la sous chaine\n ");  
            printf(" \nINFO : veuillez saisire la commande de de la maniere suivante :");
            printf(" \n \t$./<nom_prog> <chaine(scr)> <debut_s.chaine> <fin_s.chaine>\n ");
            printf(" \tAvec la valeur de  <fin_s.chaine> Superieur ou egal a la VAleure de <debut_s.chaine>  \n ");
            exit(-1);
     
}
}