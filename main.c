#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct listaSimples{
    int valor;
    struct listaSimples *prox;
    struct listaSimples *ant;
};

struct listaSimples *insere(struct listaSimples *ini,int valor){

    struct listaSimples *aux = (struct listaSimples *)malloc(sizeof(struct listaSimples));
    aux->valor = valor;
    aux->prox = NULL;
    aux->ant = NULL;

    if(ini==NULL)ini = aux; /// caso o ponteiro ini seja nulo entra aqui
    else{

        struct listaSimples *ultimo = ini;
        int flag= 0;

        if(ultimo->prox==NULL){ /// condição de único bloco

            if(aux->valor > ultimo->valor){

                ultimo->prox = aux;
                aux->ant = ultimo;
            }else{

                aux->prox = ultimo;
                ultimo->ant = aux;
                ini = aux;
            }
        }else{
            /// no caso de ser menor que o primeiro ou igual o bloco novo que chegar entra aqui
            if(aux->valor < ultimo->valor || aux->valor==ultimo->valor){
                aux->prox = ultimo;
                ultimo->ant = aux;
                ini = aux;
            }else{
                    /// caso o bloco esteja no meio aqui será deslocado para a posição certa
                    while(ultimo->prox!=NULL){
                        if(aux->valor > ultimo->valor &&
                           aux->valor < ultimo->prox->valor){ /// desloca blocos do meio para encaixar o bloco na posição certa
                                flag=1;
                                aux->ant = ultimo;
                                aux->prox = ultimo->prox;
                                ultimo->prox->ant = aux;
                                ultimo->prox = aux;
                                break;
                           }else{

                                if(aux->valor==ultimo->valor){ /// Se tiver bloco com valores no meio igual entra aqui pra encaixar na posição certa
                                    flag=1;
                                    aux->prox = ultimo->prox;
                                    aux->ant = ultimo;

                                    ultimo->prox->ant = aux;
                                    ultimo->prox = aux;

                                    break;
                                }
                           }

                           ultimo = ultimo->prox;
                        }

                    if(flag==0){ /// aqui é só pra valores que vão pro final mesmo da lista
                        ultimo->prox = aux;
                        aux->ant = ultimo;
                    }
                }
            }
        }
    return ini;
}

void mostrarLista(struct listaSimples *ini){

    if(ini!=NULL){
        struct listaSimples *aux = ini;

        printf("\nindo, pra mostrar que a alocacao dinamica foi bem feita : \n");

        if(aux!=NULL){
            while(aux!=NULL){
                printf("%d -> ",aux->valor);
                aux = aux->prox;
            }
        }else{

            puts("Lista vazia");
        }
    }

    printf("\n\n");
}

void mostrarListaInverso(struct listaSimples *ini){

    if(ini!=NULL){
        struct listaSimples *aux = ini;

        printf("voltando, pra mostrar que a alocacao dinamica foi bem feita : \n");

        if(aux!=NULL){
            while(aux->prox!=NULL){
                aux = aux->prox;
            }
            while(aux!=NULL){
                printf("%d -> ",aux->valor);
                aux = aux->ant;
            }

        }else{

            puts("Lista vazia");
        }
    }

    printf("\n\n");
}

int main()
{

    struct listaSimples *ini = NULL;
    int i;

    /*ini = insere(ini,1);
    ini = insere(ini,4);
    ini = insere(ini,8);
    ini = insere(ini,4);
    ini = insere(ini,4);
    ini = insere(ini,8);
    ini = insere(ini,4);
    ini = insere(ini,4);
    ini = insere(ini,4);
    ini = insere(ini,3);
    ini = insere(ini,2);
    ini = insere(ini,7);
    ini = insere(ini,-1);
    ini = insere(ini,4);
    ini = insere(ini,6);
    ini = insere(ini,-1);
    ini = insere(ini,0);
    ini = insere(ini,0);
    ini = insere(ini,0);
    ini = insere(ini,-5);
    ini = insere(ini,5);
    ini = insere(ini,50);*/

    /* pra gerar números aleátorios ,
       pra mudar o valor limite é só alterar o valor apos %
    */

    for(i=1 ; i <= 14; i++){
        ini = insere(ini,rand() % 25);
    }

    printf("valores alocados ja ordenados : \n");
    mostrarLista(ini);
    printf("\n");
    mostrarListaInverso(ini);

    system("pause");
}
