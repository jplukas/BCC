#ifndef LLIST_H
#define LLIST_H

typedef struct s_llist* Llist;

Llist make_list(void (*destroy_el)(void*));

void destroy_Llist(Llist l);

void append(Llist l, void* el);

void* first(Llist l);

void* pop(Llist l);

unsigned int count(Llist l);

#endif /* LLIST_H */