#include <stdio.h>
#include <stdlib.h>

void fusion(int tab[], int debut, int milieu, int fin)
{
    int n1 = milieu - debut + 1;
    int n2 = fin - milieu;

    int G[n1], D[n2];

    for (int i = 0; i < n1; i++)
    G[i] = tab[debut + i];

    for (int j = 0; j < n2; j++)
    D[j] = tab[milieu + 1 + j];
    
    // maintient trois pointeurs, un pour chacun des deux tableaux et un pour
    // maintenir l'index actuel du tableau trié final
    int i, j, k;
    i = 0;
    j = 0;
    k = debut;

    while (i < n1 && j < n2)
    {
        if (G[i] <= D[j])
        {
            tab[k] = G[i];
            i++;
        }
        else
        {
            tab[k] = D[j];
            j++;
        }
        k++;
    }   
    // Copiez tous les éléments restants du tableau non vide
    while (i < n1)
    {
        tab[k] = G[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        tab[k] = D[j];
        j++;
        k++;
    }
}
    
    // Tri par fusion
void triFusion(int tab[], int debut, int fin)
{
    if (debut < fin)
    {
        // Trouvez le point milieu pour diviser le tableau en deux moitiés
        int m = (debut + fin) / 2;
        triFusion(tab, debut, m);
        triFusion(tab, m + 1, fin);
        // Fusionnez les deux moitiés triées
        fusion(tab, debut, m, fin);
    }
}

void afficher(int tab[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", tab[i]);
    printf("\n");
}
int search_key(int tab[], uint32_t c, uint32_t begin, uint32_t end)
{
    uint32_t middle = (begin + end) / 2;
    printf("middle: %d\n", middle);
    if( middle == 0 && tab[middle] != c) return -1;
    else if(tab[middle] == c ) return middle;
    else if ( c > tab[middle] && c < tab[end] ) return -1;
    else if ( c > tab[middle] && c > tab[end] ) return -1;
    else if ( c > tab[middle] ) return search_key(tab, c, middle, end);
    else if ( c <= tab[middle] ) return search_key(tab, c, begin, middle);
    
    return -1;
}

int main()
{
    int tab[] = {64, 25, 12, 22, 11};
    int n = 5;
    
    triFusion(tab, 0, n - 1);
    
    printf(" ser:%d\n" ,search_key(tab, 0, 0, 4));
    printf("Tableau trié: \n");
    afficher(tab, n);

    return 0;
}