/*****************************************************************************/
/**                                                                         **/
/**         Daniel Nery Silva de Oliveira               9349051             **/
/**         Exercício-Programa 03                                           **/
/**         Professora: Kelly Rosa Braghetto                                **/
/**         Turma: 06                                                       **/
/**                                                                         **/
/*****************************************************************************/

/** Tentativa para funcao seno **/

#include<stdio.h>
#include<math.h>
#define M_PI 3.14159265358979323846

/* Prototipos das funcoes */
double modulo(double x);
int newton(double *x_real, double *x_imag, int max_iter, double eps, double a, double b);
void multiplica(double *ret_real, double *ret_imag, double x_real, double x_imag, double y_real, double y_imag);

/* Funcao que calcula o valor do seno e de sua derivada num ponto */
void calcula(double x_real, double x_imag, double *p_real, double *p_imag, double *d_real, double *d_imag, double a, double b);

int main()
{
    double l, u, eps, delta, x_real, x_imag, a, b;
    int N, max_iter, r, s, check;
    FILE *saida; /* Arquivo de saida dos resultados */

    saida = fopen("saida.txt", "w");
    if (!saida) {
        printf("Nao consegui abrir o arquivo para gravacao!\n");
        return 0;
    }

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

    printf("\nDigite o valor de a       : ");
    scanf("%lf", &a);
    printf("Digite o valor de b       : ");
    scanf("%lf", &b);

    fprintf(saida, "%d\n", N); /* Imprime o valor de N na primeira linha do arquivo */

    delta = (u - l)/N;
    for (r = 0; r <= N; r++) {
        for (s = 0; s <= N; s++) {
            x_real = l + r*delta;
            x_imag = l + s*delta;
            check = newton (&x_real, &x_imag, max_iter, eps, a, b);
            if (!check) fprintf(saida, "N ");
            else fprintf(saida, "%.10g %.10g ", x_real, x_imag);
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
int newton(double *x_real, double *x_imag, int max_iter, double eps, double a, double b)
{
    int i;         /* Contador */
    double p_real, p_imag, d_real, d_imag, r_real, r_imag;

    for (i = 0; i < max_iter; i++) {
        calcula(*x_real, *x_imag, &p_real, &p_imag, &d_real, &d_imag, a, b);
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
        }
    }
    return 0;
}
void calcula(double x_real, double x_imag, double *p_real, double *p_imag, double *d_real, double *d_imag, double a, double b)
{
	*p_real = *p_imag = 0;
	*d_real = *d_imag = 0;

	*p_real = sin(2*M_PI*x_real) * cosh(2*M_PI*x_imag) + a;
	*p_imag = cos(2*M_PI*x_real) * sinh(2*M_PI*x_imag) + b;

	*d_real = 2*M_PI * cos(2*M_PI*x_real) * cosh(2*M_PI*x_imag);
	*d_imag = -2*M_PI * (sin(2*M_PI*x_real) * sinh(2*M_PI*x_imag));
}

