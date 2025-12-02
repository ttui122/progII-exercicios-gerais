#include <stdio.h>
#include "utils_char.h"

int main() {
    int tamanho;

    scanf("%d\n", &tamanho);

    char *palavra = CriaVetor(tamanho);
    ImprimeString(palavra, tamanho);
    LeVetor(palavra, tamanho);
    ImprimeString(palavra, tamanho);
    LiberaVetor(palavra);

    return 0;
}