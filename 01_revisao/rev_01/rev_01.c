#include <stdio.h>
#include <math.h>

int main(){
    float alvoX, alvoY, alvoR;
    float dispX, dispY, dispR;
    int distancia;
    int somaRaios;

    scanf("%f %f %f\n%f %f %f", &alvoX, &alvoY, &alvoR, &dispX, &dispY, &dispR);

    somaRaios = alvoR + dispR;
    distancia = sqrt(pow(alvoX-dispX, 2) + pow(alvoY-dispY, 2));

    if (distancia <= somaRaios) printf("ACERTOU");
    else printf("ERROU");
    
    return 0;
}