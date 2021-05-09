/*
 * Scrivere una funzione che prende in ingresso un intero e stampa a video
 * tutti i numeri in sequenza:
 * numero 5
 * 1,2,3,4,5
 *  
 * Successivamente chiamare la funzione con 10 e 25
 */
 
#include <stdio.h>


void numeri(int n){ //questa funziona fa ....

	for(int i = 1; i <= n; i++){
		printf("\t %d, ", i);
	}
	printf("\n");
}


int main(){

	numeri(5);	
	numeri(10);
	numeri(25);
	
 }