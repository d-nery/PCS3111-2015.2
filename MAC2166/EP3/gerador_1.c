/*****************************************************************************/
/**                                                                         **/
/**         Daniel Nery Silva de Oliveira               9349051             **/
/**         Exercício-Programa 03                                           **/
/**         Professora: Kelly Rosa Braghetto                                **/
/**         Turma: 06                                                       **/
/**                                                                         **/
/*****************************************************************************/

#include<stdio.h>

int main()
{
    int grau, i = 0;
    double coef_real, coef_imag;

    FILE *in, *out;
    in = fopen("polinomio.txt", "r");
    if (!in) {
        printf("Nao consegui abrir o arquivo para leitura!\n");
        return 0;
    }
    out = fopen("polinomio.c", "w");
    if (!out) {
        printf("Nao consegui abrir o arquivo para gravacao!\n");
        return 0;
    }

    fscanf(in, "%d", &grau);

    fprintf(out, "/* Funcao que calcula o valor do polinomio e de sua derivada num ponto */\n");
    fprintf(out, "void calcula(double x_real, double x_imag, double *p_real, double *p_imag, double *d_real, double *d_imag)\n");
    fprintf(out, "{\n");
    fprintf(out, "\tdouble r_real, r_imag;\n");
    fprintf(out, "\n\t*p_real = *p_imag = 0;\n");
    fprintf(out, "\t*d_real = *d_imag = 0;\n\n");

    for (i; i <= grau; i++) {
        fscanf(in, "%lf", &coef_real);
        fscanf(in, "%lf", &coef_imag);
        fprintf(out, "\n\tmultiplica(&r_real, &r_imag, x_real, x_imag, *p_real, *p_imag);\n");
        fprintf(out, "\t*p_real = %.10g + r_real;\n", coef_real);
        fprintf(out, "\t*p_imag = %.10g + r_imag;\n", coef_imag);
        if (grau - i != 0) {
            fprintf(out, "\tmultiplica(&r_real, &r_imag, x_real, x_imag, *d_real, *d_imag);\n");
            fprintf(out, "\t*d_real = %.10g + r_real;\n", coef_real * (grau - i));
            fprintf(out, "\t*d_imag = %.10g + r_imag;\n", coef_imag * (grau - i));
        }
    }
    fprintf(out, "}");

    fclose(in);
    fclose(out);

    printf("O arquivo \"polinomio.c\" foi gerado com sucesso!\n\n");

    return 0;
}
