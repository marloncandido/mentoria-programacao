#include <stdio.h>
 
int main() {

    int A, B, PROD;              // Declaração de variáveis
    scanf("%d", &A);             // Usuário digita o valor de A
    scanf("%d", &B);             // Usuário digita o valor de B
    PROD = A * B;                // Realiza o cálculo do produto
    printf("PROD = %d\n", PROD); // Retorna o valor para o produto
    return 0;
}