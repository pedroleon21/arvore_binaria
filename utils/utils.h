// UTILS FUNCTIONS TO TEST AND DEVELOPE
#ifndef UTILS_H
#define UTILS_H

#ifndef STDLIB_H
#define STDLIB_H
#endif

#ifndef TIME_H
#define TIME_H
#endif

int *cria_bagunca_vetor(int size_vet)
{
    int *vet = (int *)malloc(sizeof(int) * size_vet);
    for (int i = 0; i <= size_vet; i++)
        vet[i] = i + 1;

    for (int i = 0; i < size_vet; i++)
    {
        int rand_p = rand() % size_vet;
        int aux = vet[i];
        vet[i] = vet[rand_p];
        vet[rand_p] = aux;
    }
    return vet;
}
void pula(){
    printf("\n\n");
}

#endif