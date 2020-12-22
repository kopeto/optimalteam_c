#pragma once

enum Discipline {
    C1M,
    C1W,
    K1M,
    K1W
};

typedef struct Athlete{
    int points;
    int price;
    enum Discipline discipline;
    char* country;
    char* name;
} Athlete;

void sort(Athlete* athletes, int n);
void swap_athletes( Athlete* a, Athlete* b);
int get_athletes(Athlete** athletes);
const char* disc_to_str(enum Discipline discipline);
void print_athlete(Athlete* athlete);