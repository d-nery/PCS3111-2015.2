/*****************************************************************************/
/**                                                                         **/
/**         Daniel Nery Silva de Oliveira               9349051             **/
/**         Exercicio-Programa 04                                           **/
/**         Professora: Kelly Rosa Braghetto                                **/
/**         Turma: 06                                                       **/
/**                                                                         **/
/*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXLINHA   400
#define MAXCOLUNA  400
#define JANELA_MAX 50
#define JANELA_MIN 3
#define MAX_NAME   256 /* o tamanho maximo para nome de arquivo */

int i, j; /* contadores utilizados em varias funcoes, sempre reinicializados dentro de cada for */
int copia[MAXLINHA][MAXCOLUNA]; /* Copias usadas para operacoes em funcoes*/
typedef struct {         /* Posicao na matriz | usado na comparacao de matrizes */
    int linha, coluna;
} posicao;

void imprimeMatriz(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas);
void menu();
void troca(int* a, int* b);
int media(int media[JANELA_MAX*JANELA_MAX], int tam);
int min(int mininimizar[JANELA_MAX*JANELA_MAX], int tam);
int max(int maximizar[JANELA_MAX*JANELA_MAX], int tam);
int maiorvalor(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas);
posicao compara(int a[MAXLINHA][MAXCOLUNA], int b[MAXLINHA][MAXCOLUNA], int linhasA, int linhasB, int colunasA, int colunasB);

/* funcoes obrigatorias */
int le_pgm(char* prefixo_do_nome, int m[MAXLINHA][MAXCOLUNA], int *linhas, int* colunas, int* maiorValor);
int grava_pgm(char* prefixo_do_nome, int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int maiorValor);
void negativo(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas);
void rebatimentoVertical(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas);
void rebatimentoHorizontal(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas);
void rotacao(int m[MAXLINHA][MAXCOLUNA], int* linhas, int* colunas);
void corte(int m[MAXLINHA][MAXCOLUNA], int* linhas, int* colunas, int xsup, int ysup, int xinf, int yinf);
void filtroMediana(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela);
void filtroMedia(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela);
void filtroErosao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela);
void filtroDilatacao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela);
void limiarizacao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int k);
void filtroBorda1(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k);
void filtroBorda2(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k);
void filtroBorda3(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k);

int main()
{
    char prefixo_arquivo_in[MAX_NAME - 4],                 /* Nome maximo do arquivo sem a extensao .pgm */
         prefixo_arquivo_out[MAX_NAME - 4];
    int Imagem[MAXLINHA][MAXCOLUNA];
    int linhas, colunas, maiorValor, check, larguraJanela, k, limiteValido = 0;
    const char comandos[] = "nrvhedmz123xctgCas";          /* Comandos possiveis */
    char comando = 0;
    int flag = 0; /* Para ver se o usuario pediu para gravar o arquivo sem comando algum */

    check = 0;
    while (!check) {
        printf("Digite o nome do arquivo de entrada: ");
        scanf("%s", prefixo_arquivo_in);
        if((check = le_pgm(prefixo_arquivo_in, Imagem, &linhas, &colunas, &maiorValor))) /* Atribui o valor de retorno de le_pgm a check e verifica se e verdadeiro */
            printf("Arquivo %s.pgm carregado com sucesso.\n", prefixo_arquivo_in);
    }
    strcpy(prefixo_arquivo_out, prefixo_arquivo_in);
    menu();

    while (comando != 's') {
        printf("Digite um comando: ");
        scanf(" %c", &comando);
        if (!strchr(comandos, comando))  /* Checa se comando esta na lista de comandos possiveis */
            printf("Comando invalido\n");

        for (i = 4; i < 11; i++) {       /* Operacoes de 4 a 11 precisam da largura da Janela */
            if (comando == comandos[i]) {
                larguraJanela = 0;
                while (larguraJanela < JANELA_MIN || larguraJanela > JANELA_MAX) {
                    printf("Digite o tamanho da janela: ");
                    scanf("%d", &larguraJanela);
                    if (larguraJanela < JANELA_MIN || larguraJanela > JANELA_MAX)
                        printf("Tamanho invalido. A janela deve ser entre %d e %d.\n", JANELA_MIN, JANELA_MAX);
                }
            }
        }

        if (comando == '1' || comando == '2' || comando == '3') { /* Filtros de borda precisam de um parametro k */
            printf("Informe o valor de k: ");
            scanf("%d", &k);
        }

        if (comando == 'n') negativo(Imagem, linhas, colunas);
        if (comando == 'r') rotacao(Imagem, &linhas, &colunas);
        if (comando == 'v') rebatimentoVertical(Imagem, linhas, colunas);
        if (comando == 'h') rebatimentoHorizontal(Imagem, linhas, colunas);
        if (comando == 'e') filtroErosao(Imagem, linhas, colunas, larguraJanela);
        if (comando == 'd') filtroDilatacao(Imagem, linhas, colunas, larguraJanela);
        if (comando == 'm') filtroMediana(Imagem, linhas, colunas, larguraJanela);
        if (comando == 'z') filtroMedia(Imagem, linhas, colunas, larguraJanela);
        if (comando == '1') filtroBorda1(Imagem, linhas, colunas, larguraJanela, k);
        if (comando == '2') filtroBorda2(Imagem, linhas, colunas, larguraJanela, k);
        if (comando == '3') filtroBorda3(Imagem, linhas, colunas, larguraJanela, k);
        if (comando == 'a') menu();

        if (comando == 'c') { /* Carrega um novo arquivo */
            check = 0;
            while (!check) {
                printf("Digite o nome do arquivo de entrada: ");
                scanf("%s", prefixo_arquivo_in);
                if((check = le_pgm(prefixo_arquivo_in, Imagem, &linhas, &colunas, &maiorValor)))
                    printf("Arquivo %s.pgm carregado com sucesso.\n\n", prefixo_arquivo_in);
            }
            strcpy(prefixo_arquivo_out, prefixo_arquivo_in);
            flag = 0;
        }

        if (comando == 't') {
            imprimeMatriz(Imagem, linhas, colunas);
            printf("\n");
        }

        if (comando == 'x') {
            int xsup, ysup, xinf, yinf;
            printf("Informe x superior: ");
            scanf("%d", &xsup);
            printf("Informe y superior: ");
            scanf("%d", &ysup);
            printf("Informe x inferior: ");
            scanf("%d", &xinf);
            printf("Informe y inferior: ");
            scanf("%d", &yinf);
            if (xsup < 0 || ysup < 0 || xinf >= linhas || yinf >= colunas || xsup > xinf || ysup > yinf) limiteValido = 0;
            else limiteValido = 1;
            if (limiteValido) {
                corte(Imagem, &linhas, &colunas, xsup, ysup, xinf, yinf);
                if (!flag) {
                    strcat(prefixo_arquivo_out, "-");           /* Coloca o hifen caso haja algum comando */
                    flag = 1;
                }
                strncat(prefixo_arquivo_out, &comando, 1);      /* Coloca o comando no final do nome do arquivo      */
                printf("Operacao realizada com sucesso.\n");    /* Notifica que a operacao foi realizada com sucesso */
            }
            else printf("Limites invalidos\n\n");
        }

        if (comando == 'g') {
            /*maiorValor = maiorvalor(Imagem, linhas, colunas);*/
            grava_pgm(prefixo_arquivo_out, Imagem, linhas, colunas, maiorValor);
            printf("%s.pgm\n", prefixo_arquivo_out);
            printf("Arquivo %s.pgm gravado com sucesso.\n", prefixo_arquivo_out);
        }

        if (comando == 'C') {
            int c[MAXLINHA][MAXCOLUNA];
            int linhasC, colunasC, maiorValorC;
            char prefixo_arquivo_c[MAX_NAME - 4];
            posicao Erro;
            check = 0;
            while (!check) {
                printf("Digite o nome do arquivo com a imagem a ser comparada: ");
                scanf("%s", prefixo_arquivo_c);
                check = le_pgm(prefixo_arquivo_c, c, &linhasC, &colunasC, &maiorValorC);
            }
            Erro = compara(Imagem, c, linhas, linhasC, colunas, colunasC);
            if (Erro.linha == -2 && Erro.coluna == -2)
                printf("As matrizes sao iguais\n");
            else if (Erro.linha == -1 && Erro.coluna == -1)
                printf("As matrizes tem dimensoes diferentes\n");
            else
                printf("As matrizes tem valores diferentes na posicao %d, %d\n", Erro.linha, Erro.coluna);
        }

        for (i = 0; i < 11; i++) {                          /* Primeiros 12 comandos sao de transformacao (corte pode falhar) */
            if (comando == comandos[i]) {
                if (flag == 0) {
                    strcat(prefixo_arquivo_out, "-");       /* Coloca o hifen caso haja algum comando */
                    flag = 1;
                }
                strncat(prefixo_arquivo_out, &comando, 1);  /* Coloca o comando no final do nome do arquivo      */
                printf("Operacao realizada com sucesso.\n");/* Notifica que a operacao foi realizada com sucesso */
            }
        }
    }
    return 0;
}

void imprimeMatriz(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas)
{
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++)
            printf("%3d ", m[i][j]);
        printf("\n");
    }
}

void menu() /* Mostra os comandos possiveis para o usuario */
{
    printf("c - carga\n");
    printf("t - exibicao na tela\n");
    printf("n - negativo\n");
    printf("r - rotacao\n");
    printf("v - rebatimento vertical\n");
    printf("h - rebatimento horizontal\n");
    printf("x - corte\n");
    printf("e - filtro da erosao\n");
    printf("d - filtro da dilatacao\n");
    printf("m - filtro da mediana\n");
    printf("z - filtro da media\n");
    printf("1 - filtro de bordas 1\n");
    printf("2 - filtro de bordas 2\n");
    printf("3 - filtro de bordas 3\n");
    printf("g - gravacao\n");
    printf("C - comparacao\n");
    printf("a - ajuda\n");
    printf("s - sair\n\n");
}

void troca(int* a, int* b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ordena(int ordenar[JANELA_MAX*JANELA_MAX], int tam) /* ordena, media, min e max sao usadas dentro de outras */
{                                                        /* funcoes por isso usam uma variavel local para contar */
    int k, l;
    for (k = 0; k < tam; k++)                            /* Ordena a vetor */
        for (l = 1; l < tam - k; l++)
            if (ordenar[k] > ordenar[k + l])
                troca(&ordenar[k], &ordenar[k + l]);
}

int media(int mediar[JANELA_MAX*JANELA_MAX], int tam)
{
    int k, soma = 0;
    for (k = 0; k < tam; k++)
        soma += mediar[k];
    return soma/tam;
}

int min(int minimizar[JANELA_MAX*JANELA_MAX], int tam)
{
    int k, minimo = minimizar[0];
    for (k = 1; k < tam; k++)
        if (minimo > minimizar[k])
            minimo = minimizar[k];
    return minimo;
}

int max(int maximizar[JANELA_MAX*JANELA_MAX], int tam)
{
    int k, maximo = maximizar[0];
    for (k = 1; k < tam; k++)
        if (maximo < maximizar[k])
            maximo = maximizar[k];
    return maximo;
}

int maiorvalor(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas)
{
    int maior = 0;
    for (i = 0; i < linhas; i++)
        for (j = 0; j < linhas; j++)
            if (maior < m[i][j])
                maior = m[i][j];
    return maior;
}

posicao compara(int a[MAXLINHA][MAXCOLUNA], int b[MAXLINHA][MAXCOLUNA], int linhasA, int linhasB, int colunasA, int colunasB)
{
    posicao Erro;
    if (linhasA != linhasB || colunasA != colunasB) {
        Erro.linha = Erro.coluna = -1;
        return Erro;
    }
    for (i = 0; i < linhasA; i++)
        for (j = 0; j < colunasA; j++)
            if (a[i][j] != b[i][j]) {
                Erro.linha = i;
                Erro.coluna = j;
                return Erro;
            }
    Erro.linha = Erro.coluna = -2;
    return Erro;
}

int le_pgm(char* prefixo_do_nome, int m[MAXLINHA][MAXCOLUNA], int *linhas, int* colunas, int* maiorValor)
{
    /* ----------------------------------------------
    Le um arquivo no formato PGM.
    prefixo_do_nome : prefixo do arquivo pgm
    m : matriz correspondente a imagem lida
    linhas : numero de linhas da matriz
    colunas : numero de colunas da matriz
    max_value : maior valor na matriz
    ---------------------------------------------- */
    FILE *arq;
    char key[128];
    int aux;
    char fname[MAX_NAME];
    /* monta o nome do arquivo */
    strcpy(fname, prefixo_do_nome);
    strcat(fname,".pgm");
    /* abre o o arquivo de entrada para leitura */
    arq = fopen(fname, "r");
    if (arq == NULL){
        printf("Erro na abertura do arquivo %s\n",fname);
        return 0;
    }
    /* le dados do cabecalho */
    aux = fscanf(arq, "%s", key);
    if (aux != 1){
        printf("Erro na leitura do arquivo %s \n",fname);
        return 0;
    }
    if(strcmp(key,"P2") != 0) {
        printf("Formato desconhecido\n") ;
        fclose(arq) ;
        return 0;
    }
    aux = fscanf(arq, "%d %d %d", colunas, linhas, maiorValor) ;
    if (aux != 3) {
        printf("Formato incorreto\n") ;
        fclose(arq) ;
        return 0;
    }
    /* le a matriz (imagem) que se segue */
    for(i = 0; i < *linhas; i++) {
        for(j = 0; j < *colunas; j++) {
            fscanf(arq, "%d", &m[i][j]);
        }
    }
    fclose(arq) ; /* fecha arquivo */

    return 1;
}

int grava_pgm(char* prefixo_do_nome, int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int maiorValor)
{
    /* ----------------------------------------------
    Escreve um arquivo, no formato PGM.
    prefixo_do_nome : prefixo do arquivo pgm
    m : matriz correspondente a imagem lida
    linhas : numero de linhas da matriz
    colunas : numero de colunas da matriz
    max_value : maior valor na matriz
    ---------------------------------------------- */
    FILE *arq;
    char fname[MAX_NAME];
    /* monta o nome do arquivo */
    strcpy(fname, prefixo_do_nome);
    strcat(fname,".pgm");
    /*abre o o arquivo para gravacao */
    arq = fopen(fname, "w");
    if (arq == NULL){
        printf("Erro na abertura do arquivo %s\n",fname);
        return 0;
    }
    /* grava dados do cabecalho */
    fprintf(arq, "P2\n");
    fprintf(arq, "%d %d\n%d\n", colunas, linhas, maiorValor);
    /* grava a matriz (imagem) que se segue */
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            fprintf(arq, "%d ", m[i][j]);
        }
        fprintf(arq, "\n");
    }
    fclose(arq); /* fecha arquivo */
    return 1;
}

void negativo(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas)
{
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            m[i][j] = 255 - m[i][j];
}

void rebatimentoVertical(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas)
{
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas/2; j++)
            troca(&m[i][j], &m[i][colunas - j - 1]);
}

void rebatimentoHorizontal(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas)
{
    for (i = 0; i < linhas/2; i++)
        for (j = 0; j < colunas; j++)
            troca(&m[i][j], &m[linhas - i - 1][j]);
}

void rotacao(int m[MAXLINHA][MAXCOLUNA], int* linhas, int* colunas)
{
    int maior = *linhas > *colunas ? *linhas : *colunas;
    for (i = 0; i < maior; i++)         /* Transpoe m */
        for (j = i; j < maior; j++)
            troca(&m[i][j], &m[j][i]);
    troca(linhas, colunas);
    rebatimentoVertical(m, *linhas, *colunas);
}

void corte(int m[MAXLINHA][MAXCOLUNA], int* linhas, int* colunas, int xsup, int ysup, int xinf, int yinf)
{
    *linhas = xinf - xsup + 1;
    *colunas = yinf - ysup + 1;
    for (i = 0; i < *linhas; i++)
        for (j = 0; j < *colunas; j++)
            m[i][j] = m[xsup + i][ysup + j];
}

void filtroMediana(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela)
{
    int k, l, n;
    int vizinhanca[JANELA_MAX*JANELA_MAX];
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            copia[i][j] = m[i][j];
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            n = 0;
            for (k = i - larguraJanela/2; k <= i + larguraJanela/2; k++) {
                for (l = j - larguraJanela/2; l <= j + larguraJanela/2; l++) {
                    if (k >= 0 && l >= 0 && k < linhas && l < colunas) {
                        vizinhanca[n] = copia[k][l];
                        n++;
                    }
                }
            }
            ordena(vizinhanca, n);
            m[i][j] = n%2 == 0 ? vizinhanca[(n-1)/2  + 1] : vizinhanca[(n-1)/2];
        }
    }
}

void filtroMedia(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela)
{
    int k, l, n;
    int vizinhanca[JANELA_MAX*JANELA_MAX];
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            copia[i][j] = m[i][j];

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            n = 0;
            for (k = i - larguraJanela/2; k <= i + larguraJanela/2; k++) {
                for (l = j - larguraJanela/2; l <= j +  larguraJanela/2; l++) {
                    if (k >= 0 && l >= 0 && k < linhas && l < colunas) {
                        vizinhanca[n] = copia[k][l];
                        n++;
                    }
                }
            }
            m[i][j] = media(vizinhanca, n);
        }
    }
}

void filtroErosao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela)
{
    int k, l, n;
    int vizinhanca[JANELA_MAX*JANELA_MAX];
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            copia[i][j] = m[i][j];

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            n = 0;
            for (k = i - larguraJanela/2; k <= i + larguraJanela/2; k++) {
                for (l = j - larguraJanela/2; l <= j +  larguraJanela/2; l++) {
                    if (k >= 0 && l >= 0 && k < linhas && l < colunas) {
                        vizinhanca[n] = copia[k][l];
                        n++;
                    }
                }
            }
            m[i][j] = min(vizinhanca, n);
        }
    }
}

void filtroDilatacao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela)
{
    int k, l, n;
    int vizinhanca[JANELA_MAX*JANELA_MAX];
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            copia[i][j] = m[i][j];

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            n = 0;
            for (k = i - larguraJanela/2; k <= i + larguraJanela/2; k++) {
                for (l = j - larguraJanela/2; l <= j +  larguraJanela/2; l++) {
                    if (k >= 0 && l >= 0 && k < linhas && l < colunas) {
                        vizinhanca[n] = copia[k][l];
                        n++;
                    }
                }
            }
            m[i][j] = max(vizinhanca, n);
        }
    }
}

void limiarizacao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int k)
{
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++) {
            if (m[i][j] >= k)
                m[i][j] = 255;
            else
                m[i][j] = 0;
        }

}
void filtroBorda1(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k)
{
    int E[MAXLINHA][MAXCOLUNA];
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            E[i][j] = m[i][j];
    filtroDilatacao(m, linhas, colunas, larguraJanela);
    filtroErosao(E, linhas, colunas, larguraJanela);

    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            m[i][j] -= E[i][j];

    limiarizacao(m, linhas, colunas, k);
}

void filtroBorda2(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k)
{
    int E[MAXLINHA][MAXCOLUNA];
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            E[i][j] = m[i][j];
    filtroErosao(E, linhas, colunas, larguraJanela);

    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            m[i][j] -= E[i][j];

    limiarizacao(m, linhas, colunas, k);
}

void filtroBorda3(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k)
{
    int D[MAXLINHA][MAXCOLUNA];
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            D[i][j] = m[i][j];
    filtroDilatacao(D, linhas, colunas, larguraJanela);

    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            m[i][j] = D[i][j] - m[i][j];

    limiarizacao(m, linhas, colunas, k);
}
