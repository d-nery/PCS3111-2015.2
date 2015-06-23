#include<stdio.h>

int main()
{
    FILE *poli;
    poli = fopen("polinomio.txt", "w");
    if(!poli) {printf("erro"); return 0;}

    /* unsigned char xr = 0, xi = 255; */
    int g;

    printf("Grau do polinomio: ");
    scanf("%d", &g);

    fprintf(poli, "%d\n", g);
    for(; g >=0; g--) {
        fprintf(poli, "0 0\n");
       /* fprintf(poli, "%d %d\n", xr, xi);
        xr++; xi--; */
    }
    printf("Polinomio gerado");
    fclose(poli);
    getch();
    return 0;
}
