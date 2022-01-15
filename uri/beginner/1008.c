#include <stdio.h>
 
int main() {

    int NUMBER, HW;                         // Declaração de variáveis inteiras
    float VPH, SALARY;                      // Declaração de variáveis flutuantes
    scanf("%d", &NUMBER);                   // Usuário digita o número do funcionário
    scanf("%d", &HW);                       // Usuário digita o número de horas trabalhadas
    scanf("%f", &VPH);                      // Usuário digita o valor do funcionário por hora trabalhada
    SALARY = HW*VPH;                        // Realiza o cálculo do salário
    printf("NUMBER = %d\n", NUMBER);        // Retorna o número do funcionário  
    printf("SALARY = U$ %.2f\n", SALARY);   // Retorna o valor do salário
    return 0;
}