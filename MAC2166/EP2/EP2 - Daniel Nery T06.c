/*****************************************************************************/
/**                                                                         **/
/**         Daniel Nery Silva de Oliveira               9349051             **/
/**         Exercício-Programa 02                                           **/
/**         Professora: Kelly Rosa Braghetto                                **/
/**         Turma: 06                                                       **/
/**                                                                         **/
/*****************************************************************************/

#include<stdio.h>

#define NEG 1
#define POS 0

int main(){
    int op1, op2,             /* Operandos */
        num1, num2,           /* Mantissas */
        copia1, copia2,       /* Cópias das mantissas */
        sinal1, sinal2,       /* Sinal dos expoentes */
        exp1, exp2,           /* Expoentes */
        dignum1, dignum2,     /* Nº de dígitos das mantissas */
        opcao,                /* Opção de operação */
        Overflow, Underflow;  /* Checa se houve over/underflow */

    printf("MAC2166 - EP2 - Calculadora para Numeros de Ponto Flutuante\n");

    printf("\nOperando 1...................:");
    scanf("%d", &op1);

    /* Separa a mantissa, o sinal e o expoente */
    num1 = op1/1000;
    if(op1 >= 0){
        sinal1 = (op1/100)%10;
        exp1 = op1%100;
    }
    if(op1 < 0){
        sinal1 = (op1/100)%10 * (-1);
        exp1 = op1%100 * (-1);
    }
    if(num1 == 0) sinal1 = exp1 = 0;

    if(sinal1 == NEG) exp1 *= (-1); /* coloca o sinal no expoente */

    /* Normaliza */
    while(num1%10 == 0 && num1 != 0 && exp1 < 99){
        num1 /= 10;
        exp1++;
    }

    /* Conta os dígitos */
    copia1 = num1;
    dignum1 = 0;
    while(copia1 != 0){
        copia1 /= 10;
        dignum1++;
    }

    /* --Começa as operações-- */
    while(opcao != 6){
        Overflow = Underflow = 0;
        /* Pergunta a opção e o segundo operando */
        printf("\nOperacoes disponiveis: 1 (+), 2 (-), 3 (*), 4 (/),");
        printf(" 5 (limpar), 6 (parar)\n");
        printf("Numero da operacao desejada..:");
        scanf("%d", &opcao);
        if(opcao < 5){
            printf("\nOperando 2...................: ");
            scanf("%d", &op2);
        }

        /* Separa a mantissa, o sinal e o expoente */
        num2 = op2/1000;
        if(op2 >= 0){
            sinal2 = (op2/100)%10;
            exp2 = op2%100;
        }
        if(op2 < 0){
            sinal2 = (op2/100)%10 * (-1);
            exp2 = op2%100 * (-1);
        }
        if(num2 == 0) sinal2 = exp2 = 0;

        if(sinal2 == NEG) exp2 *= (-1); /* coloca o sinal no expoente */

        /* Normaliza */
        while(num2%10 == 0 && num2 != 0 && exp2 < 99){
            num2 /= 10;
            exp2++;
        }

        /* Conta os dígitos */
        copia2 = num2;
        dignum2 = 0;
        while(copia2 != 0){
            copia2 /= 10;
            dignum2++;
        }

        /* --SOMA e SUBTRAÇÃO-- */
        if(opcao == 1 || opcao == 2){
            if(opcao == 2) num2 *= (-1);
            if(num1 != 0 && num2 != 0){
                /* Tenta igualar os expoentes */
                /* Operando 1 maior */
                while(exp1 > exp2 && dignum1 < 6){
                    num1 *= 10;
                    exp1--;
                    dignum1++;
                }
                while(exp1 > exp2 && dignum2 > 1){
                    num2 /= 10;
                    exp2++;
                    dignum2--;
                }
                /* Operando 2 maior */
                while(exp2 > exp1 && dignum2 < 6){
                    num2 *= 10;
                    exp2--;
                    dignum2++;
                }
                while(exp2 > exp1 && dignum1 > 1){
                    num1 /= 10;
                    exp1++;
                    dignum1--;
                }

                /* Atualiza o valor do operando 1 com a soma */
                if(exp1 == exp2) num1 += num2;
                if(exp2 > exp1){
                    num1 = num2;
                    exp1 = exp2;
                }

                /* Normaliza */
                while(num1%10 == 0 && num1 != 0 && exp1 < 99){
                    num1 /= 10;
                    exp1++;
                }

                /* Conta os dígitos */
                copia1 = num1;
                dignum1 = 0;
                while(copia1 != 0){
                    copia1 /= 10;
                    dignum1++;
                }

                /* - Checagem de Overflow - */
                /* Reduz para 6 dígitos */
                while(dignum1 > 6 && exp1 < 99){
                    num1 /= 10;
                    exp1++;
                    dignum1--;
                }
                /* Reduz o expoente para até 99 */
                while(dignum1 < 6 && exp1 > 99){
                    num1 *= 10;
                    exp1--;
                    dignum1++;
                }
                /* Overflow se o numero ainda for maior que 999999E99 */
                if(num1 > 999999 || exp1 > 99){
                    Overflow = 1;
                    num1 = 999999;
                    exp1 = 99;
                    dignum1 = 6;
                }
                if(num1 < -999999 || exp1 > 99){
                    Overflow = 1;
                    num1 = -999999;
                    exp1 = 99;
                    dignum1 = 6;
                }

                /* Underflow se o expoente for menor que -99 */
                if(dignum1 > 6 || exp1 < -99){
                    Underflow = 1;
                    num1 = 0;
                    exp1 = 0;
                    dignum1 = 0;
                }
            }
            else if(num1 == 0 && num2 != 0){
                num1 = num2;
                exp1 = exp2;
                dignum1 = dignum2;
            }

            /* Imprime o resultado */
            if(Overflow)  printf("\n*** AVISO: ocorreu um overflow no expoente. ***");
            if(Underflow) printf("\n*** AVISO: ocorreu um underflow no expoente. ***");
            if(num1 == 0){
                sinal1 = exp1 = dignum1 = 0;
                printf("\nResultado (e novo operando 1): 0\n");
            }
            else if(exp1 < 0){
                printf("\nResultado (e novo operando 1): %d1", num1);
                if(exp1>-10) printf("0");
                printf("%d\n", exp1*(-1));
            }
            else if(exp1 >= 0){
                printf("\nResultado (e novo operando 1): %d0", num1);
                if(exp1<10) printf("0");
                printf("%d\n", exp1);
            }
        }

        /* --MULTIPLICAÇÃO-- */
        if(opcao == 3){
            int numM, sinalM, expM, dignumM, copiaM, /* Variaveis utilizadas */
                numS, sinalS, expS, dignumS, copiaS; /* durante a operação   */

            numM = sinalM = expM = dignumM = 0;
            numS = sinalS = expS = dignumS = 0;

            while(dignum2 >= 1 && !(Overflow||Underflow)){
                numM = num1*(num2%10);
                expM = exp1 + exp2;
                num2 /= 10;
                exp2++;
                dignum2--;
                /* Normaliza */
                while(numM%10 == 0 && numM != 0  && expM < 99){
                    numM /= 10;
                    expM++;
                }

                /* Conta os dígitos */
                copiaM = numM;
                dignumM = 0;
                while(copiaM != 0){
                    copiaM /= 10;
                    dignumM++;
                }

                /* Reduz para 6 dígitos */
                while(dignumM > 6){
                    numM /= 10;
                    expM++;
                    dignumM--;
                }

                /* ---- SOMA ---- (num1 => numS e num2 => numM) */
                if(numS != 0 && numM != 0){
                    /* Tenta igualar os expoentes */
                    /* Operando S maior */
                    while(expS > expM && dignumS < 6){
                        numS *= 10;
                        expS--;
                        dignumS++;
                    }
                    while(expS > expM && dignumM > 1){
                        numM /= 10;
                        expM++;
                        dignumM--;
                    }
                    /* Operando M maior */
                    while(expM > expS && dignumM < 6){
                        numM *= 10;
                        expM--;
                        dignumM++;
                    }
                    while(expM > expS && dignumS > 1){
                        numS /= 10;
                        expS++;
                        dignumS--;
                    }

                    /* Atualiza o valor do operando S com a soma */
                    if(expS == expM) numS += numM;
                    if(expM > expS){
                        numS = numM;
                        expS = expM;
                    }
                }
                else if(numS == 0 && numM != 0){
                    numS = numM;
                    expS = expM;
                    dignumS = dignumM;
                }
                /* Normaliza */
                while(numS%10 == 0 && numS != 0 && expS < 99){
                    numS /= 10;
                    expS++;
                }

                /* Conta os dígitos */
                copiaS = numS;
                dignumS = 0;
                while(copiaS != 0){
                    copiaS /= 10;
                    dignumS++;
                }

                /* - Checagem de Overflow */
                /* Reduz para 6 dígitos */
                while(dignumS > 6 && expS < 99){
                    numS /= 10;
                    expS++;
                    dignumS--;
                }
                /* Reduz o expoente para até 99 */
                while(dignumS < 6 && expS > 99){
                    numS *= 10;
                    expS--;
                    dignumS++;
                }
                /* Overflow se o numero ainda for maior que 999999E99 */
                if(numS > 999999 || expS > 99){
                    Overflow = 1;
                    numS = 999999;
                    expS = 99;
                    dignumS = 6;
                }
                if(numS < -999999 || expS > 99){
                    Overflow = 1;
                    numS = -999999;
                    expS = 99;
                    dignumS = 6;
                }

                /* Underflow se o expoente for menor que -99 */
                if(dignumS > 6 || expS < -99){
                    Underflow = 1;
                    numS = 0;
                    expS = 0;
                    dignumS = 0;
                }
            }

            /* Passa o valor do Operando S para o Operando 1 */
            num1 = numS;
            sinal1 = sinalS;
            exp1 = expS;
            dignum1 = dignumS;

            /* Imprime o resultado */
            if(Overflow)  printf("\n*** AVISO: ocorreu um overflow no expoente. ***");
            if(Underflow) printf("\n*** AVISO: ocorreu um underflow no expoente. ***");
            if(num1 == 0){
                sinal1 = exp1 = dignum1 = 0;
                printf("\nResultado (e novo operando 1): 0\n");
            }
            else if(exp1 < 0){
                printf("\nResultado (e novo operando 1): %d1", num1);
                if(exp1>-10) printf("0");
                printf("%d\n", exp1*(-1));
            }
            else if(exp1 >= 0){
                printf("\nResultado (e novo operando 1): %d0", num1);
                if(exp1<10) printf("0");
                printf("%d\n", exp1);
            }
        }

        /* --DIVISÃO-- */
        if(opcao == 4){
            int numD, sinalD, expD, dignumD, copiaD,        /* Variaveis utilizadas */
                numR, exp1C, cont;                          /* durante a operação   */

            numD = sinalD = expD = dignumD = 0;
            numR = cont = 0;
            exp1C = exp1;

            if(num2 == 0){
                /* Não é possível dividir */
                printf("\n*** ERRO: nao e' possivel dividir por zero. ***\n");
            }
            else{
                numD = num1/num2;
                expD = exp1C - exp2;
                numR = 10*(num1%num2);    /* Resto da divisão*10 */
                num1 = 0; exp1 = 0;
                exp2++;

                /* Normaliza */
                while(numD%10 == 0 && numD != 0  && expD < 99){
                    numD /= 10;
                    expD++;
                }

                /* Conta os dígitos */
                copiaD = numD;
                dignumD = 0;
                while(copiaD != 0){
                    copiaD /= 10;
                    dignumD++;
                }

                /* Reduz para 6 dígitos */
                while(dignumD > 6){
                    numD /= 10;
                    expD++;
                    dignumD--;
                }

                /* ---- SOMA ---- (num2 => numD); num1 = 0; Já normalizado */
                if(num1 == 0 && numD != 0){
                    num1 = numD;
                    exp1 = expD;
                    dignum1 = dignumD;
                }

                /* - Checagem de Overflow - */
                /* Reduz para 6 dígitos */
                while(dignum1 > 6 && exp1 < 99){
                    num1 /= 10;
                    exp1++;
                    dignum1--;
                }
                /* Reduz o expoente para até 99 */
                while(dignum1 < 6 && exp1 > 99){
                    num1 *= 10;
                    exp1--;
                    dignum1++;
                }
                /* Overflow se o numero ainda for maior que 999999E99 */
                if(num1 > 999999 || exp1 > 99){
                    Overflow = 1;
                    num1 = 999999;
                    exp1 = 99;
                    dignum1 = 6;
                }
                if(num1 < -999999 || exp1 > 99){
                    Overflow = 1;
                    num1 = -999999;
                    exp1 = 99;
                    dignum1 = 6;
                }

                /* Underflow se o expoente for menor que -99 */
                if(dignum1 > 6 || exp1 < -99){
                    Underflow = 1;
                    num1 = 0;
                    exp1 = 0;
                    dignum1 = 0;
                }

                while(numR != 0 && dignum1 <= 6 && !(Underflow || Overflow) && cont < 10){
                    numD = numR/num2;
                    expD = exp1C - exp2;
                    numR = 10*(numR%num2);
                    exp2++;

                    /* Normaliza */
                    while(numD%10 == 0 && numD != 0  && expD < 99){
                        numD /= 10;
                        expD++;
                    }

                    /* Conta os dígitos */
                    copiaD = numD;
                    dignumD = 0;
                    while(copiaD != 0){
                        copiaD /= 10;
                        dignumD++;
                    }

                    /* Reduz para 6 dígitos */
                    while(dignumD > 6){
                        numD /= 10;
                        expD++;
                        dignumD--;
                    }

                    /* ---- SOMA ---- (num2 => numD) */
                    if(num1 != 0 && numD != 0){
                        /* Tenta igualar os expoentes */
                        /* Operando 1 maior */
                        while(exp1 > expD && dignum1 < 6){
                            num1 *= 10;
                            exp1--;
                            dignum1++;
                        }
                        while(exp1 > expD && dignumD > 1){
                            numD /= 10;
                            expD++;
                            dignumD--;
                        }
                        /* Operando 2 maior */
                        while(expD > exp1 && dignumD < 6){
                            numD *= 10;
                            expD--;
                            dignumD++;
                        }
                        while(expD > exp1 && dignum1 > 1){
                            num1 /= 10;
                            exp1++;
                            dignum1--;
                        }

                        /* Atualiza o valor do operando 1 com a soma */
                        if(exp1 == expD) num1 += numD;
                        if(expD > exp1){
                            num1 = numD;
                            exp1 = expD;
                        }
                    }
                    else if(num1 == 0 && numD != 0){
                        num1 = numD;
                        exp1 = expD;
                        dignum1 = dignumD;
                    }
                    /* Normaliza */
                    while(num1%10 == 0 && num1 != 0 && exp1 < 99){
                        num1 /= 10;
                        exp1++;
                    }

                    /* Conta os dígitos */
                    copia1 = num1;
                    dignum1 = 0;
                    while(copia1 != 0){
                        copia1 /= 10;
                        dignum1++;
                    }

                    /* - Checagem de Overflow - */
                    /* Reduz para 6 dígitos */
                    while(dignum1 > 6 && exp1 < 99){
                        num1 /= 10;
                        exp1++;
                        dignum1--;
                    }
                    /* Reduz o expoente para até 99 */
                    while(dignum1 < 6 && exp1 > 99){
                        num1 *= 10;
                        exp1--;
                        dignum1++;
                    }
                    /* Overflow se o numero ainda for maior que 999999E99 */
                    if(num1 > 999999 || exp1 > 99){
                        Overflow = 1;
                        num1 = 999999;
                        exp1 = 99;
                        dignum1 = 6;
                    }
                    if(num1 < -999999 || exp1 > 99){
                        Overflow = 1;
                        num1 = -999999;
                        exp1 = 99;
                        dignum1 = 6;
                    }

                    /* Underflow se o expoente for menor que -99 */
                    if(dignum1 > 6 || exp1 < -99){
                        Underflow = 1;
                        num1 = 0;
                        exp1 = 0;
                        dignum1 = 0;
                    }
                    cont++; /* Impede loops infinitos no caso de num1 ter 6 digitos e numR nunca chegar a 0 */
                }

                /* Imprime os resultados */
                if(Overflow)  printf("\n*** AVISO: ocorreu um overflow no expoente. ***");
                if(Underflow) printf("\n*** AVISO: ocorreu um underflow no expoente. ***");
                if(num1 == 0){
                    sinal1 = exp1 = dignum1 = 0;
                    printf("\nResultado (e novo operando 1): 0\n");
                }
                else if(exp1 < 0){
                    printf("\nResultado (e novo operando 1): %d1", num1);
                    if(exp1>-10) printf("0");
                    printf("%d\n", exp1*(-1));
                }
                else if(exp1 >= 0){
                    printf("\nResultado (e novo operando 1): %d0", num1);
                    if(exp1<10) printf("0");
                    printf("%d\n", exp1);
                }
            }
        }

        /* --LIMPAR-- */
        if(opcao == 5){
            printf("\nOperando 1...................:");
            scanf("%d", &op1);

            /* Separa a mantissa, o sinal e o expoente */
            num1 = op1/1000;
            if(op1 >= 0){
                sinal1 = (op1/100)%10;
                exp1 = op1%100;
            }
            if(op1 < 0){
                sinal1 = (op1/100)%10 * (-1);
                exp1 = op1%100 * (-1);
            }
            if(num1 == 0) sinal1 = exp1 = 0;

            if(sinal1 == NEG) exp1 *= (-1); /* coloca o sinal no expoente */

            /* Normaliza */
            while(num1%10 == 0 && num1 != 0 && exp1 < 99){
                num1 /= 10;
                exp1++;
            }

            /* Conta os dígitos */
            copia1 = num1;
            dignum1 = 0;
            while(copia1 != 0){
                copia1 /= 10;
                dignum1++;
            }
        }
    }
    printf("\nTchau!\n");

    return 0;
}
