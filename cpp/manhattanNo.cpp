
#ifndef ____MANHATTAN_NUMBER__CALCULATOR____CPP___VER___
#define ____MANHATTAN_NUMBER__CALCULATOR____CPP___VER___
/*
From wikipedia:
https://en.wikipedia.org/wiki/Taxicab_geometry

The taxicab or Manhattan distance between two points p(px,py) and q(qx,qy)
is equal to: |px-qx| + |qx-qy|

In this code, taxicabDistance() is used to calculate this given two points
into the same grid whatsoever, while manhattanDistance() sets up things
to calculate based on the location of 0 on a list of ints, this to make easy
it's use on the sliding puzzle game.

*/

int taxicabDistance(int px, int py, int qx, int qy)
{
    int a = px-qx;
    int b = py-qy;

    if(a<0){a*=-1;}
    if(b<0){b*=-1;}

    return a+b;
}

#endif