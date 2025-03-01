#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapeamento.h"
 
typedef struct dic {
	int tam;
	Map *vet;
} *Dic;

Dic dic(int m) {
	Dic d = (struct dic*) malloc(sizeof(struct dic));
	d->tam = m;
	d->vet = (Map*) malloc(m*sizeof(Map));
	for(int i=0; i<m; i++)
		d->vet[i] = NULL;
	return d;
}

int hash(int c, int m);

int hash(int c, int m){
	return (c % m);
}

void insd(Chave c, Valor v, Dic d) {
	insm(c, v, &(d->vet[hash(c,d->tam)]));
}

void remd(Chave c, Dic d) {
	renm(c, &d->vet[hash(c,d->tam)]);
}

int pertd(Chave c, Valor v, Dic d) {
	return pertm(c, v, d->vet[hash(c,d->tam)]);
}

void exibed(Dic d) {
	for(int i=0; i<d->tam; i++) {
		printf("%d: ", i);
		exibem(d->vet[i]);
	}
}

void destroid(Dic *d) {
	for(int i=0; i<(*d)->tam; i++)
		destroim(&(*d)->vet[i]);
	free(*d);
	*d = NULL;
}

int main(void) {
	Dic D = dic(5);
	insd("bat", "morcego", D);
	insd("pig", "porco", D);
	insd("cat", "gato", D);
	insd("dog", "cachorro", D);
	insd("cow", "vaca", D);
	exibed(D);
	printf("\n");
	
	printf("Remocao: \n");
	insd("dog", "cachorro", D);
	exibed(D);
	printf("\n");
	
	printf("Pertinencia: \n");
	insd("cat", "gato", D);
	exibed(D);
	
	destroid(&D);
	
	return 0;
}

