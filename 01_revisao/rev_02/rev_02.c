#include <stdio.h>

int main(){
    int Nlinhas;
    int cont = 1;
    int acumulador = 1;
    int i;

    scanf("%d", &Nlinhas);

    while (cont <= Nlinhas){

        for (i = 0; i < cont; i++){
            printf("%d ", acumulador);
            acumulador++;
        }

        printf("\n");
        cont++;

    }

    return 0;

}