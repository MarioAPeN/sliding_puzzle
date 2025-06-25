#include<iostream>
#include"sliding_puzzle.hpp"

const char LINE_UP[] = "\033[A";
const char LINE_DEL[] = "\033[2K";
const char LINE_UQUERY[] = "\r Your move: ";
const char LINE_INVALID[] = "Invalid command. Use WASD or 2468 on numeric pad.";
const char LINE_CORRECT[] = "...Game in progress..............................";

class demo: public SlidingPuzzle{
    private:
        int temp;
        void printBoard();
        void eraseBoard();
        void refreshBoard();
    public:
        int play();
};

void demo::printBoard()
{
    for(int r=0; r<getTotalRows(); r++)
    {
        std::cout << "[";
        for(int c=0; c<getTotalColumns(); c++)
        {
            std::cout << "\t" << getValueAt(r,c);
        }
        std::cout << "\t]" << std::endl;
    }
    return;
}

void demo::eraseBoard()
{
    for(int r=0; r<getTotalRows(); r++)
    {
        std::cout << LINE_UP << LINE_DEL;
    }
    std::cout << "\r";
    return;
}

void demo::refreshBoard()
{
    eraseBoard();
    printBoard();
    return;
}

int demo::play()
{
    //demo game;
    char cBin = ' ';
    char user_input = ' ';
    int turnResult = -1;

    printBoard();

    std::cout << LINE_UQUERY;

    while((user_input != 'q' && user_input !='Q') 
            && gameStatus() == SP_UNSOLVED)
    {
        while(cBin != '\n')
        {
            user_input = cBin;
            std::cin.get(cBin);
        }
        switch(user_input)
        {
            case 'w':
            case 'W':
            case '8': {
                //std::cout<<LINE_DEL<<"↑"<<LINE_UP<<LINE_DEL<<LINE_UQUERY;
                turnResult = move(SP_UP);
                break;}
            case 'a':
            case 'A':
            case '4': {
                //std::cout<<LINE_DEL<<"←"<<LINE_UP<<LINE_DEL<<LINE_UQUERY;
                turnResult = move(SP_LEFT);
                break;}
            case 's':
            case 'S':
            case '2': {
                //std::cout<<LINE_DEL<<"↓"<<LINE_UP<<LINE_DEL<<LINE_UQUERY;
                turnResult = move(SP_DOWN);
                break;}
            case 'd':
            case 'D':
            case '6': {
                //std::cout<<LINE_DEL<<"→"<<LINE_UP<<LINE_DEL<<LINE_UQUERY;
                turnResult = move(SP_RIGHT);
                break;}
            default: {
                std::cout << LINE_DEL << LINE_INVALID;
                break;}
        }
        if(turnResult == SP_BOARD_OPERATION_SUCCESSFUL)
        {
            std::cout << LINE_CORRECT;
        }
        std::cout << LINE_UP << LINE_DEL;
        if(turnResult == SP_BOARD_OPERATION_SUCCESSFUL)
        {
            refreshBoard();
            turnResult = -1;
        }
        std::cout << LINE_UQUERY;
        cBin = ' ';        
    }

    return 0;
}

int main()
{

    demo game;

    std::cout << "Welcome to sliding puzzle test program!\n" ;
    std::cout << "You will play on a 3x3 grid by default. " ;
    std::cout << "For different sized grids, please edit the source file.\n\n" ;

    std::cout << "Move with [WASD]. To quit, press [Q]\n" ;
    std::cout << "Only the last character is recognized...\n\n" ;

    //To make a custom board, set the desired number of columns and rows and
    //remove the comment on the line below.

    //game.boardCreateNew(4,5);

    game.play();

    std::cout << "\n\nGame ended in: ";
    if(game.gameStatus() == SP_SOLVED)
    {
        std::cout << "Victory! ";
    }
    else
    {
        std::cout << "...Defeat ";
    }

    std::cout << "after " << game.turnsPlayed() << " turns.";

    std::cout << "\n\nTerminating... Thank you for playing!" << std::endl;

    return 0;
}