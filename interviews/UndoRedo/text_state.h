#ifndef TEXT_STATE_H
#define TEXT_STATE_H

#include <stdlib.h>
#include <stdbool.h>

#define TS_SUCCESS 0
#define TS_ERROR 1
#define TS_GREATER_THAN_BUFFER 2
#define TS_FAILED_TO_ALLOCATE_NODE 4

/* Here's how it works:
   1 - a buffer is set
   2 - every new state is pushed to the next position, if there are other "next"
   states, they are removed, so if the user clicks undo then writes, he can't redo the
   previous "next" states
   3 - if the new state is bigger than the total allocated space, an error is
   returned
   4 - if there's not enough space for the new state, the oldest is removed 
   repeatedly until there's space.
   5 - if it fails to allocate the node structure, nothing is done and an error 
   is returned

   Size means total size, structure + text. So there's no chance of using a lot
   more memory when the text states are really small.
 */

/* Store the state */
typedef struct Text_Node Text_Node;

typedef struct {
	char *text;
	size_t size; //including '\0'
} State;

/* The states are stored in a linked-list */
typedef struct {
	Text_Node *first;
	Text_Node *current;
	Text_Node *last;
	size_t in_use;
	size_t buffer_size;
} Text_State;

//Set up the structure, buffer size
static inline void ts_init(Text_State *ts, size_t buffer_size)
{
	ts->first = NULL;
	ts->current = NULL;
	ts->last = NULL;
	ts->in_use = 0;
	ts->buffer_size = buffer_size;
}

//Free all
void ts_free(Text_State *ts);

//Free all, keep buffer size, set structure so it can be used again (e.g. when
//a new document is created)
void ts_clear(Text_State *ts);

//Push new state, delete all old "next" states
int ts_push_state(Text_State *ts, char *text);

//Set state to the next if there's one and return it, otherwise return NULL
const State *ts_redo(Text_State *ts);

//Set state to the previous if there's one and return it, otherwise return NULL
const State *ts_undo(Text_State *ts);

//Return if there are next states
bool ts_can_redo(Text_State *ts);

//Return if there are previous states
bool ts_can_undo(Text_State *ts);

//Set state to the newest, return it
const State *ts_redo_all(Text_State *ts);

//Set state to the oldest, return it
const State *ts_undo_all(Text_State *ts);

//Set buffer size. If it's smaller, the first and last state will be removed 
//repeatedly until the buffer size is smaller or equal to the new size
void ts_set_size(Text_State *ts, size_t new_size);

#endif
