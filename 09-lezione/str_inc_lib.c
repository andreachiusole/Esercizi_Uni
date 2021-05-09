/* Scrivere una libreria che gestisce la configurazione di incroci stradali
 * L'incrocio è caratterizzado da connettere 4 strade.
 * Ogni strada ha un nome ed è connessa a un elemento che può essere strada o un incrocio.
 * Scrivere un set di istruzioni che funzioni:
 * 1. Assegnare una strada ad un incrocio in una certa posizione.
 * 2. Assegnare a una strada cosa è connessa.
 * 3. Fare una funzione che partendo da una strada scelta percorre la strada mostrado il
 * nome della via percorsa fino ad incontrare un incrocio e a quel punto chiede all'utente 
 * di scegliere dove andare tra le strade disponibili nell'incrocio, termina quando la strada 
 * non è connessa a niente.
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "str_inc_lib.h"

char *nome_tipo_el[] = {"Strada", "Incrocio", "Chiusa"};

//funzioni

struct strada* crea_strada(char *nome){
	struct strada *street = malloc(sizeof(struct strada));
	strcpy(street->name, nome);
	street->tipo_next = CHIUSA;
	street->next.s = 0;
	return street;
}

void str_initializer(struct strada *str, char *street_name, enum tipo_el elem_type, void *type){

	strcpy(str->name, street_name);
	str->tipo_next = elem_type;
	
	if(elem_type == STRADA){
		str->next.s = type;
	} else if(elem_type == INCROCIO){
		str->next.i = type;
	} else {
		str->next.i = NULL;
	}
}

void int_initializer(struct incrocio *intersec, struct strada *first_street, struct strada *second_street, struct strada *third_street, struct strada *forth_street){
	intersec->uscita[0] = first_street;
	intersec->uscita[1] = second_street;
	intersec->uscita[2] = third_street;
	intersec->uscita[3] = fourth_street;
}

int choose_path(struct incrocio *intersec){
	int a = -1;
	
	fflush(stdin);
	int c = getchar();
	switch(c){
		case '1':
			a = 0;
			break;
		case '2':
			a = 1;
			break;
		case '3':
			a = 2;
			break;
		case '4':
			a = 3;
			break;
		default:
			a = -1;
	}

	if(intersec->uscita[a] == NULL) {
		a = -1;
	}
	
	return a;
}

void show_intersection(struct incrocio *intersec){
	printf("Sei arrivato ad un incrocio.\nQueste sono le strade che puoi prendere:\n");
	for(int i=0; i<4; i++){
		if(intersec->uscita[i] != NULL) printf("\t%d- %s\n", (i+1), intersec->uscita[i]->name);
	}

	bool x = 0;
	int scelta = -1;
	printf("Quale scegli?\n>>>");
	while(x == false){

		scelta = choose_path(intersec);
		if(scelta != -1){	
			x = true;
			printf("Hai scelto %s.\n\n", intersec->uscita[scelta]->name);
			//break;
			path(intersec->uscita[scelta]);
		} else {
			printf("Scegli una delle opzioni indicate scrivendo il numero.\n");
		}
	}
	//path(intersec->uscita[scelta]);

}

void path(struct strada *street){

	printf("Stai percorrendo %s.\n\t...\n", street->name);

	if(street->tipo_next == STRADA){
		path(street->next.s);
	} else if(street->tipo_next == INCROCIO) {
		show_intersection(street->next.i);
	} else {
		printf("Perfetto! Sei giunto a destinazione.\n");
	}
}

/*
int main(){
	struct strada ss[4];
	struct incrocio ii[1];


	strcpy(ss[0].name, "via Gorizia");
	ss[0].tipo_next = INCROCIO;
	ss[0].next.i = &ii[0];

	strcpy(ss[1].name, "via della Cervara");
	ss[1].tipo_next = STRADA;
	ss[1].next.s = &ss[0];

	strcpy(ss[2].name, "via Camillo Cavour");
	ss[2].tipo_next = INCROCIO;
	ss[2].next.i = &ii[0];

	strcpy(ss[3].name, "viale Vittoria");
	ss[3].tipo_next = CHIUSA;
	ss[3].next.s = NULL;

	int_initializer(&ii[0], &ss[3], &ss[1], &ss[2], NULL);

	str_initializer(&ss[0], "via Gorizia", INCROCIO, &ii[0]);
	str_initializer(&ss[1], "via della Cervara", STRADA, &ss[1]);
	str_initializer(&ss[2], "viale Vittoria", CHIUSA, NULL);
	for(int i=0; i<3; i++){
		printf("%s\t%s\n", ss[i].name, nome_tipo_el[ss[i].tipo_next]);
	}
	//show_intersection(&ii[0]);

	//path(ss);

}*/