#include <stdio.h>
 
int main() {

    double A, B, MEDIA;               // Declaração de variáveis
    scanf("%lf", &A);                 // Usuário digita o valor de A com 1 casa decimal
    scanf("%lf", &B);                 // Usuário digita o valor de B com 1 casa decimal
    MEDIA = ((A*3.5) + (B*7.5))/11;   // Realiza o cálculo da media
    printf("MEDIA = %.5lf\n", MEDIA); // Retorna o valor para o produto
    return 0;
}