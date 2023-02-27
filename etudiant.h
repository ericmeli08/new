#ifndef BANQUE_UN
#define BANQUE_UN
#define Tmax 100
#define N 10
typedef struct ETUDIANT{
    char Matricule[N];
    char Nom[N];
    char Prenom[N];
    int Age;
    char Filiere[N];
    int Niveau;
    int Cotisation;
}ETUDIANT;
//structure d'un etudiant
typedef ETUDIANT CLASS[Tmax];
//structure d'une class
ETUDIANT LireEtud();
//lire un etudiant
void LireClass(CLASS C,int n);
//lire une class
int RechercheEtud(CLASS C,char*mat,int n);
//recherche d'un etudiant a partir de son matricule
ETUDIANT copie(ETUDIANT T);
//copie un etudiant dans un autre
void Corrige(CLASS C,int n,char*mat);
//corrige un element de la class
void supprimer(CLASS C,int n,char*mat);
//supprime uun etudiant
void AfficheEtud(ETUDIANT T);
//affiche un etudiant
void AfficheListe(CLASS C,int n);
//affiche la liste d'etudiant
void MontantTotal(CLASS C,int n);
//montant total
void add(CLASS C,int n);
//ajoute un etudiant
void RechercheAffiche(CLASS C,int n,char*mat);
//recherche un etudiant et affiche
void fermer();
//pour fermer
void menu();
//le menu principal du programme
#endif // BANQUE_UN