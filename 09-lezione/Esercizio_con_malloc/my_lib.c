#include <stdarg.h>		// va_list, va_start, va_arg, va_end
#include <stdio.h>		// printf, fgets
#include <stdlib.h>		// malloc, free
#include <string.h>		// strcpy
#include "my_lib.h"


char *name_element[] = {"Street", "Intersection", "Your Home", "Closed Road"};

struct link* street_maker(char *name, enum el_type t, void *n)
{
	/* IMPORTANT
	For this function you have to start from the last street or from a closed one
	because of how it has been defined.
	*/

	//allocate memory for a street and define it
	struct link *street = malloc(sizeof(struct link));
	
	strcpy(street->name, name);
	street->next_type = t;
	
	switch(t)
	{
		case STREET:
			street->next_el_address.s = n;

		case INTERSEC:
			street->next_el_address.i = n;
		
		default: //home and closed road are the same
			street->next_el_address.s = NULL;	
	}
		
	return street;
}

struct node* intersec_maker(int branches, ...)
{
	/*check for no-exit intersection*/
	if (branches < 2)
	{
		fprintf(stderr, "Intersections need at least two arguments.\nExiting...\n");
		exit(EXIT_FAILURE);
	}

	/*malloc of a intersec and linking of the exits*/
	struct node *intersec = malloc(sizeof(struct node));
	struct node *temp = intersec;
	

	va_list arguments;
	va_start(arguments, branches);
	
	for(int i = 0; i < (branches-1); i++)
	{
		temp->exit = va_arg(arguments, struct link*);
		temp->next_exit = malloc(sizeof(struct node));
		temp = temp->next_exit;
	}

	// last item of the intersection is set to NULL
	temp->exit = va_arg(arguments, struct link*);
	temp->next_exit = NULL;
	
	va_end(arguments);

	return intersec;
}

int show_intersection(struct node *intersec)
{
	int i = 1;	
	struct node *temp = intersec;

	printf("Sei arrivato ad un incrocio.\nQueste sono le strade che puoi prendere:\n");
	
	do{
		printf("\t%d- %s\n", i, temp->exit->name);
		i++;
		temp = temp->next_exit;		
	} 
	while(temp != NULL);
	/*return the number of options of the intersection*/
	return i-1;
}

struct link* choose_path(struct node *intersec)
{
	struct node *temp = intersec;
	int max = show_intersection(intersec);
	//printf("%d\n", max);

	char s[4];

	while(1)
	{
		printf("Quale scegli? [1->%d]\n>>>", max);
		fgets(s, 4, stdin);
		int c = atoi(s);
		
		/*check if the input is in range [1->c] then return the exit address*/
		if (c <= max && c > 0)
		{
			for(int i = 1; i < c; i++)
			{
				temp = temp->next_exit;
			}

			return temp->exit;
		}
		
		printf("Scegli una delle opzioni scrivendo il numero indicato.\n");
	}
}

int main()
{
	/*grid definition*/
	struct link *prova_str[3];
	struct node *prova_int = malloc(sizeof(struct node));

	prova_str[0] = street_maker("Finish", HOME, NULL);
	prova_str[1] = street_maker("Start", STREET, prova_str[2]);
	prova_str[2] = street_maker("Middle", INTERSEC, prova_int);

	prova_int = intersec_maker(2, prova_str[0], prova_str[1]);

	/*start of the route*/
	struct link *here_I_am = prova_str[1];

	printf("%s\n", here_I_am->next_el_address.s->name);
	/*
	while(here_I_am->next_type != HOME)
	{
		printf("Stai percorrendo %s\n\t...\n", here_I_am->name);
		printf("%s\n", name_element[here_I_am->next_type]);

		if (here_I_am->next_type == STREET)
		{
			printf("Controllo effettuato");
			//here_I_am = here_I_am->next_el_address.s;
		}
		
		else if (here_I_am->next_type == INTERSEC) 
		{
			printf("Controllo effettuato");
			here_I_am = choose_path(here_I_am->next_el_address.i);
		}
		else if (here_I_am->next_type != CLOSED_ROAD)
		{
			printf("Hai raggiunto un vicolo cieco.\nRicomincia da capo.\n");
			here_I_am = prova_str[1];
		}
		
		//printf("selezione:%s\n", choose_path(prova_int)->name);
	}
	*/
	free(prova_str[0]);
	free(prova_str[1]);
	free(prova_str[2]);
	free(prova_int);
}