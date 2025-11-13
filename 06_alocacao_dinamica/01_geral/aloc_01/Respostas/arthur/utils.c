#include <stdio.h>
#include <stdlib.h>

int *CriaVetor(int tamanho) {

    int *v = (int*) calloc (tamanho, sizeof(int));
    
    return v;
}

void LeVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
}

float CalculaMedia(int *vetor, int tamanho) {
    float soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }

    return soma / tamanho;
}

void LiberaVetor(int *vetor) {
    free(vetor);
}