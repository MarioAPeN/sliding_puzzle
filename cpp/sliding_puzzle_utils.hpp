#ifndef ___SP___MAPN___UTILS____CPP_VER____
#define ___SP___MAPN___UTILS____CPP_VER____
#include<vector>

//Given that all the neccessary arguments to calculate the Manhattan Distance
//are already included in the class definition and as such are easilly accessed
//to any funciton inside the class' methods, instead of adding a function a
//macro to taxicabDistance is used instead. This also prevents the program from
//calculating the position of 0 on the board, saving a few cicles.


#ifndef manhattanDistance
#define manhattanDistance(columnPosition,rowPosition,columns,rows) \
        taxicabDistance(columnPosition,rowPosition,columns,rows)
#endif

int taxicabDistance(int px, int py, int qx, int qy);

int findCicles(std::vector<int>& list);

void fisherYatesShuffle(std::vector<int>& list);

#endif