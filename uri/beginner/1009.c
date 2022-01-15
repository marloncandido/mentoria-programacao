#include <stdio.h>
 
int main() {

    char NAME[61];                          // Nomes dos funcionários
    double FIXED_SALARY, VENDAS, SALARY;    // Declaração de variáveis flutuantes
    scanf("%s",NAME);                       // Usuário digita o nome do funcionário
    scanf("%lf",&FIXED_SALARY);             // Usuário digita o salário fixo do funcionário
    scanf("%lf",&VENDAS);                   // Usuário digita o valor das vendas mensais do funcionário
    SALARY=FIXED_SALARY+(VENDAS*0.15);      // Realiza o cálculo do salário
    printf("TOTAL = R$ %.2lf\n",SALARY);    // Retorna o valor do salário + bonu
    return 0;
}