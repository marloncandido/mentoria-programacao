#include <stdio.h>
 
int main() {

    int CODE1, CODE2, UNIT1, UNIT2;             // Declaração de variáveis inteiras
    float PRICE1, PRICE2, TOTAL;                // Declaração de variáveis flutuantes
    scanf("%d",&CODE1);                          // Usuário digita o código do produto 1
    scanf("%d",&UNIT1);                          // Usuário digita a quantidade do produto 1
    scanf("%f",&PRICE1);                         // Usuário digita o valor do produto 1
    scanf("%d",&CODE2);                          // Usuário digita o código do produto 2
    scanf("%d",&UNIT2);                          // Usuário digita a quantidade do produto 2
    scanf("%f",&PRICE2);                         // Usuário digita o valor do produto 2
    TOTAL=(UNIT1*PRICE1)+(UNIT2*PRICE2);        // Realiza o cálculo total
    printf("VALOR A PAGAR: R$ %.2f\n",TOTAL);   // Retorna o valor
    return 0;
}