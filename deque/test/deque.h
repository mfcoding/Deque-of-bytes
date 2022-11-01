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

/* 
    Lightweight versions of the declared functions. 
*/

#define _push_left_(deq, data)                                                           \
    if(deq.c)                                                                            \
    {                                                                                    \
        _begin_(deq.deque)--;                                                            \
        _len_(deq.deque)++;                                                              \
        *_begin_(deq.deque) = data;                                                      \
        deq.c--;                                                                         \
    }                                                                                    \
    else                                                                                 \
    {                                                                                    \
        reserve(&deq.deque, _len_(deq.deque) + MAX);                                     \
        memcpy(_begin_(deq.deque) + MAX, _begin_(deq.deque), _len_(deq.deque));          \
        deq.c += MAX-1;                                                                  \
        _begin_(deq.deque) += MAX-1;                                                     \
        _len_(deq.deque)++;                                                              \
        *_begin_(deq.deque) = data;                                                      \
    }                                                                                    \
 
#define _pop_left_(deq)                                                                  \
    if (_len_(deq.deque))                                                                \
    {                                                                                    \
        _begin_(deq.deque)++;                                                            \
        _len_(deq.deque)--;                                                              \
        deq.c++;                                                                         \
    }                                                                                    \
    else                                                                                 \
    {                                                                                    \
        _begin_(deq.deque) -= deq.c;                                                     \
        deq.c = 0;                                                                       \
        clear(&deq.deque);                                                               \
    }                                                                                    \
 
#define _push_right_(deq, data)                                                          \
    if(deq.c)                                                                            \
    {                                                                                    \
        _begin_(deq.deque) -= deq.c;                                                     \
        memcpy(_begin_(deq.deque), _begin_(deq.deque) + deq.c, _len_(deq.deque));        \
        deq.c = 0;                                                                       \
        shrinkTofit(&deq.deque);                                                         \
        _push_back_(deq.deque, data);                                                    \
    }                                                                                    \
    else                                                                                 \
    {                                                                                    \
        _push_back_(deq.deque, data);                                                    \
    }                                                                                    \

#define _pop_right_(deq)                                                                 \
    _pop_back_(deq.deque)


#define _push_left__(deq, data)                                                          \
    if(deq->c)                                                                           \
    {                                                                                    \
        _begin_(deq->deque)--;                                                           \
        _len_(deq->deque)++;                                                             \
        *_begin_(deq->deque) = data;                                                     \
        deq->c--;                                                                        \
    }                                                                                    \
    else                                                                                 \
    {                                                                                    \
        reserve(&deq->deque, _len_(deq->deque) + MAX);                                   \
        memcpy(_begin_(deq->deque) + MAX, _begin_(deq->deque), _len_(deq->deque));       \
        deq->c += MAX-1;                                                                 \
        _begin_(deq->deque) += MAX-1;                                                    \
        _len_(deq->deque)++;                                                             \
        *_begin_(deq->deque) = data;                                                     \
    }                                                                                    \

#define _pop_left__(deq)                                                                 \
    if (_len_(deq->deque))                                                               \
    {                                                                                    \
        _begin_(deq->deque)++;                                                           \
        _len_(deq->deque)--;                                                             \
        deq->c++;                                                                        \
    }                                                                                    \
    else                                                                                 \
    {                                                                                    \
        _begin_(deq->deque) -= deq->c;                                                   \
        deq->c = 0;                                                                      \
        clear(&deq->deque);                                                              \
    }                                                                                    \

#define _push_right__(deq, data)                                                         \
    if(deq->c)                                                                           \
    {                                                                                    \
        _begin_(deq->deque) -= deq->c;                                                   \
        memcpy(_begin_(deq->deque), _begin_(deq->deque) + deq->c, _len_(deq->deque));    \
        deq->c = 0;                                                                      \
        shrinkTofit(&deq->deque);                                                        \
        _push_back_(deq->deque, data);                                                   \
    }                                                                                    \
    else                                                                                 \
    {                                                                                    \
        _push_back_(deq->deque, data);                                                   \
    }                                                                                    \

#define _pop_right__(deq)                                                                \
    _pop_back_(deq->deque)


/* Initialize deque using individual items or 'characters'. */
extern deque init_deque(uint64_t i, ...);

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
