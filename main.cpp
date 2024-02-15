/*
    Isaiah Doan
    PA2
*/

/*  
    Yes, CPU time affects the runtime. std::list is better for insertions and removals.
    However, std::vectors are better at random access and iteration. Choosing one over the 
    other mostly depends on the specific problem requirements. The running time dependency
    on M may have a more significant impact on the overall runtime compared to N, 
    especially if M significantly affects the number of iterations required for each 
    elimination round. However, the relative impact of N and M on runtime depends on the 
    specific implementation and characteristics of the problem. I noticed that vectors
    have a significantly lower CPU runtime, but lack in Average Elimination Time.
*/

#include "header.h"
#include "Destination.h"
#include "ListMyJosephus.h"
#include "VectorMyJosephus.h"
#include "TestListMyJosephus.h"
#include "TestVectorMyJosephus.h"

int main(void)
{

    testList();

    testVector();

    return 0;
}