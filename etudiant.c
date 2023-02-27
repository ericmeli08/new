#include<stdio.h>
#include<string.h>
#include "etudiant.h"
#define Tmax 100
#define N 10

ETUDIANT LireEtud(){
    ETUDIANT T;
    printf("entrez le maticule\n");
    scanf("%s",T.Matricule);
    printf("entrez le nom \n");
    scanf("%s",T.Nom);
    printf("entrez le prenom\n");
    scanf("%s",T.Prenom);
    printf("entrez l'age\n");
    scanf("%d",&T.Age);
    printf("entrez la filiere \n");
    scanf("%s",T.Filiere);
    printf("entrez le niveau \n");
    scanf("%d",&T.Niveau);
    printf("entrez le montant de la cotisation \n");
    scanf("%d",&T.Cotisation);
    return T;
}

void LireClass(CLASS C,int n){
    for(int i=0;i<n;i++)
    {
        printf("entrez les informations de l'etudiant %d :\n",i+1);
        C[i] = LireEtud();
    }
}

int RechercheEtud(CLASS C,char*mat,int n){
    int i;
    i=0;
    while(i<n)
    {
        if(!strcmp(C[i].Matricule,mat))
            return i;
        i++;
    }
    printf("il n'existe pas\n");
    return -1;
}

ETUDIANT copie(ETUDIANT T)
{
    ETUDIANT E;
    strcpy(E.Matricule,T.Matricule);
    strcpy(E.Nom,T.Nom);
    strcpy(E.Prenom,T.Prenom);
    E.Age=T.Age;
    strcpy(E.Filiere,T.Filiere);
    E.Niveau=T.Niveau;
    E.Cotisation=T.Cotisation;
    return E;
}

void add(CLASS C,int n)
{
    printf("entrez les donnees du nouvel etudiant\n");
    C[n-1]=LireEtud();
}

void Corrige(CLASS C,int n,char*mat){
    ETUDIANT T;
    int pos;
    pos=RechercheEtud(C,mat,n);
    if(pos!=-1)
    {
        printf("entrez les nouvelles informations\n");
        T = LireEtud();
        C[pos]= copie(T);
        printf("corection effectuer !\n");
    }
}

void supprimer(CLASS C,int n,char*mat)
{
    int pos;
    pos=RechercheEtud(C,mat,n);
    if(pos!=-1)
    {
        for(int i=pos;i<n-1;i++)
            C[i]= copie(C[i+1]);
        printf("suppression effectuer !\n");
    }
}

void AfficheEtud(ETUDIANT T)
{
    printf("MATRICULE: %s\tNOM: %s\tPRENOM: %s\tCOTISATION: %d\n",T.Matricule,T.Nom,T.Prenom,T.Cotisation);
}

void AfficheListe(CLASS C,int n){
    int choix;
    printf("Les informations des etudiants\n");
    for(int i=0;i<n;i++)
        AfficheEtud(C[i]);
}

void MontantTotal(CLASS C,int n)
{
    int S=0,choix;
    for( int i=0;i<n;i++)
        S +=C[i].Cotisation;
    printf("le montant totald de cotisation est : %d\n",S);
}

void RechercheAffiche(CLASS C,int n,char*mat)
{
    int pos;
    pos = RechercheEtud(C,mat,n);
    if(pos!=-1)
        AfficheEtud(C[pos]);
}
void fermer()
{
    printf("\n\n\t\t-------------------TERMINER DEVELEPPER PAR MELI ERIC-------------------------\n");
}

void menu()
{
    CLASS C;
    int choix,n;
    char mat[N];
    repeat:
        printf("\n\n\n\t\t\t-------------Bienvenu dans la gestion des etudiant----------------\n");
        printf("1 - Entrer les information des etudiants\n");
        printf("2 - Corriger les donnees d'un etudiant\n");
        printf("3 - Supprimer un etudiant de la liste\n");
        printf("4 - Afficher la liste des etudiant\n");
        printf("5 - Voir le montant total de cotisation\n");
        printf("6 - Voir les donnees d'un etudiant\n");
        printf("7 - Ajouter un etudiant a la liste\n");
        printf("8 - Quitter\n");
        printf("que voulez vous faire ?  ");
        scanf("%d",&choix);
        switch(choix)
        {
            case 1:
                printf("entrez le nombre d'etudiants : ");
                scanf("%d",&n);
                LireClass(C,n);
            break;
            case 2:
                printf("entrez le matricule de l'etudiant a corriger\n");
                scanf("%s",mat);
                Corrige(C,n,mat);
            break;
            case 3:
                printf("entrer le matricule de l'etudiant a supprimer : ");
                scanf("%s",mat);
                supprimer(C,n,mat);
                n--;
            break;
            case 4:
                AfficheListe(C,n);
            break;
            case 5:
                MontantTotal(C,n);
            break;
            case 6:
                printf("entrer le matricule de l'etudiant : ");
                scanf("%s",mat);
                RechercheAffiche(C,n,mat);
            break;
            case 7:
                n++;
                add(C,n);
            break;
            default:
                fermer();
            break;
        }
    if (choix!=8)
        goto repeat;
}