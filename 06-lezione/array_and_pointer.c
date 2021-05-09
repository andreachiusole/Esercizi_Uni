/*array e puntatori*/
#include <stdio.h>

int ar[5]; 
int A = 5;
int *p;
/*
esempio di deferenziazione  eseguita da
una funzione esterna al main()
*/
void change2three(int *B){
	//Cambio il valore dell'oggetto puntato in tre.
	//Le parentesi non sono necessarie, ma aiutano a separare in casi più complessi
	(*B) = 3;
}

void fun1(int (*c)[10]){

	(*c)[0] = 4;

}

void fun2(int (*c)){
//void fun2(int c[]){
	
	c[3] = 7;
	//Equivalente a 
	//*(c+3) = 7;
}

void fun3(int (*c)[5]){
	(*c)[0] = 4;
}

void main(){
	p = &A; //il valore di p è l'indirizzo di A 

	//Deferenziazione
	/*
	Uso del puntatore per andare a modificare
	il contenuto dell'oggetto puntato 
	*/
	(*p)=7;

	int c = 4;
	change2three(&c);

	p = &ar[0];
	(*p) = 3;
	for (int i=0; i<10; i++){
		printf("%d ", ar[i]);
	}
	printf("\n");
	int *point;
	int array[10];

	point = array; //in C gli array sono considerati dei puntatori

	fun2(array);



	/*	questo crea un warning di incompatibilità di tipo perché 
		array ha dimensione 10 mentre c nella funzione fun3 ha 
		dimensione 3
	*/
	//fun3(array); 

	/*
	array multidimensionali sono puntatori di puntatori o puntatori 
	a più livelli di deferenziazione
	*/
	
	int ar2d[5][4];

	for(int i=0; i<5; i++){
		for (int j=0; j<4; j++){
			ar2d[i][j] = j + i*4 + 1;
		}
	}

	for(int i=0; i<5; i++){
		for (int j=0; j<4; j++){
			printf("%d, ", ar2d[i][j]);
		}
		printf("\n");
	}

	/* 	allocazione di un puntatore ad array di quattro elementi
		che punta alla riga della matrice 	*/

	int (*ar4i)[4]; //dichiaro questa variabile come indirizzo di 
	
	for(ar4i = ar2d; ar4i < &(ar2d[5]); ar4i++){
	//for(ar4i = &ar2d[0]; ar4i <= &(ar2d[4]); ar4i++){
		(*ar4i)[2] = 0;
	}

	for(int i=0; i<5; i++){
		for (int j=0; j<4; j++){
			printf("%d, ", ar2d[i][j]);
		}
		printf("\n");
	}
}