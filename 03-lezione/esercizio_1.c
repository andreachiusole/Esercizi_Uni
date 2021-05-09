/*
 * Scrivere un programma inizializza due variabili
 * intere a 10 e 5 ne esegue 
 * la somma e la stampa a video
 * la sottrazione e la stampa a video
 * la divisione e la stampa a video
 */

#include <stdio.h> 

int a = 10, b = 5;

int pippo;



int somma( int x, int y){
	return x + y;
}

int sottrazione( int x, int y){
	return x - y;
}

double divisione( double x, double y){

	//questa funzione prende solo multipli
	return x / y;
}

void stampa(double p){
	printf("%.2f\n", p);
}

int main(){

	pippo = somma(a, b);
	printf("10 + 5 = %d", pippo);
	// stampa(somma(a, b));
	// printf(pippo);

	printf("10 - 5 = ");
	stampa(sottrazione(a, b));

	printf("5 - 10 = ");
	stampa(sottrazione(b, a));

	printf("10 / 5 = ");
	stampa(divisione(a, b));

	printf("5 / 10 = ");
	stampa(divisione(b, a));

}