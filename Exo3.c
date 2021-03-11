#include <stdio.h>
#include <stdlib.h>


// Declaration du type UNION
 union U3{
   char   a; // 1 octet
   short  b; // 2 octet
   int    c; // 4 octet
   float  d; // 4 octet
   double e; // 8 octet
};

//___Programme principale ___________
int main(){
    
    int tail_union = sizeof(union U3) ;  // aura la valeur 8 le plus grand chant
    printf("Ennumeration du type UNION :\n ");

    //_________Partie-1_______ 
      union U3 u; // Declation de la variable u de type U3 

      printf("\tLa tail en Octer de la variable u de type UNION => %d Octet \n", tail_union);  // $ 8
        
    //_________Partie-2_______ 


      u.a='A'; // Affectation de la premiere valeur 
      printf("\tLe champ du type char contien la valeur = %c\n",u.a);   // affichage de la premiere affectation
      

      u.c=2; // seconde affectation pour un champ differant 
      printf("\tLe champ du type char(aprer affectation d'une valeur a un autre champ) contien la valeur = %d\n",u.a);  // Affichage aprer affectation d'une valeur a un autre champ
      
      printf("\n\n\t______________Fin du programme___________________\n\n");
      exit(0);
}

