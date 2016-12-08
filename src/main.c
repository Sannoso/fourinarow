#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 255

struct
{
  int timebank;
  int time_per_move;
  int botid;
  int field_columns;
  int field_rows;
} game_settings;


int main(int argc, const char *argv[])
{
    char line[MAX_LINE_LENGTH];

    #ifdef DEBUG
    printf("debug-mode\n");
    freopen("test.in", "r", stdin);
    #endif // DEBUG
//    srand(time(NULL)); //seed for random number generator

    #ifdef DEBUG
    while(fgets(line, MAX_LINE_LENGTH, stdin) != NULL)
    #else
    while(fgets(line, MAX_LINE_LENGTH, stdin) !=NULL)
    #endif
    {
        if(!strncmp(line, "action ", 7))//action input
        {
            #ifdef DEBUG
            printf("Engine asks me to make a move\n");
            printf(line);
            #endif // DEBUG
        }
        else if (!strncmp(line, "settings ",8)) //update settings
        {
            #ifdef DEBUG
            printf("setting the following:\n");
            printf(line);
            #endif // DEBUG
        }
        else if (!strncmp(line, "update game ", 12))
        {
            #ifdef DEBUG
            printf("update on the game namely:\n");
            printf(line);
            #endif // DEBUG
        }

    }

    return EXIT_SUCCESS;
}
