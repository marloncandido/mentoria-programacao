#include <stdio.h>
 
int main() {

    double R, VOLUME;                         // Declaração de variáveis flutuantes
    scanf("%lf",&R);                          // Usuário digita o valor do raio
    VOLUME=(4/3.0)*(3.14159)*(R*R*R);         // Realiza o cálculo do volume
    printf("VOLUME = %.3lf\n",VOLUME);        // Retorna o valor do volume
    return 0;
}