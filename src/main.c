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
void makemove(void);
void process_settings(char *, char *);
void initialise();

int main(int argc, const char *argv[])
{
    #ifdef DEBUG
    printf("debug-mode\n");
    #endif // DEBUG
    initialise();
    while(1==1)
    {
        int b_makemove = FALSE;
        b_makemove = process_input();
        if(b_makemove == TRUE)
        {
            makemove();
            fflush(stdout);
        }
        //take action after parsing input
        //makemove
    }
    return EXIT_SUCCESS;
}

void initialise()
{
    srand(time(NULL));
    #ifdef DEBUG
    freopen("test.in", "r", stdin);
    #endif // DEBUG
}

int process_input(void)
{
    char line[MAX_LINE_LENGTH];
    char part[3][MAX_LINE_LENGTH];

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
        else if (!strncmp(line, "settings ",9)) //update settings
        {
            #ifdef DEBUG
            printf("setting the following:\n");
            printf(line);
            #endif // DEBUG
            sscanf(&line[9], "%s %s", part[0], part[1]);
            process_settings(part[0], part[1]);
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
    return FALSE;
}

void process_settings(char *setting, char *value)
{
    #ifdef DEBUG
    //printf("processing settings\n");
    #endif // DEBUG
    if(!strncmp(setting, "timebank", 8 ))
    {
        game_settings.timebank = atoi(value);
        #ifdef DEBUG
        printf("timebank set to %d\n", atoi(value));
        #endif // DEBUG
        return;
    }
    else if(!strncmp(setting, "time_per_move", 13))
    {
        game_settings.time_per_move = atoi(value);
        #ifdef DEBUG
        printf("time per move set to %d\n", atoi(value));
        #endif // DEBUG
        return;
    }
    else if(!strncmp(setting, "player_names", 12))
    {
        //not interested in player_name, so do nothing
        return;
    }
    else if(!strncmp(setting, "your_botid", 10))
    {
        game_settings.botid = atoi(value);
        #ifdef DEBUG
        printf("bot ID = %d\n", atoi(value));
        #endif // DEBUG
        return;
    }
    else if(!strncmp(setting, "your_bot", 8))
    {
        //not interested in player_name, so do nothing
        return;
    }
    else if (!strncmp(setting, "field_columns", 13))
    {
        game_settings.field_columns = atoi(value);
        #ifdef DEBUG
        printf("amount of field columns = %d\n", atoi(value));
        #endif // DEBUG
        return;
    }
    else if (!strncmp(setting, "field_rows", 10))
    {
        game_settings.field_rows = atoi(value);
        #ifdef DEBUG
        printf("amount of field rows = %d\n", atoi(value));
        #endif // DEBUG
        return;
    }
    else
    {
        printf("Unknown setting\n");
    }
    return;
}

void makemove()
{
    #ifdef DEBUG
    printf("making my move \n");
    #endif // DEBUG
    fprintf(stdout, "place_disc %d\n", rand() %7);
    //printf("place_disc %d\n", 1);
}
