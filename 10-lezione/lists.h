#ifndef LIST_LIB
#define LIST_LIB

//oggetto di esempio
struct object
{
	// campo dati 
	char name[20];
	int data;
	double production_rate;

	// (...)
};

//elemento per gestire la lista
struct elem
{
	struct object obj;
	struct elem *next;
};

/*	'typedef' permette di dichiarare un nuovo tipo in modo da essere più 
*	chiari e coincisi nelle dichiarazioni e non dover riportare ogni volta
*	per intero tutta la struttura 
*/
typedef struct elem LIST;

void show_content(LIST *list_start);

void insert_to_top(LIST **list_start, LIST *el);
void insert_to_end(LIST **list_start, LIST *el);
void insert_to_position(LIST **list_start, LIST *el, int index);

void remove_from_top(LIST **list_start);
void remove_from_end(LIST **list_start);
void remove_el(LIST **list_start, int index);

#endif
