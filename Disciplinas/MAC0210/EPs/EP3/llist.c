#include "llist.h"
#include <stdlib.h>

struct s_cell{
    struct s_cell* next;
    void* el;
}s_cell;

struct s_llist{
    struct s_cell* first;
    void (*destroy_el)(void*);
}s_llist;

Llist make_list(void (*destroy_el)(void*)){
    Llist l = malloc(sizeof(s_llist));
    l->first = NULL;
    l->destroy_el = destroy_el;
    return l;
}

void destroy_Llist(Llist l){
    struct s_cell* curr = l->first;

    while (curr){
        void* el = curr->el;
        struct s_cell* last = curr;
        curr = curr->next;
        l->destroy_el(el);
        free(last);
    }
    free(l);
}

void append(Llist l, void* el){
    struct s_cell* new_l = malloc(sizeof(s_cell));
    new_l->next = l->first;
    new_l->el = el;
    l->first = new_l;
}

void* first(Llist l){
    if(!(l && l->first)) return NULL;
    return l->first->el;
}

void* pop(Llist l){
    if(!(l && l->first)) return NULL;
    struct s_cell* second = l->first->next;
    void* el = l->first->el;
    free(l->first);
    l->first = second;
    return el;
}

unsigned int count(Llist l){
    if(!l) return 0;
    unsigned int c = 0;
    struct s_cell* curr = l->first;
    while(curr){
        c++;
        curr = curr->next;
    }
    return c;
}

// Llist remove(Llist l, void* el, int (*eq)(const void*, const void*)){
//     Llist curr = l;
//     Llist last = NULL;

//     while (curr){
//         if(eq(curr->el, el)){
//             destroy_el(el);
//             free(l);
//             break;
//         }
//         last = curr;
//         curr = curr->next;
//     }
// }