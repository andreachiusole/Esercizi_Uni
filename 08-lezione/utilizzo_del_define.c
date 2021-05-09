#include <stdio.h>

//sostituisce ogni volta che incontra NUM all'interno del file con il valore 10
#define NUM 10 

//sostituisce la funzione FUN(X) con quello che è stato definito in seguito
#define FUN(X) X*X

//un'applicazione interessante è quella di andare a sostituire formulazioni lunghe e ripetitive all'interno del codice
#define FOR(X, Y) for(int i = 0; i < X; i++){Y}

//altro esempio
#define ESEGUI(F,A,B) A F B

//define multiriga. Nella sostituzione 
#define TEXT \
printf("audashuda");\
printf("dadhashda");

/*
I define vengono eseguiti in ordine, e nella definizione dello stesso placeholder l'ultimo ha la priorità.
Se in questo punto del codice scrivessi
#define NUM 14
il compilatore alzerebbe un warning dicendo che ho già definito il valore di num, ma mi permette comunque di creare il file oggetto da poi eseguire.
*/


int main(){
	int vett[NUM];
	int r = FUN(4);

	FOR(10, r+=i; r--; printf("%d \n", i);)

	printf("\n");
	int num = ESEGUI(+, 12, 5);
	printf("%d \n", num);
}

/*
Comando per far eseguire solo la parte di preprocessore:
gcc -E utilizzo_del_define.c -o output_preprocessore.i
*/