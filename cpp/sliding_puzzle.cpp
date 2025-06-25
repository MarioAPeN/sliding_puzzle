#include<vector>
#include<numeric>

#include"sliding_puzzle.hpp"
#include"sliding_puzzle_utils.hpp"


const int SP_SOLVED                     = 0x33;
const int SP_UNSOLVED                   = 0x44;
const int SP_BOARD_NOT_INITIALIZED      = 0x55;

const int SP_SINGLE_STEP                = 0x66;

const int SP_BOARD_OPERATION_SUCCESSFUL = 0x77;
const int SP_BOARD_OPERATION_FAILED     = 0x88;

const int SP_BOARD_CANNOT_MOVE = 1;
const int SP_BOARD_MOVE_ALLOWED = 5;

int SlidingPuzzle::verifyIfSolved()
{
    int boardSize = (rows)*(columns);

    /*The game being solved won't neccessarially stop player from keep
    making moves. For that, the status of the game must be checked to get
    the player out of the main loop. 
    
    In case that the player keeps making moves after the board is solved, 
    this function will just assume the board is again in an unsolved stat
    and will skip verifications.*/
    if(status == SP_SOLVED && status!=SP_BOARD_NOT_INITIALIZED)
    {
        status == SP_UNSOLVED;
    }
    else
        {for(int i=0;i<boardSize;i++)
        {
            if(i==(boardSize-1))
            {
                status = SP_SOLVED;
                break;
            }

            if(board[i]!=(i+1)){break;}
        }
    }
    return status;
}

bool SlidingPuzzle::locateEmptySpace()
{
    if((rows > 1) && (columns > 1))
    {
        for(int row=0; row < rows; row++)
        {
            for(int column=0; column < columns; column++)
            {
                if(board[row*(columns)+column]==0)
                {
                    rowPosition = row;
                    columnPosition = column;
                    return true;
                }
            }
        }
    }
    return false;
}

int SlidingPuzzle::shuffleBoard()
{
    int mDistance = 0;
    int nCicles = 1;
    if((rows > 1) && (columns > 1) && (status!=SP_BOARD_NOT_INITIALIZED))
    {
        do{
            fisherYatesShuffle(board);
            locateEmptySpace();
            mDistance = 
                manhattanDistance(columnPosition,rowPosition,columns,rows);
            nCicles = findCicles(board);
        }while((mDistance%2)+(nCicles%2)!=1);

        return SP_BOARD_OPERATION_SUCCESSFUL;
    }
    
    return SP_BOARD_OPERATION_FAILED;
}

bool SlidingPuzzle::initializeBoard(int Rows, int Columns)
{
    bool boardInitialized = false;
    if(Rows > 2 && Columns > 2)
    {
        rows=Rows;
        columns=Columns;
        board.resize(Rows*Columns);
        iota(board.begin(),board.end(),0);
        shuffleBoard();
        turns = 0;
        boardInitialized = true;
    }
    return boardInitialized;
}

bool SlidingPuzzle::boardCreateNew(int Rows, int Columns)
{
    //Creates a new game board using the same object.
    return initializeBoard(Rows,Columns);
}

int SlidingPuzzle::boardResetGame()
{
    //Generates a new puzzle using the current board configuration
    shuffleBoard();
    status = SP_UNSOLVED;
    return status;
}        

int SlidingPuzzle::getValueAt(int position)
{
    int valueAt = SP_BOARD_OPERATION_FAILED;
    if(position < (rows*columns))
    {
        valueAt = board[position];
    }
    return valueAt;
}

int SlidingPuzzle::getValueAt(int Row, int Column)
{
    int valueAt = SP_BOARD_OPERATION_FAILED;
    if(Row<rows && Column<columns)
    {
        valueAt = board[(Row*columns)+Column];
    }
    return valueAt;
}

int SlidingPuzzle::getTotalRows()
{
    return rows;
}
int SlidingPuzzle::getTotalColumns()
{
    return columns;
}

int SlidingPuzzle::turnsPlayed()
{
    return turns;
}

int SlidingPuzzle::gameStatus()
{
    return status;
}

int SlidingPuzzle::spMove(int direction, int step)
{
    if(step>0)
    {
        int rowStep = (direction==SP_UP)?(-1):(direction==SP_DOWN?1:0);
        int colStep = (direction==SP_LEFT)?(-1):(direction==SP_RIGHT?1:0);

        int zeroPosition=((rowPosition)*(columns)) +
                        columnPosition;

        int nextPosition = (((rowPosition) + rowStep)*(columns)) +
            (columnPosition + colStep);
           

        board[zeroPosition]=board[nextPosition];
        board[nextPosition] = 0;
        rowPosition += rowStep;
        columnPosition += colStep;
        step--;
    }

    return (step>0)?spMove(direction,step):SP_BOARD_OPERATION_SUCCESSFUL;
}

int SlidingPuzzle::move(int direction, int requestedStep)
{
    int step = 1;
    int movementStatus = SP_BOARD_CANNOT_MOVE;

    if(requestedStep!=SP_SINGLE_STEP && requestedStep > 0)
    {step = requestedStep;}

    if((rows > 1) && (columns > 1)
    && (rowPosition < rows) 
    && (columnPosition < columns))
    {
        
        switch (direction)
        {
            case SP_UP:{
                if(rowPosition - step >= 0)
                {
                    movementStatus = SP_BOARD_MOVE_ALLOWED;
                }
                break;}
            case SP_DOWN:{
                if(rowPosition + step < rows)
                {
                    movementStatus = SP_BOARD_MOVE_ALLOWED;
                }
                break;}
            case SP_LEFT:{
                if(columnPosition - step >= 0)
                {
                    movementStatus = SP_BOARD_MOVE_ALLOWED;
                }
                break;}
            case SP_RIGHT:{
                if(columnPosition + step < columns)
                {
                    movementStatus = SP_BOARD_MOVE_ALLOWED;
                }
                break;}
            default:
                break;
        }
        if(movementStatus == SP_BOARD_MOVE_ALLOWED)
        {
            int result = spMove(direction,step);
            turns += 1;
            verifyIfSolved();
            return result;
        }
    }
    return SP_BOARD_OPERATION_FAILED;
}

SlidingPuzzle::SlidingPuzzle()
{
    if(initializeBoard(3,3)==true)
    {status = SP_UNSOLVED;}
    else{status = SP_BOARD_NOT_INITIALIZED;}
    return;
}

SlidingPuzzle::SlidingPuzzle(int Dimensions)
{
    if(initializeBoard(Dimensions,Dimensions)==true)
    {status = SP_UNSOLVED;}
    else{status = SP_BOARD_NOT_INITIALIZED;}
    return;
}

SlidingPuzzle::SlidingPuzzle(int Rows, int Columns)
{
    if(initializeBoard(Rows,Columns)==true)
    {status = SP_UNSOLVED;}
    else{status = SP_BOARD_NOT_INITIALIZED;}
    return;
}