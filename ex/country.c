/*
Write a program lab6 - get - a - country.c which gets the detail of a country from the command line as follows :
 -Name - Capital - Population(in million) - Size(in km2) The program can then print the information of the country line by line in the above order of information, for example : Input :

	. / lab6 - get - a - contry Ireland Dublin 4.99 84421
	Output :

	Ireland
	Dublin
	4.99 million people
	84421 km2
*/

#include <stdio.h>
#include <stdlib.h>

struct Country {
    char name[50];
    char capital[50];
    double population;
    double size;
};

typedef struct Country Country;

void write(int i, Country *country);
void print_country(Country *country);

int main()
{
    Country *country = malloc( sizeof(Country) );
    char para[4][11] = {"Name", "Capital", "Population", "Size"};

    for(int i = 0; i < 4; i++)
    {
        printf("Enter %s -> ", para[i]);
        write(i, country);
    }

    print_country(country);
    free(country);
}

void write(int i, Country *country)
{
    switch (i)
    {
            case 0:
                scanf("%s", country -> name);
                break;
            case 1:
                scanf("%s", country -> capital);
                break;
            case 2:
                scanf("%lf", &(country -> population));
                break;
            case 3:
                scanf("%lf", &(country -> size));
                break;
    }
}

void print_country(Country *country) 
{
    printf("%s\n", country -> name);
    printf("%s\n", country -> capital);
    printf("%.2f\n", country -> population);
    printf("%.2f\n", country -> size);
}