#include "lllifo.h"
#include "test_lllifo.h"
#include "cbfifo.h"
#include "test_cbfifo.h"

int main()
{
    test_cbfifo();
    test_lllifo();
    return 0;
}