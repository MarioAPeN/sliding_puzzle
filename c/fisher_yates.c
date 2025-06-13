/*==============================================================================
Implementation of Fisher-Yates shuffling algorithm.

Sources:
-Basic Theory
https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
-To reduce the bias
https://stackoverflow.com/questions/10984974/why-do-people-say-there-is-modulo-bias-when-using-a-random-number-generator#10984975

This particular functions is meant to take an array of integers and shuffle 
their contents according to the following algorithm:

for i from n−1 down to 1 do
     j ← random integer such that 0 ≤ j ≤ i
     exchange a[j] and a[i]

==============================================================================*/
#ifndef ___ED____FISHER__YATES_SHUFFLING____
#define ___ED____FISHER__YATES_SHUFFLING____
#include<stdlib.h>
#include<time.h>

int fisherYatesShuffle(int* cicle, int cicle_size)
{
    int shuffle_index = 0;
    int swap_holder = 0;
    srand(time(NULL));
    for(int current_index=(cicle_size-1); current_index>=0;current_index--)
    {
#ifdef __BIAS_PROTECTION__
        do{
            shuffle_index=rand();
        }while(shuffle_index >= (RAND_MAX-(RAND_MAX%cicle_size)));
        shuffle_index%=cicle_size;
#else
        shuffle_index=rand()%cicle_size;
#endif
        swap_holder = cicle[current_index];
        cicle[current_index] = cicle[shuffle_index];
        cicle[shuffle_index] = swap_holder;
    }
    return 0;
}

#endif