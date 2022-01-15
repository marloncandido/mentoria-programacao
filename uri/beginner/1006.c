#include <stdio.h>
 
int main() {

    double A, B, C, MEDIA;             // Declaração de variáveis
    scanf("%lf", &A);                  // Usuário digita o valor de A com 1 casa decimal
    scanf("%lf", &B);                  // Usuário digita o valor de B com 1 casa decimal
    scanf("%lf", &C);                  // Usuário digita o valor de C com 1 casa decimal
    MEDIA = ((A*2) + (B*3)+(C*5))/10;  // Realiza o cálculo da media
    printf("MEDIA = %.1lf\n", MEDIA);  // Retorna o valor para o produto
    return 0;
}