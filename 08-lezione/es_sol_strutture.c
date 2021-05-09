/*
* Scrivere un gruppo di funzioni che opera sulla struttura treno
* Il treno è identificato dal numero di carrozze, dal tipo di trazione (elettrica o a gasolio).
* La funzione aggiungi carrozza che aumenta le carrozze del treno
* La funzione rimuovi carrozza che diminuisce le carrozze del treno
* ed un ultima funzione che prende un treno e un tipo di trazione ed assegna la trazione al treno.
* Fare una funzione che connette due treni modificando il primo.
*/

//definendo il tipo di trazione esternamente alla struct questa puà essere utilizzata 
//anche in altre struct o in generale può essere utilizzata da 

#include <stdio.h>

enum tipo_trazione{
	ELETTRICO, GASOLIO
};
char *str_tipo_trazione[] = {"ELETTRICO","GASOLIO"};

struct treno{
	int num_carrozze;
	enum tipo_trazione trazione;
	/* char trazione; // 'e' oppure 'g'
	int trazione; // 0 el. e 1 gas ad esempio
	*/
};

/* stesso risultato dove l'enum esiste solo nella dichiarazione della struct

struct treno {
	int num_carrozze;
	enum {
		ELETTRICO, GASOLIO
	} trazione;
}

*/

void aumenta_carrozze(struct treno *t){
	// (*t).num_carrozze++; // equivalente ma l'altro è più corretto
	t->num_carrozze++; // la deferenziazione avviene in automatico
}

void diminuisci_carrozze(struct treno *t){
	t->num_carrozze--;
}

void assegna_trazione(struct treno *t, enum tipo_trazione tipo){
	t->trazione = tipo;
}

int main(){
	struct treno A = {5, ELETTRICO};
	A.num_carrozze = 6;
	printf("Il treno ha %d carrozze e utilizza una trazione di tipo %s \n", A.num_carrozze, str_tipo_trazione[A.trazione]);

	aumenta_carrozze(&A);
	printf("Ora il treno ha %d carrozze.\n", A.num_carrozze);

	diminuisci_carrozze(&A);
	printf("Ora il treno ha %d carrozze.\n", A.num_carrozze);

	assegna_trazione(&A, GASOLIO);
	printf("Ora il treno utilizza una trazione di tipo %s.\n", str_tipo_trazione[A.trazione]);
} 