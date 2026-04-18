#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILENAME "Personne.csv"

typedef struct {
      char nom[250] ;
      char prenom[250];
      char tel[50];
      char genre[50];
}Personne;

void ajouter_fichier()
{   
     FILE *f = fopen(FILENAME,"a");                                                              
    if(f == NULL){
               printf("Il y a une erreur de fichier");
               exit(1);
     }

     Personne p;
     printf("Nom:"); scanf("%s",p.nom);
     printf("Prenom:"); scanf("%s",p.prenom);
     printf("Telephone:"); scanf("%s",p.tel);
     printf("Genre:"); scanf("%s",p.genre);
    fprintf(f,"%s\t%s\t%s\t%s\n" , p.nom,p.prenom,p.tel,p.genre);

    fclose(f);

}

void affiche_fichier()
{
    FILE *f =fopen(FILENAME,"r");
    if (f == NULL){
        printf("Le fichier est Vide");
        exit(1);
    }
    Personne p;

    printf("La liste de toutes les personnes:\n");
    printf("NOM\t\tPRENOM\t\t\tTELEPHONE\t\tGENRE\t\n");
    
 
while (fscanf(f, "%s %s %s %s", p.nom, p.prenom, p.tel, p.genre) != EOF) {
        printf("%-15s |  %-15s | %-20s | %-10s \n", p.nom, p.prenom, p.tel, p.genre);
    }

    fclose(f);

}

void recherche()
{
    FILE *f = fopen(FILENAME,"r");
    Personne p;
    char recherche[250];
    printf("entrer le nom a rechercher:");
    scanf("%s",recherche);
    int trouve = 0;
    while(fscanf(f,"%s %s %s %s",p.nom,p.prenom,p.tel,p.genre)!=EOF){
        if (strcmp(p.nom, recherche) == 0)
        {
            printf("On trouve: %-15s |  %-15s | %-20s | %-10s\n", p.nom, p.prenom, p.tel, p.genre);
            trouve = 1;
        }
    }

    if (!trouve) printf("Contact non trouve.\n");                        //si trouve=0 pas de chgmnt en 1

    fclose(f);
        
}


void supprimer() {
    FILE *f = fopen(FILENAME, "r");
    if (!f) {
        printf("Impossible d'ouvrir le fichier.\n");
        exit(1);
    }
    FILE *temp = fopen("temp.csv", "w");
    if (!temp) {
        printf("Impossible de creer le fichier temporaire.\n");
        fclose(f);
        exit(1);
    }
    Personne p;
    char recherche[250];
    printf("Entrez le nom a supprimer: ");
    scanf("%s", recherche);
    while (fscanf(f, "%s %s %s %s\n",
                  p.nom, p.prenom, p.tel, p.genre) != EOF) {
        if (strcmp(p.nom, recherche) != 0) {
            fprintf(temp, "%s\t%s\t%s\t%s\n" , p.nom,p.prenom,p.tel,p.genre);
        }
    }
    fclose(f);
    fclose(temp);
    remove(FILENAME);
    rename("temp.csv", FILENAME);
    printf("La Suppression est effectuee.\n");
}

void modifier(){
    FILE *f = fopen(FILENAME,"r");
if(f==NULL)
{
    printf("Erreur d'ouverture du fichier");
    exit(1);
}
   
    FILE *temp = fopen("TEMP.csv","w");
if(temp==NULL)
{
    printf("Erreur d'ouverture du fichier temporaire ");
    fclose(temp);
    exit(1);
}

Personne p;
char modifier[250],NOM[250];
printf("Entrer le nom a mofidier:");
scanf("%s",modifier);
while(fscanf(f,"%s %s %s %s \n",p.nom,p.prenom,p.tel,p.genre)!=EOF)
{
    if (strcmp(p.nom,modifier)==0)
    { printf("Entrer le nouveau nom pour remplacer ce nom:"); scanf("%s",NOM);
      printf("Entrer le nouveau Prenom:"); scanf("%s",p.prenom);
      printf("Entrer le nouveau telephone:"); scanf("%s",p.tel);
      printf("Entrer le nouveau genre:"); scanf("%s",p.genre);

      fprintf(temp,"%s\t%s\t%s\t%s\n" ,NOM,p.prenom,p.tel,p.genre);
    }
    fprintf(temp,"%s\t%s\t%s\t%s\n" , p.nom,p.prenom,p.tel,p.genre);
}

fclose(f);
fclose(temp);
remove(FILENAME);
rename("TEMP.csv",FILENAME);
printf("Modification effectuee \n");


}




int main()
{
    /*ajouter_fichier();
    affiche_fichier();
    recherche();
    supprimer() ;
    modifier();
    affiche_fichier();
*/
    int choix;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Ajouter Personne\n");
        printf("2. Affiche les Personnes\n");
        printf("3. Rechercher Personne\n");
        printf("4. Supprimer Personne\n");
        printf("5. Modifier Personne\n");
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: ajouter_fichier(); break;
            case 2: affiche_fichier(); break;
            case 3: recherche(); break;
            case 4: supprimer() ; break;
            case 5:  modifier(); break;
        }
    } while (choix != 0);
    
    return 0;
}   

