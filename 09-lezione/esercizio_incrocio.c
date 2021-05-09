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

/*
È un po' diverso dalla geometria stradale, forse sarebbe meglio dire che 
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "str_inc_lib.h"


int main(){
	struct strada ss[12];
	struct incrocio ii[3];

	//inizializzazione strade

	str_initializer(&ss[0], "viale Vittoria", STRADA, &ss[1]);
	str_initializer(&ss[1], "via Venezia", INCROCIO, &ii[0]);
	str_initializer(&ss[2], "via Gorizia", INCROCIO, &ii[1]);
	str_initializer(&ss[3], "via della Cervara", STRADA, &ss[4]);
	str_initializer(&ss[4], "via Rodolfo Belenzani", INCROCIO, &ii[1]);
	str_initializer(&ss[5], "via Camillo Cavour", INCROCIO, &ii[2]);
	str_initializer(&ss[6], "via S. Pacifico", INCROCIO, &ii[2]);
	str_initializer(&ss[7], "via Guido Rey", STRADA, &ss[8]);
	str_initializer(&ss[8], "viale Giuseppe Garibaldi", INCROCIO, &ii[2]);
	str_initializer(&ss[9], "via Carducci", INCROCIO, &ii[0]);
	str_initializer(&ss[10], "via Nuova", CHIUSA, NULL); // Prendendo questa strada si arriva alla fine
	str_initializer(&ss[11], "via Cartagine", STRADA, &ss[1]);

	//inizializzazione incroci

	int_initializer(&ii[0], &ss[2], &ss[3], &ss[5], NULL);
	int_initializer(&ii[1], &ss[6], &ss[7], &ss[11], NULL);
	int_initializer(&ii[2], &ss[9], &ss[10], NULL, NULL);
	
	printf("Ti trovi in viale Vittoria e devi raggiungere casa tua, in via Nuova.\n");
	path(ss);
	
	// //crea una nuova strada usando la memoria dinamica
	// struct strada *ss = crea_strada("24 Maggio");
	// free(ss);

}