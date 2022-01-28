#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    int N = 1, Enter = 0;           // Declaração de variáveis inteiras
    char texto[100];                // Declaração de variável de texto
    char buffer[MAX];
    scanf("%d",&N);                 // Usuário digita o número de linhas do texto
    Enter--;
    while (Enter < N)
    {
        strcat(buffer,fgets(texto, MAX, stdin));// Programa lê as teclas digitadas pelo usuário
        if('\n')
        {
            Enter++;                // Soma o número de vezes que o Enter é pressionado
        }
    }
    printf("%s\n", buffer);          // Retorna o texto justificado
    return 0;
}