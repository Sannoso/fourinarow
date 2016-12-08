#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 255
#define TRUE 1
#define FALSE 0

struct
{
  int timebank;
  int time_per_move;
  int botid;
  int field_columns;
  int field_rows;
} game_settings;

int process_input(void);
int makemove(void);
int process_settings(void);
void initialise();

int main(int argc, const char *argv[])
{
//    intialise();
    while(1==1)
    {
        int b_makemove = FALSE;
        b_makemove = process_input();
        if(b_makemove == TRUE)
        {
            makemove();
        }
        //take action after parsing input
        //makemove
    }
    return EXIT_SUCCESS;
}

void initialise()
{
    //dunno yet
}

int process_input(void)
{
    char line[MAX_LINE_LENGTH];
    char part[3][MAX_LINE_LENGTH];

    #ifdef DEBUG
    printf("debug-mode\n");
    freopen("test.in", "r", stdin);
    #endif // DEBUG
//    srand(time(NULL)); //seed for random number generator

    //parse input
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
            sscanf(&line[7], "%s %s", part[0], part[1]);
            return TRUE;
        }
        else if (!strncmp(line, "settings ",8)) //update settings
        {
            #ifdef DEBUG
            printf("setting the following:\n");
            printf(line);
            #endif // DEBUG
            process_settings();
            return FALSE;
        }
        else if (!strncmp(line, "update game ", 12))
        {
            #ifdef DEBUG
            printf("update on the game namely:\n");
            printf(line);
            #endif // DEBUG
            return FALSE;
        }
    }
    return TRUE;
}

int process_settings()
{
    printf("processing settings\n");
}

int makemove()
{
    printf("making my move \n");
}
