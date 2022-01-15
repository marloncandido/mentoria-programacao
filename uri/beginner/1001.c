#include <stdio.h>
 
int main() {
 
    int A, B, X;            // Declaração de variáveis
    scanf("%d", &A);        // Recebe um inteiro e armazena em A
    scanf("%d", &B);        // Recebe um inteiro e armazena em B
    X = A + B;              // Realiza a soma de A e B
    printf("X = %d\n", X);  // Retorna o valor para X
    return 0;
}