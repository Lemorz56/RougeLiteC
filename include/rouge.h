#ifndef ROUGE_H
#define ROUGE_H

#include <curses.h> //curses library
#include <stdlib.h>
#include <time.h> //to allow s.rand

typedef struct Position
{
    int x;
    int y;
    //TILE_TYPE tile;
} Position;

typedef struct Room
{
    Position position;
    int height;
    int width;

    Position **doors;
    // Monster ** monsters;
    // Item ** items;
} Room;

typedef struct Player //player "class" / struct.
{
    Position position;
    int health;
    //Room * room; //used to store which room player is in.
} Player;

int screenSetUp();     //screenSetup func

/* level/map functions */
Room **mapSetUp();     //print map func
char **saveLevelPositions();

    /* Player functions */
    Player *
    playerSetup(); //pointer that creates player.
int handleInput(int input, Player *user);
int checkPosition(Position * newPosition, Player *user);
int playerMove(Position *newPosition, Player *user);

/* room functions */
Room *createRoom(int y, int x, int height, int width);
int drawRoom(Room *room);
int connectDoors(Position *doorOne, Position *doorTwo);

#endif