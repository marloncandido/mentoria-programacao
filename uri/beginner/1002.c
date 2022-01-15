#include <stdio.h>
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
    double R, A;                 // Declaração de variáveis flutuantes
    scanf("%lf", &R);            // Usuário digita um raio
    A = 3.14159*R*R;             // Realiza o cálculo da área
    printf("A=%.4lf\n", A);      // Retorna o valor para A com 4 casas decimais
    return 0;
}