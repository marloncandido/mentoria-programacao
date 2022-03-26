#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int main(void)
{
    int N = 1, Enter = 0;
    char frase[51], texto[500];
    scanf("%d\n", &N);
    while (Enter < N)
    {
        strcat(texto, fgets(frase, MAX, stdin));
        if ('\n')
            Enter++;
    }
    
    char ultimo_era_espaco = 1;

    for (int x = 0; texto[x] != '\0'; x++)
    {
        if (texto[x] == ' ')
        {
            if (ultimo_era_espaco)
            {
                for (int y = x; texto[y] != '\0'; y++)
                    texto[y] = texto[y + 1];
                
                if (x > 0)
                    x --;
                ultimo_era_espaco = 1;
            }
            else
                ultimo_era_espaco = 1;
        }
        else
    	{	
    		if (texto[x] == '\n')
                    ultimo_era_espaco = 1;
    		else
    		    ultimo_era_espaco = 0;
    	}
    }
    
    for (int x = 0; texto[x] != '\0'; x++)
    {
        if (texto[x] == ' ')
        {
            if (texto[x+1] == '\n')
            {
                for (int y = x; texto[y] != '\0'; y++)
                    texto[y] = texto[y + 1];
                
                if (x > 0)
                    x --;
            }
        }
    }
    
    printf("%s", texto);
    
    int caracteres = strlen(texto) - N;

    printf("%d", caracteres);

    return 0;
}