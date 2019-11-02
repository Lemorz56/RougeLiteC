#ifndef ROUGE_H
#define ROUGE_H

#include <curses.h> //curses library
#include <stdlib.h>
#include <time.h> //to allow s.rand

typedef struct Level
{
    char ** tiles;
    int level;
    int numberOfRooms;
    struct Room ** rooms;
    struct Monster ** monsters;
    int numberOfMonsters;
    struct Player * user;
} Level;

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

    Position ** doors;
    // Monster ** monsters;
    // Item ** items;
} Room;

typedef struct Player //player "class" / struct.
{
    Position position;
    int health;
    //Room * room; //used to store which room player is in.
} Player;

typedef struct Monster
{
    char symbol;
    int health;
    int attack;
    int speed;
    int defence;
    int pathfinding;
    Position position;
    
} Monster;


int screenSetUp();     //screenSetup func

/* level/map functions */
Level *createLevel();
Room ** roomSetUp();     //print map func
char ** saveLevelPositions();

/* Player functions */
Player * playerSetup(); //pointer that creates player.
Position * handleInput(int input, Player * user);
int checkPosition(Position * newPosition, Player * user, char ** level);
int playerMove(Position * newPosition, Player *user, char **level);

/* room functions */
Room * createRoom(int y, int x, int height, int width);
int drawRoom(Room * room);
int connectDoors(Position * doorOne, Position * doorTwo);

#endif