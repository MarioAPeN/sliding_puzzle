#ifndef ___ED___SLIDDING_PUZZLE_LOGIC___
#define ___ED___SLIDDING_PUZZLE_LOGIC___

#include<stdint.h>

typedef struct SP_PIECE{
/*
To include:
Coordinates of a single "piece". A fragment of the image we will be loading
to make the puzzle more attractive. Will check later if it's needed SDL
datatype or if I can use custome ones.

Index for the actuall location of the piece on the board. This will change,
depending on where the empty space is moving.

*/
    uint8_t currentLocation;
};

/*
Verification that the Manhathan number and the cicles are even/odd, so that
the game actually has a solution.
*/
int isSolvable(SP_PIECE** board,int boardWidth, int boardHeight)
{
    for(int piece = 0; piece<(boardWidth*boardHeight);boardWidth*boardHeight)
    {
        
    }
}

#endif