#include <stdio.h>
 
int main() {

    int A, B, C, Maior;                 // Declaração de variáveis inteiras
    scanf("%d",&A);                     // Usuário digita o valor de A
    scanf("%d",&B);                     // Usuário digita o valor de B
    scanf("%d",&C);                     // Usuário digita o valor de C
    Maior=(A+B+abs(A-B))/2;             // Realiza o cálculo do maior número entre A e B
    Maior=(Maior+C+abs(Maior-C))/2;     // Realiza o cálculo do maior número entre A, B e C
    printf("%d eh o maior\n",Maior);    // Retorna o valor do maior número
    return 0;
}