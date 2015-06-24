/*
  MAC2166 Introducao a Computacao - Grande area Eletrica - 2015
  EP1 - Usando Inteiros para Representar Reais
  Enunciado: http://www.ime.usp.br/~mac2166/ep1C/

  Exemplo de solucao 1
*/
#include <stdio.h>

int main()
{
    int m;    /* armazenara os algarismos significativos do numero real */
    int e;    /* armazenara a posicao da virgula no numero real */
    int decimal_reverso = 0; /* guardara o reverso da parte decimal do numero */
    int i, digito;

    /* Le m e e do numero real fornecido como entrada */
    printf("MAC2166 - EP1 - Usando Inteiros para Representar Reais\n\n");
    printf("Digite os algarismos do numero..................: ");
    scanf("%d", &m);
    printf("Digite a posicao do separador das casas decimais: ");
    scanf("%d", &e);

    /* Obtem os digitos da parte decimal do numero, armazenando-os em ordem
       reversa na variavel decimal_reverso. Na ordem reversa, os possiveis
       zeros aa esquerda que aparecem na parte decimal viram zeros a direita
       e, portanto, nao sao "perdidos" no processo de armazenamento */
    for(i = 1; i <= e; i++)
    {
        /* Extrai o ultimo digito de m */
        digito = m % 10;
        m = m / 10;

        /* Inclui o digito no "final" de decimal_reverso */
        decimal_reverso *= 10;
        decimal_reverso += digito;
    }
    /* Depois da execucao do laco acima, a variavel m contem o valor da
       parte inteira do numero real fornecido como entrada ao programa  */

    /* Exibe o numero em notacao decimal */
    printf("O numero correspondente na notacao decimal e....: %d", m);

    if (e > 0)  /* Se o numero tem casas decimais */
    {
        printf(",");
        /* Exibe o valor de uma casa decimal por vez,
           por meio do "descascamento" do valor em decimal_reverso. */
        for(i=1; i <= e; i++)
        {
            digito = decimal_reverso %10;
            decimal_reverso /= 10;
            printf("%d", digito);
        }
    }

    printf("\n");

    return 0;
}
