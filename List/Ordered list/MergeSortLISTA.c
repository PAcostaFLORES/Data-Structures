/*This program generates aleatory numbers in a list, then the list is separated at the middle, the two news lists 
are ordered and finally are joined to form the same original but ordered list.

*/
#include<stdio.h>
#include<stdlib.h>
#include"Elem.h"
#include"Lista.h"

int main(){
	int i, N = 30, M = 100;
	Lista l;
	l = vacia();
	srand(time(NULL));
	for(i=0; i<(rand()%(N+1)); i++){
		l = cons((rand()%(M+1)), l);
	}
	
	printf("Observaciones: La lista l es de tamano aleatorio y de numeros aleatorios, que cambiaran con cada ejecucion del programa.\n");
	printf("\tLa lista generada aleatoriamente es:\n");
	ImpLista(l);
	printf("\n\tLa mitad inferior de la lista es:\n");
	ImpLista(MitadInferior(l));
	printf("\n\tLa mitad superior de la lista es:\n");
	ImpLista(MitadSuperior(l));
	printf("\n\tLa lista mezclada es:\n");
	ImpLista(OrdenaListaMezcla(l));

	return 0;
}
