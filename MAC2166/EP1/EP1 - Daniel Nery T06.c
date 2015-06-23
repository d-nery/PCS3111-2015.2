/**************************************************************************/
/**                                                                      **/
/**   Daniel Nery Silva de Oliveira              n� USP: 9349051         **/
/**   Exerc�cio-Programa 01                                              **/
/**   Professor: Kelly Rosa Braghetto                                    **/
/**   Turma: 06                                                          **/
/**                                                                      **/
/**************************************************************************/

#include <stdio.h>

int main()
{
    int m,                   /* algarismos do n�mero/n�mero antes da v�rgula */
        e,                   /* n�mero de casas decimais                     */
        b,                   /* n�mero ap�s a v�rgula                        */
        x,                   /* multiplicador                                */
        cm, cb, ct,          /* copias                                       */
        nm, nb, nt,          /* n� de algarismos de cada parte               */
        cont1, cont2, cont3; /* contadores                                   */

    printf("MAC2166 - EP1 - Usando Inteiros para Representar Reais\n\n");

    printf("Digite os algarismos do numero..................: ");
    scanf ("%d", &m);
    printf("Digite a posicao do separador das casas decimais: ");
    scanf ("%d", &e);

    b = nm = nb = nt = cont1 = cont2 = cont3 = 0;
    x = 1;

    for(ct = m; ct > 0; ct = ct/10) nt = nt + 1; /* conta o n� de algarismos para checagem final */

    while (cont1 < e) {
        if (m > 0) {
            b = b + x*(m%10);
            m = m/10;
            x = x*10;
        }
        else {
            cont2 = cont2 + 1;
        }
        cont1 = cont1 + 1;
    }

    for(cb = b; cb > 0; cb = cb/10) nb = nb + 1;
    for(cm = m; cm > 0; cm = cm/10) nm = nm + 1;

    printf ("O numero correspondente na notacao decimal e....: %d", m);
    if (cont1 > 0) printf (",");
    if (nm + nb < nt) {                                                        /* Condi��o para o caso de o  */
        for (cont3 = nt - (nb + nm); cont3 > 0; cont3 = cont3 - 1) printf("0");/* n�mero ter 0 imediatamente */
    }                                                                          /* ap�s a v�rgula             */
    for (; cont2 > 0; cont2 = cont2 - 1) printf ("0"); /* zeros a esquerda */
    if (b != 0) printf ("%d", b);

    return 0;
}
