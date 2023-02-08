    #include "lllifo.h"
    #include <stdio.h>
    #include <assert.h>
    #include <string.h>
    /*
    *Returns 1 when all asserts are true.
    *
    *Parameters: None
    *
    *Performs stateful testing to checks if functions:  lllifo_length(), lllifo_capacity(), lllifo_pop(),
    * lllifo_push(), lllifo_destroy(), lllifo_create() works as intended by asserting expected return values to function calls over various cases.
    */
    int test_lllifo();