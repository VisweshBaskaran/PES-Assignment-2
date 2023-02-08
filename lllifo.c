    /*

    File Author Name: Visweshwaran Baskaran

    Sources: https://codeforwin.org/data-structures/c-program-to-create-and-traverse-singly-linked-list
    */

    #include <stdio.h>
    #include <stdlib.h>
    #include "lllifo.h"
    #include <assert.h>

    #define PUSH_PASSED_INSTANCE_NULL -1 
    #define PUSH_PASSED_ELEMENT_NULL -1 
    #define ADDITIONAL_MALLOC_FAILED -1
    #define ERROR_CODE_LENGTH_OF_NULL_NODE -1
    #define ERROR_CODE_CAPACITY_OF_NULL_NODE -1

    struct lllifo_node_s 
    {
        void *element;
        struct lllifo_node_s *next;
    };
    typedef struct lllifo_node_s lllifo_node_t;

    struct lllifo_s 
    {
        lllifo_node_t *head;
        int length;
        int capacity;
    };

    /*
    *Returns a lllifo_t instance with capacity nodes.
    *lllifo_t *lifo is the containing structure 
    *lllifo_node_t *first is the first lllifo node which is stored in lifo->head
    *A for loop is used to append remaining capacity - 1 nodes to lifo->head
    */
    lllifo_t *lllifo_create (int capacity)
    {
        if(capacity < 0)
            return NULL; // Error code when capacity < 0

        lllifo_t *lifo = (lllifo_t *) malloc (sizeof (lllifo_t));
        if (lifo == NULL)
            return NULL; //Error code when malloc() fails to allocate memory for lllifo_t *lifo

        lifo->length = 0;
        lifo->capacity = capacity;

        if(capacity == 0)
            return lifo; //Returning lllifo_t instance lifo which is only the containing structure without lllifo nodes

        lllifo_node_t *first = (lllifo_node_t *) malloc (sizeof (lllifo_node_t));
        if (first == NULL)
        {
            free(first);
            return NULL; ////Error code when malloc() fails to allocate memory for lllifo_t *lifo
        }
        //Assigning struct elements of first lllifo node
        first->element = NULL; 
        first->next = NULL;
        lifo->head = first;

        //Appending (capacity - 1) no. of nodes
        lllifo_node_t *current_node = first;
        lllifo_node_t *next_node;

        for(int i = 1; i <capacity; i++)
        {         
            next_node = (lllifo_node_t *) malloc (sizeof(lllifo_node_t));
            if(next_node == NULL)
            {
                free(next_node);
                lllifo_destroy(lifo);
                return NULL;
            }

            next_node->element = NULL;
            next_node->next=NULL;

            current_node->next = next_node;
            current_node = current_node->next;

        }

        return lifo;
    } 
    /*
    * Pushes the data present in element to lifo. Returns the length of lllifo
    * First by traversing through all existing nodes, availability of nodes is checked and pushed when a unused node is present. Increments length by 1and returns it.
    * Otherwise
    * Mallocs an instance of lllifo_t, appends it to end of lifo and pushes element. Increments both length and capacity by 1, and returns length.
    *
    */
    int lllifo_push(lllifo_t* lifo, void *element)
    {
        if(lifo == NULL) 
            return PUSH_PASSED_INSTANCE_NULL;
        if(element == NULL) 
            return PUSH_PASSED_ELEMENT_NULL;
        lllifo_node_t* traverse = lifo->head;
        if(lifo->length >=0)
        {
            for(int i=1; i<=lifo->capacity; i++)
            {   
                if(traverse->element == NULL)
                {
                    traverse->element = element;
                    lifo->length++;
                    return lifo->length;
                }
                traverse = traverse->next;
            }
        }
        lllifo_node_t* traverse_extra = lifo->head;
        for(int i=1; i<lifo->capacity;)
        {
            traverse_extra = traverse_extra->next;
            i++;
        }   
        lllifo_node_t *extra_node = (lllifo_node_t *) malloc (sizeof(lllifo_node_t));
        if(extra_node == NULL)
            return  ADDITIONAL_MALLOC_FAILED;
        extra_node->element = element;
        extra_node->next = NULL;
        traverse_extra->next=extra_node;
        lifo->length++;
        lifo->capacity++;
        return lifo->length;
    }
    /*
    * pops the data present in last used lifo node. Returns the popped element
    * Checks if all nodes are full and pops data present last node
    * Otherwise
    * Traverses through all nodes to check for last used node to pop the data present in it
    * Capacity remains same after pop, length is decremented by 1
    */
    void *lllifo_pop(lllifo_t *lifo)
    {
        void* stored;
        if(lifo == NULL)
        return NULL; // Error code when passed instance is NULL
        if(lifo->length == 0 || lifo->capacity == 0)
        return NULL; //Error code when no element is available to push or there is no lllifo nodes at all
        lllifo_node_t *pop_traverse = lifo->head;
        if(lifo->length == lifo->capacity) 
        {
            for(int i = 1; i<(lifo->capacity); i++)
            {
                pop_traverse = pop_traverse->next;
            }
            stored = pop_traverse->element;
            pop_traverse->element=NULL;
            lifo->length--;
            return stored;
        }
        for(int j = 1; j<=(lifo->capacity); j++)
        {
            if((pop_traverse->element != NULL) && (((pop_traverse->next)->element) == NULL))
            {
                stored = pop_traverse->element;
                pop_traverse->element=NULL;
                lifo->length--;
                return stored;
            }
            pop_traverse = pop_traverse->next;
        }
        return NULL; //Error code to handle invalid input as passed lifo instance does not enter the above two loops.
    }
    /*
    * Frees the nodes of the linked list and containing structure
    */
    void lllifo_destroy(lllifo_t *lifo)
    {
    if(lifo == NULL)
        return; //Exiting function call as passed instance is NULL
    lllifo_node_t *destroy_traverse; 
    lllifo_t *first = lifo;
    //Traversing till end of lllifo_node_t nodes to access them one by one to free them
    while(first->head != NULL)
    {
        destroy_traverse = first->head;
        first->head = (first->head)->next;
        free(destroy_traverse); //freeing node structure i.e instance of lllifo_node_t
        destroy_traverse = NULL;
    }
    free(lifo); //freeing containing structure i.e instance of lllifo_t
    lifo = NULL ;
    }
    /*
    * Returns the current length of the passed instance by accessing length struct element of containing structure
    */
    int lllifo_length(lllifo_t *lifo)
    {
        if(lifo == NULL)
        return ERROR_CODE_LENGTH_OF_NULL_NODE; 
        return lifo->length;
    }
    /*
    * Returns the current capacity of the passed instance by accessing capacity struct element of containing structure
    */
    int lllifo_capacity(lllifo_t *lifo)
    {
        if(lifo == NULL)
        return ERROR_CODE_CAPACITY_OF_NULL_NODE;
        return lifo->capacity;
    }



