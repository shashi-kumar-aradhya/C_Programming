#ifndef L_LIST_H
#define L_LIST_H
//Linked list declaration
typedef struct ll {
	struct ll * next;
}LL;

#define NULL ((void *)0)
void add_tail(LL **list_ptr, LL *ptr);
void add_head(LL **list_ptr, LL *ptr); 
void del(LL **list_ptr, LL *ptr);
void del_head(LL **list_ptr);
void del_tail(LL **list_ptr);

#endif
