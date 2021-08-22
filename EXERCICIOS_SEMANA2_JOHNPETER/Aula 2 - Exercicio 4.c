#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *memoria(void);
int *realocaMem(int *x, int quantidade);
int menu();

int main(){
    int *var;
    var=memoria();
    int i;
    int tot=0;
    switch(menu()){
        case 1:
            free(var);
            exit(1);
            break;
        case 2:    
            do{
                printf("Quantos valores deseja incluir? ");
                scanf("%d",&tot);
            }while(tot<=0);
            var=realocaMem(var, tot);
            for(i=0; i<tot; i++){
                printf("Valor %d:  ",i+1);
                scanf("%d",&var[i]);
            }
            printf("\nValores digitados:  ");
            for(i=0; i<tot; i++){
                printf(" %d -",var[i]);
            }
            free(var);
            break;
    }
}

int *realocaMem(int *x, int quantidade){
    x=(int *)realloc(x, quantidade*sizeof(int));
    if( x==NULL){
        printf("\nFALTA DE MEMORIA");
        free(x);
        exit(1);
    }
    return x;
}

int menu(){
    int aux=0;
    do{
        printf("[ 1 ] - Para SAIR.\n[ 2 ] - Para add valor.\nInforme sua opcao:  ");
        scanf("%d",&aux);
    }while(aux<=0);
    return aux;
}

int *memoria(void){
	int *start;
	start = (int *) malloc(sizeof(int));
	return start;
}
