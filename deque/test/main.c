#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"


int main()
{
    deque deq = new deque(null); 

    int operation = 1;
    char item;
    
    while (operation > 0 && operation < 9)
    {
        printf("%s", "\n\033[0;33m");
        puts("Select one of these operations below:-\n"
        " 1  to push an item at the right side of the deque.\n"
        " 2  to pop an element from the right side of the deque.\n"
        " 3  to push an item at the left side of the deque.\n"
        " 4  to pop an element from the left side of the deque.\n"
        " 5  to show content of the deque.\n"
        " 6  to print the number of the characters in the deque.\n"
        " 7  to shrink capacity of the deque to fit its content.\n"
        " 8  to remove the entire deque from memory.\n"
        " 0  to exit the program.\033[0m\n");  

        printf("Enter operation code: ");
        scanf("%i", &operation);

        switch (operation)
        {
            case 1:
                printf("%s", "Enter a character to be added to the right side of the deque: ");
                scanf(" %c", &item);
                push_right(&deq, item);
                break;
            case 2:
                if(!empty(&deq.deque))
                {
                    printf("\nThe popped character from the right side is %c\n", *back(&deq.deque)); 
                    pop_right(&deq); 
                }
                else
                {
                    puts("Deque is empty.");
                }
                break;
            case 3:
                printf("%s", "Enter a character to be added to the left side of the deque: ");
                char item;
                scanf(" %c", &item);
                push_left(&deq, item);
                break;
            case 4:
                if(!empty(&deq.deque))
                {
                    printf("\nThe popped character from the left side is %c\n", *begin(&deq.deque)); 
                    pop_left(&deq); 
                }
                else
                {
                    puts("Deque is empty.");
                }
                break;
            case 5:
                if(!empty(&deq.deque))
                {
                    printf("Content of deque: ");
                    deque_show(&deq);
                    putchar('\n');
                }
                else
                {
                    puts("Deque is empty.");
                }
                break;
            case 6:
                printf("The deque is holding %llu items (characters).\n", deque_count(&deq));
                break;
            case 7:
                deque_fit(&deq);
                puts("Deque fitted its content successfully."); 
                break;
            case 8:
                deque_destroy(&deq);
                puts("Deque removed successfully.");
                break;
            case 0:
                Used_memory();
                return 0;
            default:
                printf("Not valid op code.");
                break;
        }
    }

    return 0;
}
