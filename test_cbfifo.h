    #include "cbfifo.h"
    #include <string.h>
    #include <assert.h>
    #include <stdio.h>
    /*
    *Returns 1 when all asserts are true.
    *
    *Parameters: None
    *
    *Performs stateful testing to checks if functions:  cbfifo_length(), cbfifo_capacity(), cbfifo_enqueue() and cbfifo_dequeue()
    *works as intended by asserting expected return values to function calls over various cases.
    */
    int test_cbfifo();