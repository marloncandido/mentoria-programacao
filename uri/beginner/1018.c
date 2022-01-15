#include <stdio.h>
 
int main() {

    int Valor, N100, N50, N20, N10, N5, N2, N1;                        // Declaração de variáveis inteiras
    scanf("%d",&Valor);                                                // Usuário digita o valor a ser dividido
    N100=Valor/100;                                                    // Realiza o calculo do número de notas de R$ 100,00
    N50=(Valor-(N100*100))/50;                                         // Realiza o calculo do número de notas de R$ 50,00
    N20=(Valor-(N100*100)-(N50*50))/20;                                // Realiza o calculo do número de notas de R$ 20,00
    N10=(Valor-(N100*100)-(N50*50)-(N20*20))/10;                       // Realiza o calculo do número de notas de R$ 10,00
    N5=(Valor-(N100*100)-(N50*50)-(N20*20)-(N10*10))/5;                // Realiza o calculo do número de notas de R$ 5,00
    N2=(Valor-(N100*100)-(N50*50)-(N20*20)-(N10*10)-(N5*5))/2;         // Realiza o calculo do número de notas de R$ 2,00
    N1=(Valor-(N100*100)-(N50*50)-(N20*20)-(N10*10)-(N5*5)-(N2*2))/1;  // Realiza o calculo do número de notas de R$ 1,00
    printf("%d\n",Valor);                                              // Retorna o valor total digitado
    printf("%d nota(s) de R$ 100,00\n",N100);                          // Retorna o número de notas de R$ 100,00
    printf("%d nota(s) de R$ 50,00\n",N50);                            // Retorna o número de notas de R$ 50,00
    printf("%d nota(s) de R$ 20,00\n",N20);                            // Retorna o número de notas de R$ 20,00
    printf("%d nota(s) de R$ 10,00\n",N10);                            // Retorna o número de notas de R$ 10,00
    printf("%d nota(s) de R$ 5,00\n",N5);                              // Retorna o número de notas de R$ 5,00
    printf("%d nota(s) de R$ 2,00\n",N2);                              // Retorna o número de notas de R$ 2,00
    printf("%d nota(s) de R$ 1,00\n",N1);                              // Retorna o número de notas de R$ 1,00
    return 0;
}