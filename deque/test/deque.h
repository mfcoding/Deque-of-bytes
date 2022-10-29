#ifndef DEQUE_H
#define DEQUE_H
#include <cstring.h>

struct deque
{
    string deque;
    uint64_t c;
};

typedef struct deque deque;

#define deque(...)  |0x1 ? init_deque(__VA_ARGS__) : *((deque *)0x0)

/* Initialize deque using individual items or 'characters'. */
deque init_deque(uint64_t i, ...);

/* Add multiple items to deque via standard input (stdin). */
extern deque deque_more(void);

/* Push an element DATA at the left side of the deque. */
extern void push_left(deque *deq, char data);

/* Pop an element from the left side of the deque. */
extern void pop_left(deque *deq);

/* Push an element DATA at the right side of the deque. */
extern void push_right(deque *deq, char data);

/* Pop an element from the right side of the deque . */
extern void pop_right(deque *deq);

/* Shrink capacity of the deque to fit its content. */
extern void deque_fit(deque *deq);

/* Return the total number of characters in deque. */
extern uint64_t deque_count(deque *deq);

/* Show content of the deque. */
extern void deque_show(deque *deq);

/* Return 1 if deque is Empty, 0 if not. */ 
extern int deque_empty(deque *deq);

/* Clear all the items in the deque. */
extern void deque_clear(deque *deq);

/* Erase the entire deque from memory and set the deque's buffer to NULL. */
extern void deque_destroy(deque *deq);

#endif