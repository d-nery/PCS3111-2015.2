/*****************************************************************************/
/**                                                                         **/
/**         Daniel Nery Silva de Oliveira               9349051             **/
/**         Exercício-Programa 03                                           **/
/**         Professora: Kelly Rosa Braghetto                                **/
/**         Turma: 06                                                       **/
/**                                                                         **/
/*****************************************************************************/

#include<stdio.h>
#define TESTE 1

/* Prototipos das funcoes */
double modulo(double x);
int newton(double *x_real, double *x_imag, int max_iter, double eps);
void multiplica(double *ret_real, double *ret_imag, double x_real, double x_imag, double y_real, double y_imag);
FILE *log;
/* Funcao que calcula o valor do polinomio e de sua derivada num ponto */
#include "polinomio.c"

int main()
{
    double l, u, eps, delta, x_real, x_imag;
    int N, max_iter, r, s, check;
    FILE *saida;


    log = fopen("log.txt", "w");
    if (!log) {
        printf("Erro\n");
        return 0;
    }

    saida = fopen("saida.txt", "w");
    if (!saida) {
        printf("Nao consegui abrir o arquivo para gravacao!\n");
        return 0;
    }

    /* if (TESTE) {
        printf("Valor de x_real: ");
        scanf("%lf", &x_real);
        printf("Valor de x_imag: ");
        scanf("%lf", &x_imag);

        /* calcula(x_real, x_imag, &p_real, &p_imag, &d_real, &d_imag);

        printf("\nResultado (%.10g + %.10gi)", p_real, p_imag);
        printf("\nResultado derivada (%.10g + %.10gi)", d_real, d_imag);
    } */

    printf("Digite o valor de l       : ");   /* Valores digitados pelo usuario */
    scanf("%lf", &l);
    printf("Digite o valor de u       : ");
    scanf("%lf", &u);
    printf("Digite o valor de N       : ");
    scanf("%d", &N);
    printf("Digite o valor de max_iter: ");
    scanf("%d", &max_iter);
    printf("Digite o valor de epsilon : ");
    scanf("%lf", &eps);

    fprintf(saida, "%d\n", N); /* Imprime o valor de N na primeira linha do arquivo */

    delta = (u - l)/N;
    for (r = 0; r <= N; r++) {
        for (s = 0; s <= N; s++) {
            x_real = l + r*delta;
            x_imag = l + s*delta;
            if(TESTE) fprintf(log, "x = (%.10g + %.10gi)\n", x_real, x_imag);
            check = newton (&x_real, &x_imag, max_iter, eps);
            if(TESTE) fprintf(log, "%d\n", check);
            if (check == 0) fprintf(saida, "N ");
            else fprintf(saida, "%.10g %.10g ", x_real, x_imag);
            if (TESTE) {
                if (!check) fprintf(log, "N\n");
                else fprintf(log, "(%.10g + %.10gi)\n\n ", x_real, x_imag);
            }
        }
        fprintf(saida, "\n");
    }
    fclose(saida);

    return 0;
}
/* Calcula o valor absoluto de um numero */
double modulo(double x)
{
    if (x < 0) return -x;
    else return x;
}

/* Faz a multiplicacao de dois numeros complexos */
void multiplica(double *ret_real, double *ret_imag, double x_real, double x_imag, double y_real, double y_imag)
{
    *ret_real = (x_real*y_real) - (x_imag*y_imag);
    *ret_imag = (x_real*y_imag) + (x_imag*y_real);
}

/* Executa o metodo de Newton para um ponto */
int newton(double *x_real, double *x_imag, int max_iter, double eps)
{
    int i;         /* Contador */
    double p_real, p_imag, d_real, d_imag, r_real, r_imag;

    for (i = 0; i < max_iter; i++) {
        calcula(*x_real, *x_imag, &p_real, &p_imag, &d_real, &d_imag);
        if (TESTE) {
            fprintf(log, "p = (%.10g + %.10gi)\n", p_real, p_imag);
            fprintf(log, "d = (%.10g + %.10gi)\n", d_real, d_imag);
        }
        /* if (TESTE) printf("modulos: %.10g %.10g %.10g %.10g\n", modpr, modpi, moddr, moddi); */
        if (modulo(p_real) <= eps && modulo(p_imag) <= eps) {
            return 1;
        }
        if (modulo(d_real) <= eps && modulo(d_imag) <= eps) {
            return 0;
        }

        if (d_real == 0 && d_imag == 0) {
            return 0;
        } else {
            multiplica(&r_real, &r_imag, p_real, p_imag, d_real, -d_imag);
            *x_real = *x_real - r_real/(d_real*d_real + d_imag*d_imag);
            *x_imag = *x_imag - r_imag/(d_real*d_real + d_imag*d_imag);
            if (TESTE) {
                fprintf(log, "Novo x = (%.10g + %.10gi)\n", *x_real, *x_imag);
            }
        }
    }
    return 0;
}
