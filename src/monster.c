#include "rouge.h"

int addMonsters(Level* level)
{
    int x;
    level->monsters = malloc(sizeof(Monster *)* 6);
    level->numberOfMonsters = 0;

    for(x = 0; x < level->numberOfRooms; x++)
    {
        if ((rand() % 2) == 0)
        {
            level->monsters[level->numberOfMonsters] = selectMonster(level->level);

            setStartingPosition(level->monsters[level->numberOfMonsters], level->rooms[x]);

            level->numberOfMonsters++;
        }
    }
}

Monster * selectMonster(int level)
{
    int monster;
    switch (level)
    {
        case 1:
        case 2:
        case 3:
            monster = (rand() % 2) + 1;
            break;
        case 4:
        case 5:
            monster = (rand() % 2) + 2;
            break;
        case 6:
            monster = 3;
            break;
    }
    /*

1. SPIDER:
    symbol: X
    levels: 1-3
    health: 2
    attacK: 1
    speed: 1
    defence: 1
    pathfinding: 1 (random)

2. Goblin:
    symbol: G
    levels: 1-5
    health: 5
    attacK: 3
    speed: 1
    defence: 1
    pathfinding: 2 (seeking)

3. Troll:
    symbol: T
    levels: 4-6
    health: 15
    attack: 5 
    speed: 1
    defence: 1
    pathfinding: 1 (random)

*/
    switch(monster)
    {
        case 1: //spider
            return createMonster('X', 2, 1, 1, 1, 1);
        case 2: //goblin
            return createMonster('G', 5, 3, 1, 1, 2);
        case 3: //troll
            return createMonster('T', 15, 5, 1, 1, 1);
    }
}

Monster * createMonster(char symbol, int health, int attack, int speed, int defence, int pathfinding)
{
    Monster * newMonster;
    newMonster = malloc(sizeof(Monster));

    newMonster->symbol = symbol;
    newMonster->health = health;
    newMonster->attack = attack;
    newMonster->speed = speed;
    newMonster->defence = defence;
    newMonster->pathfinding = pathfinding;

    return newMonster;
}

int setStartingPosition(Monster * monster, Room * room)
{
    char buffer[8];

    monster->position.x = (rand() % (room->width - 2)) + room->position.x + 1;
    monster->position.y = (rand() % (room->height - 2)) + room->position.y + 1;

    sprintf(buffer, "%c", monster->symbol); //converting monster->symbol to "symbol" instead of 'symbol' which mvprintw does not work with.

    mvprintw(monster->position.y, monster->position.x, buffer);
}

//Börja om här https://youtu.be/jAp2CHjjKKs?t=1878