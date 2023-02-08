    /*
    *File Author Name: Visweshwaran Baskaran
    *Date: 02-07-2023
    *Sources: 
    *    https://www.geeksforgeeks.org/void-pointer-c-cpp/
    *    https://stackoverflow.com/questions/18993591/how-to-loop-through-a-string-created-by-pointer
    *    https://stackoverflow.com/questions/394767/pointer-arithmetic
    */

    #include <stddef.h>
    #include <stdint.h>
    #include "cbfifo.h"

    #define CAPACITY 256 //Max size of circular buffer
    #define READ_PTR_START 0 //Read pointer initial position
    #define WRITE_PTR_START 0 //Write pointer initial position

    // Macros for ERROR CODES
    #define ENQ_BUF_IS_NULL 0 
    #define DQ_BUF_IS_NULL 0




    static uint8_t buffer[CAPACITY]; //statically initialized buffer array
    static size_t read_ptr = READ_PTR_START; 
    static size_t write_ptr = WRITE_PTR_START;
    /*
    *Returns number of bytes enqueued to the circular buffer
    *Maintaining write ptr = read ptr - 1; to enqueue data 
    *Error Code(s): 
    *Null check for the argument passed buf in cbfifo_enqueue(): ENQ_BUF_IS_NULL
    */
    size_t cbfifo_enqueue(void *buf, size_t nbyte) 
    {
    if(buf == NULL)
    {
        return ENQ_BUF_IS_NULL; //Data variable passed is NULL
    }
    size_t i;
    size_t enq_count = 0; //counter variable for bytes enqueued onto buffer
    size_t length = cbfifo_length();
    if (nbyte > (CAPACITY -1) - length) 
    {
        nbyte = (CAPACITY-1) - length;
    }
    for (i = 0; i <nbyte; i++) 
    {
        size_t write_ptr_pos = ((write_ptr + 1) & (CAPACITY - 1)); //Calculating write_ptr = (write_ptr + 1)%CAPACITY
        if (write_ptr_pos != read_ptr) 
        {
            //data at current index of input buffer is stored into the circular buffer
            uint8_t *p = (uint8_t *)buf + i;
            uint8_t data = *p;

            buffer[write_ptr] = data;
            write_ptr++;
            write_ptr = (write_ptr) & (CAPACITY - 1);
            enq_count++;
        } 
        else
        {
            break; 
        }
    }
        return enq_count;
    }
    /*
    *Returns number of bytes dequeued from the circular buffer
    *Checking read ptr ! = write ptr ; to dequeue data 
    *Error Codes: 
    *Null check for the argument passed buf in cbfifo_dequeue(): DQ_BUF_IS_NULL
    */

    size_t cbfifo_dequeue(void *buf, size_t nbyte) 
    {
        if(buf == NULL)
        {
            return DQ_BUF_IS_NULL; //Data variable passed is NULL
        }
        size_t i;
        size_t dq_count = 0; //counter variable for bytes dequeued from buffer

        size_t length = cbfifo_length();
        if (nbyte > length )
        {
            nbyte = length;
        }
        for (i = 0; i < nbyte; i++)
        {
            if (read_ptr != write_ptr)  //Buffer has space for further storage conditon
            {
                //The next available item in buffer is stored in the variable buf passed through dequeue()
                uint8_t *p = (uint8_t *)buf + i;
                *p = buffer[read_ptr];
                read_ptr++;
                read_ptr = (read_ptr) & (CAPACITY - 1);
                dq_count++;
            } 
            else 
            {
                break;
            }
        }
    return dq_count;
    }

    /*
    *Returns no. of bytes currently stored in the buffer
    */

    size_t cbfifo_length() 
    {
        size_t length = (write_ptr - read_ptr) & (CAPACITY-1);
        return length;
    }
    /*
    *Returns max size of circular buffer
    */
    size_t cbfifo_capacity() 
    {
        return CAPACITY;
    }
