#include <stdio.h>
#include <string.h>
#include <ctype.h>

int NumeroPlaca(char c){
    return (c >= '0' && c <= '9');
}

void convertePraMinusculas(char *str){
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int AutorizacaoPrarodar(char placa[], char diaSemana[]){
    int tam = strlen(placa);

    char ultimoDigito = placa[tam - 1];
    int digito = ultimoDigito - '0';

    if ((strcmp(diaSemana, "segunda-feira") == 0 && (digito == 0 || digito == 1)) || (strcmp(diaSemana, "terca-feira") == 0 && (digito == 2 || digito == 3)) ||
        (strcmp(diaSemana, "quarta-feira") == 0 && (digito == 4 || digito == 5)) || (strcmp(diaSemana, "quinta-feira") == 0 && (digito == 6 || digito == 7)) ||
        (strcmp(diaSemana, "sexta-feira") == 0 && (digito == 8 || digito == 9))){
        return 0; 
    } else {
        return 1; 
    }
}

int main(){
    char placa[10];
    char diadaSemana[15];

    scanf("%s", placa);
    scanf("%s", diadaSemana);

    if (!((strlen(placa) == 7 || strlen(placa) == 8) &&
          (placa[0] >= 'A' && placa[0] <= 'Z') &&
          (placa[1] >= 'A' && placa[1] <= 'Z') &&
          (placa[2] >= 'A' && placa[2] <= 'Z') &&
          NumeroPlaca(placa[strlen(placa) - 1]))){
        printf("Placa invalida\n");

        if (strcmp(diadaSemana, "SEGUNDA-FEIRA") != 0 &&
            strcmp(diadaSemana, "TERCA-FEIRA") != 0 &&
            strcmp(diadaSemana, "QUARTA-FEIRA") != 0 &&
            strcmp(diadaSemana, "QUINTA-FEIRA") != 0 &&
            strcmp(diadaSemana, "SEXTA-FEIRA") != 0 &&
            strcmp(diadaSemana, "SABADO") != 0 &&
            strcmp(diadaSemana, "DOMINGO") != 0){
            printf("Dia da semana invalido\n");
        }
        return 0;
    }

    if (strcmp(diadaSemana, "SEGUNDA-FEIRA") != 0 &&
        strcmp(diadaSemana, "TERCA-FEIRA") != 0 &&
        strcmp(diadaSemana, "QUARTA-FEIRA") != 0 &&
        strcmp(diadaSemana, "QUINTA-FEIRA") != 0 &&
        strcmp(diadaSemana, "SEXTA-FEIRA") != 0 &&
        strcmp(diadaSemana, "SABADO") != 0 &&
        strcmp(diadaSemana, "DOMINGO") != 0){
        printf("Dia da semana invalido\n");
        return 0;
    }

    convertePraMinusculas(diadaSemana);

    int autorizado = AutorizacaoPrarodar(placa, diadaSemana);

    if (strcmp(diadaSemana, "sabado") == 0 || strcmp(diadaSemana, "domingo") == 0){
        printf("Nao ha proibicao no fim de semana\n");
    } else if (autorizado){
        printf("%s pode circular %s\n", placa, diadaSemana);
    } else{
        printf("%s nao pode circular %s\n", placa, diadaSemana);
    }

    return 0;
}