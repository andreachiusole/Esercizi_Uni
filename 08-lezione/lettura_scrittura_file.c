#include <stdio.h>

int main(){
	//puntatore a file
	FILE *file;

	/*fopen("NOME_FILE", tipologia_di_apertura);
	"w"  - scrittura (crea il file da zero, se esiste già lo crea comunque vuoto)
	"r"  - lettura (il file deve esistere)
	"a"  - append -> aggiungo contenuto al file proseguendo dal punto in cui  
	"r+" - leggo e scrivo solo se esiste il file
	"w+" - leggo e scrivo creando il file
	"a+" - leggo e aggiungo contenuto al file (viene creato se non esiste)
	*/

	file = fopen("data", "a");

	/*fprintf(PUNTATORE_AL_FILE, "STRINGA", VALORI_ALL'INTERNO_DELLA_STRINGA)
	*/
	fprintf(file, "%d\n", 12);

	//funzione per chiudere il file 
	fclose(file);





	// ora provo a leggere il file
	file = fopen("data", "r");
	//devo allocare un array di caratteri per la lettura
	char mystring [100];

	//controllo che esista il file
	if(file == NULL){
		perror ("Errore nell'apertura del file");
	}else{
		if(fgets(mystring, 100, file) != NULL){
			puts(mystring);
			fclose(file);
		}	
	}
	
}