#ifndef ___SLIDING___PUZZLE____CPP___
#define ___SLIDING___PUZZLE____CPP___

#include<vector>

#define SP_UP       0xd5
#define SP_DOWN     0x5f
#define SP_LEFT     0x0a
#define SP_RIGHT    0xc3

extern const int SP_SOLVED;
extern const int SP_UNSOLVED;
extern const int SP_BOARD_NOT_INITIALIZED;

extern const int SP_SINGLE_STEP;

extern const int SP_BOARD_OPERATION_SUCCESSFUL;
extern const int SP_BOARD_OPERATION_FAILED;

class SlidingPuzzle{
    private:
        std::vector <int>board;
        int rows;
        int columns;
        int rowPosition;
        int columnPosition;
        int turns;
        int status;

        bool initializeBoard(int Rows, int Columns);
        bool locateEmptySpace();
        int verifyIfSolved();
        int shuffleBoard();
        int spMove(int direction, int step);
    
    protected:
        int getValueAt(int position);
        int getValueAt(int Row, int Column);

        int getTotalRows();
        int getTotalColumns();

    public:
        SlidingPuzzle();
        SlidingPuzzle(int Dimension);
        SlidingPuzzle(int Rows, int Columns);

        bool boardCreateNew(int Rows, int Columns);
        int boardResetGame();
        int move(int direction, int requestedStep = SP_SINGLE_STEP);

        int turnsPlayed();
        int gameStatus();
};

#endif