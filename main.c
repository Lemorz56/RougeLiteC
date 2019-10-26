#include <curses.h> //curses library
#include <stdlib.h>
#include <windows.h>

typedef struct Room
{
    int xPosition;
    int yPosition;
    int height;
    int width;
    // Monster ** monsters;
    // Item ** items;

} Room;

typedef struct Player //player "class" / struct.
{
    int xPosition;
    int yPosition;
    int health;
    //Room * room; //used to store which room player is in.
}   Player;

int screenSetUp(); //screenSetup func
Room ** mapSetUp(); //print map func
Player * playerSetup(); //pointer that creates player.
int handleInput(int input, Player * user);
int checkPosition(int newY, int newX, Player *user);
int playerMove(int y, int x, Player *user);

/* room functions */
Room * createRoom(int y, int x, int height, int width);
int drawRoom(Room *room);

    int main()
{
    Player * user; //player is a pointer to user so we cant manipulate it later.
    int ch;
    screenSetUp();

    mapSetUp();

    user = playerSetup(); //Pointer variable gets assigned in the function

    //main game loop
    while ((ch = getch()) != 'q')
    {
        handleInput(ch, user);

    }

    
    endwin();
    return 0;
}


int screenSetUp() //setup the screen
{
    initscr(); //starts "screen"
    noecho(); //disables typing ON screen
    refresh();

    return 1;

}

Room ** mapSetUp() //setup the map
{
    Room ** rooms;
    rooms = malloc(sizeof(Room)*6);

   //mvprintw(y, x, "string");
//    mvprintw(13, 13, "--------");
//    mvprintw(14, 13, "|......|");
//    mvprintw(15, 13, "|......|");
//    mvprintw(16, 13, "|......|");
//    mvprintw(17, 13, "|......|");
//    mvprintw(18, 13, "--------");

   rooms[0] = createRoom(13, 13, 6, 8); //returns a room like above
   drawRoom(rooms[0]);

//    mvprintw(2, 40, "--------");
//    mvprintw(3, 40, "|......|");
//    mvprintw(4, 40, "|......|");
//    mvprintw(5, 40, "|......|");
//    mvprintw(6, 40, "|......|");
//    mvprintw(7, 40, "--------");

   rooms[1] = createRoom(2, 40, 6, 8); //returns a room like above
   drawRoom(rooms[1]);

//    mvprintw(10, 40, "------------");
//    mvprintw(11, 40, "|..........|");
//    mvprintw(12, 40, "|..........|");
//    mvprintw(13, 40, "|..........|");
//    mvprintw(14, 40, "|..........|");
//    mvprintw(15, 40, "------------");

   rooms[2] = createRoom(10, 40, 6, 12); //returns a room like above
   drawRoom(rooms[2]);

   return rooms;
}
int drawRoom(Room * room)
{
    int x;
    int y;
    /* draw top and bottom */
    for(x = room->xPosition; x < room->xPosition + room->width; x++)
    {
        mvprintw(room->yPosition, x, "-"); //Top
        mvprintw(room->yPosition + room->height - 1, x, "-"); //Bottom
    }

    /* Draw floors and sidewalls*/
    for(y = room->yPosition + 1; y < room->yPosition + room->height - 1; y++)
    {
        //draw side walls
        mvprintw(y, room->xPosition, "|");
        mvprintw(y, room->xPosition + room->width - 1, "|");
        //draw walls
        for(x = room->xPosition + 1; x < room->xPosition + room->width - 1; x++)
        {
            mvprintw(y, x, ".");
        }
    }
    return 1;
}

Room * createRoom(int y, int x, int height, int width)
{
    //declare new room
    Room * newRoom;
    newRoom = malloc(sizeof(Room));

    newRoom->xPosition = x;
    newRoom->yPosition = y;
    newRoom->height = height;
    newRoom->width = width;

    return newRoom;
}

Player * playerSetup()
{
    Player * newPlayer;
    //newPlayer = malloc(sizeof(Player));
    newPlayer = (Player *)malloc(sizeof(Player));

    newPlayer->xPosition = 14;
    newPlayer->yPosition = 14;
    newPlayer->health = 20;
   
    mvprintw(newPlayer->yPosition, newPlayer->xPosition, "@");
    move(newPlayer->yPosition, newPlayer->xPosition);

    return newPlayer;
}

int handleInput(int input, Player *user)
{
    int newY;
    int newX;
    switch (input)
    {
        //Move up
        case 'w':
        case 'W':
            newY = user->yPosition - 1;
            newX = user->xPosition;
            //playerMove(user->yPosition - 1, user->xPosition, user);
            break;
        //move down
        case 's':
        case 'S':
            newY = user->yPosition + 1;
            newX = user->xPosition;
            // playerMove(user->yPosition + 1, user->xPosition, user);
            break;
        //move left
        case 'a':
        case 'A':
            newY = user->yPosition;
            newX = user->xPosition - 1;
            // playerMove(user->yPosition, user->xPosition - 1, user);
            break;
        //move right
        case 'd':
        case 'D':
            newY = user->yPosition;
            newX = user->xPosition + 1;
            // playerMove(user->yPosition, user->xPosition + 1, user);
            break;
        default:
            break;
    }
    checkPosition(newY, newX, user);
}

/* check what is at the next position */
int checkPosition(int newY, int newX, Player * user) 
{
    int space;
    switch (mvinch(newY, newX))
    {
        case '.':
            playerMove(newY, newX, user);
            break;
        default:
            move(user->yPosition, user->xPosition);
            break;
    }
}

int playerMove(int y, int x, Player * user)
{
    mvprintw(user->yPosition, user->xPosition, "."); //put a floor mark where user is.

    user->xPosition = x;
    user->yPosition = y;

    mvprintw(user->yPosition, user->xPosition, "@"); //put user att updated pos.
    move(user->yPosition, user->xPosition); //move cursor to user.
}

// https://youtu.be/6D_G2ceFFGA?t=558