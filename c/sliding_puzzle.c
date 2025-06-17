#include<stdio.h>
#include<stdlib.h>

#include"sliding_puzzle.h"
#include"sliding_puzzle_utils.h"

const int SP_SOLVED=0xFF;
const int SP_UNSOLVED=0xDD;
const int SP_SINGLE_STEP=0x00;

const int SP_CANNOT_MANAGE_MEMORY = -1;
const int SP_BOARD_NOT_INITIALIZED = -2;
const int SP_BOARD_OPERATION_SUCCESSFUL = 0;
const int SP_BOARD_OPERATION_FAILED = -3;

const int SP_BOARD_CANNOT_MOVE = 1;
const int SP_BOARD_MOVE_ALLOWED = 5;

static int verifyIfSolved(SP_board* game)
{
    int boardSize = (game->rows)*(game->columns);

    /*The game being solved won't neccessarially stop player from keep
    making moves. For that, the status of the game must be checked to get
    the player out of the main loop. 
    
    In case that the player keeps making moves after the board is solved, 
    this function will just assume the board is again in an unsolved stat
    and will skip verifications.*/
    if(game->status == SP_SOLVED)
    {
        game->status == SP_UNSOLVED;
    }
    else
        {for(int i=0;i<boardSize;i++)
        {
            if(i==(boardSize-1))
            {
                game->status = SP_SOLVED;
                break;
            }

            if(game->board[i]!=(i+1)){break;}
        }
    }
    return game->status;
}

static int locateEmptySpace(SP_board* game)
{
    if((game->rows > 1) && (game->columns > 1) && (game->board!=NULL))
    {
        for(int row=0; row < game->rows; row++)
        {
            for(int column=0; column < game->columns; column++)
            {
                if(game->board[row*(game->columns)+column]==0)
                {
                    game->rowPosition = row;
                    game->columnPosition = column;
                    return SP_BOARD_OPERATION_SUCCESSFUL;
                }
            }
        }
    }
    else
    {
        return SP_BOARD_NOT_INITIALIZED;
    }
    return SP_BOARD_OPERATION_FAILED;
}

static int shuffleBoard(SP_board* game)
{
    int mDistance = 0;
    int nCicles = 1;
    if((game->rows > 1) && (game->columns > 1) && (game->board!=NULL))
    {
        do{
            fisherYatesShuffle(game->board,((game->rows)*(game->columns)));
            mDistance = manhattanDistance(game->board,
                            ((game->rows)*(game->columns)),
                            game->rows,
                            game->columns);
            nCicles = findCicles(game->board,((game->rows)*(game->columns)));
        }while((mDistance%2)+(nCicles%2)!=1);

        return SP_BOARD_OPERATION_SUCCESSFUL;
    }
    
    return SP_BOARD_OPERATION_FAILED;
}

static int spMove(SP_board* game, int direction, int step)
{
    if(step>0)
    {
        int rowStep = (direction==SP_UP)?(-1):(direction==SP_DOWN?1:0);
        int colStep = (direction==SP_LEFT)?(-1):(direction==SP_RIGHT?1:0);

        int zeroPosition=((game->rowPosition)*(game->columns)) +
                        game->columnPosition;

        int nextPosition = (((game->rowPosition) + rowStep)*(game->columns)) +
            (game->columnPosition + colStep);
           

        game->board[zeroPosition]=game->board[nextPosition];
        game->board[nextPosition] = 0;
        game->rowPosition += rowStep;
        game->columnPosition += colStep;
        step--;
    }

    return (step>0)?spMove(game,direction,step):SP_BOARD_OPERATION_SUCCESSFUL;
}


int boardCreate(SP_board* game,int rows,int columns)
{
    /*To keep things organized, rows and columns should be assigned in this
    function*/
    game->rows = rows;
    game->columns = columns;
    if((game->rows > 1) && (game->columns > 1) && (game->board==NULL))
    {
        /*If the measures of the rows and columns are real and correct,
        attempt to allocate memory occurs. If it's successfull, the array is
        filled with numbers from 0 to rows*columns*/
        game->board=(int*)malloc(sizeof(int)*((game->rows)*(game->columns)));
        if(game->board == NULL)
        {
            return SP_CANNOT_MANAGE_MEMORY;
        }
        for(int i=0; i<((game->rows)*(game->columns));i++)
        {
            game->board[i]=i;
        }

        /*The array will be shuffled once, and it will then shuffle it again
        only if the pair of number of cicles and Manhattan number are a pair
        of odd+even number. This guarantees that the result array will be a
        board that can be solved by the player.*/
       
        shuffleBoard(game);

        locateEmptySpace(game);

        game->turns = 0;
        game->status = SP_UNSOLVED;
    }
    else
    {
        return SP_BOARD_NOT_INITIALIZED;
    }
    return SP_BOARD_OPERATION_SUCCESSFUL;
}

int boardReset(SP_board* game)
{
    if(game->board == NULL)
    {return SP_BOARD_OPERATION_FAILED;}

    shuffleBoard(game);
    locateEmptySpace(game);
    game->turns = 0;
    game->status = SP_UNSOLVED;

    return SP_BOARD_OPERATION_SUCCESSFUL;
}

int boardDestroy(SP_board* game)
{
    if(game->board != NULL)
    {
        free(game->board);

        game->board = NULL;
        game->rows = 0;
        game->columns = 0;
        game->rowPosition = 0;
        game->columnPosition = 0;
        game->turns = 0;
        game->status = SP_UNSOLVED;
    }
    else
    {
        return SP_CANNOT_MANAGE_MEMORY;
    }
    return SP_BOARD_OPERATION_SUCCESSFUL    ;
}

int slidingPuzzleMove(SP_board* game, int direction, int requestedStep)
{
    int step = 1;
    int movementStatus = SP_BOARD_CANNOT_MOVE;

    if(requestedStep!=SP_SINGLE_STEP && requestedStep > 0)
    {step = requestedStep;}

    if((game->rows > 1) && (game->columns > 1) && (game->board!=NULL)
    && (game->rowPosition < game->rows) 
    && (game->columnPosition < game->columns))
    {
        
        switch (direction)
        {
            case SP_UP:{
                if(game->rowPosition - step >= 0)
                {
                    movementStatus = SP_BOARD_MOVE_ALLOWED;
                }
                break;}
            case SP_DOWN:{
                if(game->rowPosition + step < game->rows)
                {
                    movementStatus = SP_BOARD_MOVE_ALLOWED;
                }
                break;}
            case SP_LEFT:{
                if(game->columnPosition - step >= 0)
                {
                    movementStatus = SP_BOARD_MOVE_ALLOWED;
                }
                break;}
            case SP_RIGHT:{
                if(game->columnPosition + step < game->columns)
                {
                    movementStatus = SP_BOARD_MOVE_ALLOWED;
                }
                break;}
            default:
                break;
        }
        if(movementStatus == SP_BOARD_MOVE_ALLOWED)
        {
            int result = spMove(game,direction,step);
            game->turns += 1;
            verifyIfSolved(game);
            return result;
        }
    }
    return SP_BOARD_OPERATION_FAILED;
}