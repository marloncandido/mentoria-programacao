#include <stdio.h>
 
int main() {

    int A, B, C, D, DIFERENCA;              // Declaração de variáveis
    scanf("%d", &A);                        // Usuário digita o valor de A
    scanf("%d", &B);                        // Usuário digita o valor de B
    scanf("%d", &C);                        // Usuário digita o valor de C
    scanf("%d", &D);                        // Usuário digita o valor de D    
    DIFERENCA = (A*B) - (C*D);              // Realiza o cálculo da diferenca
    printf("DIFERENCA = %d\n", DIFERENCA);  // Retorna o valor para a diferenca
    return 0;
}