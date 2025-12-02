#include <stdlib.h>
#include <stdio.h>
#include "utils_char.h"

char *CriaVetor(int tamanho) {

    char *vetor = (char*) calloc (tamanho, sizeof(char));

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = '_';
    }

    return vetor;
}

void LeVetor(char *vetor, int tamanho) {
    char letra;
    for (int i = 0; i < tamanho; i++) {
        scanf("%c", &letra);
        if (letra == '\n') break;
        vetor[i] = letra;
    }
}

void ImprimeString(char *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%c", vetor[i]);
    }
    printf("\n");
}

void LiberaVetor(char *vetor) {
    free(vetor);
}