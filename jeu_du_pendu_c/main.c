#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Jeu du pendu qui demande a l'utilisateur de trouver le mot secret ecrit en dure dans le code.

int main()
{
    printf("Bienvenue dans le jeu du pendu numerique\n\n");

    int nb_vies = 10;
    char saisie_utilisateur = ' ';

    char mot_secret[] = "PROGRAMMATION"; // Ou alors MOT_SECRET[] = {'P', 'R', 'O', 'G', 'R', 'A', 'M', 'M', 'A', 'T', 'I', 'O', 'N', '\0'};
    int taille_mot = strlen(mot_secret);

    char mot_trouve[taille_mot+1]; //+1 c'est pour allouer de l'espace pour le caracter de fin de chaine qui est " \0 "
    for (int i=0; i<taille_mot; i++) mot_trouve[i] = '-'; // Ici on initialise notre tableau mot_trouve en y en inserant des tirets " ---- "
    mot_trouve[taille_mot] = '\0'; // On insere le " \0 " a la derniere place du tableau..


    do
    {
        // Lecture saisie utilisateur
        printf("Proposer une lettre > ");
        fflush(stdin);
        scanf("%c", &saisie_utilisateur);

        // Recherche de la presence de la lettre
        int lettre_presente = 0;
        for (int i=0; i < taille_mot; i++)
        {
            if (mot_secret[i] == saisie_utilisateur)
            {
                lettre_presente = 1;
                mot_trouve[i] = saisie_utilisateur;
            }
        }

        // Affichage du resultat
        if (lettre_presente)
        {
            printf("Oui, la lettre '%c' est bien presente dans le mot \"%s\". \n", saisie_utilisateur, mot_trouve);
            printf("\t Il vous reste %d vies. \n", nb_vies);
        }
        else
        {
            nb_vies--;
            printf("Non, la lettre '%c' n'est pas presente dans le mot \"%s\". \n", saisie_utilisateur, mot_trouve);
            printf("\t Il vous reste %d vies. \n", nb_vies);
        }

        // Test de la victoire
        if (strcmp(mot_secret, mot_trouve) == 0)
        {
            printf("Bravo, vous avez trouve le mot \"%s\" et il vous reste %d vies.", mot_secret, nb_vies);
            break;
        }

    } while (nb_vies > 0);

    if (nb_vies == 0)
        printf("Dommage, vous avez perdu ! Le mot secret etait \"%s\".", mot_secret);

    return 0;
}
