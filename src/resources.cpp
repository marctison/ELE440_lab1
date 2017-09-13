#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void afficher(char* note, int* un_tableau, int taille)
{
    int i;
    printf("%s : ", note);
    for (i = 0; i < taille; i++)
    {
        printf("%i ", un_tableau[i]);
    }
    printf("\n");
}

int* generer_donnees(int nb_donnees, int rang, int desordre)
{
    int* donnees;           // Les données générées et leur position original.
    int* position;

    int i, j, temp;         // Servira à trier les données générées.

    int m, k;                       // Servira à mélanger les données
    int indice, nb_permutation;

    // On initialise les tableaux et les générateurs.
    srand(time(NULL));
    nb_permutation = nb_donnees / 2;
    donnees = (int*) malloc(nb_donnees * sizeof(int));
    position = (int*) malloc(nb_permutation * sizeof(int));

    // On crée les données aléatoirement.
    for (i = 0; i < nb_donnees; i++)
        donnees[i] = rand() % rang;

    // On trie les données aléatoirement.
    for (i = 0; i < nb_donnees - 1; i++)
        for (j = i + 1; j < nb_donnees; j++)
            if (donnees[i] > donnees[j])
            {
                temp = donnees[i];
                donnees[i] = donnees[j];
                donnees[j] = temp;
            }

    // On initialise les positions des données triées.
    for (i = 0; i < nb_permutation; i++)
        position[i] = i;

    // On déplace les données pour créer le niveau de désordre spécifié.
    m = nb_permutation;
    for (i = 0; i < nb_permutation * desordre / 100; i++)
    {
        k = rand() % m;
        indice = position[k];
        position[k] = position[m - 1];
        m--;

        temp = donnees[nb_permutation - indice - 1];
        donnees[nb_permutation - indice - 1] = donnees[nb_permutation + indice];
        donnees[nb_permutation + indice] = temp;
    }

    free(position);
    return donnees;
}

void sauvegarder(int nb_donnees, int rang, int desordre,
        int* temps_executions,
        int nb_temps,
        char* nom_fichier)
{
    FILE* fichier_id;
    int i;

    // On ouvre le fichier où inscrire les résultatsé
    fichier_id = fopen(nom_fichier, "a+");

    // On inscrit l'entête
    fprintf(fichier_id, "%d\n", nb_donnees);
    fprintf(fichier_id, "%d\n", rang);
    fprintf(fichier_id, "%d\n", desordre);

    // On inscrit les temps d'exécutions.
    for (i = 0; i < nb_temps; i++)
        fprintf(fichier_id, "%d ", temps_executions[i]);
    fprintf(fichier_id, "\n");

    // On ferme le fichier.
    fclose(fichier_id);
}
