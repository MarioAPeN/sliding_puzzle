#ifndef ___FIND_CICLES_IN____ARRAY___CPP_VER____
#define ___FIND_CICLES_IN____ARRAY___CPP_VER____
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
#include<vector>

#define FC_ARRAY_IS_MISSING_VALUES -1
#define FC_CANT_ALLOCATE_MEMORY    -2
#define FC_ARRAY_IS_EMPTY          -3

int valueExistsInArray(int value, std::vector<int>& array)
{
    int timesRepeated = 0;
    for(int i=0;i<array.size();i++)
    {
        if(array[i]==value){timesRepeated++;}
    }
    return timesRepeated;
}

int verifyAllValues(std::vector<int>& array, int* missN, int* reptN)
{
    int missingNumbers = 0;
    int repeatedValues = 0;

    for(int i=0; i<array.size(); i++)
    {
        switch(valueExistsInArray(i,array))
        {
            case 0: missingNumbers++; break;
            case 1: break;
            default: repeatedValues++;
        }
    }

    if(missN != NULL){missN[0] = missingNumbers;}
    if(reptN != NULL){reptN[0] = repeatedValues;}

    return missingNumbers + repeatedValues;
}

int findCicles(std::vector<int>& list)
{
    int cicles = 0;
    int selector = 0;
    std::vector<int> verificationVector;

    if(list.size() < 2 ) {return FC_ARRAY_IS_EMPTY;}
    if(verifyAllValues(list,NULL,NULL)>0){ return FC_ARRAY_IS_MISSING_VALUES;}

    verificationVector.resize(list.size());
    fill(verificationVector.begin(),verificationVector.end(),0);

    for(int currentPosition = 0; currentPosition<list.size(); currentPosition++)
    {
        if(verificationVector[currentPosition]==1){continue;}
        selector = currentPosition;
        do{
            verificationVector[selector] = 1;
            selector = list[selector];
        }while(selector != currentPosition);
        cicles++;
    }

    return cicles;
}

#endif