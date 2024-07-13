#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no {
    Item item;
    struct no *prox;
} *Lista;

Lista no(Item x, Lista p) {
    Lista n = (struct no*)malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

void exibe(Lista L) {
    while (L != NULL) {
        printf("%d\n", L->item);
        L = L->prox;
    }
}

void destroi(Lista* L) {
    while (*L) {
        Lista n = *L;
        *L = n->prox;
        free(n);
    }
}

void anexa(Lista* A, Lista B) {
    if (!B) {
        return;
    }
    while (*A) {
        A = &(*A)->prox;
    }
    *A = B;
}

int pertence(Item x, Lista L) {
    while (L != NULL) {
        if (L->item == x) {
            return 1;  // O item pertence � lista
        }
        L = L->prox;
    }
    return 0;  // O item n�o pertence � lista
}

Lista inversa(Lista L) {
    Lista novaLista = NULL;
    while (L != NULL) {
        novaLista = no(L->item, novaLista);
        L = L->prox;
    }
    return novaLista;
}

int len(Lista L) {
    if (L == NULL) {
        return 0;  // Lista vazia, tamanho 0
    }
    return 1 + len(L->prox);  // Tamanho � 1 + tamanho da lista restante
}

int sum(Lista L) {
    if (L == NULL) {
        return 0;  // Lista vazia, soma 0
    }
    return L->item + sum(L->prox);  // Soma do item atual com a soma dos itens restantes
}

Lista clone(Lista L) {
    if (L == NULL) {
        return NULL;  // Lista vazia, retorna NULL
    }
    return no(L->item, clone(L->prox));  // Cria um novo n� com o item atual e faz a chamada recursiva para o pr�ximo n�
}

int main(void) {
    Lista I = no(3, no(1, no(5, NULL)));
    printf("Original: \n");
	exibe(I);
    printf("Clone: \n");
    Lista C = clone(I);
    exibe(C);
    
    destroi(&I);
    destroi(&C);
    return 0;
}

