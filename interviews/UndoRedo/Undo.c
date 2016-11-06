#include "text_state.h"
#include <string.h>


struct Text_Node {
	State state;
	Text_Node *next;
	Text_Node *previous;
};


/////////
//  Internal functions
///////
static inline size_t available_space(Text_State *ts)
{
	return ts->buffer_size - ts->in_use;
}

static inline size_t space_required(Text_Node *node)
{
        //printf("size = %d\n", sizeof(*node));
	return sizeof(Text_Node) + node->state.size;
}

//Return an allocated copy of node
static inline Text_Node *make_node_like(Text_Node *node)
{
	Text_Node *temp = malloc(sizeof(Text_Node));
	if(temp != NULL)
		*temp = *node;

	return temp;
}

static inline bool enough_space(Text_State *ts, Text_Node *node)
{
	return available_space(ts) >= space_required(node);
}

static inline bool buffer_is_too_small(Text_State *ts, Text_Node *node)
{
	return space_required(node) > ts->buffer_size;
}

//There must be a first node for it to work
static void remove_first_node(Text_State *ts)
{
	Text_Node *node = ts->first;

	if(node == ts->current)
		ts->current = node->next;

	if(node->next != NULL)
		node->next->previous = NULL;

	//Last node
	else
		ts->last = NULL;

	ts->first = node->next;
	ts->in_use -= space_required(node);

	free(node->state.text);
	free(node);
}

static void remove_last_node(Text_State *ts)
{
	Text_Node *node = ts->last;

	if(node == ts->current)
		ts->current = node->previous;

	if(node->previous != NULL)
		node->previous->next = NULL;

	//First node
	else
		ts->first = NULL;

	ts->last = node->previous;
	ts->in_use -= space_required(node);

	free(node->state.text);
	free(node);
}

//Remove the current node only if there's no other option
static void remove_one(Text_State *ts, size_t *counter)
{
	++*counter;

	//The undo list is probably longer
	if(*counter % 3 != 0){
		if(ts->first != ts->current)
			remove_first_node(ts);

		else
			remove_last_node(ts);
	}

	else {
		if(ts->last != ts->current)
			remove_last_node(ts);

		else
			remove_first_node(ts);  
	}
}

static void remove_all_nodes_after(Text_State *ts, Text_Node *node)
{
	Text_Node *next = node->next;
	node->next = NULL;

	while((node = next) != NULL){
		next = node->next;

		ts->in_use -= space_required(node);
		free(node->state.text);
		free(node);
	}
}

static void push_new_node(Text_State *ts, Text_Node *node)
{
	//Handle first node
	if(ts->current == NULL){
		node->previous = node->next = NULL;
		ts->first = ts->current = ts->last = node;
		ts->in_use += space_required(node);
		return;
	}

	node->previous = ts->current;
	node->next = NULL;
	ts->current->next = node;
	ts->current = ts->last = node;
	ts->in_use += space_required(node);
}


/////////
//  Public functions
///////
void ts_free(Text_State *ts)
{
	Text_Node *next;
	Text_Node *current;

	for(current = ts->first; current != NULL; current = next){
		next = current->next;
		free(current->state.text);
		free(current);
	}
}

//Keep the buffer size
void ts_clear(Text_State *ts)
{
	ts_free(ts);
	ts->first = NULL;
	ts->current = NULL;
	ts->last = NULL;
	ts->in_use = 0;
}
char* string(char *text, int strlenght)
{
	char *ptr = malloc(strlenght);
	if(!ptr)
		exit(0);
	strcpy(ptr, text);
	return ptr;
}
int ts_push_state(Text_State *ts, char *text)
{
	Text_Node temp;
	int strlenght = strlen(text) + 1;
	
	temp.state.text = string(text, strlenght);
	temp.state.size = strlenght;

	//Handle separately
	if(!enough_space(ts, &temp)){
		if(buffer_is_too_small(ts, &temp))
			return TS_ERROR | TS_GREATER_THAN_BUFFER;

		//After this point, it can't fail
		Text_Node *new_node = make_node_like(&temp);
		if(new_node == NULL)
			return TS_ERROR | TS_FAILED_TO_ALLOCATE_NODE;

		//First remove all nodes that will be removed anyway
		remove_all_nodes_after(ts, ts->current);

		//Remove the oldest nodes if it's necessary
		while(!enough_space(ts, &temp))
			remove_first_node(ts);

		push_new_node(ts, new_node);
		return TS_SUCCESS;
	}

	Text_Node *new_node = make_node_like(&temp);
	if(new_node == NULL)
		return TS_ERROR | TS_FAILED_TO_ALLOCATE_NODE;

	push_new_node(ts, new_node);
	return TS_SUCCESS;
}

const State *ts_redo(Text_State *ts)
{
	if(ts->current != NULL && ts->current->next != NULL){
		ts->current = ts->current->next;
		return &ts->current->state;
	}

	return NULL;
}

const State *ts_undo(Text_State *ts)
{
	if(ts->current != NULL && ts->current->previous != NULL){
		ts->current = ts->current->previous;
		return &ts->current->state;
	}

	return NULL;
}

bool ts_can_redo(Text_State *ts)
{
	return ts->current != NULL && ts->current->next != NULL;
}

bool ts_can_undo(Text_State *ts)
{
	return ts->current != NULL && ts->current->previous != NULL;
}

const State *ts_redo_all(Text_State *ts)
{
	if(ts->current == NULL)
		return NULL;

	ts->current = ts->last;
	return &ts->current->state;
}

const State *ts_undo_all(Text_State *ts)
{
	if(ts->current == NULL)
		return NULL;

	ts->current = ts->first;
	return &ts->current->state;
}

void ts_set_size(Text_State *ts, size_t new_size)
{
	if(new_size >= ts->buffer_size){
		ts->buffer_size = new_size;
		return;
	}

	//Prefer removing the first since it will probably be further from the current
	size_t counter = 0;  
	do {
		remove_one(ts, &counter);
	} while(ts->buffer_size > new_size);

	ts->buffer_size = new_size;
}


