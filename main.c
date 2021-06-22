#include <stdio.h>
#include <stdlib.h>

void maior_subarray(int *vet, int inicio, int meio, int fim, int *indice_esquerda, int *indice_direita, int *soma){
    int soma_esquerda, soma_direita;
    soma_esquerda = vet[inicio];
    *soma = 0;
    for(int i=meio; i>=inicio;i--){
        *soma = *soma + vet[i];
        if(*soma > soma_esquerda){
            soma_esquerda = *soma;
            *indice_esquerda = i;
        }
    }

    soma_direita = vet[meio+1];
    *soma = 0;

    for(int j=meio+1; j<=fim; j++){
        *soma = *soma + vet[j];
        if(*soma > soma_direita){
            soma_direita = *soma;
            *indice_direita = j;
        }
    }
    *soma = soma_esquerda + soma_direita;
}

void encontra_subarray(int *vet, int inicio, int fim, int *i, int *j, int *soma){
    int esquerda_min, esquerda_max, soma_esquerda;
    int direita_min, direita_max, soma_direita;
    int cross_min, cross_max, soma_cross;

    if(fim == inicio){
        return;
    }
    else{
        int meio = (inicio+fim)/2;
        encontra_subarray(vet, inicio, meio, &esquerda_min, &esquerda_max, &soma_esquerda);
        encontra_subarray(vet, meio+1, fim, &direita_min, &direita_max, &soma_direita);
        maior_subarray(vet, inicio, meio, fim, &cross_min, &cross_max, &soma_cross);

        if(soma_esquerda > soma_direita && soma_esquerda > soma_cross){
            *i = esquerda_min;
            *j = esquerda_max;
            *soma = soma_esquerda;
        }else if(soma_direita > soma_esquerda && soma_direita > soma_cross){
            *i = direita_min;
            *j = direita_max;
            *soma = soma_direita;
        }
        else{
            *i = cross_min;
            *j = cross_max;
            *soma = soma_cross;
        }

    }
}



int main()
{

    int vet[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4, 7};
    int *ret;
    int i, j, soma;

    encontra_subarray(vet, 0, 15, &i, &j, &soma);

    printf("O maior subarranjo continuo do vetor eh:\n\n");

    for(int k=i; k<=j; k++){
        printf("%i ", vet[k]);
        if(k!=j)
            printf("+ ");
    }
    printf("= %i\n\n", soma);




    printf("Hello world!\n");
    return 0;
}
