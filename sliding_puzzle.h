#ifndef ____SLIDING___PUZZLE___GAME___LOGIC___
#define ____SLIDING___PUZZLE___GAME___LOGIC___

#define SP_UP       0xd5
#define SP_DOWN     0x5f
#define SP_LEFT     0x0a
#define SP_RIGHT    0xc3

extern const int SP_SOLVED;
extern const int SP_UNSOLVED;
extern const int SP_SINGLE_STEP;

extern const int SP_CANNOT_MANAGE_MEMORY;
extern const int SP_BOARD_NOT_INITIALIZED;
extern const int SP_BOARD_OPERATION_SUCCESSFUL;
extern const int SP_BOARD_OPERATION_FAILED;


typedef struct SLIDING_PUZZLE_BOARD{
    int* board;
    int rows;
    int columns;
    int rowPosition;
    int columnPosition;
    int turns;
    int status;
}SP_board;

int boardCreate(SP_board* game,int rows,int columns);

int boardReset(SP_board* game);

int boardDestroy(SP_board* game);

int slidingPuzzleMove(SP_board* game, int direction, int requestedStep);

#endif