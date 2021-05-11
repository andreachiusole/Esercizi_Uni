/* Lezione 11/05/2021 */
#include <stdlib.h>
#include <stdio.h>

//example object
struct object
{
	char name[20];
	int data;
	double production_rate;
	//....
};

//elemento per gestire la lista
struct elem
{
	struct object obj;
	struct elem *next;
};

//permette di dichiarare un nuovo tipo in modo da 
typedef struct elem List;

//List l; 
//same as struct elem l; 

void show_content(List *base)
{
	printf("[");
	for(List *aux = base; aux != NULL; aux = aux->next)
	{
		printf(" %d", aux->obj.data);
		if(aux->next != NULL)
		{
			printf(",");
		}
	}
	printf("]\n");

}

// doppio puntatore perché devo andare a modificare l'indirizzo 
// del primo puntatore della lista in modo da farlo puntare
void top_insertion(List **base, List *el)
{
	List *aux = (*base);
	(*base) = el;
	el->next = aux;

	//oppure senza usare il puntatore ausiliario
	/*
	el->next = (*base);
	(*base) = el;
	*/
}

void insert_to_position(List **base, List *el, int index)
{
	List *aux = (*base);

	if(index <= 0 || aux == NULL)
	{
		(*base) = el;
		el->next = aux;
	}
	else
	{
		// il for deve solo scorrere la lista
		for(int i = 1; i < index || aux->next != NULL; i++, aux = aux->next)
		el->next = aux->next;
		aux->next = el;
	}
}

//rimuovi elemento
//inserisci in fondo


int main()
{
	List *base = NULL;
	List *el = malloc(sizeof(List));
	el->obj.data = 7;
	el->next = NULL;
	top_insertion(&base, el);

	//ora l'informazione di el è stato registrato in base, quindi
	//posso usare lo stesso elemento per allocare nuova memoria
	el = malloc(sizeof(List));
	el->obj.data = 12;
	el->next = NULL;
	top_insertion(&base, el);

	show_content(base);
}