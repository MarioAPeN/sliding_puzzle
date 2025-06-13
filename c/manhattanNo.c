#ifndef ____MANHATTAN_NUMBER__CALCULATOR____
#define ____MANHATTAN_NUMBER__CALCULATOR____
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
#define GRID_DIMENSION_DO_NOT_MATCH -1

int taxicabDistance(int px, int py, int qx, int qy)
{
    int a = px-qx;
    int b = py-qy;

    if(a<0){a*=-1;}
    if(b<0){b*=-1;}

    return a+b;
}

int manhattanDistance(int* grid, int gridSize, int gridRows, int gridColumns)
{
    int columnPosition = -1;
    int rowPosition = -1;
    if(gridSize!=(gridColumns*gridRows)) {return GRID_DIMENSION_DO_NOT_MATCH;}
    
    for(int i=0;i<gridRows;i++)
    {
        for(int j=0;j<gridColumns;j++)
        {
            if(grid[i*gridColumns +j]==0)
            {
                columnPosition = j+1;
                rowPosition = i+1;
                break;
            }
        }
        if(columnPosition!=-1){break;}
    }

    return taxicabDistance(columnPosition,rowPosition,gridColumns,gridRows);
}

#endif