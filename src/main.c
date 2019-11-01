#include "rouge.h"

int main()
{
    Player * user; //player is a pointer to user so we cant manipulate it later.
    int ch;
    Position * newPosition;

    char ** level;

    screenSetUp();

    mapSetUp();

    level = saveLevelPositions();

    user = playerSetup(); //Pointer variable gets assigned in the function

    //main game loop
    while ((ch = getch()) != 'q')
    {
        newPosition = handleInput(ch, user);
    }
    endwin();
    return 0;
}

int screenSetUp() //setup the screen
{
    initscr(); //starts "screen"
    noecho(); //disables typing ON screen
    refresh();

    srand(time(NULL)); //allows us to call rand number
    return 1;

}