#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ADTs - Linked List
typedef char listType;

typedef struct LNode {
	listType data;
	struct LNode* next;
} LNode;

typedef struct linkedList {
    LNode* start;
    LNode* end;
    int size;
} linkedList;

linkedList* init_list_linked(void);
void print_list_linked(linkedList* l);
void free_list_linked(linkedList* l);
void addToEnd_list_linked(linkedList* l, listType data) ;
// ADTs - Linked List


// Neil
void on_error(const char* s);
void* ncalloc(int n, size_t size);

void** n2dcalloc(int h, int w, size_t size);
void** n2drecalloc(void** p, int oh, int nh, int ow, int nw, size_t szelem);
void n2dfree(void**p, int h);

void* nrecalloc(void* p, int oldsz, int newsz);
void* nremalloc(void* p, int bytes);

void* nfopen(char* fname, char* mode);
