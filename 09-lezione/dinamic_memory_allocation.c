#include <stdlib.h>
#include <stdio.h>


int main(){
	// ESEMPIO PUNTATORE CLASSICO
	int p;
	int *c = &p;
		//utilizzo dei puntatori per memorizzare un valore
	p = 5;
	(*c) = 6; 

	// ESEMPIO UTILIZZO MALLOC
	// sizeof è usato per compatibilità tra sistemi operativi

	// il puntatore allo heap è memorizzato nello stack
	int *a = malloc(sizeof(int));
	//LA MEMORIA DINAMICA È ACCESSIBILE SOLAMENTE TRAMITE L'USO DEI PUNTATORI
	(*a) = 4;
	printf("numero nello stack: %d\n", p);
	printf("numero nello stack (con puntatore): %d\n", (*c));
	printf("numero nello heap: %d\n", (*a));

	//ogni volta che si usa malloc() bisogna liberare lo spazio allocato quando non è più utile la  
	free(a);
}
