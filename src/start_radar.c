/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_radar
*/

#include "my.h"
#include "myr.h"

void malloc_all(char const *filepath, Radar *radar)
{
    count_elements(filepath, radar);
    radar->xt = malloc(sizeof(int) * radar->count_t);
    radar->yt = malloc(sizeof(int) * radar->count_t);
    radar->xp = malloc(sizeof(int) * radar->count_p);
    radar->yp = malloc(sizeof(int) * radar->count_p);
    radar->mxp = malloc(sizeof(int) * radar->count_p);
    radar->myp = malloc(sizeof(int) * radar->count_p);
    radar->rad_t = malloc(sizeof(int) * radar->count_t);
}

int start_radar(char const *filepath)
{
    struct stat sfile;
    stat(filepath, &sfile);
    int fd = open(filepath, O_RDONLY);
    int count_t = 0;
    int count_p = 0;
    Radar radar;
    char *buffer = malloc(sizeof(char) * (sfile.st_size + 1));

    if (fd == -1)
        return 84;

    malloc_all(filepath, &radar);
    read(fd, buffer, sfile.st_size);
    find_elements(filepath, count_t, &radar, count_p);
    print_map(&radar);
}
