#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

struct lista{
	int info;
	struct lista *prox;
};
typedef struct lista Lista;

Lista* iniciar(){
	return NULL;
}

Lista* inserirIni(Lista *l, int v){
	Lista *novo;
	novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = l;
	return novo;
}

void imprimir(Lista *l){
	while(l!=NULL){
		printf("%d -> ",l->info);
		l = l->prox;
	}
}

Lista* inserirFim(Lista *l, int v){
	Lista *novo, *aux = l;
	novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = NULL;

	if(aux==NULL)
		return novo;
	else{
		while(aux->prox!=NULL)
			aux = aux->prox;
		aux->prox = novo;
		return l;
	}
}

void verificar(Lista* l, int v){
	int flag=0;

	while(l!=NULL){
		if(l->info==v)
			flag = 1;
		l = l->prox;
	}
	if(flag==1)
		printf("\nNumero encontrado na lista!!!");
	else
		printf("\nNao existe o numero na lista!!!");
}

Lista* retira(Lista* l, int v){
	Lista *p=l, *ant=NULL;

	if(p==NULL){
		printf("\n\nNao foi possivel retirar, lista vazia!!!");
	}
	else{
		while(p!=NULL && p->info!=v){
			ant = p;
			p = p->prox;
		}

		if(p==l){
			l = p->prox;
			printf("\n\nElemento %d foi retirado!!!",p->info);
			free(p);
		}
		else{
			if(p==NULL){
				printf("\n\nElemento nao encontrado!!!");
			}
			else{
				ant->prox = p->prox;
				printf("\n\nElemento %d foi retirado!!!",p->info);
				free(p);
			}
		}
	}
	return l;
}

Lista* retirarlAll(Lista* l){
    Lista *p=l, *ant=NULL;
    while(p != NULL){
         p = p->prox;
         free(l);
         l = p;
    }
    return l;
}

int main(){
	Lista *L1 = NULL;
	int op, valor;
	do{
		system("cls");
		printf("(1) Iniciar lista\n");
		printf("(2) Inserir elemento no inicio da lista\n");
		printf("(3) Inserir elemento no fim da lista\n");
		printf("(4) Imprimir lista\n");
		printf("(5) Verificar existencia\n");
		printf("(6) Retirar elemento da lista\n");
		printf("(7) Retirar todos os elementos da lista\n");
		printf("(0) Sair\n");
		printf("Entre com a opcao: ");
		scanf("%d",&op);

		switch(op){
			case 1:
				L1 = iniciar();
				break;
			case 2:
				printf("\n\n Entre com o valor inteiro: ");
				scanf("%d",&valor);
				L1 = inserirIni(L1,valor);
				break;
			case 3:
				printf("\nEntre com o valor inteiro: ");
				scanf("%d",&valor);
				L1 = inserirFim(L1,valor);
				break;
			case 4:
				imprimir(L1);
				getch();
				break;
			case 5:
				printf("\nEntre com o valor inteiro: ");
				scanf("%d",&valor);
				verificar(L1,valor);
				getch();
				break;
			case 6:
				printf("\nEntre com o valor inteiro para retirar: ");
				scanf("%d",&valor);
				L1 = retira(L1,valor);
				getch();
				break;
            case 7:
                L1 = retirarlAll(L1);
                printf("\nLista eliminada com sucesso: ");
                getch();
			case 0:
				printf("\nSaindo!!!");
				break;
			default:
				printf("Entrou com o menu errado!!! Tente novamente!!!");
		}
	}while(op!=0);
}
