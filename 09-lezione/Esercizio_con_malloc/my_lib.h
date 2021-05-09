#ifndef MY_LIB
#define MY_LIB

#define DIM_NAME 30

union type
{
	struct link *s;
	struct node *i;
};

enum el_type
{
	STREET, INTERSEC, HOME, CLOSED_ROAD
};

struct link
{
	char name[DIM_NAME];

	enum el_type next_type;
	union type next_el_address;
};

struct node
{
	struct link *exit;
	struct node *next_exit;
};

struct link* street_maker(char *name, enum el_type t, void *n);
struct node* intersec_maker(int branches, ...);
int show_intersection(struct node *intersec);
struct link* choose_path();

#endif
