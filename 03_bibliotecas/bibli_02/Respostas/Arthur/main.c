#include <stdio.h>
#include "matrix_utils.h"

void print_menu(){
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");
}


int main(){
    int l1, c1, l2, c2;
    int comando;

    scanf("%d %d\n", &l1, &c1);
    int m1[l1][c1];
    matrix_read(l1, c1, m1);

    scanf("%d %d\n", &l2, &c2);
    int m2[l2][c2];
    matrix_read(l2, c2, m2);

    while (1){

        print_menu();

        scanf("%d", &comando);
    
        if (comando == 1){
            if (possible_matrix_sum(l1, c1, l2, c2)){
            int result[l1][c1];
            matrix_add(l1, c1, m1, l2, c2, m2, result);
            matrix_print(l1, c2, result);
            }
            else printf("Erro: as dimensoes da matriz nao correspondem\n\n");
        }
        else if (comando == 2){
            if (possible_matrix_sub(l1, c1, l2, c2)){
            int result[l1][c1];
            matrix_sub(l1, c1, m1, l2, c2, m2, result);
            matrix_print(l1, c2, result);
            }
            else printf("Erro: as dimensoes da matriz nao correspondem\n\n");
        }
        else if (comando == 3){
            if (possible_matrix_multiply(c1, l2)){
            int result[l1][c2];
            matrix_multiply(l1, c1, m1, l2, c2, m2, result);
            matrix_print(l1, c2, result);
            }
            else printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
        }
        else if (comando == 4){
            int option, scalar;
            scanf("%d %d", &scalar, &option);
            if (option == 1) {
                scalar_multiply(l1, c1, m1, scalar);
                matrix_print(l1, c1, m1);
            }
            else if (option == 2) {
                scalar_multiply(l2, c2, m2, scalar);
                matrix_print(l2, c2, m2);
            }
        }
        else if (comando == 5){
            int result1[l1][c1];
            int result2[l2][c2];

            transpose_matrix(l1, c1, m1, result1);
            transpose_matrix(l2, c2, m2, result2);

            matrix_print(c1, l1, result1);
            matrix_print(c2, l2, result2);
        }
        else if (comando == 6) break;

    }

    return 0;
    
}