/***************************************************************/
/**                                                           **/
/**   Daniel Nery Silva de Oliveira          9349051          **/
/**   Exercício-Programa 02                                   **/
/**   Professor: Kelly Rosa Braghetto                         **/
/**   Turma: 06                                               **/
/**                                                           **/
/***************************************************************/

#include<stdio.h>

#define NEG 1
#define POS 0

int main()
{
    int op1, op2, /* Operandos */
        num1, num2, /* Mantissas */
        copia1, copia2, /*Copias das Mantissas */
        sinal1, sinal2, /*Sinais dos expoentes */
        exp1, exp2, /* Módulos dos expoentes */
        dignum1, dignum2, /* Digitos das mantissas */
        opcao; /* Opção de operação */

    printf("MAC2166 - EP2 - Calculadora para Numeros de Ponto Flutuante\n\n");

    printf("Operando 1...................:");
    scanf("%d", &op1);
    /* Separa a Mantissa, o sinal do expoente e o módulo do expoente */
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
    /* printf("num1 = %d, sin1 = %d, exp1 = %d\n", num1, sinal1, exp1); */
    /* Normaliza */
    while(num1%10 == 0 && num1 != 0 && exp1 < 99){
        if(sinal1 == POS){
            num1 /= 10;
            exp1++;
        }
        if(sinal1 == NEG){
            num1 /= 10;
            exp1--;
        }
    }
    /* printf("num1 = %d, sin1 = %d, exp1 = %d\n", num1, sinal1, exp1); */
    /* Conta os dígitos */
    copia1 = num1;
    dignum1 = 0;
    while(copia1 != 0){
        copia1 /= 10;
        dignum1++;
    }
    /* printf("Digitos de num1 = %d\n", dignum1); */

    /* --Início-- */
    while(opcao != 6){
        printf("\nOperacoes disponiveis: 1 (+), 2 (-), 3 (*), 4 (/), 5 (limpar), 6 (parar)\n");
        printf("Numero da operacao desejada..:");
        scanf("%d", &opcao);
        if(opcao < 5){
            printf("\nOperando 2...................:");
            scanf("%d", &op2);
        }

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
        /* printf("num2 = %d, sin2 = %d, exp2 = %d\n", num2, sinal2, exp2); */
        /* Normaliza */
        while(num2%10 == 0 && num2 != 0 && exp2 < 99){
            if(sinal2 == POS){
                num2 /= 10;
                exp2++;
            }
            if(sinal2 == NEG){
                num2 /= 10;
                exp2--;
            }
        }
        /* printf("num2 = %d, sin2 = %d, exp2 = %d\n", num2, sinal2, exp2); */
        /* Conta os Dígitos*/
        copia2 = num2;
        dignum2 = 0;
        while(copia2 != 0){
            copia2 /= 10;
            dignum2++;
        }
        /* printf("Digitos de num2 = %d\n", dignum2); */
        if(opcao == 1 || opcao == 2){
            if(opcao == 2) num2 *= (-1);
            if(num1 != 0 && num2 != 0){
                if(sinal1 == POS && sinal2 == POS){
                    /* Tenta igualar os expoentes */
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
                    if(exp1 == exp2){
                        num1 += num2;
                    }
                    if(exp2 > exp1){
                        num1 = num2;
                        exp1 = exp2;
                    }
                    /* Normaliza e conta os digitos */
                    while(num1%10 == 0 && num1 != 0 && exp1 <= 99){
                        num1 /= 10;
                        exp1++;
                        dignum1--;
                    }
                }
                else if(sinal1 == NEG && sinal2 == NEG){
                    /* Tenta igualar os expoentes */
                    while(exp2 < exp1 && dignum2 < 6){
                        num2 *= 10;
                        exp2++;
                        dignum2++;
                    }
                    while(exp2 < exp1 && dignum1 > 1){
                        num1 /= 10;
                        exp1--;
                        dignum1--;
                    }
                    while(exp1 < exp2 && dignum1 < 6){
                        num1 *= 10;
                        exp1++;
                        dignum1++;
                    }
                    while(exp1 < exp2 && dignum2 > 1){
                        num2 /= 10;
                        exp2--;
                        dignum2--;
                    }
                    if(exp1 == exp2){
                        num1 += num2;
                    }
                    if(exp2 < exp1){
                        num1 = num2;
                        exp1 = exp2;
                    }
                    /* Normaliza e conta os digitos */
                    while(num1%10 == 0 && num1 != 0 && exp1 <= 99){
                        num1 /= 10;
                        exp1--;
                        dignum1--;
                    }
                }
                else if(sinal1 == POS && sinal2 == NEG){
                    /* Tenta igualar os expoentes */
                    exp2 *= (-1);
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
                    if(exp1 == exp2) num1 += num2;
                    /* Normaliza e conta os digitos */
                    while(num1%10 == 0 && num1 != 0  && exp1 <= 99){
                        num1 /= 10;
                        exp1++;
                        dignum1--;
                    }
                    if(exp1 < 0){
                        sinal1 = NEG;
                        exp1 *= (-1);
                    }
                    if(exp1 >= 0) sinal1 = POS;
                }
                else if(sinal1 == NEG && sinal2 == POS){
                    /* Tenta igualar os expoentes */
                    exp1 *= (-1);
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
                    if(exp1 == exp2) num1 += num2;
                    if(exp2 > exp1){
                        num1 = num2;
                        exp1 = exp2;
                    }
                    /* Normaliza e conta os digitos */
                    while(num1%10 == 0 && num1 != 0 && exp1 <= 99){
                        num1 /= 10;
                        exp1++;
                        dignum1--;
                    }
                    if(exp1 < 0){
                        sinal1 = NEG;
                        exp1 *= (-1);
                    }
                    if(exp1 >= 0) sinal1 = POS;
                }
                while(num1 > 999999 && exp1 < 99){
                    num1 /= 10;
                    exp1++;
                }
                if(num1 > 999999 && sinal1 == POS){
                    printf("\n*** AVISO: ocorreu um overflow no expoente. ***");
                    num1 = 999999;
                    exp1 = 99;
                }
                if(num1 < -999999 && sinal1 == POS){
                    printf("\n*** AVISO: ocorreu um overflow no expoente. ***");
                    num1 = -999999;
                    exp1 = 99;
                }
            }
            else if(num1 == 0 && num2 != 0) {
                num1 = num2;
                sinal1 = sinal2;
                exp1 = exp2;
            }

            if(num1 == 0){
                sinal1 = exp1 = 0;
                printf("\nResultado (e novo operando 1): 0\n");
            }
            else{
                printf("\nResultado (e novo operando 1): %d%d", num1, sinal1);
                if(exp1<10) printf("0");
                printf("%d\n", exp1);
            }
        }

        if(opcao == 3){
            int numM, sinalM, expM, dignumM, copiaM, /* Variaveis utilizadas */
                numS, sinalS, expS, dignumS/*, copiaS*/; /* durante a operação   */

            numM = sinalM = expM = dignumM = 0;
            numS = sinalS = expS = dignumS = 0;

            if(sinal1 == NEG) exp1 *= (-1);
            if(sinal2 == NEG) exp2 *= (-1);
            while(dignum2 >= 1){
                numM = num1*(num2%10);
                expM = exp1 + exp2;
                if(expM < 0) {sinalM = NEG; expM *= (-1);}
                num2 /= 10;
                exp2++;
                dignum2--;
                /* Normaliza */
                while(numM%10 == 0 && numM != 0  && expM < 99){
                    if(sinalM == POS){
                        numM /= 10;
                        expM++;
                    }
                    if(sinalM == NEG){
                        numM /= 10;
                        expM--;
                    }
                }
                /* Conta os Dígitos*/
                copiaM = numM;
                dignumM = 0;
                while(copiaM != 0){
                    copiaM /= 10;
                    dignumM++;
                }
                while(dignumM > 6){
                    numM /= 10;
                    expM++;
                    dignumM--;
                }
                /* SOMA */
                if(numS != 0 && numM != 0){
                    if(sinalS == POS && sinalM == POS){
                        /* Tenta igualar os expoentes */
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
                        if(expS == expM){
                            numS += numM;
                        }
                        if(expM > expS){
                            numS = numM;
                            expS = expM;
                        }
                        /* Normaliza e conta os digitos */
                        while(numS%10 == 0 && numS != 0 && expS <= 99){
                            numS /= 10;
                            expS++;
                            dignumS--;
                        }
                    }
                    else if(sinalS == NEG && sinalM == NEG){
                        /* Tenta igualar os expoentes */
                        while(expM < expS && dignumM < 6){
                            numM *= 10;
                            expM++;
                            dignumM++;
                        }
                        while(expM < expS && dignumS > 1){
                            numS /= 10;
                            expS--;
                            dignumS--;
                        }
                        while(expS < expM && dignumS < 6){
                            numS *= 10;
                            expS++;
                            dignumS++;
                        }
                        while(expS < expM && dignumM > 1){
                            numM /= 10;
                            expM--;
                            dignumM--;
                        }
                        if(expS == expM){
                            numS += numM;
                        }
                        if(expM < expS){
                            numS = numM;
                            expS = expM;
                        }
                        /* Normaliza e conta os digitos */
                        while(numS%10 == 0 && numS != 0 && expS <= 99){
                            numS /= 10;
                            expS--;
                            dignumS--;
                        }
                    }
                    else if(sinalS == POS && sinalM == NEG){
                        /* Tenta igualar os expoentes */
                        exp2 *= (-1);
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
                        if(expS == expM) numS += numM;
                        /* Normaliza e conta os digitos */
                        while(numS%10 == 0 && numS != 0  && expS <= 99){
                            numS /= 10;
                            expS++;
                            dignumS--;
                        }
                        if(expS < 0){
                            sinalS = NEG;
                            expS *= (-1);
                        }
                        if(expS >= 0) sinalS = POS;
                    }
                    else if(sinalS == NEG && sinalM == POS){
                        /* Tenta igualar os expoentes */
                        expS *= (-1);
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
                        if(expS == expM) numS += numM;
                        if(expM > expS){
                            numS = numM;
                            expS = expM;
                        }
                        /* Normaliza e conta os digitos */
                        while(numS%10 == 0 && numS != 0 && expS <= 99){
                            numS /= 10;
                            expS++;
                            dignumS--;
                        }
                        if(expS < 0){
                            sinalS = NEG;
                            expS *= (-1);
                        }
                        if(expS >= 0) sinalS = POS;
                    }
                    while(numS > 999999 && expS < 99){
                        num1 /= 10;
                        exp1++;
                    }
                    if(numS >  999999 && sinalS == POS){
                        printf("\n*** AVISO: ocorreu um overflow no expoente. ***");
                        numS = 999999;
                        expS = 99;
                    }
                    if(numS < -999999 && sinalS == POS){
                        printf("\n*** AVISO: ocorreu um overflow no expoente. ***");
                        numS = -999999;
                        expS = 99;
                    }
                }
                else if(numS == 0 && numM != 0) {
                    numS = numM;
                    sinalS = sinalM;
                    expS = expM;
                }
            }
            num1 = numS;
            sinal1 = sinalS;
            exp1 = expS;
            if(num1 == 0){
                sinal1 = exp1 = 0;
                printf("\nResultado (e novo operando 1): 0\n");
            }
            else{
                printf("\nResultado (e novo operando 1): %d%d", num1, sinal1);
                if(exp1<10) printf("0");
                printf("%d\n", exp1);
            }
        }

        if(opcao == 4){
            /* DIVISÃO */
        }
        if(opcao == 5){
            printf("\nOperando 1...................:");
            scanf("%d", &op1);
            /* Separa a Mantissa, o sinal do expoente e o módulo do expoente */
            num1 = op1/1000;
            if(op1 >= 0){
                sinal1 = (op1/100)%10;
                exp1 = op1%100;
            }
            if(op1 < 0){
                sinal1 = (op1/100)%10 * (-1);
                exp1 = op1%100 * (-1);
            }

            /* Normaliza */
            while(num1%10 == 0 && num1 != 0){
                if(sinal1 == POS){
                    num1 /= 10;
                    exp1++;
                }
                if(sinal1 == NEG){
                    num1 /= 10;
                    exp1--;
                }
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
