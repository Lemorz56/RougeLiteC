#include "rouge.h"

Player *playerSetup()
{
    Player *newPlayer;
    //newPlayer = malloc(sizeof(Player));
    newPlayer = (Player *)malloc(sizeof(Player));

    newPlayer->position.x = 14;
    newPlayer->position.y = 14;
    newPlayer->health = 20;

    mvprintw(newPlayer->position.y, newPlayer->position.x, "@");
    move(newPlayer->position.y, newPlayer->position.x);

    return newPlayer;
}

int handleInput(int input, Player *user)
{
    Position * newPosition;
    newPosition = malloc(size(Position));
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
int checkPosition(Position * newPosition, Player *user)
{
    int space;
    switch (mvinch(newY, newX))
    {
    case '.':
    case '#':
    case '+':
        playerMove(newY, newX, user);
        break;
    default:
        move(user->position.y, user->position.x);
        break;
    }
}

int playerMove(Position *newPosition, Player *user)
{
    mvprintw(user->position.y, user->position.x, "."); //put a floor mark where user is.

    user->position.x = x;
    user->position.y = y;

    mvprintw(user->position.y, user->position.x, "@"); //put user att updated pos.
    move(user->position.y, user->position.x);          //move cursor to user.
}