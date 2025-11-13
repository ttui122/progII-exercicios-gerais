#include <stdio.h>
#include "utils.h"

int main() {
    int qtdNums;
    float media;

    scanf("%d", &qtdNums);

    int *v = CriaVetor(qtdNums);
    LeVetor(v, qtdNums);
    media = CalculaMedia(v, qtdNums);
    LiberaVetor(v);

    printf("%.2f\n", media);

    return 0;

}