#ifndef LSTPTR_H
#define LSTPTR_H

typedef struct structNoeud {
   struct structNoeud *FD;
   struct structNoeud *FG;
   struct structNoeud *suivant;
   struct structNoeud *pere;
   int frequence;
   int parite;
   char caractere;
}structNoeud , *NOEUD;

typedef struct {
    NOEUD tete;
    int lg;
} laStruct,*LISTE;


#endif // LSTPTR_H_INCLUDED
