#include <stdio.h>

char buscarAdjacente(int posX, int posY, int linhas, int colunas, int matriz[linhas][colunas], char prioridade[]);


int main(){
    int i, j, c;
    int inicio = 0;
    int linhas, colunas;
    int posInicialX, posInicialY;
    int posFinalX, posFinalY;
    int posX, posY;
    char prioridade[4];
    char direcao;

    scanf("%d %d", &linhas, &colunas);

    int matriz[linhas][colunas];

    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    scanf("%d %d", &posInicialX, &posInicialY);
    scanf("%d %d", &posFinalX, posFinalY);
    for (c = 0; c < 4; c++){
        scanf("%c", &prioridade[c]);
    }


    while(1){

        if (inicio == 0){
            posX = posInicialX;
            posY = posInicialY;
        }

        if (posX == posFinalX && posY == posFinalY) break;

        direcao = buscarAdjacente(posX, posY, linhas, colunas, matriz, prioridade);
        atualizarMatriz(posX, posY, linhas, colunas, matriz);        

        if (direcao == 'B'){
            posX = posX;
            posY++;
        }
        else if (direcao == 'C'){
            posX = posX;
            posY--;
        }
        else if (direcao == 'D'){
            posX++;
            posY = posY;
        }
        else if (direcao == 'E'){
            posX--;
            posY = posY;
        }
        else break;
    }


    return 0;

}