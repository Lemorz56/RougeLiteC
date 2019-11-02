#include "rouge.h"

Player * playerSetup()
{
    Player * newPlayer;
    //newPlayer = malloc(sizeof(Player));
    newPlayer = (Player *)malloc(sizeof(Player));

    newPlayer->position.x = 14;
    newPlayer->position.y = 14;
    newPlayer->health = 20;

    mvprintw(newPlayer->position.y, newPlayer->position.x, "@");
    move(newPlayer->position.y, newPlayer->position.x);

    return newPlayer;
}

Position * handleInput(int input, Player * user)
{
    Position * newPosition;
    newPosition = malloc(sizeof(Position));
    switch (input)
    {
    //Move up
    case 'w':
    case 'W':
        newPosition->y = user->position.y - 1;
        newPosition->x = user->position.x;
        //playerMove(user->yPosition - 1, user->xPosition, user);
        break;
    //move down
    case 's':
    case 'S':
        newPosition->y = user->position.y + 1;
        newPosition->x = user->position.x;
        // playerMove(user->yPosition + 1, user->xPosition, user);
        break;
    //move left
    case 'a':
    case 'A':
        newPosition->y = user->position.y;
        newPosition->x = user->position.x - 1;
        // playerMove(user->yPosition, user->xPosition - 1, user);
        break;
    //move right
    case 'd':
    case 'D':
        newPosition->y = user->position.y;
        newPosition->x = user->position.x + 1;
        // playerMove(user->yPosition, user->xPosition + 1, user);
        break;
    default:
        break;
    }
    return newPosition;
}

/* check what is at the next position */
int checkPosition(Position * newPosition, Player * user, char ** level)
{
    int space;
    switch (mvinch(newPosition->y, newPosition->x))
    {
    case '.':
    case '#':
    case '+':
        playerMove(newPosition, user, level);
        break;
    default:
        move(user->position.y, user->position.x);
        break;
    }
}

int playerMove(Position * newPosition, Player * user, char ** level)
{
    char buffer[8]; //create an char of size 8 that we can put whatever char is where our user position is.

    //CONVERTS SINGLE CHARACTER to string characters.
    sprintf(buffer, "%c", level[user->position.y][user->position.x]); //turns the level char array into a passable char store it inside BUFFER

    mvprintw(user->position.y, user->position.x, buffer); //put a floor mark where user is. and it has 2 be double string char

    user->position.x = newPosition->x;
    user->position.y = newPosition->y;

    mvprintw(user->position.y, user->position.x, "@"); //put user att updated pos.
    move(user->position.y, user->position.x);          //move cursor to user.
}