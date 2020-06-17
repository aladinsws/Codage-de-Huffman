#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "LSTPRIM.H"
#include "LSTPRIM.C"


int longeur;



int existe (char ch[1000],char c,int pos)   //Vérifie si un caractére existe dans la chaine du début jusqu'à pos//
{
    int i=0, vrai=0;
    while ((i<pos)&&(vrai==0))
    {
        if (ch[i]==c)
            vrai=1;
        else i++;
    }
    return (vrai);
}

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
int occurence(char ch[1000], char c)    //Compter le nombre d'occurrences d'un caractére dans une chaine//
{
    int i, cnt=0;
    for(i=0; i<strlen(ch); i++)
    {
        if(ch[i]==c) cnt++;
    }
    return(cnt);
}

void nouvelleliste (LISTE L, char ch [1000])  //Création d'une liste à partir d'une chaine de caractéres//
{
    //LISTE L=listeCreer();
    int j=0,occ,k=1;
    while (j<strlen(ch))
    {
        occ=0;
        if ((existe (ch, ch[j],j))==0)
        {
            occ=occurence(ch,ch[j]);
            NOEUD n = noeudCreer(ch[j]);
            n->frequence = occ;
            insererliste(L,n,k);
            k++;
        }
        j++;
    }

}

NOEUD min1(LISTE L)    //retourner l'adresse de NOEUD possedant la plus faible fréquence//
{
    NOEUD q = L->tete;
    int min=longeur;
    NOEUD adrmin1;
    NOEUD p;
    while (q!=NULL)
    {
        if( q->pere==NULL)
        {
            if (q->frequence<=min)
            {
                min= q->frequence;
                adrmin1=q;
            }
        }
        else if( q->pere!=NULL)
        {
            p= q;
            while (p->pere!=NULL)
            {
                p= p->pere;
            }
            if (p->frequence<=min)
            {
                min= p->frequence;
                adrmin1=p;
            }

        }
        q=q->suivant ;
    }
//printf("%c",adrmin1->caractere);
    return adrmin1;
}


NOEUD min2 (LISTE L, NOEUD adrmin1)      //retourner l'adresse de NOEUD possedant la plus faible fréquence qui déffère de min1//
{
    NOEUD p, q, adrmin2 ;
    int min=longeur;
    q = L->tete;
    while (q!=NULL)
    {
        if( q->pere==NULL)
        {
            if ((q->frequence<=min)&&(q!=adrmin1))
            {
                min= q->frequence;
                adrmin2=q;
            }
        }
        else if( q->pere!=NULL)
        {
            p= q;
            while (p->pere!=NULL)
            {
                p= p->pere;
            }
            if((p->frequence<=min)&&(p!=adrmin1))
            {
                min= p->frequence;
                adrmin2=p;
            }
        }

        q=q->suivant ;
        /*min=adrmin1->frequence;*/
    }
//printf("%c",adrmin2->caractere);
    return adrmin2;
}

void build(LISTE l)      //Construire toute la liste //
{
    char c=' ';
    NOEUD q=l->tete;

    int non_marquee = listeTaille(l);

    NOEUD n,p1,p2;
    while (non_marquee>1)
    {
        n=noeudCreer(c);
        p1=min1(l);
        p2=min2(l,p1);
        inserer(l,n,p1,p2);
        non_marquee--;
        printf("\tp1 :");
        if ((p1->FD==NULL)&&(p1->FG==NULL))
            printf ("\t%c",p1->caractere);
        printf ("%i",p1->frequence);
        printf ("\n");
        printf("\tp2 :");
        if ((p2->FD==NULL)&&(p2->FG==NULL))
            printf ("\t%c",p2->caractere);
        printf ("%i",p2->frequence);
        printf ("\n");
        printf ("\tle noeud pere est : ");
        printf ("%i\n",n->frequence);
        q=q->suivant;


    }


}

void inverser(char ch[1000])   //inverser une chaine binaire //
{
    int i=0 ;
    char x;
    for(i=0; i<(strlen(ch)/2); i++)
    {
        x=ch[i];
        ch[i]=ch[strlen(ch)-1-i];
        ch[strlen(ch)-1-i]=x;
    }

}

char convert(int a) //Convertion d'un entier en un caractére soit '1' ou '0'//
{
    if (a==1)
        return ('1');
    else
        return ('0');
}

void associer_caractere(LISTE L,char c,char ch[1000])     //associer à chaque caractére son code binaire en parcourant la liste//
{
    NOEUD p=L->tete;
    int i=0;
    if (p->suivant==NULL)
    {
        ch[i]='0';
        ch[i+1]='\0';
        printf("\t%c",p->caractere);
        printf("%i\n",p->parite);
        printf("\n%s",ch);
    }
    else
    {
        while (p->caractere!=c)
            p=p->suivant;
        while(p->pere!=NULL)
        {
            ch[i]= convert(p->parite);
            p=p->pere;
            i++;
        }
        ch[i]='\0';
        inverser(ch);
        printf ("\t%c = ",c);
        printf("%s\n",ch);
    }
}

void affichage(LISTE L, char ch[1000],char cha[1000]) //Affichage de la chaine de code //
{
    char chi[1000];
    int i;
    cha[0]='\0';
    for (i=0; i<strlen(ch); i++)
    {
        chi[0]='\0';
        associer_caractere(L,ch[i],chi);
        strcat(cha,chi);
    }
    printf ("\tToute la chaine est : \t");
    printf("%s",cha);
}

///PARTIE II///




int verifchaine(char ch[1000])  //vérifie si la chaine est constitueé seulement des 0 et 1///
{
    int verif=1,i=0;
    while((verif)&&(i<strlen(ch)))
    {
        if ((ch[i]!='0')&&(ch[i]!='1'))
            verif=0;
        i++;
    }
    return (verif);

}

void saisie(char ch[])  //Saisir une chaine de code binaire//
{
    do
    {
        fflush(stdin);
        printf (" \n Saisir votre code :");
        printf("\t\t ");
        gets(ch);
    }
    while(verifchaine(ch)==0);

}

void afficher_chaine(LISTE L,char ch[])
{
    int trouve=0,a=0,vrai=0,i=0,test=1;
    NOEUD p=L->tete;
    if(p->suivant==NULL)
    {
        while (i<strlen(ch))
        {
            if (ch[i]=='1') test=0;
            i++;
        }
        if (test==0) printf("impossible");
        else
        {
            for (i=0; i<strlen(ch); i++)
                printf("%c",p->caractere);
        }
    }
    else
    {
        while(a<strlen(ch))
        {
            trouve=0;
            while (p->pere!=NULL) p=p->pere;
            while ((trouve==0)&&(a<=strlen(ch)))
            {
                if ((p->FD==NULL)&&(p->FG==NULL))
                {
                    trouve=1;
                    printf("%c",p->caractere);
                    vrai=1;
                }
                else
                {
                    if (ch[a]=='1')
                        p=p->FG;
                    else p=p->FD;
                    a++;
                }
            }
        }

        if (!vrai) printf("\tla chaine saisie est courte");
    }
}



int main()
{
    char ch[1000];
    char chcode[1000];
    LISTE L1;
    char choix;
    char choix2;

    //system("cls");

    printf("\n\n\t\t\t**************CODAGE DE HUFFMAN*******************");


    do
    {
        Color(3,0);
        do
        {
            printf ("\n\n\n\t\t ***donner une chaine*** \n");
            fflush(stdin);
            printf("\t\t");
            Color(8,0);
            scanf("%s",&ch);
        }
        while (strcmp(ch," ")==0);

        if (strlen(ch)==1)
        {
            Color(4,0);
            printf ("\n\tla chaine contient un seul caractere '%s' impossible de construire une chaine \n\n\t",ch);
        }

        else
        {
            longeur=strlen(ch);
            L1=listeCreer();
            nouvelleliste(L1, ch);
            printf ("\n\tla liste des caracteres est : \n \n ");
            listeAfficher(L1);
            printf("\n \n");
            build(L1);

            printf ("\n\tle code de cette chaine est : \t ");
            printf("\n\t");
            affichage(L1,ch,chcode);
            printf("\n");



            do
            {

                saisie(chcode);

                printf("\n");
                printf ("\t la chaine correspondante est : \t");
                afficher_chaine(L1,chcode);
                printf ("\n");
                printf("\n Veuillez saisir un autre code O/N ?");
                scanf("%c",&choix);
            }
            while(choix=='O' || choix=='o');

        }

        printf("");
        scanf("%c",&choix2);
        printf("Veuillez saisir une autre chaine O/N ? ");
        scanf("%c",&choix2);

        listeDetruire(L1);

    }
    while(choix2=='O'|| choix2=='o');

    printf("\n\n\n Good bye !!");


    return(0);
}
