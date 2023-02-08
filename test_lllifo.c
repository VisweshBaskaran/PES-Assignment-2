    #include"test_lllifo.h"
    /*
    *Tests function declared in lllifo.h
    *What the function tests: 
    *Creating a lllifo instance with capacity < = 0
    *When a lllifo_t *instance = NULL is being passed into each of the 6 functions
    *
    */
    int test_lllifo()
    {
        printf("Creating LLLIFO with 0 capacity\n");
        lllifo_t *my_lifo2 = lllifo_create(0);
        assert(0 == lllifo_capacity(my_lifo2));
        lllifo_t *null_lifo = NULL;
        null_lifo = lllifo_create(0);
        assert(0 == lllifo_capacity(null_lifo)); 
        printf("Creating LLLIFO of capacity 5 and 10\n");
        lllifo_t *my_lifo = lllifo_create(5);
        lllifo_t *my_lifo1 = lllifo_create(10);
        assert(10 == lllifo_capacity(my_lifo1));
        assert(5 == lllifo_capacity(my_lifo));
        printf("Covering lllifo_pop() invalid case(s) \n");
        assert(NULL == lllifo_pop(my_lifo1));
        assert(NULL == lllifo_pop(my_lifo));
        assert(NULL == lllifo_pop(NULL));
        printf("Covering lllifo_push() invalid case(s) \n"); 
        lllifo_t *NULL_NODE = NULL;
        assert(-1 == lllifo_push(NULL_NODE, "Sleepy"));
        printf("Covering lllifo_length() and lllifo_capacity() invalid case(s) \n"); 
        assert(-1 == lllifo_capacity(NULL_NODE));
        assert(-1 == lllifo_length(NULL_NODE));
        printf("Covering lllifo_destroy() invalid case(s) \n"); 
        lllifo_destroy(NULL_NODE);
        printf("Covering lllifo_push() valid case(s) \n"); 
        for(int i = 0; i< 9; i++)
        {
        lllifo_push(my_lifo1, "Sleepy"); 
        }
        lllifo_push(my_lifo1, "Sleepy10"); 
        for(int i = 0; i<5; i++)
        {
        lllifo_push(my_lifo, "Active"); 
        }
        printf("Covering lllifo_length() and lllifo_capacity() valid case(s) \n"); 
        assert(10 == lllifo_capacity(my_lifo1));
        assert(10 == lllifo_length(my_lifo1));
        assert(5 == lllifo_capacity(my_lifo));
        assert(5== lllifo_length(my_lifo));
        printf("Covering lllifo_pop() valid case(s) \n");
        for(int i =0; i<3; i++)
        {
            lllifo_pop(my_lifo);
        }
        assert(2 == lllifo_length(my_lifo));
        assert(10 == lllifo_capacity(my_lifo1));
        lllifo_pop(my_lifo1);
        assert(9 == lllifo_length(my_lifo1));
        lllifo_pop(my_lifo1);
        assert(10 == lllifo_capacity(my_lifo1));
        assert(8 == lllifo_length(my_lifo1));
        lllifo_push(my_lifo1, "Eleventh");
        assert(10 == lllifo_capacity(my_lifo1));
        assert(9 == lllifo_length(my_lifo1));
        lllifo_push(my_lifo1, "Twelfth");
        lllifo_push(my_lifo1, "Thirteenth");
        printf("Covering case when lllifo_push() has to malloc one more node \n");
        assert(11 == lllifo_capacity(my_lifo1));
        assert(11 == lllifo_length(my_lifo1));
        printf("Covering valid lllifo_destroy() case\n");
        lllifo_destroy(my_lifo);
        printf("Covered all cases for lllifo.h functions. All test cases passed as assert did not return error\n\n");
        return 1;
    }
