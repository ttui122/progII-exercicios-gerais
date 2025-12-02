#include <stdio.h>
#include <stdlib.h>
#include "utils_char2.h"


char *CriaVetorTamPadrao() {

    char *vetor = (char*) calloc (TAM_PADRAO+1, sizeof(char));

    for (int i = 0; i < TAM_PADRAO+1; i++) {
        if (i == TAM_PADRAO) vetor[i] = '\0';
        else vetor[i] = '_';
    }

    return vetor;

}

char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo) {

    char *vetorAumentado = (char*) realloc (vetor, (tamanhoantigo+TAM_PADRAO+1)*sizeof(char));

    for (int i = 0; i < TAM_PADRAO+1; i++) {
        if (i == TAM_PADRAO) vetorAumentado[tamanhoantigo+i] = '\0';
        else vetorAumentado[tamanhoantigo+i] = '_';
    }

    return vetorAumentado;

}

char* LeVetor(char *vetor, int *tamanho) {
    char letra;

    for (int i = 0; i < *tamanho; i++) {

        scanf("%c", &letra);

        if (letra != '\n') vetor[i] = letra;
        else break;
        
        if (i == *tamanho-1) {
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho += TAM_PADRAO;
        }


    }

    return vetor;

}

void ImprimeString(char *vetor) {
    printf("%s\n", vetor);
}

void LiberaVetor(char *vetor) {
    free(vetor);
}