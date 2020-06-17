#ifndef LSTPRIM_H
#define LSTPRIM_H
#include "LSTPTR.H"

NOEUD noeudCreer ( char );
void noeudDetruire(NOEUD);
LISTE listeCreer(void);
void listeDetruire(LISTE);
int estVide(LISTE);
int estSaturee(LISTE);
int listeTaille(LISTE);
void inserer(LISTE,NOEUD,NOEUD,NOEUD);
void listeAfficher(LISTE);
void insererliste (LISTE,NOEUD,int);




 // LSTPRIM_H_INCLUDED
#endif
