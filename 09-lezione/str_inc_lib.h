#ifndef LIBRERIA_STRADA_INCROCIO_H
#define LIBRERIA_STRADA_INCROCIO_H

#define NAME_DIM 30

union tipo{
	struct strada *s;
	struct incrocio *i;
};
enum tipo_el{
	STRADA, INCROCIO, CHIUSA
};
// char *nome_tipo_el[] = {"Strada", "Incrocio", "Chiusa"};

struct strada{
	//NOME STRADA ATTUALE 
	char name[NAME_DIM];

	//ELEMENTO A CUI SI PUÒ ARRIVARE
	enum tipo_el tipo_next;
	union tipo next;
};

struct incrocio{
	struct strada *uscita[4];
};

struct strada* crea_strada(char *nome);

void str_initializer(struct strada *str, char *street_name, enum tipo_el elem_type, void *type);
void int_initializer(struct incrocio *intersec, struct strada *first_street, struct strada *second_street, struct strada *third_street, struct strada *forth_street));
void show_intersection(struct incrocio *intersec);
int choose_path(struct incrocio *intersec);
void path(struct strada *street);

#endif
