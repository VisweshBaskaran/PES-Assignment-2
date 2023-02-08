    #include"test_cbfifo.h"

    int test_cbfifo()
    {
        char data1[1] = {'a'};
        char outdata0[1];
        printf("Checking cbfifo_enqueue() invalid case when 0 bytes of data is to be enqueued \n");
        assert(0 == cbfifo_enqueue(data1, 0)); //enqueing 0 bytes of data1 to buffer, returns 0
        printf("Checking cbfifo_enqueue() invalid case where buf = NULL \n");
        assert(0 == cbfifo_enqueue(NULL, 0)); //Trying to enqueue a NULL element: invalid case, return 0
        assert(0 == cbfifo_dequeue(outdata0,1)); //Trying to dequeue 1 byte out of the empty buffer: invalid case, return 0
        assert(0 == cbfifo_length());

        printf("Checking cbfifo_enqueue(), cbfifo_length() for valid cases\n");
        char data2[120]; 
        memset(data2, 0, sizeof(data2)); //Storing 0 in each element of data2 array;
        assert(120 == cbfifo_enqueue(data2, sizeof(data2))); //Enqueuing the entire 120 bytes stored in data2 to the buffer : length = 120
        assert(120 == cbfifo_length()); 
        assert(120 == cbfifo_length()); //Checking length after failed dequeue.
        printf("Checking cbfifo_dequeue() for invalid case: while trying to dequeue 1 byte from buffer and store in NULL \n");
        assert(0 == cbfifo_dequeue(NULL,1)); 
        printf("Checking cbfif0_enqueue() and cbfifo_length() while enqueing different datatypes\n");
        int data = 1;
        assert(4 == cbfifo_enqueue(&data, sizeof(data))); //Enqueueing all 4 bytes of data to buff
        assert(124 == cbfifo_length());
        char data3[131];
        memset(data3, 0, sizeof(data3));
        assert(131 == cbfifo_enqueue(data3, sizeof(data3)));
        assert(255 == cbfifo_length());
        char data4[1];
        memset(data4, 0, sizeof(data4));
        assert(0 == cbfifo_enqueue(data3, 1));
        assert(255 == cbfifo_length());
        printf("Checking cbfifo_dequeue() for valid cases\n");
        char outdata[20];
        memset(outdata, 0, sizeof(outdata));
        assert(20 == cbfifo_dequeue(outdata, 20));
        assert(235 == cbfifo_length());
        char outdata1[30];
        memset(outdata1, 0, sizeof(outdata1));
        assert(30 == cbfifo_dequeue(outdata1, 30) );
        assert(205 == cbfifo_length());
        int data5[12];
        memset(data5, 0, sizeof(data5));
        assert(48 == cbfifo_enqueue(data5, sizeof(data5)));
        assert(253 == cbfifo_length());
        printf("Checking cbfifo_enqueue() for the case: nbyte > space available\n");
        int data6[1];
        memset(data6, 0, sizeof(data6));
        assert(2 == cbfifo_enqueue(data6, 4)); //should be 2
        //printf("%ld",cbfifo_enqueue(data6, sizeof(data6)));
        assert(255 == cbfifo_length());
        char outdata2[256];
        assert(255 ==  cbfifo_dequeue(outdata2,256));
        assert(0 == cbfifo_length());
        printf("Checking cbfifo_capacity()\n");
        assert(256 == cbfifo_capacity());
        printf("Covered and checked all cases for cblifo.h functions. All test cases passed as assert did not return error  \n\n");

        return 1;
    }

