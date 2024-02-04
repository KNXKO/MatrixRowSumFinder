#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAX 100

const double MINHODNOTA = -100;
const double MAXHODNOTA = 100;

int osetrenie_vstupu(int pom);
void uvolnenie(double **array, int n);
double **alokacia(int n);
void zadavanie_hodnot(int n, double **array);
void generovanie_hodnot(int n, double **array);
void generovanie_hodnot_vypis(int n, double **array);
double nahodne_cisla(double MINHODNOTA, double MAXHODNOTA);
void porovnanie_cisel(int n, double **array, double *sum, double min, double max);
double *sucet_cisel(int n, double **array);
double hladanie_min(int n, double **array);
double hladanie_max(int n, double **array);
double absolutna_hodnota(double cislo);

int main(void)
{
    printf("Lukas Lechovic 07\n");
    printf("Zadanie 5:\n");
    printf("Rieste problem, ktory v stvorcovej matici zadaneho lubovolneho rozmeru N x N\nnajde riadok (riadky cislujte vo vystupe), ktoreho absolutna hodnota suctu\njeho prvkov je maximum alebo minimum v danej matici.\n");
    int n, vyber = 0, znova = 0,pom = 0, vypis_prvkov = 0;
    double min, max;
    do
    {
        do
        {
            printf("\nZadajte velkost stvorcovej matice: ");
            n = osetrenie_vstupu(pom);
        }
        while (n < 2);

        double **arr = alokacia(n);
        double *sum = alokacia(n);

        do
        {
            printf("\n\n(1) Prvky si zadate sami\n(2) Prvky si nechate nahodne vygenerovat\nZadajte 1 alebo 2: ");
            vyber = osetrenie_vstupu(pom);
        }
        while (vyber <= 0 || vyber > 2);

        switch (vyber)
        {
        case 1:
            zadavanie_hodnot(n, arr);
            break;
        case 2:
            do
            {
                printf("\nChcete vypisat maticu ?\n(1) Ano\n(2) Nie \nZadajte 1 alebo 2: ");
                vypis_prvkov = osetrenie_vstupu(pom);
            }
            while (vypis_prvkov <= 0 || vypis_prvkov > 2);
            switch(vypis_prvkov)
            {
            case 1:
                generovanie_hodnot_vypis(n, arr);
                break;
            case 2:
                generovanie_hodnot(n, arr);
                break;
            }
        }
        clock_t begin = clock();
        printf("\n");

        min = hladanie_min(n, arr);
        max = hladanie_max(n, arr);

        printf("Najmensia hodnota v matici je %0.02lf\n", min);
        printf("Najvacsia hodnota v matici je %0.02lf\n", max);

        sum = sucet_cisel(n, arr);
        porovnanie(n, arr, sum, min, max);

        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\n(The elapsed time is %f seconds", time_spent);
        uvolnenie(arr, n);
        printf("\n\nChcete program spustit znova?\n(1) Ano\n(2) Nie\nZadajte iba 1 alebo 2: ");
        znova = osetrenie_vstupu(pom);
    }
    while (znova == 1 || znova < 2);
    printf("\nDovidenia...");
    getch();
    return 0;
}

int osetrenie_vstupu(int pom)
{
    int cislo = 0, ch;
    while (1)
    {
        ch = getch();
        if (ch >= 48 && ch <= 57)
        {
            printf("%c", ch);
            cislo = cislo * 10 + (ch - 48);
        }

        if (ch == 13)
            break;
    }
    return cislo;
}

void uvolnenie(double **array, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        free(array[i]);
    }
    free(array);
    array = NULL;
}

double **alokacia(int n)
{
    double **matica;
    int i;
    if ((matica = (double **)malloc(n * sizeof(double *))) == NULL)
    {
        printf("Nedostatok pamate. Program konci.");
        exit(1);
    }
    for (i = 0; i < n; i++)
    {
        if ((matica[i] = (double *)malloc(n * sizeof(double))) == NULL)
        {
            printf("Nedostatok pamate. Program konci.");
            uvolnenie(matica, i);
            exit(1);
        }
    }
    return matica;
}

void porovnanie(int n, double **array, double *sucet, double min, double max)
{
    int i;
    printf("\n\tSUCET\t\t\tMIN\t\t\tMAX");
    for (i = 0; i < n; i++)
    {
        printf("\n(%d)\t%0.02lf\t", i + 1, sucet[i]);
        if (sucet[i] > min)
        {
            printf("\t>\t%0.02lf\t", min);
        }
        else if (sucet[i] < min)
        {
            printf("\t<\t%0.02lf\t", min);
        }
        else if (sucet[i] = min)
        {
            printf("\t=\t%0.02lf\t", min);
        }
        if (sucet[i] > max)
        {
            printf("\t>\t%0.02lf\t", max);
        }
        else if (sucet[i] < max)
        {
            printf("\t<\t%0.02lf\t", max);
        }
        else if (sucet[i] = max)
        {
            printf("\t=\t%0.02lf\t", max);
        }
    }
}

double *sucet_cisel(int n, double **array)
{
    int i, j;
    double *sucet = alokacia(n);
    double sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum += array[i][j];
        }
        sucet[i] = absolutna_hodnota(sum);
        sum = 0;
    }
    return sucet;
}

void zadavanie_hodnot(int n, double **array)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("\n%d. riadok\n", i + 1);
        for (j = 0; j < n; j++)
        {
            printf("Prvok [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &array[i][j]);
        }
    }
}

void generovanie_hodnot(int n, double **array)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            array[i][j] = nahodne_cisla(MINHODNOTA, MAXHODNOTA);
        }
    }
}

void generovanie_hodnot_vypis(int n, double **array)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        printf("(%d)", i + 1);
        for (j = 0; j < n; j++)
        {
            array[i][j] = nahodne_cisla(MINHODNOTA, MAXHODNOTA);
            printf("\t%0.02lf\t", array[i][j]);
        }
        printf("\n");
    }
}

double nahodne_cisla(double MINHODNOTA, double MAXHODNOTA)
{
    double nahodne = ((double)rand()) / RAND_MAX;
    double rozsah = (MAXHODNOTA - MINHODNOTA) * nahodne;
    double cisla = MINHODNOTA + rozsah;
    return cisla;
}

double hladanie_min(int n, double **array)
{
    int i, j;
    double min = array[0][0];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (min > array[i][j])
            {
                min = array[i][j];
            }
        }
    }
    return min;
}

double hladanie_max(int n, double **array)
{
    int i, j;
    double max = array[0][0];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (max < array[i][j])
            {
                max = array[i][j];
            }
        }
    }
    return max;
}

double absolutna_hodnota(double hodnota)
{
    return ((hodnota < 0) ? (-hodnota) : (hodnota));
}
