#include <stdio.h>
#include <math.h>

int main(){
    int meses;
    double aporte_mensal, montante;
    double juros;

    scanf("%d %lf %lf", &meses, &aporte_mensal, &juros);

    for (int i = 1; i <= meses; i++){
        montante = aporte_mensal * (1 + juros) * ((pow(1 + juros, i)) - 1) / juros;
        printf("Montante ao fim do mes %d: R$ %.2lf\n", i, montante);
    }

    return 0;
}