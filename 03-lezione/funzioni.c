
#include <stdio.h>

int /* ritorno di funzione tutti i tipi che conosciamo */
fun_a /* Nome di funzione, deve cominciare con un carattere A-Z a-z */
(
    int a,
    /* parametri di funzione divisi dalla virgola */
    int b
)
{   /* Corpo della funzione */
    return 0;  /* ritorno di funzione */
}

/* int fun_a (int a,int b){ return 0;} La funzione più essere dichiarata anche su una singola riga*/ 

int somma(int a, int b){
    return a + b;
}

double somma_double(double a, double b){
    return a + b;
}

void stampa (double a){
	printf("%f\n", a);
}

int main(){

	printf("2.4 + 4.3 = %f\n", somma_double(2.4,4.3));
	printf("2 + 4 = %d\n", somma(2,4));
	printf("int(2.4) + int(4.7) = %d\n", somma(2.4,4.7));
	stampa(3.4);
	printf("\n");

	int a = 3, b = 4;

	if(b >= a){
		/* CONDIZIONE VERA */
		printf("b >= a ? SI\n");
	
	}

	if(b == a){
		/* CONDIZIONE VERA */
		printf("b == a ? SI\n");
	
	} else {
		/* CONDIZIONE FALSA */
		printf("b == a ? NO\n");
		
	}
}

/*
[Andrea@andrea-fedora 03-lezione]$ gcc funzioni.c -o funzioni -Wall
[Andrea@andrea-fedora 03-lezione]$ ./funzioni
2.4 + 4.3 = 6.700000
2 + 4 = 6
2 + 4 = 6
3.400000
*/