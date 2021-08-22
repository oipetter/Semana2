#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **criaMatriz(int m, int n);
int leiaMatriz(int **mat, int m, int n);
void imprimeMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
int* colunaMatriz(int ** mat, int m, int n, int ncoluna);
void liberaMatriz(int **mat, int ncoluna);
void imprimeVet (int *vet, int n);

int main(){
    int coluna=0;
    int linha=0;
    int **var;
    do{
        printf("Informe o numero de linha da matriz: ");
        scanf("%d",&linha);
    }while(linha<=0);
    do{
        printf("Informe numero de colunas da matriz: ");
        scanf("%d",&coluna);
    }while(coluna<=0);
    var=criaMatriz(linha, coluna);
    var=leiaMatriz(var, linha, coluna);
    somaMatriz(var, linha, coluna);
    imprimeMatriz(var, linha, coluna);
    colunaMatriz(var, linha, coluna, 0);
    imprimeVet (var, coluna); 
    liberaMatriz(var, linha);
    return(0);

}

void imprimeVet (int *vet, int n){
    int i;
    printf("\nVetor impresso:  ");
    for(i=0; i<n; i++){
        printf(" %d  ",vet[i]);
    }
}

void liberaMatriz(int **mat, int ncoluna){
    int i;
    for(i=0; i<ncoluna; i++){
        free(mat[i]);
    }
    free(mat);
}

int *colunaMatriz(int ** mat, int m, int n, int ncoluna){
    int i,j;
    int *ponteiro;
    ponteiro=(int *)malloc(n*sizeof(int));
    if((ponteiro=(int **)malloc(n*sizeof(int)))==NULL){
        printf("\n--- ATENCAO MEMORIA CHEIA ---");
        exit(1);
    }
    printf("\nOs elementos da coluna %d:",ncoluna);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(i==ncoluna){
                printf(" -  %d ",mat[j][i]);
                ponteiro[i]=mat[j][i];
            }
        }
    }
    return ponteiro;
}

int somaMatriz(int **mat, int m, int n){
    int i,j;
    int soma=0;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            soma=soma+mat[i][j];
        }
    }
    printf("\n\nSoma da matriz: %d\n",soma);
}

void imprimeMatriz(int **mat, int m, int n){
    int i,j;
    printf("Matriz impressa:");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("\n[%d][%d]: %d",i,j,mat[i][j]);
        }
    }
}

int leiaMatriz(int **mat, int m, int n){
    int i,j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("Informe valor de [%d][%d]:  ", i, j);
            scanf("%d",&mat[i][j]);
        }
    }
    return mat;
}

int ** criaMatriz(int m, int n){
    int i;
    int **MATRIX;
    MATRIX=(int **)malloc(m*sizeof(int*));
    for(i=0; i<m; i++){
        MATRIX[i]=(int *)malloc(n*sizeof(int));
        if(((int *)malloc(n*sizeof(int)))==NULL){
            printf("\n--- ATENÇÃO FALTA DE MEMORIA ---");
            exit(1);
        }
    }
    return MATRIX;
}
