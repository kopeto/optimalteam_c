#include <stdio.h>
#include <string.h>

#include "team.h"

void push_ath(Team* team, Athlete* ath)
{
    if(team->size >= team->max_size) return;
    team->athletes[team->size] = ath;
    team->size++;
}

void pop_ath(Team* team)
{
    if(team->size <= 0) return;
    team->size--;
}

int total_points(Team* team)
{
    int acc = 0;
    for(int i=0; i<team->size; ++i)
    {
        acc += team->athletes[i]->points;
    }
    return acc;
}

int total_price(Team* team)
{
    int acc = 0;
    for(int i=0; i<team->size; ++i)
    {
        acc += team->athletes[i]->price;
    }
    return acc;
}

int at_least_1_in(Team* team, enum Discipline discipline)
{
    for(int i=0; i<team->size; ++i)
    {
        if(team->athletes[i]->discipline == discipline)
        {
            return 1;
        }
    }
    return 0;
}

int at_least_1_per_discipline(Team* team)
{
    return  at_least_1_in(team,C1M) &&
            at_least_1_in(team,C1W) &&
            at_least_1_in(team,K1M) &&
            at_least_1_in(team,K1W);
}

int per_country_max(Team* team, const int max_per_country)
{
    for(int i=0; i<team->size; ++i)
    {
        Athlete* outter = team->athletes[i];
        int acc=1;
        for(int j=i+1; j<team->size; ++j)
        {
            if(!strcmp(outter->country, team->athletes[j]->country))
            {
                acc++;
                if(acc>max_per_country)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void print_team(Team* team)
{
    for(int i=0; i<team->size; ++i)
    {
        print_athlete(team->athletes[i]);
    }
    printf("------------------------------\n");
    printf("%4d %19s %5d\n", total_points(team), "", total_price(team));
}