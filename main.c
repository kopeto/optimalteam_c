#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "team.h"

void solver(Athlete* current_candidate, 
            Athlete* last_candidate, 
            Team* current_team, 
            Team* best_team, 
            const int remaining_budget, 
            const int max_per_country);   

#define TEAM_SIZE 7
#define MAX_PER_COUNTRY 2
#define INITIAL_BUDGET 25000

int main()
{
    Athlete* athletes;
    int n = get_athletes(&athletes);


    clock_t start, end;
    Team current_team;
    Team best_team;

    current_team.athletes = (Athlete**)malloc(TEAM_SIZE * sizeof(Athlete*));
    current_team.max_size = TEAM_SIZE;
    current_team.size = 0;

    best_team.athletes = (Athlete**)malloc(TEAM_SIZE * sizeof(Athlete*));
    best_team.max_size = TEAM_SIZE;
    best_team.size = 0;

    start = clock();
    solver(&athletes[0], &athletes[n-1], &current_team, &best_team, INITIAL_BUDGET, MAX_PER_COUNTRY);
    end = clock();

    print_team(&best_team);

    printf("%.3lfms\n", (double)(end-start));

}

void solver(Athlete* current_candidate, 
            Athlete* last_candidate, 
            Team* current_team, 
            Team* best_team, 
            const int remaining_budget, 
            const int max_per_country)
{
    // TRIVIAL
    if(current_team->size == current_team->max_size)
    {
        //Apply Team constraints
        if( total_points(current_team) > total_points(best_team) &&
            at_least_1_per_discipline(current_team) &&
            per_country_max(current_team,max_per_country))
        {
            for(int i=0; i<current_team->size; ++i)
            {
                best_team->athletes[i] = current_team->athletes[i];
            }
            best_team->size = current_team->size;
        }
    }
    // RECURSIVE
    else
    {   
        while(current_candidate <= last_candidate)
        {
            if( (current_team->max_size - current_team->size) * current_candidate->points + total_points(current_team) < total_points(best_team) )
            {
                return;
            }
            else if( remaining_budget > current_candidate->price)
            {
                push_ath(current_team,current_candidate);
                solver(current_candidate+1, last_candidate, current_team, best_team, remaining_budget-current_candidate->price, max_per_country);
                pop_ath(current_team);
            }
            ++current_candidate;
        }
    }
    
    return;
}  
