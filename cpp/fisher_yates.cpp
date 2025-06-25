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
#ifndef ___ED____FISHER__YATES_SHUFFLING____CPP__VER____
#define ___ED____FISHER__YATES_SHUFFLING____CPP__VER____
#include<vector>
#include<random>

void fisherYatesShuffle(std::vector<int>& cicle)
{
    int shuffle_index = 0;
    int swap_holder = 0;

    std::random_device seed;
    std::mt19937 generator(seed());
    std::uniform_int_distribution<int> distribution(0,cicle.size()-1);

    for(int current_index=(cicle.size() -1); current_index>=0; current_index--)
    {
        shuffle_index=distribution(generator);
        swap_holder = cicle[current_index];
        cicle[current_index] = cicle[shuffle_index];
        cicle[shuffle_index] = swap_holder;
    }
    return;
}

#endif