#ifndef ___FIND_CICLES_IN____ARRAY___
#define ___FIND_CICLES_IN____ARRAY___
/*
Logic:

1 - Verify that cicles can be found in the array. This means:
    a- The min number in the array is 0
    b- The max number in the array is n-1
    c- There are no repeated numbers in the array
Since we are generating cicles by matching the value stored in the array with 
their index, it's enough to verify that each index exists in the array 
(0 to n-1).

2 - Create a second array of size n, that serves as a buffer to know in which
places we already been through. This is to avoid spoting a cicle more than once
while we loop through the whole array.

3 - Return the number of cicles found.

*/
#include<stdlib.h>
#define FC_ARRAY_IS_MISSING_VALUES -1
#define FC_CANT_ALLOCATE_MEMORY    -2
#define FC_ARRAY_IS_EMPTY          -3

static int verifyAllValues(int* array, int arraySize)
{
    int missingNumbers = 0;
    
    for(int i=0; i<arraySize; i++)
    {
        for(int j=0; j<arraySize; j++)
        {
            if(array[j] == i){break;}
            if((array[j] != i) && (j==(arraySize-1)))
            {missingNumbers++;}
        }
    }
    return missingNumbers;
}

int findCicles(int* array, int arraySize)
{
    int cicles = 0;
    int selector = 0;
    int* verificationArray = NULL;

    if(array == NULL) {return FC_ARRAY_IS_EMPTY;}
    if(verifyAllValues(array,arraySize)>0){ return FC_ARRAY_IS_MISSING_VALUES;}
    
    verificationArray = (int*)malloc(sizeof(int)*arraySize);
    if(verificationArray == NULL) {return FC_CANT_ALLOCATE_MEMORY;}
    for(int i=0;i<arraySize;i++){verificationArray[i]=0;}

    for(int currentPosition = 0; currentPosition<arraySize; currentPosition++)
    {
        if(verificationArray[currentPosition]==1){continue;}
        selector = currentPosition;
        do{
            verificationArray[selector] = 1;
            selector = array[selector];
        }while(selector != currentPosition);
        cicles++;
    }
    free(verificationArray);
    return cicles;
}

#endif