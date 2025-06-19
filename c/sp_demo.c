#include<stdio.h>
#include<stdlib.h>
#include"../c/sliding_puzzle.h"

const char LINE_UP[] = "\033[A";
const char LINE_DEL[] = "\033[2K";

const int REQUEST_QUIT = 136;
const int CONTINUE = 225;

char readInput()
{
	char input[]={' ',' '};
	do{
		input[0] = input[1];
		input[1] = getchar();
	}while(input[1]!='\n');
	
	return input[0];
}

void printBoard(SP_board* game)
{
    for(int i = 0;i<(game->rows);i++)
	{
		printf("[\t");
		for(int j = 0;j<(game->columns);j++)
		{
			printf("%d\t",
                game->board[(i*(game->columns))+j]);
		}
		printf("]\n");
	}
    return;
}

void refreshBoard(SP_board* game)
{
    for(int i=0;i<=(game->rows);i++)
    {
        printf("%s%s",LINE_UP,LINE_DEL);
    }
    printf("\r");
    printBoard(game);
    printf("\n");
    return;
}

int main()
{
    int quitFlag = CONTINUE;
    int boardRows = 3;
    int boardCols = 3;
    SP_board puzzle;

    if(boardCreate(&puzzle,boardRows,boardCols) == SP_BOARD_OPERATION_SUCCESSFUL)
    {
        printf("Welcome to sliding puzzle test program!\n");
        printf("You will play on a 3x3 grid by default. ");
        printf("For different sized grids, please edit the source file.\n\n");

        printf("Move with [WASD]. To quit, press [Q]\n");
        printf("Only the last character is recognized...\n\n");

        printBoard(&puzzle);
        printf("Your move: ");
        while(puzzle.status != SP_SOLVED  && quitFlag != REQUEST_QUIT)
        {
            switch (readInput())
            {
                case 'w':
                case 'W':
                {
                    if(slidingPuzzleMove(&puzzle,SP_UP,SP_SINGLE_STEP) ==
                    SP_BOARD_OPERATION_SUCCESSFUL)
                    {
                        refreshBoard(&puzzle);
                    }
                    break;
                }
                case 'a':
                case 'A':
                {
                    if(slidingPuzzleMove(&puzzle,SP_LEFT,SP_SINGLE_STEP) ==
                    SP_BOARD_OPERATION_SUCCESSFUL)
                    {
                        refreshBoard(&puzzle);
                    }
                    break;
                }
                case 's':
                case 'S':{
                    if(slidingPuzzleMove(&puzzle,SP_DOWN,SP_SINGLE_STEP) ==
                    SP_BOARD_OPERATION_SUCCESSFUL)
                    {
                        refreshBoard(&puzzle);
                    }
                    break;
                }
                case 'd':
                case 'D':{
                    if(slidingPuzzleMove(&puzzle,SP_RIGHT,SP_SINGLE_STEP) ==
                    SP_BOARD_OPERATION_SUCCESSFUL)
                    {
                        refreshBoard(&puzzle);
                    }
                    break;
                }
                case 'q':
                case 'Q':{
                    quitFlag = REQUEST_QUIT;
                }
                default:
                    break;
            }
            printf("%s%s\rYour move: ",LINE_UP,LINE_DEL);
        }
    }
    else
    {
        printf("If you're reading this...");
        printf("you messed up royaly at some point lol\n");
        printf("Please, try some valid vaules ok? Rows and columns");
        printf(" cannot be less than or equal to 1\n\n");
    }

    printf("\n\nTerminating... Thank you for playing!\n");

    boardDestroy(&puzzle);

    return 0;
}
