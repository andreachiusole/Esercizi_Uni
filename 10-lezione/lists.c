/* Lezione 11/05/2021 */
#include <stdlib.h>
#include <stdio.h>
#include "lists.h"	/*struct incluse nel header file*/

#define LISTDEF(X, num); \
		LIST *el = NULL;\
		for (int i = 0; i < (num); i++)\
		{\
			el = malloc(sizeof(LIST));\
			el->obj.data = i;\
			el->next = NULL;\
			/*insert_to_top(X, el);*/\
			insert_to_end((X), el);\
		}

//LIST l; 
/* È identico a: */
//struct elem l; 

void show_content(LIST *list_start)
{
	printf("[");
	for (LIST *aux = list_start; aux != NULL; aux = aux->next)
	{
		printf("%d", aux->obj.data);
		if (aux->next != NULL)
		{
			printf(",");
		}
	}
	printf("]\n");
}

void freelist(LIST *list_start)
{
	while (list_start != NULL)
	{
		remove_from_top(&list_start);
	}
}

/*	Bisogna utilizzare un doppio puntatore perché devo andare a modificare l'indirizzo 
*	del primo puntatore della lista in modo da modificare ciò a cui sta puntando.
*	Se venisse passato un puntatore singolo non sarebbe possibile modificare 
*	il contenuto del puntatore nel main che continuerebbe a puntare al vecchio 
*	indirizzo.
*/
void insert_to_top(LIST **list_start, LIST *el)
{
	LIST *aux = (*list_start);
	(*list_start) = el;
	el->next = aux;

	//oppure senza usare il puntatore ausiliario
	/*
	el->next = (*list_start);
	(*list_start) = el;
	*/
}

void insert_to_end(LIST **list_start, LIST *el)
{
	if ((*list_start) == NULL)
	{
		(*list_start) = el;
		return;
	}
	LIST *aux = (*list_start);

	for (; aux->next != NULL; aux = aux->next)
		;
	aux->next = el;
	el->next = NULL;
}


void insert_to_position(LIST **list_start, LIST *el, int index)
{
	LIST *aux = (*list_start);
	
	if (index < 0)
	{
		printf("Index value must be greater than or equal to 0.\n");
		return;
	}
	else if (index == 0 || aux == NULL)
	{
		/*Si potrebbe chiamare direttamente la funzione che ha questo scopo*/
		//insert_to_top(list_start, el);
		(*list_start) = el;
		el->next = aux;
		return;
	}
	else
	{
		// il for deve solo scorrere la lista per questo non ha corpo
		for (int i = 1; i == index && aux->next != NULL; i++, aux = aux->next)
			; 	// è meglio mettere ';' su una nuova riga per far capire l'intenzione di non avere niente all'interno 
						
		el->next = aux->next;
		aux->next = el;
	}
}

void remove_from_top(LIST **list_start)
{
	if ((*list_start) == NULL)
	{
		printf("The list is already empty\n");
		return;	
	}
	else if ((*list_start)->next == NULL)
	{
		free((*list_start));
		(*list_start) = NULL;
		return;
	}

	LIST *aux = (*list_start);
	(*list_start) = aux->next;
	free(aux);
}

void remove_from_end(LIST **list_start)
{
	if ((*list_start) == NULL)
	{
		printf("The list is already empty\n");
		return;	
	}
	else if ((*list_start)->next == NULL)
	{
		free((*list_start));
		(*list_start) = NULL;
		return;
	}


	LIST *aux = (*list_start);
	//get to the second last element of the list
	for (; aux->next->next != NULL; aux = aux->next)
		;
	free(aux->next);
	aux->next = NULL;
}

void remove_el(LIST **list_start, int index)
{
	if ((*list_start) == NULL)
	{
		printf("The list is already empty\n");
		return;
	}
	int i = 0;
	LIST *aux = (*list_start);
	LIST *temp = NULL;	

	for (i; i < index; i++)
	{
		if (aux->next == NULL)
		{
		printf("This list has %d elements. The last element has been removed \n", (i+1));
		remove_from_end(list_start);
		return;
		}
		aux = aux->next;
	}
	
	if (aux->next == NULL)
	{
		remove_from_end(list_start);
	}
	else
	{
		temp = aux;
		aux->next = aux->next->next;
		free(temp->next);
	}
}

int main()
{
	LIST *init = NULL;
	#if 0
	LIST *el = NULL;
	el = malloc(sizeof(LIST));
	el->obj.data = 7;
	el->next = NULL;
	insert_to_top(&init, el);

	//ora l'informazione di el è stato registrato in init, quindi
	//posso usare lo stesso elemento per allocare nuova memoria
	el = malloc(sizeof(LIST));
	el->obj.data = 12;
	el->next = NULL;
	insert_to_top(&init, el);

	el = malloc(sizeof(LIST));
	el->obj.data = 15;
	el->next = NULL;
	insert_to_top(&init, el);

	#else
	LISTDEF(&init, 1);

	#endif

	show_content(init);
	remove_from_top(&init);

	#if 0
	LIST *el = malloc(sizeof(LIST));
	el->obj.data = 13;
	el->next = NULL;
	insert_to_position(&init, el, 2);
	remove_from_end(&init);
	#endif
	show_content(init);

	freelist(init);
}