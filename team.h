#pragma once

#include "athlete.h"

typedef struct Team {
    int max_size;
    int size;
    Athlete** athletes;
} Team;

int is_full(Team* team);

int total_price(Team* team);
int total_points(Team* team);
void print_team(Team* team);

int at_least_1_per_discipline(Team* team);
int at_least_1_in(Team* team, enum Discipline discipline);
int per_country_max(Team* team, const int max_per_country);

void push_ath(Team* team, Athlete* ath);
void pop_ath(Team* team);