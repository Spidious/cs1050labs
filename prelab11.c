#include <stdio.h>
#include <string.h>

// Movie Struct
typedef struct _Movie
{
	char title[256];
	long gross;
	int year;
}Movie;

// Function headers
void bubblesort(Movie * movies, long size);
void printArray(Movie * movies, int s);


void bubblesort(Movie * movies, long size)
{
    int i, j;
    Movie temp; // You had "int temp;""

    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-1-i; j++)
        {
            if(strcmp(movies[j].title, movies[j+1].title)>0)    //You can't do "movies[j] > movies[j+1]". 
            {
                temp = movies[j];
                movies[j]=movies[j+1];
                movies[j+1]=temp;
            }
        }
    }
}

void printArray(Movie * movies, int s)
{
    int i;

    for (i = 0; i < s; i++)
    {
        printf("%-30s\t%ld\t%d\n", movies[i].title, movies[i].gross, movies[i].year);   //"I added -30 to where the title is printed to make this look nicer"
    } 
}

int main(void)
{
    Movie movies[] = 
    {
        {"Gone_with_the_Wind", 3713000000, 1939},
        {"Avatar", 3263000000, 2009},
        {"Titanic", 3087000000, 1997},
        {"Star_Wars", 3049000000, 1977},
        {"Avengers:_Endgame", 2798000000, 2019},
        {"The_Sound_of_Music", 2554000000, 1965},
        {"E.T._the_Extra-Terrestrial", 2493000000, 1982},
        {"The_Ten_Commandments", 2361000000, 1956},
        {"Doctor_Zhivago", 2238000000, 1965},
        {"Star_Wars:_The_Force_Awakens", 2206000000, 2015},
        {"Snow_White", 2150000000, 1937},
        {"Jurassic_Park", 2100000000, 1993},
        {"Jaws", 2100000000, 1975},
        {"Avengers:_Infinity_War", 2050000000, 2018},
        {"The_Exorcist", 2000000000, 1973},
    };

    // sizeof movies is like 4000 because its adding together all the movies sizes
    // so divide it by the size of each movie variable
    printArray(movies, sizeof(movies)/sizeof(Movie));
    bubblesort(movies, sizeof(movies)/sizeof(Movie));
    puts("\n-------------------------------------------------------\n\n");
    printArray(movies, sizeof(movies)/sizeof(Movie));
}
