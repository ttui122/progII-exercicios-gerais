#include <stdio.h>

void lerIdentificadores(int Nlivros, int ids[]){
    int i;

    for (i = 0; i < Nlivros; i++){
        scanf("%d", &ids[i]);
    }

}


int main(){
    int Nlivros;
    int i, j;
    int copia = 0;

    scanf("%d\n", &Nlivros);

    int ids[Nlivros];

    lerIdentificadores(Nlivros, ids);

    for (i = 0; i < Nlivros; i++){
        for (i = 0; i < Nlivros; i++){
            if (j != i && ids[i] == ids[j]) return 0;
            printf("%d ", ids[i]);
            copia++;
        }
    }

    if (copia == 0) printf("NENHUM");

    return 0;

}