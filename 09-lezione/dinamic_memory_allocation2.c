#include <stdlib.h>
#include <stdio.h>
#define DIM 10



// POSSO USARE UNA FUNZIONE PER ALLOCARE DELLA MEMORIA

int* fun(int val){
	int *b = malloc(sizeof(int));
	(*b) = val;
	return b;
}

// UTILIZZO SCORRETTO
/*
int* fun(){
	int p
	int *a = &p;
	(*a) = 4;
	return a;
} */

void stampa_vett(double *v, int dim){
	// nel for le operazioni sono opzionali, cioè posso eseguirle su un'altra riga di codice. Ma il ciclo deve comunque funzionare, quindi bisogna stare attenti
	// in questo caso è comodo definire fuori i in modo da poter usare l'indice anche fuori dal for
	int i = 0;

	printf("[");
	for(; i < (dim-1); i++){
		printf("%f,\n", v[i]);
	}
	printf("%f]\n", v[i]);
}

struct data{
	double r;
	int i;
	char str[10];
};


int main(){
	int *a = fun(7);
	printf("numero: %d\n", (*a));
	free(a);

/*quando i programmi vanno in esecuzione non vengono sempre eseguiti
 nella stessa zona di memoria perché questa posizione è assegnata 
 dal sistema operativo. Questo può causare problemi...*/

	//allocazione di un vettore di dieci elementi
	double *vett = malloc(sizeof(double) * DIM);
	
	//occupazione della memoria identica tra i due vettori, ma locazione differente: uno stack l'altro heap (con punt nello stack)
	double dVett[DIM];
	
	if(vett != NULL)
	// si può andare ad utilizzare la notazione vettoriale
	vett[2] = 5;

	stampa_vett(vett, DIM);
	free(vett);

	// per allocare una struct nella memoria dinamica
	struct data *d = malloc(sizeof(struct data)); 

	// per scrivere all'interno di un campo di una struct con puntatore
	d->r = 5.3; // posso anche usare (*d).r = 5.3

	free(d);

	// allocare un vettore della struct di tipo data
	struct data *dd = malloc(sizeof(struct data) * DIM);

	//come accedo al campo i del terzo vettore (3 metodi equivalenti)
	(dd+2)->i = 5; //

	//(*(dd+2)).i = 6; //aritmetica dei puntatori, aumento di due dimensioni il puntatore dd poi dereferenzio
	
	//dd[2].i = 4; //dereferenzio tramite la sintassi dei vettori e posso dunque accedere al campo i

	free(dd);


	//USO DELLA CALLOC
	int *g = calloc(1, sizeof(int));
	free(g);

	double *vv = calloc(DIM, sizeof(int));

	vv[4] = 15;
	stampa_vett(vv,DIM);


	// aumentare la dimensione di un vettore tramite riallocazione
	// può essere molto costosa perché prima alloca la nuova dimensione del vettore
	// e successivamente copia i vecchi elementi nelle nuove posizioni
	double *vv_new = realloc(vv, sizeof(double) * (DIM+5));
	// È importante utilizzare un puntatore d'appoggio che poi tramite un controllo sull'esito dell'allocazione
	// viene assegnato al nuovo puntatore e non fare direttamente:
	//double *vv= realloc(vv, sizeof(double) * (DIM+5));

	if(vv_new != NULL){
		vv = vv_new;
	} else {
	// in caso di errore perché la memoria disponibile è terminata è buona norma gestire questa eccezione
	// chiudendo i file aperti dove si stanno riportando dei dati per non andare a perdere ciò che è stato scritto 
	// fino a quel momento

		return 0;
	}
	free(vv);
}
