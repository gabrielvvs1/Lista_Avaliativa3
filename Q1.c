#include <stdio.h>
#include <string.h>

int valor_emRomano(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romano_emDecimal(char *romano) {
    int resultado = 0;
    int comprimento = strlen(romano);

    for (int i = 0; i < comprimento; i++) {
        int valorAtual = valor_emRomano(romano[i]);
        int valorProximo = (i + 1 < comprimento) ? valor_emRomano(romano[i + 1]) : 0;

        if (valorAtual < valorProximo) {
            resultado += valorProximo - valorAtual;
            i++;
        } else {
            resultado += valorAtual;
        }
    }

    return resultado;
}

void decimal_emBinario(int decimal){
    if (decimal > 1) {
        decimal_emBinario(decimal / 2);
    }
    printf("%d", decimal % 2);
}

int main(){
    char numero_romano[13];
    
    scanf("%s", numero_romano);
    
    int decimal = romano_emDecimal(numero_romano);

    // Imprimindo representação binária
    printf("%s na base 2: ", numero_romano);
    decimal_emBinario(decimal);
    printf("\n");

    // Imprimindo representação decimal
    printf("%s na base 10: %d\n", numero_romano, decimal);

    // Imprimindo representação hexadecimal
    printf("%s na base 16: %x\n", numero_romano, decimal);

    return 0;
}
