#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RANGE 15
#define MIN_RANGE 1
#define SPRINT 100

#define TEAMS 3
#define RUNNERS 4

typedef struct Runner Runner;
struct Runner {
    int vel;
    int distance;
};

typedef struct Team Team;
struct Team {
    Runner runner[4];
    int curr_runner_idx;
    int finished;
};

Team *create_teams();

int main()
{   
    srand(time(NULL));
    Team *teams = create_teams();

    int is_race_finished = 0;
    while ( !is_race_finished )
    {
        for (int t = 0; t < TEAMS; t++)
        {
            // se un team ha finito, skippalo
            if (teams[t].finished)
                continue;

            // mi fetcho il runner di ora
            int runner_idx = teams[t].curr_runner_idx;
            Runner *runner = &teams[t].runner[runner_idx];

            int vel_distance = rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE;
            runner -> distance += vel_distance;

            if ( runner -> distance >= SPRINT )
            {
                runner -> distance = SPRINT;
                teams[t].curr_runner_idx += 1;

                if (teams[t].curr_runner_idx >= 4) 
                {
                    teams[t].finished = 1;
                    printf("Team %d ha terminato la gara\n", t + 1);
                }
            }
        }

        int finished_count = 0;
        for (int t = 0; t < TEAMS; t++)
            if ( teams[t].finished )
                finished_count += 1;
        
        if ( finished_count == TEAMS )
            is_race_finished = 1;
    }

    free(teams);
    return 0;
}

Team *create_teams()
{
    Team *teams = malloc(sizeof(Team) * TEAMS);
    if ( !teams ) exit(EXIT_FAILURE);

    for (int i = 0; i < TEAMS; i++)
    {
        teams[i].curr_runner_idx = 0;
        teams[i].finished = 0;

        for (int r = 0; i < r; r++)
        {
            teams[i].runner[r].vel = rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE;
            teams[i].runner[r].distance = 0;
        }
    }

    return teams;
}

