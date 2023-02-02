/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_radar
*/

#include "my.h"
#include "myr.h"

int get_elements(char *temp, int i, int *coordinate, int count_p)
{
    int n = 0;
    for ( ; temp[i] != ' ' && temp[i] != '\n' ;i++) {
        n = n + temp[i] - 48;
        n = n * 10;
    }
    n /= 10;

    coordinate[count_p] = n;
    return i + 1;
}

int find_elements(char const *filepath, int count_t, Radar *radar, int count_p)
{
    size_t size = 0;
    FILE * buff = NULL;
    buff = fopen(filepath, "r");
    char * temp;
    while (getline(&temp, &size, buff) != -1) {
        int i = 2;
        if (temp[0] == 'A') {
            i = get_elements(temp, i, radar->xp, count_p);
            i = get_elements(temp, i, radar->yp, count_p);
            i = get_elements(temp, i, radar->mxp, count_p);
            i = get_elements(temp, i, radar->myp, count_p);
            count_p++;
        }
        if (temp[0] == 'T') {
            i = get_elements(temp, i, radar->xt, count_t);
            i = get_elements(temp, i, radar->yt, count_t);
            i = get_elements(temp, i, radar->rad_t, count_t);
            count_t++;
        }
    }
}

int count_elements(char const *filepath, Radar *radar)
{
    size_t size = 0;
    FILE * buff = NULL;
    buff = fopen(filepath, "r");
    char * temp;
    struct stat sfile;
    stat(filepath, &sfile);
    while (getline(&temp, &size, buff) != -1) {
        if (temp[0] == 'A')
            radar->count_p++;
        if (temp[0] == 'T')
            radar->count_t++;
    }
}
