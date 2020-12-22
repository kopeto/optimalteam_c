#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "athlete.h"


void swap_athletes( Athlete* a, Athlete* b) 
{ 
    Athlete temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void sort(Athlete* athletes, int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n - 1; i++) { 
  
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
            if (athletes[j].points > athletes[min_idx].points) 
                min_idx = j; 
  
        // Swap the found minimum element 
        // with the first element 
        swap_athletes(&athletes[min_idx], &athletes[i]); 
    } 
} 

int get_athletes(Athlete** athletes)
{
    char line[128];
    fgets(line, 128, stdin);
    int n = atoi(line);
    *athletes = (Athlete*)malloc(n*sizeof(Athlete));

    for(int i=0; i<n; ++i) // each athlete
    {
        fgets(line, 128, stdin);
        char* pch;
        const char* delimiters = " \n\t";

        //NAME
        pch = strtok (line,delimiters);
        (*athletes)[i].name = (char*)malloc(strlen(pch)*sizeof(char));
        strcpy( (*athletes)[i].name, pch);

        //PRICE
        pch = strtok (NULL, delimiters);
        (*athletes)[i].price = atoi(pch);

        //POINTS
        pch = strtok (NULL, delimiters);
        (*athletes)[i].points = atoi(pch);

        //COUNTRY
        pch = strtok (NULL, delimiters);
        (*athletes)[i].country = (char*)malloc(strlen(pch)*sizeof(char));
        strcpy ((*athletes)[i].country, pch);

        //DISCIPLINE
        pch = strtok (NULL, delimiters);
        if(!strcmp(pch,"C1M"))  (*athletes)[i].discipline = C1M;
        else if(!strcmp(pch,"C1W"))  (*athletes)[i].discipline = C1W;
        else if(!strcmp(pch,"K1M")) (*athletes)[i].discipline = K1M;
        else if(!strcmp(pch,"K1W")) (*athletes)[i].discipline = K1W;

    }  

    sort(*athletes,n);

    return n;
}

const char* disc_to_str(enum Discipline discipline)
{
    switch(discipline)
    {
        case C1M:
            return "C1M";
        case C1W:
            return "C1W";
        case K1M:
            return "K1M";
        case K1W:
            return "K1W";
        default:
            return NULL;
    }
}

void print_athlete(Athlete* athlete)
{
    printf("%4d %9s %4s %4s %5d\n", athlete->points, athlete->name, disc_to_str(athlete->discipline),  athlete->country, athlete->price);
}