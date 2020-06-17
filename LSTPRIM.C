#include <stdio.h>
#include <stdlib.h>
#include "LSTPRIM.H"



NOEUD noeudCreer ( char c )
{
    NOEUD n;

    n = (NOEUD) malloc (sizeof(structNoeud));
    if(!n)
        printf("\n pas d'espace dans la mémoire");
    else
    {
        n->FD= NULL;
        n->FG= NULL;
        n->suivant = NULL;
        n->pere =NULL;
        n->frequence =0;
        n->parite =0;
        n->caractere=c;

    }
    return (n);
}

void noeudDetruire(NOEUD n)
{
    free(n);
}

LISTE listeCreer()
{
    LISTE L;
    L = (LISTE) malloc(sizeof(laStruct));
    if(!L)
    {
        printf("\nProbleme de memoire") ;
        exit(0) ;
    }
    L->tete =NULL;
    L->lg = 0;
    return(L);
}

void listeDetruire(LISTE l)
{
    free(l);
}



void inserer(LISTE l,NOEUD n, NOEUD fd, NOEUD fg)
{
    n->FD = fd;
    n->FG =fg;
    n->frequence=fg->frequence + fd->frequence;
    fg->pere =n;
    fd->pere =n;
    fg->parite=1;
    l->lg++;
}



int listeTaille(LISTE L)
{
    return (L->lg);
}
int listevide (LISTE L)
{
    return (L->lg==0);
}

//insertion de la liste chainee contenant les caracteres//
void insererliste (LISTE L,NOEUD n, int pos)
{
    int i;
    if (pos==1)
    {
        n->suivant=L->tete;
        L->tete=n;
    }
    else
    {
        NOEUD q,p;
        q=L->tete;
        for (i=1; i<pos; i++)
        {
            p=q;
            q=q->suivant;
        }
        p->suivant=n;
        n->suivant=q;
    }
    (L->lg)++;

}
void listeAfficher(LISTE L)
{
    int i;
    NOEUD p;
    p=L->tete;
    for (i=1; i<=listeTaille(L); i++)
    {

        printf ("\t\t%c :",p->caractere);
        printf ("\t\t%i\n",p->frequence);
        p=p->suivant;
    }
}

