#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "deque.h"
#define MAX 0x7d00

deque init_deque(uint64_t i, ...)
{
    deque q;
    q.deque.buffer = NULL;
    q.c = q.deque.i = q.deque.max = 0;
    if(i == 0)
    {
        return q;
    }
    va_list args;        
    va_start (args, i);           
    for(uint64_t c = 0; c < i; c++)        
    {
        push_back(&q.deque, va_arg (args, int)); 
    }
    va_end (args); 
    shrinkTofit(&q.deque);
    return q;  
}

deque deque_more(void)
{
    deque new_queue;
    new_queue.c = new_queue.deque.i = new_queue.deque.max = 0;
    new_queue.deque = input_str(NULL);
    return new_queue;
}

void push_left(deque *deq, char data)
{
    if(deq->c)
    {
        _begin_(deq->deque)--;
        _len_(deq->deque)++;
        *_begin_(deq->deque) = data;
        deq->c--;
    }
    else
    {
        reserve(&deq->deque, _len_(deq->deque) + MAX);
        memcpy(_begin_(deq->deque) + MAX, _begin_(deq->deque), _len_(deq->deque));
        deq->c += MAX-1;
        _begin_(deq->deque) += MAX-1;
        _len_(deq->deque)++;
        *_begin_(deq->deque) = data;
    }
}

void pop_left(deque *deq)
{
    if (_len_(deq->deque))
    {
        _begin_(deq->deque)++;
        _len_(deq->deque)--;
        deq->c++;
    }
    else
    {
        _begin_(deq->deque) -= deq->c;
        deq->c = 0; 
        clear(&deq->deque);
    }
}

void push_right(deque *deq, char data)
{
    if(deq->c)
    {
        _begin_(deq->deque) -= deq->c;
        memcpy(_begin_(deq->deque), _begin_(deq->deque) + deq->c, _len_(deq->deque));
        deq->c = 0;
        shrinkTofit(&deq->deque);
        _push_back_(deq->deque, data); 
    }
    else
    {
        _push_back_(deq->deque, data);
    }
}

void pop_right(deque *deq)
{
    _pop_back_(deq->deque);
}

void deque_fit(deque *deq)
{
    if(deq->c)
    {
        _begin_(deq->deque) -= deq->c;
        memcpy(_begin_(deq->deque), _begin_(deq->deque) + deq->c, _len_(deq->deque));
        deq->c = 0;
    }
    if(capacity(&deq->deque))
    {
        shrinkTofit(&deq->deque);
    }
}

uint64_t deque_count(deque *deq)
{
    return _len_(deq->deque);
}

void deque_show(deque *deq)
{
    display(&deq->deque);
}

int deque_empty(deque *deq)
{
    return empty(&deq->deque);
}

void deque_clear(deque *deq)
{
    if(deq->c)
    {
        _begin_(deq->deque) -= deq->c;
        deq->c = 0;
    }
    clear(&deq->deque);
}

void deque_destroy(deque *deq)
{
    if(deq->c)
    {
        _begin_(deq->deque) -= deq->c;
        deq->c = 0;
    }
    erase(&deq->deque);
}