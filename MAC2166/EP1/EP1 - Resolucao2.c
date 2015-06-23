/*
  MAC2166 Introducao a Computacao - Grande area Eletrica - 2015
  EP1 - Usando Inteiros para Representar Reais
  Enunciado: http://www.ime.usp.br/~mac2166/ep1C/

  Exemplo de solucao 2
  Obs.: Essa solucao tambem funciona para valores de e maiores que 9.
*/

#include <stdio.h>

int main()
{
    int m;    /* armazenara os algarismos significativos do numero real */
    int e;    /* armazenara a posicao da virgula no numero real */
    int nd;   /* armazenara o numero de digitos de m */
    int pot;  /* armazenara a maior potencia de 10 que eh menor que m,
                 ou seja, 10 elevado a (nd-1) */
    int i, tmp;


    /* Le m e e do numero real fornecido como entrada */
    printf("MAC2166 - EP1 - Usando Inteiros para Representar Reais\n\n");
    printf("Digite os algarismos do numero..................: ");
    scanf("%d", &m);
    printf("Digite a posicao do separador das casas decimais: ");
    scanf("%d", &e);

    /* Conta o numero de digitos de m e armazena em nd*/
    nd = 0;
    pot = 1;
    for(tmp = m; tmp > 0; tmp /= 10)
    {
        nd++;
        pot *= 10;
    }

    pot /= 10;

    if (m == 0)
        nd = 1;

    if (e >= nd)
    {
        /* O numero de digitos e' menor que o numero
           de casas decimais, portanto e' preciso
           exibir zero(s) antes dos digitos em m*/
        printf("0,");

        for ( ; e > nd; e--)
            printf("0");

        printf("%d\n", m);
    }
    else
    {
        /* A virgula vai aparecer entre os digitos
           de m (caso o numero tenha uma virgula,
           ou seja, se e > 0) */

        /* Obtem de m os digitos que devem aparecer
           antes da virgula e exibe-os um por vez */
        for (i = 0; i < nd - e; i++)
        {
            printf("%d", (m / pot) % 10);
            pot /= 10;
        }

        /* Se o numero possui casas decimais,
           obtem de m os digitos que devem aparecer
           antes da virgula e exibe-os um por vez */
        if (e > 0)
            printf(",");

        for (i = 0; i < e; i++)
        {
            printf("%d", (m / pot) % 10);
            pot /= 10;
        }

        printf("\n");
    }

    return 0;
}
